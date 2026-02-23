/*
 * Copyright (C) Bouffalo Lab 2016-2018
 * SPDX-License-Identifier: Apache-2.0
 *
 * IPC APP register access — ported from M1s SDK.
 */

#ifndef _REG_IPC_APP_H_
#define _REG_IPC_APP_H_

#include "lmac_types.h"
#include "ipc_compat.h"
#include "reg_access.h"

#define REG_WIFI_REG_BASE 0x24000000

#define REG_IPC_APP_DECODING_MASK 0x0000007F

#define IPC_APP2EMB_TRIGGER_INDEX      0x00000000
#define IPC_EMB2APP_RAWSTATUS_INDEX    0x00000001
#define IPC_EMB2APP_ACK_INDEX          0x00000002
#define IPC_EMB2APP_UNMASK_SET_INDEX   0x00000003
#define IPC_EMB2APP_UNMASK_CLEAR_INDEX 0x00000004
#define IPC_EMB2APP_STATUS_INDEX       0x00000007
#define IPC_APP_SIGNATURE_INDEX        0x00000010

#ifndef __INLINE
#define __INLINE inline
#endif

static __INLINE void ipc_app2emb_trigger_set(u32 value)
{
	REG_IPC_APP_WR(REG_WIFI_REG_BASE, IPC_APP2EMB_TRIGGER_INDEX, value);
}

static __INLINE void ipc_app2emb_trigger_setf(u32 app2embtrigger)
{
	REG_IPC_APP_WR(REG_WIFI_REG_BASE, IPC_APP2EMB_TRIGGER_INDEX, app2embtrigger);
}

static __INLINE u32 ipc_emb2app_rawstatus_get(void)
{
	return REG_IPC_APP_RD(REG_WIFI_REG_BASE, IPC_EMB2APP_RAWSTATUS_INDEX);
}

static __INLINE void ipc_emb2app_ack_clear(u32 value)
{
	REG_IPC_APP_WR(REG_WIFI_REG_BASE, IPC_EMB2APP_ACK_INDEX, value);
}

static __INLINE void ipc_emb2app_unmask_set(u32 value)
{
	REG_IPC_APP_WR(REG_WIFI_REG_BASE, IPC_EMB2APP_UNMASK_SET_INDEX, value);
}

static __INLINE void ipc_emb2app_unmask_clear(u32 value)
{
	REG_IPC_APP_WR(REG_WIFI_REG_BASE, IPC_EMB2APP_UNMASK_CLEAR_INDEX, value);
}

static __INLINE u32 ipc_emb2app_status_get(void)
{
	return REG_IPC_APP_RD(REG_WIFI_REG_BASE, IPC_EMB2APP_STATUS_INDEX);
}

static __INLINE u32 ipc_app_signature_get(void)
{
	return REG_IPC_APP_RD(REG_WIFI_REG_BASE, IPC_APP_SIGNATURE_INDEX);
}

static __INLINE void ipc_app_signature_set(u32 value)
{
	REG_IPC_APP_WR(REG_WIFI_REG_BASE, IPC_APP_SIGNATURE_INDEX, value);
}

#endif /* _REG_IPC_APP_H_ */
