/*
 *   Copyright (C) 2015,2016 by Jonathan Naylor G4KLX
 *   Copyright (C) 2016 by Colin Durbridge G4EML
 *   Copyright (C) 2016,2017,2018 by Andy Uribe CA6JAU
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "Config.h"
#include "Globals.h"

// Global variables
bool m_tx  = false;
bool m_dcd = false;

CPOCSAGRX   pocsagRX;
CPOCSAGTX   pocsagTX;

CBCH3121    pocsagFEC;

CPOCSAGDecoder pocsagDec;
CPOCSAGEncoder pocsagEnc;

CIO io;

CSerialPort serial;

CDisplay display;

void setup()
{
  io.start();
  serial.start();
  display.init();
  io.setFreq(FREQ_RX, FREQ_TX, 255U);
  io.ifConf();
}

void loop()
{
  io.process();
  pocsagDec.process();
  pocsagTX.process();
  serial.process();
}
