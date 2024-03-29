//****************************************************************************
// DPP example, CMSIS-RTX kernel
// Last updated for version 5.4.0
// Last updated on  2015-04-29
//
//                    Q u a n t u m     L e a P s
//                    ---------------------------
//                    innovating embedded systems
//
// Copyright (C) Quantum Leaps, www.state-machine.com.
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
#include "qpcpp.h"
#include "dpp.h"
#include "bsp.h"

//............................................................................
int main() {
    static QP::QEvt const *tableQueueSto[N_PHILO];
    static QP::QEvt const *philoQueueSto[N_PHILO][N_PHILO];
    static QP::QSubscrList subscrSto[DPP::MAX_PUB_SIG];

    static QF_MPOOL_EL(DPP::TableEvt) smlPoolSto[2*N_PHILO];


    QP::QF::init();  // initialize the framework and the underlying RT kernel

    DPP::BSP_init(); // initialize the BSP

    // object dictionaries...
    QS_OBJ_DICTIONARY(smlPoolSto);
    QS_OBJ_DICTIONARY(tableQueueSto);
    QS_OBJ_DICTIONARY(philoQueueSto[0]);
    QS_OBJ_DICTIONARY(philoQueueSto[1]);
    QS_OBJ_DICTIONARY(philoQueueSto[2]);
    QS_OBJ_DICTIONARY(philoQueueSto[3]);
    QS_OBJ_DICTIONARY(philoQueueSto[4]);

    QP::QF::psInit(subscrSto, Q_DIM(subscrSto)); // init publish-subscribe

    // initialize event pools...
    QP::QF::poolInit(smlPoolSto,
                     sizeof(smlPoolSto), sizeof(smlPoolSto[0]));

    // start the active objects...
    for (uint8_t n = 0U; n < N_PHILO; ++n) {
        DPP::AO_Philo[n]->start(
            static_cast<uint_fast8_t>(n + 1U), // QP priority of the AO
            philoQueueSto[n],        // event queue storage
            Q_DIM(philoQueueSto[n]), // queue length [events]
            (void *)0,               // stack storage (stanard RTX stack)
            0U);                     // default size of the stack
    }

    // Table AO uses the custom stack size.
    // NOTE: Remember to configure sufficient number of threads with
    // user-provided stack size OS_PRIVCNT in RTX_Conf_CM.c
    //
    QP::QF_setRtxPrio(DPP::AO_Table, osPriorityHigh); // set RTX priority
    DPP::AO_Table->start(
        static_cast<uint_fast8_t>(N_PHILO + 1U), // QP priority of the AO
        tableQueueSto,         // event queue storage
        Q_DIM(tableQueueSto),  // queue length [events]
        (void *)0,             // stack storage (not used)
        128U*4U);              // custom stack size [bytes]

    return QP::QF::run(); // run the QF application
}
