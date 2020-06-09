/*****************************************************************************
* Product: SST example, 80x86, Turbo C++ 1.01
*
* Copyright (C) 2006 Miro Samek and Robert Ward. All rights reserved.
*
* This software may be distributed and modified under the terms of the GNU
* General Public License version 2 (GPL) as published by the Free Software
* Foundation and appearing in the file GPL.TXT included in the packaging of
* this file. Please note that GPL Section 2[b] requires that all works based
* on this software must also be made publicly available under the terms of
* the GPL ("Copyleft").
*
* Contact information:
* Email:    miro@quantum-leaps.com
* Internet: www.quantum-leaps.com
*****************************************************************************/
#ifndef sst_port_h
#define sst_port_h

#include <libopencm3/cm3/cortex.h>

/* SST interrupt locking/unlocking */
#define SST_INT_LOCK() cm_disable_interrupts()
#define SST_INT_UNLOCK() cm_enable_interrupts()
/*SST End of Interrupt Command*/

#endif
