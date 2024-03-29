///***************************************************************************
// Product: BSP for DPP with lwIP on EK-LM3S9665 board, QK kernel
// Last updated for version 5.4.0
// Last updated on  2015-05-06
//
//                    Q u a n t u m     L e a P s
//                    ---------------------------
//                    innovating embedded systems
//
// Copyright (C) Quantum Leaps, LLC. All rights reserved.
//
// This program is open source software: you can redistribute it and/or
// modify it under the terms of the GNU General Public License as published
// by the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Alternatively, this program may be distributed and modified under the
// terms of Quantum Leaps commercial licenses, which expressly supersede
// the GNU General Public License and are specifically designed for
// licensees interested in retaining the proprietary status of their code.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.
//
// Contact information:
// Web:   www.state-machine.com
// Email: info@state-machine.com
//****************************************************************************
#include "qpcpp.h"    // QP port header file
#include "dpp.h"      // application events and active objects
#include "bsp.h"      // Board Support Package header file

#include "LM3S6965.h" // the device specific header (TI)

Q_DEFINE_THIS_FILE

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! CAUTION !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Assign a priority to EVERY ISR explicitly by calling NVIC_SetPriority().
// DO NOT LEAVE THE ISR PRIORITIES AT THE DEFAULT VALUE!
//
enum KernelUnawareISRs {  // see NOTE00
    // ...
    MAX_KERNEL_UNAWARE_CMSIS_PRI  // keep always last
};
// "kernel-unaware" interrupts can't overlap "kernel-aware" interrupts
Q_ASSERT_COMPILE(MAX_KERNEL_UNAWARE_CMSIS_PRI <= QF_AWARE_ISR_CMSIS_PRI);

enum KernelAwareISRs {
    ETHERNET_PRIO = QF_AWARE_ISR_CMSIS_PRI,  // see NOTE00
    SYSTICK_PRIO,
    // ...
    MAX_KERNEL_AWARE_CMSIS_PRI // keep always last
};
// "kernel-aware" interrupts should not overlap the PendSV priority
Q_ASSERT_COMPILE(MAX_KERNEL_AWARE_CMSIS_PRI <= (0xFF >>(8-__NVIC_PRIO_BITS)));

// ISRs defined in this BSP --------------------------------------------------
extern "C" void SysTick_Handler(void);

// Local-scope objects -------------------------------------------------------
#define USER_LED           (1U << 0)
#define USER_BTN           (1U << 1)

#define ETH0_LED           (1U << 3)
#define ETH1_LED           (1U << 2)

static uint32_t l_nTicks;

#ifdef Q_SPY

    QSTimeCtr QS_tickTime_;
    QSTimeCtr QS_tickPeriod_;
    static uint8_t l_SysTick_Handler;

    #define UART_BAUD_RATE      115200U
    #define UART_TXFIFO_DEPTH   16U
    #define UART_FR_TXFE        (1U << 7)

#endif

//............................................................................
extern "C" void SysTick_Handler(void) {
    uint32_t volatile tmp;

    QK_ISR_ENTRY(); // inform QK about ISR entry

    ++l_nTicks;     // count the number of clock ticks

#ifdef Q_SPY
    tmp = SysTick->CTRL;            // clear SysTick_CTRL_COUNTFLAG
    QS_tickTime_ += QS_tickPeriod_; // account for the clock rollover
#endif

    QF::TICK_X(0U, &l_SysTick_Handler); // process time events at rate 0


    // Perform the debouncing of buttons. The algorithm for debouncing
    // adapted from the book "Embedded Systems Dictionary" by Jack Ganssle
    // and Michael Barr, page 71.
    //
    static struct ButtonsDebouncing {
        uint32_t depressed;
        uint32_t previous;
    } buttons = { ~0U, ~0U }; // state of the button debouncing
    uint32_t current;

    current = ~GPIOF->DATA_Bits[USER_BTN]; // read USER_BTN
    tmp = buttons.depressed; // save the debounced depressed buttons
    buttons.depressed |= (buttons.previous & current); // set depressed
    buttons.depressed &= (buttons.previous | current); // clear released
    buttons.previous   = current; // update the history
    tmp ^= buttons.depressed;     // changed debounced depressed
    if ((tmp & USER_BTN) != 0U) { // debounced USER_BTN state changed?
        if ((buttons.depressed & USER_BTN) != 0U) { // is USER_BTN depressed?
            static QEvt const bd = { BTN_DOWN_SIG, 0U, 0U };
            QF::PUBLISH(&bd, &l_SysTick_Handler);
        }
        else { // the button is released
            static QEvt const bu = { BTN_UP_SIG, 0U, 0U };
            QF::PUBLISH(&bu, &l_SysTick_Handler);
        }
    }

    QK_ISR_EXIT(); // inform QK about ISR exit
}

//............................................................................
void BSP_init(void) {
    // NOTE: SystemInit() already called from startup_TM4C123GH6PM.s
    //  but SystemCoreClock needs to be updated
    //
    SystemCoreClockUpdate();

    SYSCTL->RCGC2 |= (1 << 5); // enable clock to GPIOF (User and Eth LEDs)
    __NOP();
    __NOP();

    // configure the pin driving the Ethernet LED
    GPIOF->DIR   &= ~(ETH0_LED | ETH1_LED); // set direction: hardware
    GPIOF->AFSEL |=  (ETH0_LED | ETH1_LED);
    GPIOF->DR2R  |=  (ETH0_LED | ETH1_LED);
    GPIOF->ODR   &= ~(ETH0_LED | ETH1_LED);
    GPIOF->PUR   |=  (ETH0_LED | ETH1_LED);
    GPIOF->PDR   &= ~(ETH0_LED | ETH1_LED);
    GPIOF->DEN   |=  (ETH0_LED | ETH1_LED);
    GPIOF->AMSEL &= ~(ETH0_LED | ETH1_LED);

    // configure the pin driving the User LED
    GPIOF->DIR   |=  USER_LED;  // set direction: output
    GPIOF->DR2R  |=  USER_LED;
    GPIOF->DEN   |=  USER_LED;
    GPIOF->AMSEL &= ~USER_LED;
    GPIOF->DATA_Bits[USER_LED] = 0; // turn the LED off

    // configure the pin connected to the Buttons
    GPIOF->DIR   &= ~USER_BTN;  // set direction: input
    GPIOF->DR2R  |=  USER_BTN;
    GPIOF->ODR   &= ~USER_BTN;
    GPIOF->PUR   |=  USER_BTN;
    GPIOF->PDR   &= ~USER_BTN;
    GPIOF->DEN   |=  USER_BTN;
    GPIOF->AMSEL &= ~USER_BTN;

    // NOTE:
    // The OLED display is encapsulated inside the Table AO, so the
    // initialization of the OLED display happens in the top-most initial
    // transition of the Table AO (see Table_displayInit()).
    //

    if (!QS_INIT((void *)0)) { // initialize the QS software tracing
        Q_ERROR();
    }
    QS_OBJ_DICTIONARY(&l_SysTick_Handler);
}
//............................................................................
void QF::onStartup(void) {
    // set up the SysTick timer to fire at BSP_TICKS_PER_SEC rate
    SysTick_Config(SystemCoreClock / BSP_TICKS_PER_SEC);

    // assing all priority bits for preemption-prio. and none to sub-prio.
    NVIC_SetPriorityGrouping(0U);

    // set priorities of ALL ISRs used in the system, see NOTE00
    //
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!! CAUTION !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // Assign a priority to EVERY ISR explicitly by calling NVIC_SetPriority()
    // DO NOT LEAVE THE ISR PRIORITIES AT THE DEFAULT VALUE!
    //
    NVIC_SetPriority(SysTick_IRQn,   SYSTICK_PRIO);
    NVIC_SetPriority(Ethernet_IRQn,  ETHERNET_PRIO);
    // ...

    NVIC_EnableIRQ(Ethernet_IRQn); // enable the Ethernet Interrupt
    // ...
}
//............................................................................
void QF::onCleanup(void) {
}
//............................................................................
void QK::onIdle(void) {

    // toggle the User LED on and then off, see NOTE01
    QF_INT_DISABLE();
    GPIOF->DATA_Bits[USER_LED] = USER_LED; // turn the User LED on
    GPIOF->DATA_Bits[USER_LED] = 0U;       // turn the User LED off
    QF_INT_ENABLE();

#ifdef Q_SPY
    if ((UART0->FR & UART_FR_TXFE) != 0U) { // TX done?
        uint16_t fifo = UART_TXFIFO_DEPTH;  // max bytes we can accept
        uint8_t const *block;

        QF_INT_DISABLE();
        block = QS::getBlock(&fifo); // try to get next block to transmit
        QF_INT_ENABLE();

        while (fifo-- != 0U) {    // any bytes in the block?
            UART0->DR = *block++; // put into the FIFO
        }
    }
#elif defined NDEBUG
    // Put the CPU and peripherals to the low-power mode.
    // you might need to customize the clock management for your application,
    // see the datasheet for your particular MCU.
    //
    __WFI(); // Wait-For-Interrupt
#endif
}

//............................................................................
// NOTE Q_onAssert() defined in assembly in startup_LM3S6965.s

//............................................................................
// sys_now() is used in the lwIP stack
extern "C" uint32_t sys_now(void) {
    return l_nTicks * (1000U / BSP_TICKS_PER_SEC);
}

//----------------------------------------------------------------------------
#ifdef Q_SPY
//............................................................................
bool QS::onStartup(void const *arg) {
    static uint8_t qsBuf[2*1024]; // buffer for Quantum Spy
    uint32_t tmp;
    initBuf(qsBuf, sizeof(qsBuf));

    // enable the peripherals used by the UART0...
    SYSCTL->RCGC1 |= (1U << 0); // enable clock to UART0
    SYSCTL->RCGC2 |= (1U << 0); // enable clock to GPIOA
    __NOP();                    // wait after enabling clocks
    __NOP();
    __NOP();

    // configure UART0 pins for UART operation...
    tmp = (1U << 0) | (1U << 1);
    GPIOA->DIR   &= ~tmp;
    GPIOA->AFSEL |=  tmp;
    GPIOA->DR2R  |=  tmp; // set 2mA drive, DR4R and DR8R are cleared
    GPIOA->SLR   &= ~tmp;
    GPIOA->ODR   &= ~tmp;
    GPIOA->PUR   &= ~tmp;
    GPIOA->PDR   &= ~tmp;
    GPIOA->DEN   |=  tmp;
    GPIOA->AMSEL &= ~tmp;

    // configure the UART for the desired baud rate, 8-N-1 operation...
    tmp = (((SystemCoreClock * 8U) / UART_BAUD_RATE) + 1U) / 2U;
    UART0->IBRD   = tmp / 64U;
    UART0->FBRD   = tmp % 64U;
    UART0->LCRH   = 0x60U; // configure 8-bit operation
    UART0->LCRH  |= 0x10U; // enable FIFOs
    UART0->CTL   |= (1U << 0) | (1U << 8) | (1U << 9);

    QS_tickPeriod_ = SystemCoreClock / BSP_TICKS_PER_SEC;
    QS_tickTime_   = QS_tickPeriod_; // to start the timestamp at zero

    // setup the QS filters...
    QS_FILTER_ON(QS_QEP_STATE_ENTRY);
    QS_FILTER_ON(QS_QEP_STATE_EXIT);
    QS_FILTER_ON(QS_QEP_STATE_INIT);
    QS_FILTER_ON(QS_QEP_INIT_TRAN);
    QS_FILTER_ON(QS_QEP_INTERN_TRAN);
    QS_FILTER_ON(QS_QEP_TRAN);
    QS_FILTER_ON(QS_QEP_IGNORED);
    QS_FILTER_ON(QS_QEP_DISPATCH);
    QS_FILTER_ON(QS_QEP_UNHANDLED);

//    QS_FILTER_ON(QS_QF_ACTIVE_ADD);
//    QS_FILTER_ON(QS_QF_ACTIVE_REMOVE);
//    QS_FILTER_ON(QS_QF_ACTIVE_SUBSCRIBE);
//    QS_FILTER_ON(QS_QF_ACTIVE_UNSUBSCRIBE);
//    QS_FILTER_ON(QS_QF_ACTIVE_POST_FIFO);
//    QS_FILTER_ON(QS_QF_ACTIVE_POST_LIFO);
//    QS_FILTER_ON(QS_QF_ACTIVE_GET);
//    QS_FILTER_ON(QS_QF_ACTIVE_GET_LAST);
//    QS_FILTER_ON(QS_QF_EQUEUE_INIT);
//    QS_FILTER_ON(QS_QF_EQUEUE_POST_FIFO);
//    QS_FILTER_ON(QS_QF_EQUEUE_POST_LIFO);
//    QS_FILTER_ON(QS_QF_EQUEUE_GET);
//    QS_FILTER_ON(QS_QF_EQUEUE_GET_LAST);
//    QS_FILTER_ON(QS_QF_MPOOL_INIT);
//    QS_FILTER_ON(QS_QF_MPOOL_GET);
//    QS_FILTER_ON(QS_QF_MPOOL_PUT);
//    QS_FILTER_ON(QS_QF_PUBLISH);
//    QS_FILTER_ON(QS_QF_RESERVED8);
//    QS_FILTER_ON(QS_QF_NEW);
//    QS_FILTER_ON(QS_QF_GC_ATTEMPT);
//    QS_FILTER_ON(QS_QF_GC);
    QS_FILTER_ON(QS_QF_TICK);
//    QS_FILTER_ON(QS_QF_TIMEEVT_ARM);
//    QS_FILTER_ON(QS_QF_TIMEEVT_AUTO_DISARM);
//    QS_FILTER_ON(QS_QF_TIMEEVT_DISARM_ATTEMPT);
//    QS_FILTER_ON(QS_QF_TIMEEVT_DISARM);
//    QS_FILTER_ON(QS_QF_TIMEEVT_REARM);
//    QS_FILTER_ON(QS_QF_TIMEEVT_POST);
//    QS_FILTER_ON(QS_QF_TIMEEVT_CTR);
//    QS_FILTER_ON(QS_QF_CRIT_ENTRY);
//    QS_FILTER_ON(QS_QF_CRIT_EXIT);
//    QS_FILTER_ON(QS_QF_ISR_ENTRY);
//    QS_FILTER_ON(QS_QF_ISR_EXIT);
//    QS_FILTER_ON(QS_QF_INT_DISABLE);
//    QS_FILTER_ON(QS_QF_INT_ENABLE);
//    QS_FILTER_ON(QS_QF_ACTIVE_POST_ATTEMPT);
//    QS_FILTER_ON(QS_QF_EQUEUE_POST_ATTEMPT);
//    QS_FILTER_ON(QS_QF_MPOOL_GET_ATTEMPT);
//    QS_FILTER_ON(QS_QF_RESERVED1);
//    QS_FILTER_ON(QS_QF_RESERVED0);

//    QS_FILTER_ON(QS_QK_MUTEX_LOCK);
//    QS_FILTER_ON(QS_QK_MUTEX_UNLOCK);
//    QS_FILTER_ON(QS_QK_SCHEDULE);
//    QS_FILTER_ON(QS_QK_RESERVED1);
//    QS_FILTER_ON(QS_QK_RESERVED0);

//    QS_FILTER_ON(QS_QEP_TRAN_HIST);
//    QS_FILTER_ON(QS_QEP_TRAN_EP);
//    QS_FILTER_ON(QS_QEP_TRAN_XP);
//    QS_FILTER_ON(QS_QEP_RESERVED1);
//    QS_FILTER_ON(QS_QEP_RESERVED0);

    QS_FILTER_ON(QS_SIG_DICT);
    QS_FILTER_ON(QS_OBJ_DICT);
    QS_FILTER_ON(QS_FUN_DICT);
    QS_FILTER_ON(QS_USR_DICT);
    QS_FILTER_ON(QS_EMPTY);
    QS_FILTER_ON(QS_RESERVED3);
    QS_FILTER_ON(QS_RESERVED2);
    QS_FILTER_ON(QS_TEST_RUN);
    QS_FILTER_ON(QS_TEST_FAIL);
    QS_FILTER_ON(QS_ASSERT_FAIL);

    return true; // return success
}
//............................................................................
void QS::onCleanup(void) {
}
//............................................................................
QSTimeCtr QS::onGetTime(void) { // invoked with interrupts locked
    if ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == 0U) { // flag not set?
        return QS_tickTime_ - (QSTimeCtr)SysTick->VAL;
    }
    else { // the rollover occured, but the SysTick_ISR did not run yet
        return QS_tickTime_ + QS_tickPeriod_ - (QSTimeCtr)SysTick->VAL;
    }
}
//............................................................................
void QS::onFlush(void) {
    uint16_t fifo = UART_TXFIFO_DEPTH; // Tx FIFO depth
    uint8_t const *block;
    while ((block = QS::getBlock(&fifo)) != (uint8_t *)0) {
        // busy-wait until TX FIFO empty
        while ((UART0->FR & UART_FR_TXFE) == 0) {
        }

        while (fifo-- != 0U) {    // any bytes in the block?
            UART0->DR = *block++; // put into the TX FIFO
        }
        fifo = UART_TXFIFO_DEPTH; // re-load the Tx FIFO depth
    }
}
#endif // Q_SPY
//----------------------------------------------------------------------------

//****************************************************************************
// NOTE00:
// The QF_AWARE_ISR_CMSIS_PRI constant from the QF port specifies the highest
// ISR priority that is disabled by the QF framework. The value is suitable
// for the NVIC_SetPriority() CMSIS function.
//
// Only ISRs prioritized at or below the QF_AWARE_ISR_CMSIS_PRI level (i.e.,
// with the numerical values of priorities equal or higher than
// QF_AWARE_ISR_CMSIS_PRI) are allowed to call the QK_ISR_ENTRY/QK_ISR_ENTRY
// macros or any other QF/QK  services. These ISRs are "QF-aware".
//
// Conversely, any ISRs prioritized above the QF_AWARE_ISR_CMSIS_PRI priority
// level (i.e., with the numerical values of priorities less than
// QF_AWARE_ISR_CMSIS_PRI) are never disabled and are not aware of the kernel.
// Such "QF-unaware" ISRs cannot call any QF/QK services. In particular they
// can NOT call the macros QK_ISR_ENTRY/QK_ISR_ENTRY. The only mechanism
// by which a "QF-unaware" ISR can communicate with the QF framework is by
// triggering a "QF-aware" ISR, which can post/publish events.
//
// NOTE01:
// The User LED is used to visualize the idle loop activity. The brightness
// of the LED is proportional to the frequency of invcations of the idle loop.
// Please note that the LED is toggled with interrupts locked, so no interrupt
// execution time contributes to the brightness of the User LED.
//
