/*
 * Copyright (C) Bouffalo Lab 2016-2018
 * SPDX-License-Identifier: Apache-2.0
 *
 * IPC shared memory structures — ported from M1s SDK.
 */

#ifndef _IPC_SHARED_H_
#define _IPC_SHARED_H_

#include <bl60x_fw_api.h>
#include "ipc_compat.h"
#include "lmac_types.h"
#include "lmac_mac.h"

/* Config defines needed by the blob */
#ifndef CFG_TXDESC
#define CFG_TXDESC 4
#endif

#ifndef CFG_STA_MAX
#define CFG_STA_MAX 4
#endif

#ifndef CFG_CHIP_BL808
#define CFG_CHIP_BL808 1
#endif

#define CO_BIT(pos)     (1U << (pos))
#define NX_TXQ_CNT      4
#define CONFIG_USER_MAX 1

#define IPC_TXQUEUE_CNT NX_TXQ_CNT
#define NX_TXDESC_CNT0  CFG_TXDESC
#define NX_TXDESC_CNT1  CFG_TXDESC
#define NX_TXDESC_CNT2  CFG_TXDESC
#define NX_TXDESC_CNT3  CFG_TXDESC
#define NX_TXDESC_CNT4  CFG_TXDESC

#define IPC_RXBUF_CNT      2
#define IPC_RXDESC_CNT     2
#define IPC_RADARBUF_CNT   4
#define IPC_RXBUF_SIZE     2048
#define IPC_MSGE2A_BUF_CNT 8
#define IPC_DBGBUF_CNT     4

#define IPC_A2E_MSG_BUF_SIZE   127
#define IPC_E2A_MSG_PARAM_SIZE (257 - 4 - 8)
#define IPC_DBG_PARAM_SIZE     256

#define RX_DMA_OVER_PATTERN      0xAAAAAA00
#define IPC_MSGE2A_VALID_PATTERN 0xADDEDE2A
#define IPC_DBG_VALID_PATTERN    0x000CACA0

#define DMA_HDR_PHYVECT_LEN 36
#define NX_TX_PAYLOAD_MAX   6

/// Descriptor filled by the Host
struct hostdesc {
	uint32_t pbuf_addr;
	uint32_t packet_addr;
	uint16_t packet_len;
	uint32_t status_addr;
	struct mac_addr eth_dest_addr;
	struct mac_addr eth_src_addr;
	uint16_t ethertype;
	uint16_t pn[4];
	uint16_t sn;
	uint16_t timestamp;
	uint8_t tid;
	uint8_t vif_idx;
	uint8_t staid;
	uint16_t flags;
	uint32_t pbuf_chained_ptr[4];
	uint32_t pbuf_chained_len[4];
};

struct txdesc_host {
	uint32_t ready;
#if defined(CFG_CHIP_BL808) || defined(CFG_CHIP_BL606P)
	uint32_t eth_packet[1600 / 4];
#endif
	struct hostdesc host;
	uint32_t pad_txdesc[204 / 4];
	uint32_t pad_buf[400 / 4];
};

struct phy_channel_info {
	uint32_t info1;
	uint32_t info2;
};

/// Message structure for MSGs from Emb to App
struct ipc_e2a_msg {
	ke_msg_id_t id;
	ke_task_id_t dummy_dest_id;
	ke_task_id_t dummy_src_id;
	uint32_t param_len;
	uint32_t param[IPC_E2A_MSG_PARAM_SIZE];
	uint32_t pattern;
};

/// Message structure for MSGs from App to Emb
struct ipc_a2e_msg {
	uint32_t dummy_word;
	uint32_t msg[IPC_A2E_MSG_BUF_SIZE];
};

struct ipc_shared_env_tag {
	volatile struct ipc_a2e_msg msg_a2e_buf;
	volatile uint32_t pattern_addr;
	volatile struct txdesc_host txdesc0[NX_TXDESC_CNT0];
};

extern struct ipc_shared_env_tag ipc_shared_env;

/* IPC IRQ masks */
#define IPC_IRQ_A2E_TXDESC          0xFF00
#define IPC_IRQ_A2E_TXDESC_FIRSTBIT (8)
#define IPC_IRQ_A2E_RXBUF_BACK      CO_BIT(5)
#define IPC_IRQ_A2E_RXDESC_BACK     CO_BIT(4)
#define IPC_IRQ_A2E_MSG             CO_BIT(1)
#define IPC_IRQ_A2E_DBG             CO_BIT(0)
#define IPC_IRQ_A2E_ALL             (IPC_IRQ_A2E_TXDESC | IPC_IRQ_A2E_MSG | IPC_IRQ_A2E_DBG)

#define IPC_IRQ_E2A_TXCFM_POS 7
#define IPC_IRQ_E2A_TXCFM     ((1 << NX_TXQ_CNT) - 1) << IPC_IRQ_E2A_TXCFM_POS

#define IPC_IRQ_E2A_RADAR     CO_BIT(6)
#define IPC_IRQ_E2A_TBTT_SEC  CO_BIT(5)
#define IPC_IRQ_E2A_TBTT_PRIM CO_BIT(4)
#define IPC_IRQ_E2A_RXDESC    CO_BIT(3)
#define IPC_IRQ_E2A_MSG_ACK   CO_BIT(2)
#define IPC_IRQ_E2A_MSG       CO_BIT(1)
#define IPC_IRQ_E2A_DBG       CO_BIT(0)

#define IPC_IRQ_E2A_ALL                                                                            \
	(IPC_IRQ_E2A_TXCFM | IPC_IRQ_E2A_RXDESC | IPC_IRQ_E2A_MSG_ACK | IPC_IRQ_E2A_MSG |          \
	 IPC_IRQ_E2A_DBG | IPC_IRQ_E2A_TBTT_PRIM | IPC_IRQ_E2A_TBTT_SEC | IPC_IRQ_E2A_RADAR)

#endif /* _IPC_SHARED_H_ */
