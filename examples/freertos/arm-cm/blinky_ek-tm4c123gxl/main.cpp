//****************************************************************************
// Product: Simple Blinky example, FreeRTOS.org kernel
// Last Updated for Version: 5.4.0
// Date of the Last Update:  2015-05-11
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
// Web  : http://www.state-machine.com
// Email: info@state-machine.com
//****************************************************************************
#include "qpcpp.h"
#include "bsp.h"
#include "blinky.h"

int main() {
    static QEvt const *blinkyQSto[10]; // Event queue storage for Blinky

    BSP_init(); // initialize the Board Support Package
    QF::init(); // initialize the framework and the underlying RT kernel

    // publish-subscribe not used, no call to QF::psInit()
    // dynamic event allocation not used, no call to QF::poolInit()

    // instantiate and start the active objects...
    AO_Blinky->start(1U, // priority
        blinkyQSto, Q_DIM(blinkyQSto), // event queue
        static_cast<void *>(0), // stack storage (not used in FreeRTOS)
        512U);                  // stack size [bytes] (needed in FreeRTOS)

    return QF::run(); // run the QF application
}
