namespace QP {

/*! @page exa_apps Example Applications

<p>To demonstrate QP/C features, you need to create an application that does "something interesting". Instead of inventing this "something interesting" for each and every example, most of the example projects implement one of the three example applications, which are described on the separate pages:
</p>

- @subpage blinky
- @subpage dpp
- @subpage game

Additionally, the QP/C distribution contains several application examples described in the <a class="extern" target="_blank" href="http://www.state-machine.com/psicc2">PSiCC2</a> book.

- Calculator
- QHsmTst
- PELICAN
- ...

*/

/*##########################################################################*/
/*! @page blinky Simple Blinky Application

<p>The ultra-simple Blinky example is the embedded systems' equivalent of the venerable <i>"Hello World!"</i> program, that is, the simplest possible working QP application that does "something". In the case of Blinky, this "something" is blinking an LED at the rate of 1Hz, where an LED turns on and remains on for 0.5 seconds on then turns off and remains off for 0.5 seconds.
</p>

@image html blinky_ek-tm4c123gxl.gif Blinky on EK-TM4C123GLX (TivaC LaunchPad)

The ultra-simple Blinky application, which  consists of just one active object named `Blinky`, is intentionally kept small and illustrates only the most basic QP features, such as:

- defining a simple Blinky active object (AO) @ref oop "class";
- hand-coding the simple state machine of the Blinky AO;
- using a periodic time event;
- initializing the QP framework; and
- starting an AO.


------------------------------------------------------------------------------
@section blinky_sm State Machine
The very simple state machine of the Blinky AO is shown in the figure below:

@image html SM_blinky.png "State Machine of the Blinky AO"

<ul class="tag">
  <li><span class="tag">1</span> The top-most initial transition in this state machine arms a QP time event (QTimeEvt_armX()) to deliver the `TIMEOUT` signal every half second, so that the LED can stay on for one half second and off for the other half.
  </li>

  <li><span class="tag">2</span> The initial transition leads to state "off", which turns the LED off in the entry action  (`BSP_ledOff()`).
  </li>

  <li><span class="tag">3</span> When the `TIMEOUT` event arrives in the "off" state, the "off" state transitions to the "on" state
  </li>
  
  <li><span class="tag">4</span> The "on" state turns the LED on in the entry action (`BSP_ledOn()`).
  </li>
  
  <li><span class="tag">5</span> When the `TIMEOUT` event arrives in the "on" state, the "on" state transitions back to "off", which cases execution of the entry action, in which the LED is turned off. From that point on the cycle repeats forever because the `TIMEOUT` events keep getting generated at the pre-determined rate.
  </li>
</ul>

@image html under_construction.jpg

@next{dpp}
*/
/*##########################################################################*/
/*! @page dpp Dining Philosophers Problem (DPP)

@image html dpp_win32.jpg

@image html under_construction.jpg

@next{game}
*/

/*##########################################################################*/
/*! @page game "Fly 'n' Shoot" Game

@image html game_win32.jpg

@image html under_construction.jpg

*/

} // namespace QP

