//****************************************************************************
// Product: QP/C++ example for DPP-console example with Qt5
// Last Updated for Version: QP/C++ 5.4.0/Qt 5.x
// Last updated on  2015-05-03
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
#include <QCoreApplication>
//-----------------
#include "qp_port.h"
#include "dpp.h"
#include "bsp.h"

//............................................................................
static QP::QEvt const *l_philoQueueSto[N_PHILO][N_PHILO];
static QP::QEvt const *l_tableQueueSto[N_PHILO];
static QP::QSubscrList l_subscrSto[DPP::MAX_PUB_SIG];

// storage for event pools...
static QF_MPOOL_EL(DPP::TableEvt) l_smlPoolSto[2*N_PHILO]; // small pool

//............................................................................
int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv); // console Qt application

    QP::QF::init(); // initialize the framework
    BSP_init();     // initialize the BSP

    // object dictionaries...
    QS_OBJ_DICTIONARY(l_smlPoolSto);

    QP::QF::psInit(l_subscrSto, Q_DIM(l_subscrSto)); // init publish-subscribe

    // initialize event pools...
    QP::QF::poolInit(l_smlPoolSto,
                     sizeof(l_smlPoolSto), sizeof(l_smlPoolSto[0]));

    // start the active objects...
    for (uint_fast8_t n = 0U; n < N_PHILO; ++n) {
        DPP::AO_Philo[n]->start((uint_fast8_t)(n + 1),
                                l_philoQueueSto[n], Q_DIM(l_philoQueueSto[n]),
                                (void *)0, 1024U*4U);
    }
    DPP::AO_Table->start((uint_fast8_t)(N_PHILO + 1),
                         l_tableQueueSto, Q_DIM(l_tableQueueSto),
                         (void *)0, 1024U*4U);

    return QP::QF::run(); // calls qApp->exec()
}
