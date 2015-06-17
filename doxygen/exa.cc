namespace QP {

/*! @page exa Examples

@htmlonly
<script src="preview.js" type="text/javascript"></script>
@endhtmlonly

@tableofcontents


@section exa_gen General Comments
The QP/C++ distribution contains many @subpage exa_ref "example projects" to demonstrate various QP/C++ features. Each example project is described on its own dedicated page that you can find using several criteria (see @ref exa_ref). The example projects have the following main goals:

- <strong>to help you learn how to use QP/C++</strong> &mdash; the examples show the intended way of using QP/C++ features and structuring QP/C++ applications.

- <strong>to provide you with a starting point for your own projects</strong> &mdash; the examples are complete working projects, with correctly pre-configured tools, such as compiler options, linker script, debugger setup, etc.

@note
It is highly recommended that you create your own projects by **copying and modifying** existing example projects rather than starting your QP/C++ projects from scratch. 


------------------------------------------------------------------------------
@subsection exa_code Example Code Structure
Starting with QP/C++ release 5.4.0, **all** examples are bundled into the QP/C++ download, as opposed to being distributed as separate QP Development Kits (QDKs). The main benefit is of this approach is that it greatly reduces chances of mistakes in combining the mainline QP/C++ code with various QDKs. The downside is that the QP/C++ distribution becomes quite large and that examples can't be added or updated independently from the QP/C++ baseline code.

All examples are located in sub-directories of the <span class="img folder">examples</span> @ref qpc_files "top-level folder", with the hierarchical organization outlined below:

<ul class="tag">
  <li><span class="img folder">examples</span>
  </li>
  <ul class="tag">
    <li><span class="img folder">arm-cm</span> &mdash; Native examples for ARM-Cortex-M (bare-metal) <span class="tag">A</span>
    </li>
    <ul class="tag">
      <li><span class="img folder">blinky_ek-tm4c123gxl</span> &mdash; Blinky example for EK-TM4C123GXL board
      </li>
      <ul class="tag">
        <li><span class="img folder">qk</span> &mdash; Version for the @ref comp_qk "preemptive QK kernel"
        </li>
        <ul class="tag">
          <li><span class="img folder">arm</span> &mdash; build with ARM toolset
          </li>
          <ul class="tag">
            <li><span class="img folder">dbg</span> &mdash; Debug @ref exa_sec_conf "build configuration"
            </li>
            <li><span class="img folder">rel</span> &mdash; Release build configuration
            </li>
            <li><span class="img folder">spy</span> &mdash; Spy build configuration
            </li>
          </ul>  
          <li><span class="img folder">gnu</span> &mdash; build with GNU toolset
          </li>
          <li><span class="img folder">iar</span> &mdash; build with IAR toolset
          </li>
        </ul>  
        <li><span class="img folder">qv</span> &mdash;  Version for the @ref comp_qv "cooperative QV kernel"
        </li>
        <ul class="tag">
          <li><span class="img folder">arm</span> &mdash; build with ARM toolset
          </li>
          <ul class="tag">
            <li><span class="img folder">dbg</span> &mdash; Debug @ref exa_sec_conf "build configuration"
            </li>
            <li><span class="img folder">rel</span> &mdash; Release build configuration
            </li>
            <li><span class="img folder">spy</span> &mdash; Spy build configuration
            </li>
          </ul>  
          <li><span class="img folder">gnu</span> &mdash; build with GNU toolset
          </li>
          <li><span class="img folder">iar</span> &mdash; build with IAR toolset
          </li>
        </ul>  
        <li><span class="img file_c">...</span> &mdash; source code independent on the toolset
        </li>
      </ul>
    </ul>  

    <li><span class="img folder">ucos-ii</span> &mdash; Examples for uCOS-II (3rd-party RTOS) <span class="tag">B</span>
    </li>  
    <ul class="tag">
      <li><span class="img folder">arm-cm</span> &mdash; Examples for ARM-Cortex-M
      </li>
      <ul class="tag">
        <li><span class="img folder">blinky_ek-tm4c123gxl</span> &mdash; Blinky example for EK-TM4C123GXL board
        </li>
        <ul class="tag">
          <li><span class="img folder">arm</span> &mdash; build with ARM toolset
          </li>
          <ul class="tag">
            <li><span class="img folder">dbg</span> &mdash; Debug build configuration
            </li>
            <li><span class="img folder">rel</span> &mdash; Release build configuration
            </li>
            <li><span class="img folder">spy</span> &mdash; Spy build configuration
            </li>
          </ul>  
          <li><span class="img folder">iar</span> &mdash; build with IAR toolset
          </li>
        </ul>
      </ul>  
    </ul>

    <li><span class="img folder">lwip</span> &mdash; Examples for lwIP (3rd-party TCP/IP) <span class="tag">C</span>
    </li>  
    <ul class="tag">
      <li><span class="img folder">arm-cm</span> &mdash; Examples for ARM-Cortex-M
      </li>
      <ul class="tag">
        <li><span class="img folder">lwip_ek-lm3s6965</span> &mdash; lwIP example for EK-LM3S6965 board
        </li>
        <ul class="tag">
          <li><span class="img folder">qk</span> &mdash; Version for the @ref comp_qk "preemptive QK kernel"
          </li>
          <ul class="tag">
            <li><span class="img folder">gnu</span> &mdash; build with GNU toolset
            </li>
            <ul class="tag">
              <li><span class="img folder">dbg</span> &mdash; Debug build configuration
              </li>
              <li><span class="img folder">rel</span> &mdash; Release build configuration
              </li>
              <li><span class="img folder">spy</span> &mdash; Spy build configuration
              </li>
            </ul>
            <li><span class="img folder">iar</span> &mdash; build with IAR toolset
            </li>
          </ul>
          <li><span class="img folder">qv</span> &mdash; Version for the @ref comp_qv "cooperative QV kernel"
          </li>
          <ul class="tag">
            <li><span class="img folder">gnu</span> &mdash; build with GNU toolset
            </li>
            <li><span class="img folder">iar</span> &mdash; build with IAR toolset
            </li>
          </ul>
        </ul>
      </ul>  
    </ul>
  </ul>    
</ul>

<ul class="tag">
  <li><span class="tag">A</span> @subpage exa_native "Native examples" are located in sub-directories named after the CPU architecture, such as <span class="img folder">arm-cm</span> for ARM Cortex-M. Under that directory, the sub-directories <span class="img folder">blinky_ek-tm4c123gxl</span> contain the specific example on the specified board, such as "Blinky" on the EK-TM4C123GXL board here. In the specific example folder, you find sub-folders for the @ref comp_qk "QK" and @ref comp_qv "QV" kernels, respectively.
  </li>
  
  <li><span class="tag">B</span> @subpage exa_rtos "Examples for 3rd-party RTOS"/@subpage exa_os "OS" are located in sub-directories named after the RTOS/OS, such as <span class="img folder">ucos-ii</span> for uCOS-II RTOS. Under that directory, the sub-directories, such as <span class="img folder">arm-cm</span>, contain examples for the specified CPU architecture, such as ARM Cortex-M here.
  </li>

  <li><span class="tag">C</span> @subpage exa_mware "Examples for 3rd-party Middleware" are located in sub-directories named after the middleware, such as <span class="img folder">lwIP</span> for the lwIP TCP/IP stack. Under that directory, the sub-directories, such as <span class="img folder">arm-cm</span>, contain examples for the specified CPU architecture, such as ARM Cortex-M here.
  </li>
</ul>

@note
Because the QP distribution contains *all* examples, the number of sub-directories and files in the <span class="img folder">examples</span> folder may seem daunting. However, knowing the structure of the <span class="img folder">examples</span> folder, you can simply **delete** the sub-directories that are not interesting to you. 


------------------------------------------------------------------------------
@subsection exa_sec_apps Example Applications
To demonstrate QP/C++ features on an embedded board, you need to create an application that does "something interesting". Instead of inventing this "something interesting" for each and every example, the example projects implement one of the three @subpage exa_apps "example applications", which are described on the separate pages:

- @ref blinky
- @ref dpp
- @ref game

With the exception of the game application, all other example applications can be implemented on a board with just a couple of LEDs. The @ref game application is a bit more involved and requires a small graphic display on the board.

Beyond these basic applications for demonstrating and testing the various @ref ports "QP/C++ ports", the QP/C++ distribution contains all examples described in the book <a class="extern" target="_blank" href="http://www.state-machine.com/psicc2" >Practical UML Statecharts in C/C++, 2nd Edition</a>

@sa
- @ref exa_win32


------------------------------------------------------------------------------
@subsection exa_sec_boards Development Boards
While some provided examples can run on your @ref exa_os "desktop computer", most embedded example projects require special hardware in form of @ref exa_sec_boards, which you need to acquire to be able to run the examples. The boards chosen for the examples are generally inexpensive and self-contained with no need for external hardware (such as external JTAG debuggers or power supplies).


------------------------------------------------------------------------------
@subsection exa_sec_tools Development Tools
Most provided examples require special embedded cross-development tools, such as embedded compilers, linkers, debuggers and IDEs, which you need to acquire independently from the QP/C++ distribution. Generally, the examples work with the free (size limited) evaluation versions of the commercial tools. The examples list the versions of tools they were developed and tested with. Please refer to the @ref exa_ref "cross-reference section" @ref exa_sec_tools to see which embedded toolsets are used.  


------------------------------------------------------------------------------
@subsection exa_sec_conf Build Configurations
QP examples @ref ports "QP ports" are provided in the following three **build configurations**:

- **Debug** &mdash; this configuration is built with full debugging information and minimal optimization. When the QP framework finds no events to process, the framework busy-idles until there are new events to process. The @ref comp_qs "QS trace instrumentation" is **disabled**.

- **Release** &mdash; this configuration is built with no debugging information and high optimization. Single-stepping and debugging at the source-code level is effectively impossible due to the lack of debugging information and optimized code, but the debugger can be used to download and start the executable. When the QP framework finds no events to process, the framework puts the CPU to sleep until there are new events to process.  The @ref comp_qs "QS trace instrumentation" is **disabled**.

- **Spy** &mdash; like the debug variant, this variant is built with full debugging information and minimal optimization. Additionally, it is build with the @ref comp_qs "QS trace instrumentation" enabled. The on-board serial port and the Q-Spy host application are used for sending and viewing trace data. Like the Debug configuration, the QP framework busy-idles until there are new events to process.


@remark
<strong>Why do you need multiple build configurations?</strong>@n
The different phases of embedded software lifecycle pose different challenges. During the development and maintenance phase, for example, the emphasis is on the ease of debugging and verifying the correctness of the code, which require lower levels of optimization and special scaffolding code. In contrast, for releasing the code in the final product, the emphasis is on small memory footprint and CPU time efficiency, which require high-level of optimization and removal of any scaffolding code. To address these conflicting needs, the same source code is compiled into multiple **build configurations** that differ in the use of compiler options and activation of the scaffolding code.


-----------------------------------------------------------------------------
@subsection exa_sec_qm QM Models
Many example projects contain code auto-generated by the <a class="extern" target="_blank" href="http://www.state-machine.com/qm/help"><strong>QM modeling tool</strong></a>. Such projects always contain the corresponding **QM model** file, which you can open in QM, modify, and re-generate the code.

@note
The auto-generated files are saved as **read-only**. This protects them from inadvertent modifications, which will get lost when the files are re-generated by QM (or QMC). All modifications to the auto-generated code should be done in the QM model, not in the code.


------------------------------------------------------------------------------
@subsection exa_sec_3rd Third-Party Code
The QP/C++ example projects often need to use various additional code, such as MCU register definition files, startup code, device drivers, etc., which are provided by Third-Party vendors. All such code is located in the <span class="img folder">3rd_party</span> @ref qpc_files "top-level folder".

@note
As far as possible, the code in the <span class="img folder">3rd_party</span> folder has been left unchanged from the original source. (Any modified code is clearly identified by top-level comments that detail the applied changes.) For that reason, the Third-Party code might produce **compilation warnings** in your builds. 

The code in the <span class="img folder">3rd_party</span> folder comes from various sources, and Quantum
Leaps, LLC expressly makes **no claims of ownership** to any of this code, even though some of the code might be customized or modified by Quantum Leaps.

@attention
The Third-Party software components included in the <span class="img folder">3rd_party</span> folder are licensed under a variety of different licensing terms that are defined by the respective owners of this software and are spelled out in the `README.txt` or `LICENSE.txt` files included in the respective
sub-folders.


@next{exa_ref}
*/

/*##########################################################################*/
/*! @page exa_ref Cross-Reference

@htmlonly
<script src="preview.js" type="text/javascript"></script>
@endhtmlonly

@tableofcontents


------------------------------------------------------------------------------
@section exa_ref_native Native Examples (Bare-Metal)
- @ref exa_arm-cm (Cortex-M0/M0+/M3/M4/M4F)
- @ref exa_arm7-9 ("classic ARM")
- @ref exa_avr (8-bit megaAVR)
- @ref exa_msp430 ("classic" MSP430 and "extended" MSP430x)


------------------------------------------------------------------------------
@section exa_ref_rtos Examples for Third-Party RTOS
- @ref exa_cmsis-rtx (ARM Ltd.)
- @ref exa_embos (SEGGER)
- @ref exa_freertos (Real Time Engineers Ltd.)
- @ref exa_threadx (Express Logic)
- @ref exa_ucos-ii (Micrium)


------------------------------------------------------------------------------
@section exa_ref_os Examples for Third-Party OS
- @ref exa_posix
- @ref exa_win32
- @ref exa_win32-qv


------------------------------------------------------------------------------
@section exa_ref_mwware Examples for Third-Party Middleware
- @ref exa_qt (open source/commercial, see http://qt.io )
- @ref exa_lwip (open source, see http://lwip.wikia.com/wiki/LwIP_Wiki )
- @ref exa_emwin (SEGGER) &mdash; coming soon...


------------------------------------------------------------------------------
@section exa_ref_boards Examples by Development Board
The boards chosen for the examples are generally inexpensive and self-contained with minimal need for external hardware (such as external JTAG debuggers or power supplies). Also, all the selected boards provide a virtual COM port (ideally) or can be easily connected to a TTL-to-USB serial converter cable for @ref comp_qs "QS software tracing" output.

@note
You can hover the mouse cursor over the <span class="board"></span>&nbsp;&nbsp; icon in the list below to see the picture of the board.

- ARM Cortex-M Boards:
    - <a class="preview board" href="bd_EK-TM4C123GXL.jpg" title="EK-TM4C123GXL">EK-TM4C123GXL</a> (TivaC LaunchPad)
    - <a class="preview board" href="bd_mbed-LPC1768.jpg" title="mbed-LPC1768">mbed-LPC1768</a>
    - <a class="preview board" href="bd_nucleo-l053r8.jpg" title="NUCLEO-L053R8">NUCLEO-L053R8</a>
    - <a class="preview board" href="bd_nucleo-l152re.jpg" title="NUCLEO-L152RE">NUCLEO-L152RE</a>
    - <a class="preview board" href="bd_EK-LM3S811.jpg" title="EK-LM3S811">EK-LM3S811</a>
    - <a class="preview board" href="bd_EK-LM3S6965.jpg" title="EK-LM3S6965">EK-LM3S6965</a>
    - <a class="preview board" href="bd_STM32F4-Discovery.jpg" title="STM32F4-Discovery">STM32F4-Discovery</a>

- ARM7 Boards:
    - <a class="preview board" href="bd_AT91SAM7S-EK.jpg" title="AT91SAM7S-EK">AT91SAM7S-EK</a>

- AVR (megaAVR) Boards:
    - <a class="preview board" href="bd_Arduino-UNO.jpg" title="Arduino-UNO">Arduino-UNO</a>

- MSP430 Boards:
    - <a class="preview board" href="bd_MSP-EXP430G2.jpg" title="MSP-EXP430G2">MSP-EXP430G2</a> (MSP430 LaunchPad)
    - <a class="preview board" href="bd_MSP-EXP430F5529LP.jpg" title="MSP-EXP430F5529LP">MSP-EXP430F5529LP</a> (MSP430X LaunchPad)


------------------------------------------------------------------------------
@section exa_ref_mcu Examples by MCU Architecture
- ARM Cortex-M0/M0+
    - @ref arm-cm_dpp_nucleo-l053r8  <a class="preview board" href="bd_nucleo-l053r8.jpg" title="NUCLEO-L053R8"></a>
- ARM Cortex-M3
    - @ref arm-cm_dpp_nucleo-l152re  <a class="preview board" href="bd_nucleo-l152re.jpg" title="NUCLEO-L152RE"></a>
    - @ref arm-cm_game_ek-lm3s811  <a class="preview board" href="bd_EK-LM3S811.jpg" title="EK-LM3S811"></a>
    - @ref arm-cm_dpp_mbed-lpc1768  <a class="preview board" href="bd_mbed-LPC1768.jpg" title="mbed-LPC1768"></a>
    - @ref lwip_ek-lm3s6965 <a class="preview board" href="bd_EK-LM3S6965.jpg" title="EK-LM3S6965"></a>
- ARM Cortex-M4F (with hardware FPU)
    - @ref arm-cm_blinky_ek-tm4c123gxl <a class="preview board" href="bd_EK-TM4C123GXL.jpg" title="EK-TM4C123GXL"></a>
    - @ref arm-cm_dpp_ek-tm4c123gxl <a class="preview board" href="bd_EK-TM4C123GXL.jpg" title="EK-TM4C123GXL"></a>
- ARM7 / ARM9
    - @ref arm7-9_dpp_at91sam7s-ek <a class="preview board" href="bd_AT91SAM7S-EK.jpg" title="AT91SAM7S-EK"></a>

- AVRmega
    - @ref avr_blinky_arduino-uno <a class="preview board" href="bd_Arduino-UNO.jpg" title="Arduino-UNO"></a>
    - @ref avr_dpp_arduino-uno <a class="preview board" href="bd_Arduino-UNO.jpg" title="Arduino-UNO"></a>

- AVR32UC (coming soon...)

- MSP430
    - @ref msp430_blinky_msp-exp430g2 <a class="preview board" href="bd_MSP-EXP430G2.jpg" title="MSP-EXP430G2"></a>
    - @ref msp430_blinky_msp-exp430f5529lp <a class="preview board" href="bd_MSP-EXP430F5529LP.jpg" title="MSP-EXP430F5529LP"></a>
    - @ref msp430_dpp_msp-exp430g2 <a class="preview board" href="bd_MSP-EXP430G2.jpg" title="MSP-EXP430G2"></a>

- PIC24 /dsPIC (coming soon...)
- PIC32 (coming soon...)
- Renesas RX (coming soon...) 
- TI TMS320C28x (C28x) (coming soon...) 
- TI TMS320C55x (C55x) (coming soon...) 


------------------------------------------------------------------------------
@section exa_ref_tools Examples by Development Toolset
- ARM architecture
    - ARM (ARM-Keil)
        - @ref arm-cm_blinky_ek-tm4c123gxl <a class="preview board" href="bd_EK-TM4C123GXL.jpg" title="EK-TM4C123GXL"></a>
        - @ref arm-cm_dpp_ek-tm4c123gxl <a class="preview board" href="bd_EK-TM4C123GXL.jpg" title="EK-TM4C123GXL"></a>
        - @ref arm-cm_dpp_mbed-lpc1768  <a class="preview board" href="bd_mbed-LPC1768.jpg" title="mbed-LPC1768"></a>
        - @ref arm-cm_dpp_nucleo-l053r8  <a class="preview board" href="bd_nucleo-l053r8.jpg" title="NUCLEO-L053R8"></a>
        - @ref arm-cm_dpp_nucleo-l152re  <a class="preview board" href="bd_nucleo-l152re.jpg" title="NUCLEO-L152RE"></a>
        - @ref arm-cm_game_ek-lm3s811  <a class="preview board" href="bd_EK-LM3S811.jpg" title="EK-LM3S811"></a>
    - GNU-ARM
        - @ref arm-cm_blinky_ek-tm4c123gxl <a class="preview board" href="bd_EK-TM4C123GXL.jpg" title="EK-TM4C123GXL"></a>
        - @ref arm-cm_dpp_ek-tm4c123gxl <a class="preview board" href="bd_EK-TM4C123GXL.jpg" title="EK-TM4C123GXL"></a>
        - @ref arm-cm_dpp_mbed-lpc1768  <a class="preview board" href="bd_mbed-LPC1768.jpg" title="mbed-LPC1768"></a>
        - @ref arm-cm_dpp_nucleo-l053r8  <a class="preview board" href="bd_nucleo-l053r8.jpg" title="NUCLEO-L053R8"></a>
        - @ref arm-cm_dpp_nucleo-l152re  <a class="preview board" href="bd_nucleo-l152re.jpg" title="NUCLEO-L152RE"></a>
        - @ref arm-cm_game_ek-lm3s811  <a class="preview board" href="bd_EK-LM3S811.jpg" title="EK-LM3S811"></a>
        - @ref lwip_ek-lm3s6965 <a class="preview board" href="bd_EK-LM3S6965.jpg" title="EK-LM3S6965"></a>
        - @ref arm7-9_dpp_at91sam7s-ek <a class="preview board" href="bd_AT91SAM7S-EK.jpg" title="AT91SAM7S-EK"></a>
    - IAR EWARM
        - @ref arm-cm_blinky_ek-tm4c123gxl <a class="preview board" href="bd_EK-TM4C123GXL.jpg" title="EK-TM4C123GXL"></a>
        - @ref arm-cm_dpp_ek-tm4c123gxl <a class="preview board" href="bd_EK-TM4C123GXL.jpg" title="EK-TM4C123GXL"></a>
        - @ref arm-cm_dpp_mbed-lpc1768  <a class="preview board" href="bd_mbed-LPC1768.jpg" title="mbed-LPC1768"></a>
        - @ref arm-cm_dpp_nucleo-l053r8  <a class="preview board" href="bd_nucleo-l053r8.jpg" title="NUCLEO-L053R8"></a>
        - @ref arm-cm_dpp_nucleo-l152re  <a class="preview board" href="bd_nucleo-l152re.jpg" title="NUCLEO-L152RE"></a>
        - @ref arm-cm_game_ek-lm3s811  <a class="preview board" href="bd_EK-LM3S811.jpg" title="EK-LM3S811"></a>
        - @ref lwip_ek-lm3s6965 <a class="preview board" href="bd_EK-LM3S6965.jpg" title="EK-LM3S6965"></a>
        - @ref arm7-9_dpp_at91sam7s-ek <a class="preview board" href="bd_AT91SAM7S-EK.jpg" title="AT91SAM7S-EK"></a>

- AVR architecture
    - GNU-AVR (WinAVR)
        - @ref avr_blinky_arduino-uno <a class="preview board" href="bd_Arduino-UNO.jpg" title="Arduino-UNO"></a>
        - @ref avr_dpp_arduino-uno <a class="preview board" href="bd_Arduino-UNO.jpg" title="Arduino-UNO"></a>
    - IAR EWAVR
        - @ref avr_blinky_arduino-uno <a class="preview board" href="bd_Arduino-UNO.jpg" title="Arduino-UNO"></a>
        - @ref avr_dpp_arduino-uno <a class="preview board" href="bd_Arduino-UNO.jpg" title="Arduino-UNO"></a>

- MSP430 architecture
    - CCS-430
        - @ref msp430_blinky_msp-exp430g2 <a class="preview board" href="bd_MSP-EXP430G2.jpg" title="MSP-EXP430G2"></a>
        - @ref msp430_blinky_msp-exp430f5529lp <a class="preview board" href="bd_MSP-EXP430F5529LP.jpg" title="MSP-EXP430F5529LP"></a>
        - @ref msp430_dpp_msp-exp430g2 <a class="preview board" href="bd_MSP-EXP430G2.jpg" title="MSP-EXP430G2"></a>
    - IAR EW430
        - @ref msp430_blinky_msp-exp430g2 <a class="preview board" href="bd_MSP-EXP430G2.jpg" title="MSP-EXP430G2"></a>
        - @ref msp430_blinky_msp-exp430f5529lp <a class="preview board" href="bd_MSP-EXP430F5529LP.jpg" title="MSP-EXP430F5529LP"></a>
        - @ref msp430_dpp_msp-exp430g2 <a class="preview board" href="bd_MSP-EXP430G2.jpg" title="MSP-EXP430G2"></a>


------------------------------------------------------------------------------
@section exa_ref_vendor Examples by MCU Vendor
- Atmel
    - @ref arm7-9_dpp_at91sam7s-ek <a class="preview board" href="bd_AT91SAM7S-EK.jpg" title="AT91SAM7S-EK"></a>
    - @ref avr_blinky_arduino-uno <a class="preview board" href="bd_Arduino-UNO.jpg" title="Arduino-UNO"></a>
    - @ref avr_dpp_arduino-uno <a class="preview board" href="bd_Arduino-UNO.jpg" title="Arduino-UNO"></a>
- NXP
    - @ref arm-cm_dpp_mbed-lpc1768  <a class="preview board" href="bd_mbed-LPC1768.jpg" title="mbed-LPC1768"></a>
- STMicroelectronics
    - @ref arm-cm_dpp_nucleo-l053r8  <a class="preview board" href="bd_nucleo-l053r8.jpg" title="NUCLEO-L053R8"></a>
    - @ref arm-cm_dpp_nucleo-l152re  <a class="preview board" href="bd_nucleo-l152re.jpg" title="NUCLEO-L152RE"></a>
- Texas Instruments
    - @ref arm-cm_blinky_ek-tm4c123gxl <a class="preview board" href="bd_EK-TM4C123GXL.jpg" title="EK-TM4C123GXL"></a>
    - @ref arm-cm_dpp_ek-tm4c123gxl <a class="preview board" href="bd_EK-TM4C123GXL.jpg" title="EK-TM4C123GXL"></a>
    - @ref arm-cm_game_ek-lm3s811  <a class="preview board" href="bd_EK-LM3S811.jpg" title="EK-LM3S811"></a>
    - @ref lwip_ek-lm3s6965 <a class="preview board" href="bd_EK-LM3S6965.jpg" title="EK-LM3S6965"></a>

@next{exa_native}
*/

} // namespace QP