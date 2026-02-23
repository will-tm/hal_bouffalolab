/*
 * Copyright (C) Bouffalo Lab 2016-2018
 * SPDX-License-Identifier: Apache-2.0
 *
 * Register access macros — ported from M1s SDK.
 */

#ifndef REG_ACCESS_H_
#define REG_ACCESS_H_

#include "lmac_types.h"

#define RAM_LMAC_FW_ADDR       0x00000000
#define SHARED_RAM_START_ADDR  0x00000000
#define IPC_REG_BASE_ADDR      0x00800000
#define SYSCTRL_SIGNATURE_ADDR 0x00900000

/* Macros for IPC registers access (used in reg_ipc_app.h) */
#define REG_IPC_APP_RD(env, INDEX) (*(volatile u32 *)((u8 *)env + IPC_REG_BASE_ADDR + 4 * (INDEX)))

#define REG_IPC_APP_WR(env, INDEX, value)                                                          \
	(*(volatile u32 *)((u8 *)env + IPC_REG_BASE_ADDR + 4 * (INDEX)) = value)

#define REG_PL_RD(addr) 0
#define REG_PL_WR(addr, value)

#endif /* REG_ACCESS_H_ */
