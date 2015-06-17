namespace QP {

/*! @page exa_rtos Examples for Third-Party RTOS

The main purpose of integrating QP/C with conventional RTOSes is to enable you to incorporate various communication stacks (TCP/IP, USB, CAN, etc.) as well as other middleware, which requires the ability to **block** the task code.   

- @subpage exa_cmsis-rtx
- @subpage exa_embos
- @subpage exa_freertos
- @subpage exa_threadx
- @subpage exa_ucos-ii

@note
You do **not** need to use a traditional RTOS just to achieve preemptive multitasking with QP. The @ref comp_qk "preemptive QK kernel", available as part of the QP package, supports preemptive priority-based multitasking and is fully compatible with Rate Monotonic Scheduling to achieve guaranteed, hard real-time performance. The preemptive, run-to-completion QK kernel perfectly matches the run-to-completion execution semantics of active objects, yet it is simpler, faster, and more efficient than any traditional blocking kernel.

@next{cmsis-rtx}
*/

/*##########################################################################*/
/*! @page exa_cmsis-rtx CMSIS-RTOS RTX

@htmlonly
<script src="preview.js" type="text/javascript"></script>
@endhtmlonly

The QP/C examples for CMSIS-RTX (on Cortex-M) are as follows:

- @subpage cmsis-rtx_blinky_ek-tm4c123gxl (Cortex-M4F) <a class="preview board" href="bd_EK-TM4C123GXL.jpg" title="EK-TM4C123GXL"></a>
- @subpage cmsis-rtx_dpp_ek-tm4c123gxl (Cortex-M4F) <a class="preview board" href="bd_EK-TM4C123GXL.jpg" title="EK-TM4C123GXL"></a>
- @subpage cmsis-rtx_dpp_nucleo-l053r8 (Cortex-M0+) <a class="preview board" href="bd_nucleo-l053r8.jpg" title="NUCLEO-L053R8"></a>
- @subpage cmsis-rtx_dpp_nucleo-l152re (Cortex-M43) <a class="preview board" href="bd_nucleo-l152re.jpg" title="NUCLEO-L152RE"></a>

*/

/*##########################################################################*/
/*! @page cmsis-rtx_blinky_ek-tm4c123gxl Blinky on EK-TM4C123GXL

@image html bd_EK-TM4C123GXL.jpg EK-TM4C123GXL board

Simple "Blinky" example for Texas Instruments TivaC123GXL MCU (Cortex-M4F), ARM (MDK-ARM), GNU-ARM, IAR EWARM toolsets.

@image html under_construction.jpg

*/
/*##########################################################################*/
/*! @page cmsis-rtx_dpp_ek-tm4c123gxl DPP on EK-TM4C123GXL

@image html bd_EK-TM4C123GXL.jpg EK-TM4C123GXL board

Dining Philosophers Problem (DPP) example for Texas Instruments TivaC123GXL MCU (Cortex-M4F), ARM (MDK-ARM), GNU-ARM, IAR EWARM toolsets.

@image html under_construction.jpg

*/
/*##########################################################################*/
/*! @page cmsis-rtx_dpp_nucleo-l053r8 DPP on NUCLEO-L053R8

@image html bd_nucleo-l053r8.jpg NUCLEO-L053R8 board

Dining Philosophers Problem (DPP) example for STM32-L053R8T6 MCU (Cortex-M0+) with ARM-Keil, GNU-ARM, and IAR-ARM toolsets.

@image html under_construction.jpg

*/
/*##########################################################################*/
/*! @page cmsis-rtx_dpp_nucleo-l152re DPP on NUCLEO-L152RE

@image html bd_nucleo-l152re.jpg NUCLEO-L152RE board

Dining Philosophers Problem (DPP) example for STM32-L152RET6 MCU (Cortex-M3) with ARM-Keil, GNU-ARM, and IAR-ARM toolsets.

@image html under_construction.jpg

*/

/*##########################################################################*/
/*! @page exa_embos embOS

@htmlonly
<script src="preview.js" type="text/javascript"></script>
@endhtmlonly

The QP/C examples for SEGGER embOS are as follows:

- ARM Cortex-M
    - @subpage embos_dpp_stm32f429-discovery (Cortex-M4F) <a class="preview board" href="bd_STM32F4-Discovery.jpg" title="STM32F4-Discovery">STM32F4-Discovery</a>

*/
/*##########################################################################*/
/*! @page embos_dpp_stm32f429-discovery DPP on STM32F4-Discovery

@image html bd_STM32F4-Discovery.jpg STM32F4-Discovery board

DPP example for STM32F4407VGT6 MCU (Cortex-M4F), IAR EWARM toolset.


------------------------------------------------------------------------------
@section embos_dpp_stm32f429-discovery_qs QS Software Tracing

The DPP example provides the "Spy" build configuration, which outputs the QS (Quantum Spy) software tracing data through USART2. To get the data out ouf the board, you need to connect the TTL/RS232 converter as follows:

<center>
STM32F4-Discovery  | TTL/RS232 Converter
-------------------|:------------------------
PA2                | TX
PA3                | RX (currently not used)
VDD                | VCC
GND                | GND
</center> 

@image html bd_STM32F4-Discovery_RS232.jpg STM32F4-Discovery board connected to RS232 level shifter 

The output is generated at 115200 baud rate.

Here is an example invocation of the QSPY host application to receive the QS data from STM32F4-Discovery:

\verbatim
qspy -cCOM1
\endverbatim

The actual COM port number might be different on your Windows machine. Please check the Device Manager to find the COM port number.

@image html under_construction.jpg

*/

/*##########################################################################*/
/*! @page exa_freertos FreeRTOS

@htmlonly
<script src="preview.js" type="text/javascript"></script>
@endhtmlonly

The QP/C examples for FreeRTOS are as follows:

- ARM Cortex-M
    - @subpage freertos_blinky_ek-tm4c123gxl (Cortex-M4F) <a class="preview board" href="bd_EK-TM4C123GXL.jpg" title="EK-TM4C123GXL"></a>
    - @subpage freertos_dpp_ek-tm4c123gxl (Cortex-M4F) <a class="preview board" href="bd_EK-TM4C123GXL.jpg" title="EK-TM4C123GXL"></a>
*/
/*##########################################################################*/
/*! @page freertos_blinky_ek-tm4c123gxl Blinky on EK-TM4C123GXL

@image html bd_EK-TM4C123GXL.jpg EK-TM4C123GXL board

Simple "Blinky" example for Texas Instruments TivaC123GXL MCU (Cortex-M4F), GNU-ARM, IAR EWARM toolsets.

@image html under_construction.jpg

*/
/*##########################################################################*/
/*! @page freertos_dpp_ek-tm4c123gxl DPP on EK-TM4C123GXL

@image html bd_EK-TM4C123GXL.jpg EK-TM4C123GXL board

Dining Philosophers Problem (DPP) example for Texas Instruments TivaC123GXL MCU (Cortex-M4F), GNU-ARM, IAR EWARM toolsets.

@image html under_construction.jpg

*/

/*##########################################################################*/
/*! @page exa_threadx ThreadX

The QP/C examples for ThreadX (Express Logic) are as follows:

- @subpage threadx_dpp_visual-studio

*/
/*##########################################################################*/
/*! @page threadx_dpp_visual-studio DPP Demo with VC++

@image html threadx_dpp.jpg DPP example for ThreadX in Command Prompt on Windows 

DPP example built for ThreadX demo on Windows with Visual Studio.

@note
Due to the limitations of the ThreadX library for Windows, the DPP example can only instantiate one `Philo[0]` active object.

@image html under_construction.jpg

*/

/*##########################################################################*/
/*! @page exa_ucos-ii uC/OS-II
@htmlonly
<script src="preview.js" type="text/javascript"></script>
@endhtmlonly

The QP/C examples for uC/OS-II are as follows:

- ARM Cortex-M
    - @subpage ucos-ii_dpp_ek-tm4c123gxl (Cortex-M4F) <a class="preview board" href="bd_EK-TM4C123GXL.jpg" title="EK-TM4C123GXL"></a>
    - @subpage ucos-ii_dpp_nucleo-l152re (Cortex-M3) <a class="preview board" href="bd_STM32F4-Discovery.jpg" title="STM32F4-Discovery"></a>

*/
/*##########################################################################*/
/*! @page ucos-ii_dpp_ek-tm4c123gxl DPP on EK-TM4C123GXL

@image html bd_EK-TM4C123GXL.jpg EK-TM4C123GXL board

DPP example for Texas Instruments TivaC123GXL MCU (Cortex-M4F) and IAR EWARM toolsets.

@image html under_construction.jpg

*/
/*##########################################################################*/
/*! @page ucos-ii_dpp_nucleo-l152re DPP on NUCLEO-L152RE

@image html bd_nucleo-l152re.jpg NUCLEO-L152RE board

DPP example for Texas Instruments STM32 L152RET6 MCU (Cortex-M3) and IAR EWARM toolsets.

@image html under_construction.jpg
*/

} // namespace QP