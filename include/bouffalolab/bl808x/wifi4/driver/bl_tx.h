/*
 * Copyright (C) Bouffalo Lab 2016-2018
 * SPDX-License-Identifier: Apache-2.0
 *
 * TX path — ported from M1s SDK.
 * Replaces lwIP includes with minimal definitions.
 */

#ifndef __RWNX_TX_H__
#define __RWNX_TX_H__

#include "lmac_types.h"
#include "ipc_shared.h"
#include "bl_utils.h"

typedef void (*bl_custom_tx_callback_t)(void *cb_arg, bool tx_ok);

struct bl_custom_tx_cfm {
	bl_custom_tx_callback_t cb;
	void *cb_arg;
};

struct ke_tx_fc {
	uint8_t vif_bits;
	struct {
		uint8_t fc_chan;
		uint8_t fc_ps_sta_bits;
	} ap;
	struct {
		uint8_t fc_chan;
		uint8_t fc_ps;
	} sta;
};

union bl_hw_txstatus {
	struct {
		u32 tx_done: 1;
		u32 retry_required: 1;
		u32 sw_retry_required: 1;
		u32 reserved: 29;
	};
	u32 value;
};

struct bl_txhdr {
	union bl_hw_txstatus status;
	uint32_t *p;
	struct hostdesc host;
	struct bl_custom_tx_cfm custom_cfm;
};

/* Forward declarations — full implementations in milestone 4 */
struct bl_hw;
struct netif;
struct pbuf;

int bl_txdatacfm(void *pthis, void *host_id);
void bl_tx_try_flush(int param, struct ke_tx_fc *tx_fc_field);

/* Send a raw Ethernet frame through the firmware TX path */
int bl_output_raw(const uint8_t *frame, uint16_t len, uint8_t vif_idx, uint8_t sta_idx);

#endif /* __RWNX_TX_H__ */
