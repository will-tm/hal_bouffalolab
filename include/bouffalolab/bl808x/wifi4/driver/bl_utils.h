/*
 * Copyright (C) Bouffalo Lab 2016-2018
 * SPDX-License-Identifier: Apache-2.0
 *
 * Utility functions — ported from M1s SDK.
 */

#ifndef __RWNX_UTILS_H__
#define __RWNX_UTILS_H__

#include "bl_defs.h"

#define RWNX_DBG(a...)                                                                             \
	do {                                                                                       \
	} while (0)

#define RWNX_FN_ENTRY_STR ">>> %s()\r\n", __func__
#define RWNX_FN_LEAVE_STR "<<< %s()\r\n", __func__

#define RWNX_RXBUFF_PATTERN               (0xCAFEFADE)
#define RWNX_RXBUFF_VALID_IDX(idx)        ((idx) < RWNX_RXBUFF_MAX)
#define RWNX_RXBUFF_IDX_TO_HOSTID(idx)    ((idx) + 1)
#define RWNX_RXBUFF_HOSTID_TO_IDX(hostid) ((hostid) - 1)
#define RWNX_RXBUFF_DMA_ADDR_GET(skbuff)  skbuff->payload

struct bl_e2amsg_elem {
	struct ipc_e2a_msg *msgbuf_ptr;
	u32 dma_addr;
};

struct bl_dbg_elem {
	struct ipc_dbg_msg *dbgbuf_ptr;
	u32 dma_addr;
};

int bl_ipc_init(struct bl_hw *bl_hw, struct ipc_shared_env_tag *ipc_shared_mem);
uint32_t *bl_utils_pbuf_alloc(void);
void bl_utils_pbuf_free(uint32_t *p);
int bl_utils_idx_lookup(struct bl_hw *bl_hw, uint8_t *mac);

#endif /* __RWNX_UTILS_H__ */
