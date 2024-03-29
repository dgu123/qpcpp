/// @file
/// @brief QEP/C++ port to  AVRmega, GNU-AVR toolset
/// @cond
///***************************************************************************
/// Last updated for version 5.4.0
/// Last updated on  2015-03-14
///
///                    Q u a n t u m     L e a P s
///                    ---------------------------
///                    innovating embedded systems
///
/// Copyright (C) Quantum Leaps, www.state-machine.com.
///
/// This program is open source software: you can redistribute it and/or
/// modify it under the terms of the GNU General Public License as published
/// by the Free Software Foundation, either version 3 of the License, or
/// (at your option) any later version.
///
/// Alternatively, this program may be distributed and modified under the
/// terms of Quantum Leaps commercial licenses, which expressly supersede
/// the GNU General Public License and are specifically designed for
/// licensees interested in retaining the proprietary status of their code.
///
/// This program is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
/// GNU General Public License for more details.
///
/// You should have received a copy of the GNU General Public License
/// along with this program. If not, see <http://www.gnu.org/licenses/>.
///
/// Contact information:
/// Web:   www.state-machine.com
/// Email: info@state-machine.com
///***************************************************************************
/// @endcond

#ifndef qep_port_h
#define qep_port_h

// the macro 'PROGMEM' allocates const objects to ROM
#define Q_ROM  PROGMEM

// the macros 'Q_ROM_' for reading data from ROM
#define Q_ROM_BYTE(rom_var_)    pgm_read_byte_near(&(rom_var_))
#define Q_ROM_OBJ_PTR(rom_var_) pgm_read_word_near(&(rom_var_))
#define Q_ROM_FUN_PTR(rom_var_) pgm_read_word_near(&(rom_var_))

#include <stdint.h>   // Exact-width types. WG14/N843 C99 Standard

#include <avr\pgmspace.h> // accessing data in the program memory (PROGMEM)

#include "qep.h" // QEP platform-independent public interface

#endif // qep_port_h
