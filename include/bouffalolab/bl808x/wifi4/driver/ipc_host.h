/*
 * Copyright (C) Bouffalo Lab 2016-2018
 * SPDX-License-Identifier: Apache-2.0
 *
 * IPC host environment — ported from M1s SDK.
 */

#ifndef __IPC_HOST_H__
#define __IPC_HOST_H__

#include <stdint.h>
#include "ipc_shared.h"

enum ipc_host_desc_status {
	IPC_HOST_DESC_IDLE = 0,
	IPC_HOST_DESC_FORWARD,
	IPC_HOST_DESC_KEEP,
	IPC_HOST_DESC_DELETE,
	IPC_HOST_DESC_LEN_UPDATE,
};

struct ipc_host_cb_tag {
	int (*send_data_cfm)(void *pthis, void *host_id);
	uint8_t (*recv_data_ind)(void *pthis, void *host_id);
	uint8_t (*recv_radar_ind)(void *pthis, void *host_id);
	uint8_t (*recv_msg_ind)(void *pthis, void *host_id);
	uint8_t (*recv_msgack_ind)(void *pthis, void *host_id);
	uint8_t (*recv_dbg_ind)(void *pthis, void *host_id);
	void (*prim_tbtt_ind)(void *pthis);
	void (*sec_tbtt_ind)(void *pthis);
};

struct ipc_hostbuf {
	void *hostid;
	uint32_t dma_addr;
};

struct ipc_host_env_tag {
	struct ipc_host_cb_tag cb;
	struct ipc_shared_env_tag *shared;

	struct ipc_hostbuf ipc_host_rxdesc_array[IPC_RXDESC_CNT];
	uint8_t ipc_host_rxdesc_idx;
	uint8_t rxdesc_nb;

	uint8_t ipc_host_rxbuf_idx;
	uint32_t rx_bufnb;
	uint32_t rx_bufsz;

	uint32_t txdesc_free_idx;
	uint32_t txdesc_used_idx;
	void *tx_host_id0[NX_TXDESC_CNT0];
	void **tx_host_id;
	volatile struct txdesc_host *txdesc;

	struct ipc_hostbuf ipc_host_msgbuf_array[IPC_MSGE2A_BUF_CNT];
	uint8_t ipc_host_msge2a_idx;
	uint32_t ipc_e2amsg_bufnb;
	uint32_t ipc_e2amsg_bufsz;

	uint8_t msga2e_cnt;
	void *msga2e_hostid;

	struct ipc_hostbuf ipc_host_dbgbuf_array[IPC_DBGBUF_CNT];
	uint8_t ipc_host_dbg_idx;
	uint32_t ipc_dbg_bufnb;
	uint32_t ipc_dbg_bufsz;

	void *pthis;
};

void ipc_host_init(struct ipc_host_env_tag *env, struct ipc_host_cb_tag *cb,
		   struct ipc_shared_env_tag *shared_env_ptr, void *pthis);
int ipc_host_msg_push(struct ipc_host_env_tag *env, void *msg_buf, uint16_t len);
uint32_t ipc_host_get_status(struct ipc_host_env_tag *env);
uint32_t ipc_host_get_rawstatus(struct ipc_host_env_tag *env);
volatile struct txdesc_host *ipc_host_txdesc_get(struct ipc_host_env_tag *env);
void ipc_host_txdesc_push(struct ipc_host_env_tag *env, void *host_id);
void ipc_host_irq(struct ipc_host_env_tag *env, uint32_t status);
void ipc_host_enable_irq(struct ipc_host_env_tag *env, uint32_t value);
void ipc_host_disable_irq(struct ipc_host_env_tag *env, uint32_t value);
int ipc_host_msgbuf_push(struct ipc_host_env_tag *env, void *hostid, uint32_t hostbuf);
void ipc_host_patt_addr_push(struct ipc_host_env_tag *env, uint32_t addr);
int ipc_host_rxbuf_push(struct ipc_host_env_tag *env, uint32_t hostid, uint32_t hostbuf);
int ipc_host_rxdesc_push(struct ipc_host_env_tag *env, void *hostid, uint32_t hostbuf);
int ipc_host_txdesc_left(struct ipc_host_env_tag *env, const int queue_idx, const int user_pos);

#endif /* __IPC_HOST_H__ */
