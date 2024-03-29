namespace QP {

/** @page history Revision History


@section qpcpp_5_4_2 Version 5.4.2, 2015-06-06

The main focus of this release is to improve the support for "dual targeting" of QP/C++ applications, which is developing of deeply embedded code as much as possible on the desktop OS, such as Windows. Experience shows that "dual targeting" dramatically improves productivity of embedded systems developers, perhaps more than any other technique.

This release makes it possible to use exactly the **same** application code, main function, and the Board Support Package interface (bsp.h) on both deeply embedded target and on Windows. The only differences between these targets can be completely encapsulated in the Board Support Package implementation (bsp.cpp).

The support for "dual targeting" in this QP/C++ release works both for Win32 console and Win32 GUI applications. The Win32-GUI support enables developers to easily emulate the front-panels of the embedded devices, with LCD-screens (graphical and segmented), LEDs, buttons, switches, sliders, etc.

Changes in detail:

1. Modified the QP/C++ ports to Windows (both @ref win32 and @ref win32-qv) so that they support both Win32 console and Win32-GUI applications. The newly introduced pre-processor #WIN32_GUI macro is now required to use the Win32-GUI facilities.

2. Added portable "safe" macros from `<stdio.h>` and `<string.h>` to the QP/C++ ports to Windows. These macros encapsulate the differences between Microsoft Visual C++ and other compilers (such as MinGW).

3. Simplified the structure of the QP/C++ Windows ports by eliminating one level of directories for the compilers used. Both VC++ and MinGW builds can now be run in the same port directory.

4. Modified the QF::stop() function in the QP/C++ port to @ref win32-qv, so that it unblocks the QV event-loop and thus lets the application terminate. 

5. Modified all examples for Windows to use the new port structure.

6. Improved all Makefiles (for the MinGW toolset) in all Windows examples, to make them easier to adapt to custom applications, both Win32 console and Win32 GUI.

7. Moved several examples from the `examples/win32/` and examples/win32-qv directories to `examples/arm-cm/` directory with native embedded examples for ARM Cortex-M. This co-location of the Win32 emulation with the embedded code running on the actual board demonstrates better the "dual targeting" development approach.

8. Updated all Windows examples to the latest QP API by compiling the code with the macro #QP_API_VERSION set to 9999 (latest API without backwards compatibility)

9. Improved the PC-Lint support for checking the application-level code located in in `examples\arm-cm\dpp_ek-tm4c123gxl\lint`


------------------------------------------------------------------------------
@section qpcpp_5_4_1 Version 5.4.1, 2015-05-21

This release changes the active object class hierarchy so that ::QMActive is now more fundamental and is the base class for QActive. (Previously ::QMActive was a subclass of ::QActive). The newly added documentation section about @ref classes "QP/C++ Design" shows the current class hierarchy.

@note
Because the types QMActive and QActive are equivalent in QP/C++, this change has minimal impact on the applications, but it is now more correct to use QMActive as the base class for all "opaque" active object pointers.

Also, this release brings several cosmetic improvements:

1. All QM models have been saved with QM 3.3.0, which means that they will not open with QM 3.2.x or earlier QM versions.

2. The `qpcpp/ports/arm-cm/qk/gnu/qk_port.s` ARM Cortex-M port to QK with GNU has been modified to use the CMSIS-compliant symbol __FPU_PRESENT instead of the FPU_VFP_V4_SP_D16 symbol.

3. All Makefiles for the GNU toolset have been cleaned up, whereas any `\` (back-slash) characters in the paths have been repalced with `/` (forward-slash) characters. Also all these Makefiles have been updated to provide the __FPU_PRESENT to C/C++ and assembler when the hardware FPU is used.

4. The file display drver for the EK-LM2S811 board locate at `qpc/3rd_party/ek-lm3s811/display96x16x1.c` has been modified to fix the problem with incorrect hardware delay with the GNU compiler at higher levels of optimization. The in-line assembly for the GNU compiler has been updated such that the delay loop cannot be "optimized away". 

5. Several README files have been updated.



------------------------------------------------------------------------------
@section qpcpp_5_4_0 Version 5.4.0, 2015-05-14

This release changes the basic philosophy of distributing the QP frameworks by **combining** the "QP/C++ Baseline Code" with all currently available "QP/C++ Development Kits" (QDK/C++). This is done to eliminate any potential mistakes in downloading and installing separate pieces of code.

Additionally, this release changes the basic philosophy of building your embedded applications with the QP/C++ framework. Starting with this release, all @ref exa "examples" for embedded boards include the QP/C++ framework as **source code** within the projects, instead of statically linking with a QP/C++ library. (**NOTE:** It is still possible to use QP/C++ as a library, but you need to build such libraries yourself, as they are no longer provided in the QP/C++ distribution.)

The move to building QP/C++ from sources ensures the consistent toolset version and compiler options applied to the application code as well as the QP/C++ framework code. (**NOTE:** The QP/C++ examples for "big operating systems", like @ref exa_win32 "Windows" or @ref exa_posix "Linux", still use QP/C++ as a pre-compiled library that is statically linked with the application code.)

This release also changes the active object class hierarchy so that QMActive is now more fundamental and is the base class for QActive. (Previously QMActive was a subclass of ::QActive). The newly added documentation section about @ref classes "QP/C++ Design" shows the current class hierarchy.

@note
Even though the QP/C++ source has been re-packaged in this release, the changes have minimal impact on the existing QP/C++ applications. The biggest difference is that "opaque" pointers to active objects derived from QMActive now need to be also typed QMActive (as opposed to QActive), because QMActive is no longer a subclass of QActive and the automatic upcast no longer applies. 

The changes in basic approach to distributing and building the framework have also the following ripple effects:

1. The QP/C++ source code has been simplified and has been re-packaged into a much smaller number of source files. The whole QP/C++ source code now resides in the single <span class="img folder"><a href="dir_b2f33c71d4aa5e7af42a1ca61ff5af1b.html"><strong>source</strong></a></span> folder. Additionally, the source code files have now the **read-only** protection to prevent inadvertent changes to the QP/C++ source code that is part of your projects.

2. It is no longer necessary to define the **QPCPP environment variable** to build the QP/C++ examples. All directories and files referenced by example projects are **relative** to the project folder. This change reflects the fact that most development tools add source files to the project using relative paths (and now the projects contain QP/C++ source code, not just the QP library).   

3. The QP/C++ <span class="img folder">@ref ports</span> folder has been reorganized to contain all currently available QP/C++ ports. The ports are organized into three categories: @ref ports_native "native QP/C++ ports" ("bare-metal"), @ref ports_rtos "ports to 3rd-party RTOSes", and @ref ports_os "ports to big operating systems" (Windows and Linux).(**NOTE**: the ports are now documented in the this <strong>QP/C++ Reference Manual</strong>. Each port sub-directory contains a <span class="img qp_link">README</span> link to the corresponding page in the online documentation)

5. The QP/C++ <span class="img folder">@ref exa</span> folder has been reorganized to reduce the repetitions and contains all currently available QP/C++ examples. The folder includes four categories of examples: @ref exa_native "native QP/C++ examples" ("bare-metal"), @ref exa_rtos "examples for 3rd-party RTOSes", @ref exa_os "examples for big operating systems" (Windows and Linux), and @ref exa_mware "examples for 3rd-party Middleware". As mentioned before, all example projects for embedded systems use QP/C++ as source code and not as a library. The <span class="img folder">examples</span> folder has been expanded to contain all currently available QP/C++ examples, many of them are new in this release. (**NOTE**: the currently available examples are now documented in the <strong>QP/C++ Reference Manual</strong>. Each example sub-directory contains a <span class="img qp_link">README</span> link to the corresponding page in the online documentation)

6. A new <span class="img folder">3rd_party</span> folder created to contain the Third-Party code used in the QP/C++ ports and examples, such as MCU register files, low-level startup code, device drivers, etc. The <span class="img folder">3rd_party</span> folder avoids the need to repeat such code in every project. Also, the separation of the Third-Party components helps to clearly indicate code that comes from various sources, and to which Quantum Leaps, LLC expressly makes **no claims of ownership**. The Third-Party software components included in this "3rd_party" folder are licensed under a variety of different licensing terms that are defined by the respective owners of this software and are spelled out in the README.txt or LICENSE.txt files included in the respective sub-folders.

7. This release also comes with the much expanded online <strong>QP/C++ Reference Manual</strong>, which is cross-linked with the ports and examples.


Changes in detail:

1. Renamed the "Vanilla" scheduler to the @ref comp_qv "QV cooperative kernel" for symmetry with the @ref comp_qk "QK preemptive kernel". Renamed QF::onIdle() callback to QV::onIdle().

2. Removed class QFsm (which is now deprecated). Legacy state machines coded in the "QFsm-style" will continue to work, but will use the QHsm implementation internally. There is no longer any efficiency advantage in using the "QFsm-style" state machines.

3. Applied a slight performance improvement to the ARM Cortex-M port to the QK preemptive kernel. The QK port now checks for ISR context by looking at the IPSR register, instead of incrementing and decrementing the `QK_intNest_` up-down counter.

4. Updated @ref exa_arm-cm "ARM Cortex-M examples" and provided new examples for NXP mbed-LPC1768, and STM32 NUCLEO-L053R8, and NUCLEO-L152RE boards. All examples now use the latest CMSIS (V4.3.0). All ARM Cortex-M exampels are provided for the ARM-KEIL, GNU-ARM, and IAR-ARM toolsets.

5. Added the native @ref arm7-9 "port" and @ref exa_arm7-9 "examples" to the @ref arm7-9 "classic ARM7/9" with AT91SAM7S-EK board and the IAR-ARM toolset.

6. Added the native @ref avr "port" and @ref exa_avr "examples" to the AVR (AVRmega) with GNU-AVR and IAR-AVR toolsets. The @ref exa_avr "examples" are provided for the Arduino-UNO board. 

7. Added the native @ref msp430 "port" and @ref exa_msp430 "examples" to MSP430 with TI CCS-430 and IAR-430 toolsets. The @ref exa_msp430 "examples" are provided for the MSP430 LauchPad boards (the MSP-EXP430G2 and MSP-EXP430F5529LP for the "classic" MSP430 and "extened" MSP430X, respectively).

8. Added port to @ref cmsis-rtx "CMSIS-RTOS RTX". Examples are available for TI EK-TM4C123GLX, STM32 NUCLEO-L053R8, and NUCLEO-L152RE boards with ARM-KEIL, GNU-ARM, and IAR-ARM toolsets.

9. Updated port to @ref embos "embOS". Examples are available for STM32 STM32F4-Discovery board with IAR-ARM toolset.

10. Updated port to @ref freertos "FreeRTOS" for the latest version 8.2.1. Examples are available for TI EK-TM4C123GLX board with GNU-ARM and IAR-ARM toolsets.

11. Added @ref threadx "port to Thread-X". Example is available for the Thread-X demo with Visual Studio on Windows.

12. Updated port to @ref ucos-ii "uC/OS-II" for the latest version v2.92. Examples are available for TI EK-TM4C123GLX and STM32 NUCLEO-L152RE boards with ARM-KEIL and IAR-ARM toolsets.

13. Updated @ref win32 "port to Win32" (Windows). Modified the port to apply a generous "fudge factor" in over-sizing QP event queues and event pools, to minimize the risk of overflowing queues/pools due to non-deterministic Windows behavior.

14. Updated the @ref qt "QP-Qt Port" (QP/C++ port to the Qt cross-platform GUI framework).

15. Added new @ref win32-qv "port to Win32-QV" (Windows with cooperative "Vanilla" scheduler, previously known as Win32-1T).    
 
16. Updated the @ref lwip_ek-lm3s6965 "lwIP-QP example for EK-LM3S6965 board".    


------------------------------------------------------------------------------
@section qpcpp_5_3_1 Version 5.3.1, 2014-09-20

\note QP/C++ 5.3.1 remains backwards-compatible with all QP/C++ ports
and applications

This release fixes the following bugs:

1. QMsm::isInState() returns invalid result (bug #105)

2. QF::gc() doc typo (bug #102)

3. POSIX-port Makefile error (bug #65)

4. Problematic friendship to extern "C" function in qf.h (bug #106)


Also, this release updates the PC-Lint options and removes all the remaining PC-Lint warnings for the latest PC-Lint 9.00k.

Additionally, this release improves the uC/OS-II port in that it is now generic and applicable for any CPU, for which uC/OS-II port exists. Specifically, all references to DOS or x86 have been removed from the QP port and any CPU-specific dependencies have been placed in the separate part of the port.

Finally, this release improves the "QP/C++ Reference Manual" generated by Doxygen and available both inside the QP/C++ baseline distribution (qpcpp.chm file) and online at: http://www.state-machine.com/qp/qpcpp


------------------------------------------------------------------------------
@section qpcpp_5_3_0 Version 5.3.0, 2014-04-14

This release adds the "transition to history" (deep history) feature to
both QHsm and QMsm state machines and their subclasses. This QP/C++
release matches the new QM modeling tool version 3.1.0, which now
supports the "transition to history" connector and the corresponding
code generation for transitions to history.

\note QP/C++ 5.3.0 remains backwards-compatible with QP/C++ applications
developed for QP/C++ 4.x and QP/5.x. However, any QM models created for
the previous QP/C++ versions require re-generating the code with QM 3.1.0.

This release adds new QS (Quantum Spy) instrumentation for tracing
transitions to history as well as entry and exit points in submachines.
All these features require the matching QSPY host application included
in Qtools 5.3.0.

Additionally, the QMsm state machine has been extended to add
implementation of the reusable submachine states and submachines with
entry points and exit points. The reusable submachines in QP/C++ 5.3.0
lay the groundwork for providing reusable submachine states and
submachine diagrams in the next upcoming QM version.

This release also uses the C99 data types uint_fast8_t and uint_fast16_t
instead of the non-standard uint_t.

Finally, this QP/C++ release brings deep changes in the source code
comments and the doxygen documentation generated from the source code.
All comments have now more consistent structure, and every function is
now documented in the implementation file (.cpp file), whereas the
interface (.h files) contain only the brief descriptions of the
functions. This re-structuring of documentation is performed as part of
the validation and verification effort that has begun to provide a
certification package for QP/C++ for safety standards, such as IEC 61508
and ISO 62304 (FDA 510(k)).


Changes in detail:

1. Moved detailed documentation of functions from the header files (.h)
to implementation files (.cpp).

2. Removed the header file "qevt.h" and merged its contents into "qep.h"

3. Added macros: trace records QS_QEP_TRAN_HIST, QS_QEP_TRAN_EP, and
QS_QEP_TRAN_XP to "qs.h"

4. Added macros: Q_TRAN_HIST(), QM_TRAN_HIST(), QM_TRAN_EP(),
QM_TRAN_XP(), and QM_SUPER_SUB() to "qep.h"

5. Added attributes entryAction and initAction to the QMState struct in
"qep.h" (needed for transition to history).

6. Added attribute act to the QMAttr union in "qep.h" (needed for
transitions to entry point in submachine states).

7. Changed the QState return type from action/state handler functions to
uint_fast8_t.

8. Added QM models to the "Transition to History" design pattern example
(directory qpcpp\examples\win32\mingw\history) and also added an example
for "Transition to History" with the QMsm class (see
qpcpp\examples\win32\mingw\history_qm).

9. Changed the m_prio attribute of QActive to uint_fast8_t.

10. Changed the type of prio argument to uint_fast8_t and qlen/stkSize
to uint_fast16_t in the signature of QActiveVtbl.start function pointer
and QActive::start_() implementation.

11. Changed the type of the tickRate argument in QTimeEvt constructor
and ::QF::tickX_(), and ::QF::noTimeEvtsActiveX() to uint_fast8_t.

12. Changed the type of the poolSize argument in ::QF::poolInit() to
uint_fast16_t.

13. Changed arguments evtSize and margin in ::QF::newX_() to
uint_fast16_t.

14. Changed attribute bits in QPSet8 as well as bytes and bits[] in
QPSet64 to uint_fast8_t.

15. Changed the QEQueueCtr event queue counter type to uint_fast8_t.

16. Changed type of arguments qLen and margin in ::QEQueue::init() and
QEQueue/QActive::post() to uint_fast16_t.

17. Changed the return type from QK_schedPrio_() (priority) as well as
the p argument in QK_sched_() and QK_schedExt_() to uint_fast8_t

18. Added function QMsm::isInState() to "qep.h" and its implementation
file qmsm_in.cpp. This function tests whether the QMsm state machine (or
its subclasses like QMActive) "is in" the given state.

19. Updated all make scripts for QP/C++ ports to include the new
qmsm_in.cpp in the QP/C++ library builds.


------------------------------------------------------------------------------
@section qpcpp_5_2_1 Version 5.2.1, 2014-01-06

This release fixes two bugs.

1. In file qmsm_dis.cpp added saving of the action-table into a
temporary variable *before* exiting the current state to the transition
source. Also, changed the signature of the QMsm::msm_tran() helper
function to take the action table as parameter. NOTE: This bug only
affected the Spy configuration and because of this escaped regression
testing. The internal testing process have been updated to test all
build configurations: Debug, Release, and Spy.

2. In file qs_mem.cpp fixed an error in accounting used bytes in the QS
trace buffer.


------------------------------------------------------------------------------
@section qpcpp_5_2_0 Version 5.2.0, 2013-12-28

This release matches the new QM 3.0.0, for which it provides model
examples based on the new QMsm/QMActive classes. This, in turn
demonstrates the new state machine code generation that QM3 was
specifically designed to do.

This release also provides a clearly separated API compatibility layer,
whereas you can configure a level of backwards compatibility by means of
the #QP_API_VERSION macro. This facilitates migrating existing QP
applications to the newer API.

An cyclomatic complexity (McCabe V(G)) analysis of this version has been
performed and the maximum V(G) complexity per function has been reduced
to 15 by breaking up the QHsm::dispatch() function. The code metrics
report, including cyclomatic complexity by function as well as other
standard code metrics (e.g., lines of code), is now included in the
"QP/C++ Reference Manual", see
http://www.state-machine.com/qp/qpcpp/metrics.html

Also, in this release all internal QP data that were previously
uninitialized are now explicitly initialized to zero. In other words,
this release no longer assumes that all uninitialized data (global and
static inside functions) is implicitly initialized to zero before the
control is transferred to main(). This is a requirement of the C
Standard, but some embedded startup code fails to do this.

Finally, this release demonstrates safer stack allocation and safer
exception handlers in all ARM Cortex-M examples. The techniques are
described in the Embedded.com article "Are We Shooting Ourselves in the
Foot with Stack Overflow?".

Changes in detail:

1. for backwards compatibility, in file qp_port.h defined "API
Compatibility Layer", which is controlled by the macro #QP_API_VERSION.
For example, specifying QP_API_VERSION=500 chooses API compatible with
QP version 5.0.0 or newer, but excludes APIs that became deprecated in
the earlier versions. If the macro #QP_API_VERSION is not defined by the
user (typically on the command line for the compiler), the default value
of 0 is assumed. This default means maximum backwards compatibility
(from version 0.0.0). On the other hand, higher values of
#QP_API_VERSION mean less backwards compatibility. For example
QP_API_VERSION=9999 will specify compatibility only with the latest
version of QP. The API Compatibility Layer for QP_API_VERSION < 500
provides macros: postLIFO(), publish(), and tick(). These macros resolve
to POST(), PUBLISH(), and TICK_X() respectively.

2. In file qhsm_dis.cpp, broken up the function QHsm::dispatch() into
two functions QHsm::dispatch() and a private helper QHsm::hsm_tran().
This has reduced the cyclomatic complexity from 25 for the original
function, to 11 and 15 for QHsm::dispatch_() and QHsm::hsm_tran(),
respectively.

3. In file qmsm_dis.cpp, broken up the function QMsm::dispatch() into
two functions QMsm::dispatch() and a private helper QMsm::msm_tran().
This has reduced the cyclomatic complexity from 15 for the original
function, to 9 and 7 for QMsm::dispatch() and QMsm::msm_tran(),
respectively.

4. Changed QM models dpp.qm and game.qm to use QMActive and QMsm base
classes instead of QActive and QHsm, to showcase the new code generation
capabilities of QM3.

5. Added the QMsmTst example application analogous to the QHsmTst to
test the QMsm base class. The QMsmTst comes with the QM model qmsmtst.qm.

6. In file qf_act.cpp added the function QF::bzero(), and in files
qvanilla.cpp and qk.cpp added calls to QF::bzero() to explicitly clear
the uninitialized data. Also added calls to QF::bzero() inside
qf_psini.cpp.

7. Updated all examples for ARM Cortex-M to use safer stack allocation
and safer exception handlers in all ARM Cortex-M examples, as described
in the Embedded.com article "Are We Shooting Ourselves in the Foot with
Stack Overflow?".


------------------------------------------------------------------------------
@section qpcpp_5_1_1 Version 5.1.1, 2013-10-10

This release fixes reversal of logic in the QF::noTimeEvtsActiveX()
function as well as sleep mode transition in the ARM Cortex-M3/M4 ports
to the cooperative Vanilla kernel. Also, the native QP event queue
implementation has been changed to count the extra "front-event"
location into the number of free entries, which fixes the problem of
defer queues of depth 1. Finally, the release restores the support for
linting (with PC-Lint) of the QP/C++ applications for ARM Cortex-M (with
IAR and GNU compilers).

Changes in detail:

1. In file qf_tick.cpp reversed the logic inside QF::noTimeEvtsActiveX()

2. Modified free entry accounting (nFree) in the files: qeq_init.cpp,
qeq_fifo.cpp, qeq_get.cpp, and qeq_lifo.cpp.

3. Modified free entry accounting (nFree) in the files: qa_init.cpp,
qa_fifo.cpp, qa_get_.cpp, and qa_lifo.cpp.

4. Introduced new macro QF_CPU_SLEEP() in the ARM Cortex-M Vanilla ports.

5. Changed Board Support Package files (bsp.cpp) in the ARM Cortex-M
Vanilla examples.

6. Modified the CMSIS-compliant startup code in all ARM Cortex-M Vanilla
examples.

7. Modified the application examples with PC-Lint
(qpcpp/examples/arm-cm/qk/gnu/dpp-qk_ek-lm3s811-lint and
qpcpp/examples/arm-cm/qk/iar/dpp-qk_ek-lm3s811-lint). Updated lint files
for the latest PC-Lint

8. Ported all state pattern examples to Win32/MinGW. That way, all these
examples can be run and modified directly on Windows, without going back
to DOS.


------------------------------------------------------------------------------
@section qpcpp_5_1_0 Version 5.1.0, 2013-10-02

\note QP/C++ 5.1.0 remains <b>backwards-compatible</b> with the existing
QP/C 4.x applications, except the <b>ARM Cortex-M applications</b> need to
adjust the interrupt priorities. Specifically, you need to set the
interrupt priorities equal or lower than <b>QF_AWARE_ISR_CMSIS_PRI</b>
constant provided in the qf_port.h header file.

The main purpose of this milestone QP/C++ release is to enable the QM
modeling tool to generate a new type of state machine code (requires QM
version 3.0.0, which is still in development as of this writing).

This new type of state machine implementation in QP/C++ 5 is based on
the new ::QMsm class, which takes advantage of the QM tool as an advanced
"state machine compiler". QM can perform optimizations that were not
possible with the C pre-processor alone. Specifically, the QM can easily
determine the LCA (Least-Common-Ancestor) state for every transition and
it can generate the complete transition-sequences (sequences of
exit/entry/initial actions) at code-generation time. The resulting code
can be still highly human-readable, but it will no longer be
human-maintainable. The lab tests indicate that the new "housekeeping"
code for executing hierarchical state machines can be about twice as
fast as the previous code based on the ::QHsm class.

The next important change introduced in QP/C++ 5 is making several
important functions in QP/C++ base classes virtual. The new virtual
functions include: QMsm::init() and QMsm::dispatch() and
QActive::start(), QActive::post(), and QActive::postLIFO() perations.
Making theses functions virtual means that all these operations can be
overridden in sub-classes of state machines and active objects. This, in
turn, allows a single application to use a mix of state machine classes
derived from the new QMsm base class with state machines derived from
the QHsm base class, each one using a different state machine
implementation strategy. Additionally, the virtual QActive::post()
operation could be very useful for implementing various Proxy active
objects (e.g., for active object event posting across networks).

Another big feature introduced in QP/C++ 5 are the multiple, independent
system clock tick rates for time events. The number of system tick rates
can be now configured in the QP/C++ ports. For example, a digital watch
can use a "fast" clock tick rate of 100Hz and a "slow" clock tick rate
of only 1Hz. These clock tick rates can be managed independently, so for
example, the fast clock tick rate can be shut down in the absence of
time events assigned to this rate. This feature allows the applications
to implement sophisticated power-saving policies.

As yet another important feature, QP/C++ adds a new "extended" API for
non-asserting event allocation and posting. This feature is intended for
situations, where an application is hammered with external events that
at times arrive too fast for processing, but that can be ignored under
the overload conditions. In those cases firing an assertion inside the
framework is undesirable. The non-asserting API allows a designer to
request a safety-margin when allocating or posting an event. The event
is not allocated/posted if the safety margin cannot be satisfied at the
time of the call. On the other hand, the safety margin allows the
application to still use the regular (asserting) event allocation and
posting, because the event pools and event queues are guaranteed to
maintain a minimal margin for safe operation.

Finally, this QP/C++ release brings significant improvements to the QS
software tracing implementation and also brings important changes the
ARM Cortex-M port. Changes in detail are as follows:

0. Removed the conditional compilation of the QP:: namespace based on
the macro Q_NNAMESPACE. The namespace QP:: is now enabled permanently,
which is a requirement of MISRA-C++:2004 and is also is part of the QM
code generation for QP/C++. Also, the use of explicit QP:: namespace
improves the doxygen documentation (QP/C++ Reference Manual).

1. Added the new QMsm class to qep.h. Changed the inheritance tree by
deriving QHsm and QFsm from the QMsm base class.

2. Added new source files qmsm_ini.cpp and qmsm_dis.cpp to the QEP. These
files implement the QMsm::init() and QMsm::dispatch() functions, respectively.

3. Added the new QMActive class to qf.h. Extended the inheritance
tree to derive QMActive from QActive.

4. Added the multiple system clock tick rates feature in qf.h:
    - added new configuration macro #QF_MAX_TICK_RATE, which specifies
      the number of clock tick rates. This macro is to be defined in
      the QF ports (in the qf_port.h header file). If the macro is
      undefined, the default value is 1 (one clock tick rate).
    - renamed and re-implemented the QF::tick() function as the
      "extended" QF::tickX() function with the argument 'tickRate' for
      processing time events allocated to different clock rates. The
      application must call QF::tickX(0), QF::tickX(1), ... at the
      specified tick rates from ISRs or *tasks*.
    - added an "extended" time event constructor, which assigns a time
      event to a specific tick rate as well as specific active object.
    - renamed and re-implemented the internal function QTimeEvt::arm_()
      to a public function QTimeEvt::armX() for arming time events
      initialized with the "extended" constructor. The QTimeEvt::armX()
      function is the new recommended API for arming time events, both
      one-shot and periodic.
    - re-implemented QTimeEvt::disarm() and QTimeEvt::rarm().
    - renamed QF::noTimeEvtsActive() to the "extended" version
      QF::noTimeEvtsActiveX(), which checks time events assigned to the
      given tick rate.

5. Added the new non-asserting API to qf.h:
    - renamed internal function QF::new_() to QF::newX_(), the latter one
      taking the argument 'margin' for allocating events. The function
      returns NULL if the event pool has less free events than the
      specified margin. The function asserts if the margin is zero and
      the event can't be allocated.
    - added function QActive::post() to post an event to the given
      active object. The function does not post the event if the target
      event queue has less free slots than the specified margin. The
      function asserts if the margin is zero and the event can't be
      posted.
    - added "extended" macro Q_NEW_X() for allocating events with a
      margin.
    - added "extended" macro POST_X() for posting events with a
      margin.

6. Modified the QActive::defer() function to return the status of the
   defer operation (true==success), instead of asserting when the defer
   queue overflows.

7. Modified QS (Quantum Spy) software tracing implementation:
    - Optimized the internal QS implementation of all functions that
      insert trace data into the trace buffer. The general idea of the
      optimization is to extensively use automatic variables instead of
      global variables (such as buffer head and tail indexes, the
      running checksum, etc.).
    - Reduced the number of QS global filters from 256 to 124 (0x7C).
      This enables the code to avoid escaping the trace record numbers
    - added additional tick rate byte to the trace records QS_QF_TICK
      and QS_QFF_TIMEEVT_*.
    - An empty QS record and the QS_RESET record are now inserted
      automatically into the trace buffer in the function
      QS::initBuf(). The empty QS record/QS_RESET pair provides a clean
      start of a session and allows the QSPY host application to
       re-synch with the data stream.
    - added new trace records #QS_QF_ACTIVE_POST_ATTEMPT,
      #QS_QF_EQUEUE_POST_ATTEMPT, and #QS_QF_MPOOL_GET_ATTEMPT for the
      "extened" non-asserting event allocation and posting.
    - added new trace records QS_TEST_RUN and QS_TEST_FAIL for future
      support for unit testing.
    - added new QS source file qs_dict.cpp with functions QS_*_dict() to
      generate various dictionary entries. Changed the macros
      QS_*_DICTIONARY() to call these functions. This was done to
      significantly reduce the amount of tracing code needed to send the
      dictionaries from applications.
    - grouped together the various QS variables (such as filters, trace
      buffer indexes, etc.) in a single struct, which results in a more
      efficient code for various QS operations.

8. Changed the structure of the ARM Cortex-M ports
    - renamed the sub-directory for ARM Cortex-M ports and examples
      from "arm-cortex" to "arm-cm". This is done to avoid confusion
      with other ARM Cortex variants, such as Cortex-A/R, which very
      different from Cortex-M.
    - Changed the policy of disabling interrupts for Cortex-M3/M4.
      For these cores, QP 5.1.0 never completely disables interrupts,
      even inside the critical sections. The QP port disables
      interrupts selectively using the BASEPRI register. (NOTE: The
      BASEPRI register is not implemented in the ARMv6-M architecture
      (Cortex-M0/M0+), so Cortex-M0/M0+ need to use the PRIMASK
      register to disable interrupts globally).

    - removed the CMSIS (Cortex Microcontroller Software Interface
      Standard) directories from the Cortex-M examples and moved it to
      the common location in the %QPC%\ports\arm-cm\cmsis\ directory.
      Upgraded the CMSIS to the latest version 3.20.
    - added the ARM Cortex-M ports and examples with Keil/ARM MDK to
      the QP Baseline Code.
    - upgraded ARM Cortex-M ports with IAR to the latest IAR EWARM 6.60
    - upgraded ARM Cortex-M ports with Sourcery CodeBench to the latest
      version 2013.05-53.

9. Added the requested simple "Blinky" example for Windows and ARM
   Cortex-M (with the GNU, IAR, and Keil toolsets).
    - Added "Getting Started with QP/C++" guide based on the Blinky
      example.

10. Updated the Doxygen documentation (QP/C++ Reference Manual)
    - removed the outdated tutorial section
    - updated and added documentation and code samples
    - added search box and tree-view panel to the HTML documentation


\note This new policy of disabling interrupts in ARM Cortex-M divides
interrupts into "kernel-unaware" interrupts, which are never disabled,
and "kernel-aware" interrupts, which are disabled in the QP critical
sections. Only "kernel-aware" interrupts are allowed to call QP
services. "Kernel-unaware" interrupts are *NOT* allowed to call any QP
services and they can communicate with QP only by triggering a
"kernel-aware" interrupt (which can post or publish events).


------------------------------------------------------------------------------
@section qpcpp_4_5_04 Version 4.5.04, 2013-02-10

The main purpose of this release is adding support for the ARM Cortex-M4F
processors with the hardware Floating-Point Unit (FPU). The QP/C ports
to Cortex-M4F take full advantage of the "lazy stacking" feature of the
FPU registers, and by doing so offer the most efficient preemptive
multitasking on this processor.

Changes in detail:

1. Added ports and examples for ARM Cortex-M4F with the EK-LM4F120XL
board (Stellaris Launchpad).

2. Added the macro QF_LOG2(), which can be re-implemented in the QP ports,
if the CPU supports special instructions, such as CLZ (count leading zeros
in Cortex-M3/M4). If the macro is not defined in the QP port, the default
implementation uses a lookup table.

3. Updated all ARM Cortex-M ports and examples to the latest IAR EWARM
6.50 and Sourcery CodeBench 2012.09-85.

4. Updated App Notes "QP and ARM Cortex-M with IAR" and "QP and ARM
Cortex-M with GNU".

5. Updated the PC-Lint support files (include\lib-qpcpp.lnt, au-misra2.lnt)
to the latest PC-Lint 9.00j.

6. Updated the Application Note: "QP/C++ MISRA-C:2004 Compliance Matrix".

7. Spell-checked the comments in all QP/C++ source files and removed
several typos.

8. Removed the Qt ports and examples from the QP/C++ Baseline Code and
moved them to the separate QDK/C++-Qt.

\note QP/C++ Version 4.5.04 preserves full compatibility with QM 2.2.03
and all existing QDKs for QP/C++ 4.5.xx.


------------------------------------------------------------------------------
@section qpcpp_4_5_03 Version 4.5.03, 2012-11-29

This release changes the directory structure of QP ports to various
operating systems, such as POSIX (Linux, BSD, etc.), Win32 (Windows),
Qt, etc. The OS ports are moved from the ports\80x86\ directory one
level up to ports\. Also, the OS examples are moved from the
exampels\80x86\ directory one level up to examples\.


------------------------------------------------------------------------------
@section qpcpp_4_5_02 Version 4.5.02, 2012-08-15

The main purpose of this release is providing QM models in most
examples and better, more comprehensive support for (rapid)
prototyping of embedded QP applications on the desktop with the
Win32 API and with Qt. Among others, this release adds a complete
toolkit for creating realistic embedded front panels with pure
Win32-GUI API and free Visual C++ Express and ResEdit. An extensive
Application Note "QP and Win32" is included in this release.

This QP relase adds QM models, created with the new QM 2.2.01,
to most of the examples. The code generated by this new QM version
complies with MISRA-C++:2008 rules. For this compliance, the QM code
generator applies the QP:: namespace prefix to all QP/C++ elements,
such as classes, types, enumerations, etc.

For compliance with MISRA-C++:2008 and compatibility with QM, all
QP/C++ ports in this release use the QP:: namespace. The namespace
generation can be suppressed by providing the new configuration
macro Q_NNAMESPACE, but this is generally *not* recommended, because
it breaks compatiblity with the QM code generation. (In other words,
a QP/C++ port without namespace cannot use the code generated by QM.)

This release simplifies the QP ports to desktop OSs, such as
Windows (Win32), Linux, BSD, Mac OSX (POSIX) and combines 32-bit
and 64-bit ports in one with conditional compilation.

This release also enhances the option for using constructors for
dynamically allocated events. When the configuration macro
Q_EVT_CTOR is defined, the QEvt class provides a non-default
constructor and the Q_NEW() macro becomes variadic and
takes the arguments for the event constructor. This generally
allows creating dynamic events "on-the-fly" without a temporary
pointer to the event. This QP configuration is demonstrated only
in the QP port to Qt, but can be used in any other port.
NOTE: The event constructor feature is NOT backward-compatible
with the existing applications.

At the same time, the QEvt class in this release provides the virtual
destructor only when the new macro Q_EVT_VIRTUAL is defined. This
separation of QEvt constructor from virtual destructor makes the
constructor more attractive, because it saves the virtual pointer
in every event, if no virtual functions are used in QEvt subclasses
(which seems to be generally the case).

This release also adds a new macro QF_MPOOL_EL, which is intended
for allocating properly aligned storage for memory pools and event
pools.

Finally, all QP ports included in this release use only a single QP
library, rather than separate libraries for QEP, QF, QK, and QS.

Changes in detail:

1. Modified QP port to Win32 and used the free Visual C++ Express
2010 with Platform SDK rather than Visual C++ Pro 2008. Renamed
the port directory from vc2008\ to vc\. Provided a completely
revised App Note "QP and Win32".

2. Eliminated QP port to Win32 with one thread (Win32-1T).

3. Consolidated all QP ports to POSIX OSs (Linux, Linux64, Mac_OSX)
into a single port to POSIX and placed it in the directory posix\.

4. Renamed the port directory qt_1t\ to qt\.

5. Added event constructor to qevt.h (controlled by the configuration
macro Q_EVT_CTOR).

6. Added the conditional compilation with the macro Q_EVT_VIRTUAL
around the virtual destructor in the QEvt class.

7. Added macro QF_MPOOL_EL to qmpool.h. Modified all examples to
demonstrate the use of this macro to allocate properly aligned
storage for event pools.

8. Added new typedef 'enum_t' and modified signatures of functions
taking event signals from QSignal to enum_t. This was done to
significantly reduce the number of casts necessary when enumerated
signals were passed to QP functions.

9. Modified all QP ports distributed in the QP/C++ baseline code
to generate only a single QP library, rather than separate
libraries for QEP, QF, QK, and QS. This includes all QP ports
to the desktop (ports\80x86\ directory) and ARM Cortex-M ports
(ports\arm-cortex\ directory).

10. Modified all examples to link only one QP library.

11. Added QM models to most examples and used the automatically
generated code from the models instead of the hand-written code.

12. Modified Qt ports to use the event constructors and
modified examples for Qt to demonstrate this feature.

13. Added .ui files to the Qt examples for generating UIs
graphically with the Qt Designer tool. Revised and updated the
App Note "QP and Qt".

14. Added new macro QS_USR_DICTIONARY() to QS for providing symbolic
names for user-defined trace records

15. Added new macro QS_RESET() to QS for telling the QSPY application
when the target resets. This allows QSPY to reset its internal state.


------------------------------------------------------------------------------
@section qpcpp_4_5_01 Version 4.5.01, 2012-06-14

The main purpose of this minor release is providing improved
MISRA-compliant state machine implementation. Specifically, a new
macro Q_UNHANDLED() has been added for a situation when a guard
condition evaluates to FALSE, but the state model does not prescribe
the explicit [else] case for this guard. In this case, the state
handler can return Q_UNHANDLED(), which will cause the QEP event
processor to propagate the event to the superstate, which is what
UML semantics prescribes.

NOTE: These change to the QEP event processor is completely
backwards-compatible. All state hander functions coded the old
way will continue to handle the guard conditions correctly and
in accordance with the UML specification. The new Q_UNHANDLED()
macro is necessary only for MISRA-compliant state handler coding,
which will be applied in the upcoming release of the QM modeling
and code generation tool.  

Changes in detail:

1. Added macro Q_UNHANDLED() and return value Q_RET_UNHANDLED in
qep.h.

2. Modified qhsm_dis.cpp to handle the Q_RET_UNHANDLED return value.

3. Updated the QP/C MISRA-C++:2008 compliance matrix to 
include the new MISRA-compliant way of coding guard conditions.

4. Modified qs.h and qs_dummy.h to add new trace record type
QS_QEP_UNHANDLED, which is generated when the state handler returns
Q_RET_UNHANDLED.

5. Modified qs.h and qs_dummy.h to add the User record dictionary
trace record and macro QS_USR_DICTIONARY().
         
NOTE: This new trace record requires the updated QSPY 4.5.01.

6. Corrected qfsm_dis.cpp, which did not generate QS trace records
for entry and exit from non-hierarchical states.

7. Updated the IAR ARM compiler used in the ARM Cortex-M examples
to the latest version IAR EWARM 6.40.

8. Modified the Qt port not to define the QPApp::onClockTick()
slot function, but instead to allow defining this slot function in
the BSP of the application.


------------------------------------------------------------------------------
@section qpcpp_4_5_00 Version 4.5.00, 2012-05-26

The main pupose of this relase is to improve host-based development of QP
applications, which is critical for Test-Driven Development (TDD). Among
others, this release provides integration between QP and the popular
Qt GUI framework, which allows developers to easily build host-based
simulations of the embedded systems with the realistic user interfaces.

This realase also simplifies implementing transitions to history, which
is a preparation to providing this feature in the QM modeling tool.

Changes in detail:

1. Renamed the event class from QEvent to QEvt to avoid a name conflict
with the Qt framework. Also, for consistency, renamed the file qevent.h
to qevt.h and the macro Q_EVENT_CAST() to Q_EVT_CAST(). 

NOTE: To minimize impact of this change on the existing QP ports and
applications, the name QEvent is provided as well, but this can be
suppressed by defining the configuration macro Q_NQEVENT in qep_port.h.

2. Changed the design of QF::tick() (file qf_tick.cpp) to better support
calling this function from low-priority tasks (as opposed to interrupts
and highest-priority tasks), which often happens when QP is executed on
the desktop operating systems. In this design only QF::tick() can remove
time events from the active linked list, so no unexpected changes to the
list structure are eliminated 

3. Simplified the QTimeEvt class by removing the m_prev link pointer,
as the new design no longer needs a bi-directional list. These changes
impact the files: qte_*.cpp. 

4. Added return value to QF::run() to allow transfer of the exit
status to the destop operating systems.

NOTE: This modification haves impact on most QP/C++ ports, because
the QF::run() function must now return a int16_t value.

5. Eliminated the m_running member of the QActive class, which
has been used only in the QP ports to "big" OSes such as Linux
or Windows.

6. Added member m_temp to the QHsm and QFsm base classes to prevent
clobbering the current state (the m_state member) during transitons.
This change allows keeping the current state unchanged during the
entire transition chain, which in turn allows easy and generic access
to the state information to store the state history in the exit
actions from states. Additional bonus of this re-design is the 
opportunity of testing for stable state configuration in assertions
added to the qhsm_*.cpp and qfsm_*.cpp files.

7. Added the QHsm::state() and QFsm::state() accessor methods.

8. Modified the "Transition to History" pattern implementation to 
use the simplified technique of obtaining the current state in the
exit action from the superstate rather than all the exit actions from
the substates. Modified the "State-Local Storage" (SLS) pattern as
well, because it was using the transition to history constructs. 

9. Re-designed the implementation of the QSPY host application, so
that it can be convenienty included as part of the QP library.
This allows direct QS tracing output to the screen for QP applications
running on the desktop.

NOTE: This change is part of the Qtools release 4.5.00.  

10. Modified the QP ports to Win32_1t (both the MinGW and VC2008) to
output QS trace data directly to the stdout via the QSPY host-application
interface. Modified the DPP examples for Win32_1T to demonstrate the
direct QS output to the screen.

11. Added QP port to Qt_1t (Qt with one thread) and two example
applications (DPP and PELICAN crossing).

12. Added GNU compiler option -pthread to QP ports for POSIX with
P-threads, including QP ports and examples for Linux and Mac OS X. 


------------------------------------------------------------------------------
@section qpcpp_4_4_00 Version 4.4.00, 2012-05-02

The main pupose of this relase is MISRA-C++:2008 compliance, strong-type
checking compliance, update of PC-Lint option files and tests, and
general cleanup.

1. Moved the qp_port.h header file from the port directories to
the qcppp/include/ directory. Also, moved the inclusion of the
QS (Spy) header files (qs_port.h/qs_dummy.h) from qep.h, qf.h,
and qk.h headers to qp_port.h. These structural changes were made
to reduce the number of preprocessor #if nesting levels below 8,
which is the ANSI-C limit. This was done to comply with the MISRA-C
rule 1.1 (all code shall conform to ANSI/ISO C). 

NOTE: This modifications have impact on most QP/C++ ports, because
the qp_port.h header file must be removed from the port.

2. Enabled the QP namespace in most QP/C++ ports (except the DOS ports
with the Open Watcom compiler). This modification was needed for
MISRA-C++:2008 compliance with the rule 7-3-1. 

NOTE: This modifications have impact on most QP/C++ ports, because
all QP elements require now using the QP:: prefix. However, this prefix
can be dropped when the application applies the "using namespace QP"
directive. (The "using" directive deviates from MISRA-C++:2008 rule
7-3-4, so it is not used in the MISRA-compliant examples. However,
a number of QP ports applies the "using" directive for backwards
compatibilty.)  

3. Added the PC-Lint option files std.lnt and lib-qpcpp.lnt to the
qcppp/include/ directory.
 
4. Cleaned the whole QP/C code from lint comments. All PC-Lint options
have been moved to PC-Lint option files.
 
5. Modified QP assertion macro Q_DEFINE_THIS_MODULE() to avoid using
the # operator (MISRA rule 16-3-2). This macro now requires the argument
enclosed in doble quotes "".

NOTE: This modification has impact on some QP/C++ ports. 

6. Added typedefs for char_t, int_t, float32_t, and float64_t to
event.h header file for compliance with MISRA-C++:2008 rules 3-9-2.

7. Added macros Q_STATE_CAST() and Q_EVENT_CAST() to qep.h to
encapsulate deviation from MISRA-C++:2008 rule 5-2-7.

8. Added macro Q_UINT2PTR_CAST() to encapsulate casting unsigned
integers to pointers, which deviates from MISRA-C++:2008 rules 5-2-7
and 5-2-8. This macro has been added for *application-level* code.

9. Updated ARM Cortex-M examples with the latest CMSIS v3.0, which
complies with more MISRA-C:2004 rules.

10. Added DPP examples for MISRA-C++:2008 compliant applications (for
IAR-ARM and GNU-ARM).

11. Updated ARM-Cortex-M3 port with GNU to the latest Sourcery
CodeBench 2011.09-60.

12. Added QP/C++ port to Win32-1t and examples (Windows with 1 thread).
This port is useful for testing embedded QP/C++ applications on windows.

13. Added documentation to QP/C++ distribution in the directory
qpcpp/doc/, with the following Application notes:
"MISRA-C++:2008 Compliance Matrix", "Quantum Leaps Coding Standard",
"QP and ARM Cortex-M, and QP and Windows",  


------------------------------------------------------------------------------
@section qpcpp_4_3_00 Version 4.3.00, 2011-11-03

1. This release changes the names of critical section macros and
introduces macros for unconditional interrupt disabling/enabling.
This is done to simplify and speed up the built-in Vanilla and QK
kernels, which no longer are dependent on the interrupt locking
policy.

NOTE: The change in handling the critical section in the Vanilla and
QK kernels can break QP ports, which use the "save and restore
interrupt lock" policy, because all such ports must also define
unconditional interrupt disabling and enabling.

2. This release changes the partitioning of the QK scheduler.
Specifically, the QK scheduler is now divided between two functions
QK_schedPrio_() and QK_sched_(), to calculate the highest-priority
task ready to run and to perform scheduling, respectively. The function
QK_schedPrio_() is useful to determine if scheduling is even necessary.

3. Updated all QP ports to comply with the new critical section
names and policies.

4. Modified the ARM Cortex-M port qk_port.s to take advantage of the
new structure of the QK scheduler.

5. Upgraded the examples for ARM Cortex with IAR EWARM to the
latest IAR EWARM version 6.30.

6. Upgraded the examples for ARM Cortex with GNU (CodeSourcery) to the
latest Sourcery CodeBench 2011.07-60.


------------------------------------------------------------------------------
@section qpcpp_4_2_04 Version 4.2.04, 2011-09-24

The main pupose of this relase is to provide a bug fix for the QK port
to ARM Cortex processors. The bug fix addresses a very rare and
undocumented behavior of late-arrival of an interrupt while entering
the PendSV exception. In this case the PENDSVSET bit in the NVIC-ICSR
register is *not* cleared when finally PendSV is entered, so the
PendSV exception is entered in a *different* state when it is entered
via the late-arrival mechanism versus the normal activation of the
exception through tail-chaining. The consequence of this undocumented
and inconsistent hardware behavior, PendSV could be re-entered again
before the SVCall exception cleans up the stack. The bug fix is
implemented in the qk_port.s file and consists of clearing the
PENDSVSET bit programmatically inside PendSV_Handler.


------------------------------------------------------------------------------
@section qpcpp_4_2_02 Version 4.2.02, 2011-09-08

1. The main pupose of this relase is to repackage the default QP/C++
distribution to contain the single root directory qpcpp/ in the
archive. That way, unziping the archive will produce only one
directory (qpcpp/), which can be then changed by the user.

2. This release also changes the ARM Cortex QP ports with GNU. The
suffix "_cs" has been added to all QP libraries generated by the
Code Sourcery toolset (now Mentor Sourcery CodeBench). This is to 
distinguish libraries generated by different GNU-toolchains (such
as CodeRed, Attolic, DevKit ARM, etc.) 


------------------------------------------------------------------------------
@section qpcpp_4_2_01 Version 4.2.01, 2011-08-13

1. Modified file qassert.h to add assertion macros #Q_ASSERT_ID,
#Q_REQUIRE_ID, #Q_ENSURE_ID, #Q_INVARIANT_ID, and #Q_ERROR_ID,
which are better suited for unit testig, because they avoid the
volatility of line numbers for indentifying assertions.

2. Added QP port and examples for Mac OS X on 80x86.


------------------------------------------------------------------------------
@section qpcpp_4_2_00 Version 4.2.00, 2011-07-15

The goal of this milestone release is to extend the number of event
pools (theoretically up to 255 pools) instead of just three event
pools available up til now. This release adds an option to use
constructors/destructors and virtual functions in subclasses of QEvent.
Also, this release adds an option to wrap the whole QP framework in
the QP namespace to avoid name conflicts with other libraries and to
improve QP compliance with MISRA C++ 2008. This release adds also
several improvements to the QS/QSPY software tracing, such as adding
sender information to event posting so that sequence diagrams could be
easily and automatically reconstructed from tracing data. Also, the
tracing now supports 64-bit targets, such as embedded Linux 64-bit.
Finally, this milestone release migrates the examples to use the
environment variable QPCPP instead of relying on the relative path to
the QP/C++ framework. This allows easier adaptation of the examples for
real projects, which don't really belong to the examples directory.

The changes in detail are:

1. Changed the QEvent base class (file qevent.h). The private member
'dynamic_' has been replaced by two members 'poolId_' and 'refCtr_'.

2. Added conditionally-compiled constructor and virtual destructor
to the QEvent base class (file qevent.h). Also added the inclusion
of the <new> header file for placement new if the constructor/
destructor option is configured.

3. Added new version of the macro #Q_NEW() with variable number of
paramters, which invokes the event constructor (via placement new)
with any parameters requried by the event constructor (file qf.h).

4. Added explicit call to the event destructor in QF::gc() (file
qf_gc.cpp).

5. Added configuration macro QF_MAX_EPOOL (file qf.h) to define the
maximum number of event pools in the QP application (default to 3).
The maximum theoretical number of this macro is 255.

6. Made algorithmic changes in the QF source code related to the change
of storing the event pool-IDs and reference counters inside QEvent.

7. Changed the default signal size (macro Q_SIGNAL_SIZE in the file
qevent.h) from 1 to 2 bytes.

8. Changed the signature of QActive::recall() to return uint8_t instead
of QEvent*, which this could encourage incorrect usage (processing of
the event at the point of recalling it). Now, the function only returns
1 (TRUE) if the event was recalled and 0 (FALSE) if the event was not
recalled.

9. Added the QTimeEvt() constructor and new source file qte_ctr.cpp.
The function returns the counter of a time event, which allows using
a time event for measuring the time. 

10. Added new QF macros #QF_TICK, #QF_PUBLISH, and #QACTIVE_POST in
file qf.h to provide sender of the events for software tracing.  

11. Added new QS macros (files qs.h and qs_dummy.h) for handling 64-bit
integers. 

12. Added the functions QS::u64() and QS::u64_() and new source file
qs_u64.cpp.

13. Added the QS macro #QS_U32_HEX_T for hexadecimal formatting of
integer numbers in the user-defined trace records. 

14. Added the new port linux64 for 64-bit Linux. Also added the
corresponding examples for 64-bit Linux. 

15. Adapted the QSPY host application for 64-bit pointer sizes and
the changed layout of trace records that contain event information
(such as PoolID and RefCtr). Also added the backwards-compatibility
option (-v) for switching the tool to the previous data format.

16. Removed the tools directory from the QPC distribution and moved
the QSPY host application to the QTOOLS distribution, which now also
contains the GNU make tools for Windows. 

17. Modified the make files and project files to use the environment
variable QPCPP instead of relying on the relative path to the QP/C++
framework.

18. Upgraded the examples for ARM Cortex with IAR EWARM to the
latest IAR EWARM 6.20.


------------------------------------------------------------------------------
@section qpcpp_4_1_07 Version 4.1.07, 2011-02-28

The goal of this release is to improve the ease of experimenting with
QP/C++ on the desktop. This release adds support for Windows (Win32) to
the baseline code. Two most popular compilers for Windows are supported:
Microsoft Visual Studio and MinGW (GNU). The support for Linux has been
improved by including pre-built QP/C++ libraries and improving makefiles
for Eclipse compatibility.

The changes in detail are:

1. Added Win32 port with the Visual C++ 2008 (ports/80x86/win32/vc2008).
This directory contains the Visual Studio solution all_qp.sln for
building all QP/C++ libraries from the IDE. Three build configurations
(Debug, Release, and Spy) are supported.

2. Added Win32 port with the MinGW comiler (ports/80x86/win32/mingw).
This directory contains the Makefile for building all QP/C++ libraries.
Three build configurations (dbg, rel, and spy) are supported.
NOTE: the Makefile assumes that the MinGW/bin directory is added
to the PATH.

3. Added Win32 examples for Visual C++ 2008 (examples/80x86/win32/
vc2008/dpp and examples/80x86/win32/vc2008/qhsmtst). Visual Studio
soultions are provides for all build configurations.

4. Added Win32 examples for MinGW (examples/80x86/win32/mingw/dpp
and examples/80x86/win32/mingw/qhsmtst). Eclipse-compatible makefiles
are provided for all build configurations. NOTE: the Makefiles assume
that the MinGW/bin directory is added to the PATH.

5. Removed memory alignment correction in the file qmp_init.c. This
correction required casting of pointers to integers and was problematic
on 64-bit targets (such as 64-bit Linux).

6. Upgraded the examples for ARM Cortex with CodeSourcery to the
latest Sourcery G++ 2011.02-2.


------------------------------------------------------------------------------
@section qpcpp_4_1_06 Version 4.1.06, 2011-01-07

1. Fixed a bug in the software tracing instrumentation in the function
QF::remove_(), file qf_act.cpp.

2. Made cosmetic improvements to the example QM models of the
"Fly 'n' Shoot" game. 

3. Made improvements in make.bat files for building the examples for
DOS/Open Watcom to run better in DosBox on Linux.

4. Upgraded the examples for ARM Cortex with IAR to the latest
IAR EWARM version 6.10.

5. Upgraded the examples for ARM Cortex with CodeSourcery to the
latest Sourcery G++ 2010.09-66.


------------------------------------------------------------------------------
@section qpcpp_4_1_05 Version 4.1.05, 2010-11-01

This release is adds examples for the QM (QP Modeler) graphical modeling
and code generation tool. The examples are based on the "Fly 'n' Shoot"
game described in the QP/C++ Tutorial and in Chapter 1 of the PSiCC2 book.

Specifically, the directory <qpcpp>/examples/80x86/dos/watcom/l/game-qm/
contains the "Fly 'n' Shoot" game model file "game.qm". This model, when
opened in the QM tool contains all state machine diagrams and generates
code into the subdirectory qm_code/. This code can then be built and
executed on any 80x86 machine (newer versions of Windows or Linux require
the DOSbox application, see http://www.dosbox.com).

The directory <qpcpp>/examples/arm-cortex/vanilla/iar/game-ev-lm3s811-qm/
contains the version of the game for the EV-LM3S811 ARM Cortex-M3 board.
This directory contains the model file "game.qm", which is actually
identical as the model in the DOS version. The LM3S811 version needs to
be compiled with the IAR compiler and executed on the EV-LM3S811 board.

Additionally, the QP/C++ baseline code has been slighlty modified for
better conformance to the MISRA C++ 2008 rules and the latest PC-Lint 9.x. 


------------------------------------------------------------------------------
@section qpcpp_4_1_04 Version 4.1.04, 2010-05-16

This release is adds compatibility of all examples for DOS with the DOSBox
emulator (http://www.dosbox.com/) that recreates a MS-DOS compatible
environment on all versions of Windows, including 64-bit Windows that don't
run 16-bit DOS applications anymore.

Also, this release includes QP ports and examples for EV-LM3S811 board with
the GNU-based Code Sourcery G++ toolset. Support for Sourcery G++ provides
a very cost-effective option for developing QP applications for ARM Cortex
MCUs. 

Finally, this release improves the Cortex Microcontroller Software Interface
Standard (CMSIS) for the whole family of the Stellaris LM3Sxxx MCUs. The
improvement extends the CMSIS from Sandstorm to Fury, DustDevil, and Tempest
Stellaris families.  


------------------------------------------------------------------------------
@section qpcpp_4_1_03 Version 4.1.03, 2010-01-21

This release is concerned with the ARM Cortex ports and examples.
Specifically, this release contains the following improvements:

1. Unified source code for ARM Cortex-M3 and the new ARM Cortex-M0 cores,
including the code for the preemptive QK kernel.

2. Compliance with the Cortex Microcontroller Software Interface Standard
(CMSIS) in all ARM Cortex examples.

3. Backward-compatible support for the new LM3S811 EVAL Rev C board with
different OLED display than previous revisions. (NOTE: The OSRAM 96x16x1 OLED
used in REV A-B boards has been replaced RITEK 96x16x1 OLED used in Rev C.)

In the process of making the examples CMSIS-compliant, the dependency on the
Luminary Micro driver library (driverlib.a) has been completely removed.

Additionally, the screen saver of the "Fly 'n' Shoot" game has been improved
to periodically switch off the power of the OLED display, which better
protects the display from burn-in. The affected file is tunnel.cpp.

Finally, this release introduces the QP_VERSION macro, which identifies the QP
version. Otherwise, this maintenance release does not change the QP/C API in
any way, so the release has NO IMPACT on the QP/C applications except for the
ARM Cortex ports and applications. 


------------------------------------------------------------------------------
@section qpcpp_4_1_02 Version 4.1.02, 2010-01-14

The purpose of this minor maintenance release is the change in the directory
structure for the ARM Cortex ports and examples. As new ARM Cortex cores are
becoming available, the old port name "cortex-m3" could be misleading, because
it actually applies to wider range of ARM Cortex cores. Consequently, all ARM
Cortex ports and examples are hosted in the directory tree called
"arm-cortex".

This maintenance release does not change the QP/C++ API in any way, so the
release has NO IMPACT on the QP/C++ applications except for the ARM Cortex
ports. 


------------------------------------------------------------------------------
@section qpcpp_4_1_01 Version 4.1.01, 2009-11-05

The main purpose of this release is to replace the Turbo C++ 1.01 toolset
with the Open Watcom C/C++ toolset, because Turbo C++ 1.01 is no longer
available for a free download. In contrast, Open Watcom is distributed under
an OSI-certified open source license, which permits free commercial and
non-commercial use. Open Watcom can be downloaded from www.openwatcom.org.

All 80x86/DOS and 80x86/qk ports and examples for Turbo C++ 1.01 have been
replaced with ports and examples for Open Watcom. The make.bat scripts are
provided to build the QP/C++ libraries and examples. 

In the process of converting the examples to Open Watcom two new examples
have been added to the standard QP/C++ distribution. The Calc2 example
located in &lt;qpcpp&gt;/examples/80x86/dos/watcom/l/calc2 shows how to derive
state machine classes with QP 4.x. The SLS example located in
&lt;qpcpp&gt;/examples/80x86/dos/watcom/l/sls shows the implemenation of the
new State-Local Storage state design pattern.


------------------------------------------------------------------------------
@section qpcpp_4_1_00 Version 4.1.00, 2009-10-09

The release provides brings a number of improvements to QP/C++ and updates
the QP/C++ ARM Cortex-M3 examples for the EK-LM3S811 board to the latest
IAR EWARM 5.40. Due to the acquisition of Liminary Micro by Texas Instruments
the directory IAR structure for the examples and drivers has changed and the
QP examples had to be changed accordingly.

This maintenance release does not change the QP/C++ API in any way, so the
release has NO IMPACT on the QP/C++ applications. 

The main changes in QP v4.1.00 with respect to earlier versions are as
follows:

- in qs.h added a new trace record QS_QEP_DISPATCH logged when an event is
dispatched to a state machine. This timestamped trace record marks the
beginning of an RTC step. The end of the RTC step is marked by the existing
timestamped trace records QS_QEP_INTERN_TRAN, QS_QEP_INIT_TRAN, and
QS_QEP_IGNORED, depending on how the event is handled. The new QS_QEP_DISPATCH
record facilitates measurement of the RTC step lengths.
- in qhsm_dis.cpp added generation of the QS_QEP_DISPATCH trace record.
- in the tools/qspy/ sub-directory added output of the new trace record to the
Q-SPY host application.
- in the tools/qspy/matlab/ sub-directory added processing of the new trace
record to the qspy.m script.
- in qpset.h changed the implementation of the Priority Set. In particular,
the QPSet64 now derives from QPSet8, which enables a common way of testing for
non-empty set (e.g., useful in assembly). Also, the findMax() functions in
QPSet8 and QPSet64 now can work with an empty set, in which case they return
0.
- in qk_sched.cpp simplified the QK_schedule_() function to skip the testing
of the ready-set for non-empty condition. Such test is no longer necessary.
The test can still be performed outside the QK_schedule_() function (e.g., in
assembly) to avoid calling the scheduler if the ready set is empty.
- in qk_ext.cpp simplified the QK_scheduleExt_() function in the same way as
QK_schedule_().
- modified make.bat files for building QP libraries in the ports/ directory
to use the externally defined environment variables for the location of the
toolchains. The defaults are applied only when the environment variable is
not defined. This enables greater flexibility in installing the development
tools in different directories than those chosen by Quantum Leaps.
- modified the ARM Cortex-M3 examples for the new IAR EWARM 5.40.
- modified slighlty the Calculator example to allow extensibility.
- in the ARM Cortex-M3 port file qk_port.s added explicit testing of the
QK_readySet_ set for empty condition. This test allows avoiding calling the QK
scheduler and two contex-switches if the ready-set is empty.
- in the game example moved setting up the QS filters from main.cpp to bsp.cpp.


------------------------------------------------------------------------------
@section qpcpp_4_0_04 Version 4.0.04 (Product) Apr 09, 2009

The maintenance release introduces the virtual destructor in the QHsm and 
QFsm base classes. This is done to allow proper handling of virtual functions
in the subclasses of QHsm or QFsm. Please note, however, that the change
increases the size of every state machine object by the additional (hidden)
virtual pointer (vptr).

Also, this release provides a fix for the compile-time assertions, which did
not work correctly for the GNU compiler family.

Finally, the ARM Cortex-M3 examples have been recompiled with the newer
IAR EWARM v5.30.  

This maintenance release does not change the QP/C++ API in any way, so the
release has NO IMPACT on the QP/C++ applications. 

The main changes in QP v4.0.04 with respect to earlier version are as follows:

- in qep.h file, virtual destructors have been added to QFsm and QHsm.
- in qassert.h file the #Q_ASSERT_COMPILE macro has been modified to render
a negative array dimension when the asserted condition is not TRUE.


------------------------------------------------------------------------------
@section qpcpp_4_0_03 Version 4.0.03, 2008-12-27

The main purpose of this release is to fix a bug in the QK preemptive kernel,
which occurs only when the advanced QK features are used. Specifically, the QK
priority-ceiling mutex could interfere with QK thread-local storage (TLS) or
QK extended context switch. When the QK mutex is in use, the TLS or the
extended context for this task could get saved to an incorrect priority level.

The release 4.0.03 fixes the bug by strictly preserving the semantics of
QK_currPrio_ variable. The mutex locking now uses a different variable
QK_ceilingPrio_, which represents the ceiling-priority locked by the mutex.
The QK scheduler and extended scheduler now perform an additional check to
make sure that only tasks with priorities above the ceiling can run. To avoid
that additional overhead, the user can define the macro QK_NO_MUTEX, which
eliminates the QK mutex API and eliminates the additional tests in the QK
schedulers.

This maintenance release does not change the QP/C++ API in any way, so the
release has NO IMPACT on the QP/C++ applications. 

The main changes in QP v4.0.03 with respect to earlier version are as follows:

- in qk.h file, made the QK mutex API only visible when the macro QK_NO_MUTEX
is *not* defined.
- in qk_pkg.h file, added the QK_ceilingPrio_ external declaration when the
macro QK_NO_MUTEX is not defined.
- in qk_mutex.cpp file, changed priority-ceiling mutex implementation to use
the QK_ceilingPrio_ instead of QK_currPrio_. Also, added compiler error when
the macro QK_NO_MUTEX is definedthis and this file is included in the build.
- in qk_sched.cpp file added testing priority against the QK_ceilingPrio_,
when the macro QK_NO_MUTEX is not defined.
- in qk_ext.cpp file added testing priority against the QK_ceilingPrio_,
when the macro QK_NO_MUTEX is not defined.


------------------------------------------------------------------------------
@section qpcpp_4_0_02 Version 4.0.02, 2008-11-15

This maintenance release does not change the QP/C API in any way, so the
release has NO IMPACT on the QP/C++ applications.

The main changes in QP v4.0.02 with respect to earlier version are as follows:

- in qep.h file, added comments to macros Q_TRAN() and Q_SUPER() to suppress
the PC-lint warining about using the comma-operator (MISRA rule 42).
- in qhsm_in.cpp file, fixed a bug in the QHsm::isIn() function. - fixed a bug
in tunnel.cpp file ("Fly 'n' Shoot" game). The constant event HIT_WALL was not
declared static.


------------------------------------------------------------------------------
@section qpcpp_4_0_01 Version 4.0.01, 2008-06-09

This maintenace release is made to allow using QS software tracing with
the GNU compiler for AVR (WinAVR). Specifically, the output of the strings
residing in ROM has been fixed.

This maintenance release does not change the QP/C++ API in any way, so the
release has NO IMPACT on the QP/C++ applications. 

The main changes in QP v4.0.01 with respect to earlier version are as follows:

- in qs_.cpp file, updated the function QS::str_ROM_().
- in qs_str.cpp file, updated the function QS::str_ROM().
- in qvanilla.cpp file, funciton QF::run(), declared the temporary variables
as static to save stack space, because QF::run() never returns and is not
reentrant.


------------------------------------------------------------------------------
@section qpcpp_4_0_00 Version 4.0.00, 2008-04-07

This milestone release is made for the book /ref PSiCC2. The book describes in
great detail this new release. The older "QP Programmer's Manual" is now
phased out and is replaced with this hyper-linked
/ref main_page "QP/C++ Reference Manual", which provides very detailed, easily
searchable reference to the software. The book /ref PSiCC2 provies in-depth
discussion of the relevant concepts as well as the design study of QP v4.0.

The main changes in QP v4.0 with respect to earlier versions are as follows:

- the coding techniques for hierarchical state machines (HSMs) and the simpler
finite state machines (FSMs) have changed. While the changes are quite simple,
the backward compatibility with QEP 3.x has been broken, meaning that some
manual changes to the state machines implemented with earlier versions are
necessary. Please refer to the "QP/C++ Tutorial" Section /ref coding_hsm for
more information about coding state machines with QEP 4.x.
    - The main change is the signature of a state-handler function, which now
    returns simply a byte. This return type (typedef'ed as QState) is the
    status of the event-handling that the state handler conveys to the QEP
    event processor.
    - The macro #Q_TRAN() must now always follow the return statement.
    - The new macro #Q_SUPER() designates the superstate of the given state.
    Again, this macro must follow the return statement.
    - Then two new macros #Q_HANDLED() and #Q_IGNORED() have been added to
    return the status of event handled and event ignored, respectively.

- all callback functions are now consistently called /c XXX_onYYY() or
/c XXX::onYYY():
    - Q_assert_handler() is now Q_onAssert()
    - QF::start() is now QF::onStartup()
    - QF::cleanup() is now QF::onCleanup()

- the new header file qevent.h has been broken off the qep.h header file.
qevent.h contains the QEvent class and other basic facilities used in the
whole QP. This new file allows easier replacement of the entire QEP event
processor with custom event processors, if you wish do so.
- the macro QEP_SIGNAL_SIZE is renamed to #Q_SIGNAL_SIZE.
- the data type QSTATE is now deprecated. Please use QP::QState.
- the #QF_FSM_ACTIVE macro is now deprecated. Instead, please define
#QF_ACTIVE_SUPER_ to the base class of QP::QActive and #QF_ACTIVE_STATE_ to the
data type represented state. By default, these macros are defined to use the
QP::QHsm base class from the QEP hierarchical event processor, but you can
replace the event processor, if you wish.
- the internal macro QACTIVE_OSOBJECT_WAIT_() is now #QACTIVE_EQUEUE_WAIT_().
- the internal macro QACTIVE_OSOBJECT_SIGNAL_() is now
#QACTIVE_EQUEUE_SIGNAL_().
- the internal macro QACTIVE_OSOBJECT_ONIDLE_() is now
#QACTIVE_EQUEUE_ONEMPTY_().
- the data mebers QActive::m_osObject and QActive::m_thread are now present
only if the macros #QF_OS_OBJECT_TYPE and #QF_THREAD_TYPE are defined.
- the QP::QPSet class has been renamed to QP::QPSet64.
- the QPSet::hasElements() has been renamed QPSet64::notEmpty()
- the QS software tracing is now better integrated with all QP components. You
no longer need to explicitly include qs_port.h, because it is automatically
included when you define the macro #Q_SPY. Also the file qs_dummy.h is
included automatically when the macro #Q_SPY is <STRONG>not</STRONG> defined.
- the new header file qvanilla.h now replaces the file qsched.h.
- the macros QF_SCHED_LOCK() and QF_SCHED_UNLOCK() are now obsolete.
- the native QF event queues (both the active object event queues and the
"raw" thread-safe queues) are slightly more efficient by counting down the
/c head and /c tail pointers rather than up. This leads to wrap-around at
zero, which is easier (faster) to test than any other wrap-around point.
Also the native QF event queues maintain the minimum of the free events in the
queue rather the maximum of used events.
- the data member of QEQueue::nTot class is removed.
- the QF::publish() function has been re-written so that QF no does <STRONG>not
need to lock the scheduler</STRONG>. The QF::publish() function posts events
to active objects with scheduler unlocked starting from the highest-priority
active objects. However, the event is protected from inadvertent recycling by
incrementing its reference counter before the publish operation. After the
event  is posted to all subscribers, the garbage collector QF::gc() is called
to decrement the reference counter and recycle the event, if necessary.
- the qf_run.cpp file is obsolete. The QF::run() function for the cooperative
"vanilla" kernel is now implemented in the file qvanilla.cpp.
- the QF::tick() function has been rewritten to allow calling QF::tick() from 
the task context as well as from the interrupt context. The nested critical
section around QF::tick() is no longer needed when it is called from the task
level. Among others, this re-design <STRONG>eliminates the need for the 
recursive</STRONG> mutex in the POSIX QF port.
- the QMPool::init() function has been re-designed to optimally align the
memory buffer in a portable and platform-independent way. This should bring
some performance improvements on some CPUs (e.g., 80x86).
- the extended QK scheduler has been re-designed to save stack space. The
extended context (e.g., coprocessor registers) are no longer saved on the
precious stack, but rather in the active object.
- a bug has been fixed in handling of Thread-Local Storage (TLS) in the QK
scheduler and extended scheduler.

- the -q (quiet) flag has been added to the QSPY host application.
- the support for two new compilers for Windows has been added for the QSPY
host application. The application can now be build with the MinGW GNU compiler
for Windows as well as the Microsoft Visual C++ 2005.

- the QP port to Linux has been improved by eliminating the need for recursive
P-Thread mutex.

- the QP port to MicroC/OS-II has been upgraded to the latest version 2.86.

- all examples in the standard QP distribution have been cleaned up and
updated to the latest QP API changes.
- all examples that use QF now contain the QS software tracing support.

*/

} // namespace QP
