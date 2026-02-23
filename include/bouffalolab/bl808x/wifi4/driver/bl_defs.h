/*
 * Copyright (C) Bouffalo Lab 2016-2018
 * SPDX-License-Identifier: Apache-2.0
 *
 * Main driver structures — ported from M1s SDK.
 */

#ifndef __RWNX_DEFS_H__
#define __RWNX_DEFS_H__

#include <errno.h>
#include "ipc_host.h"
#include "ipc_shared.h"
#include "bl_cmds.h"
#include "bl_mod_params.h"
#include "ieee80211.h"
#include "cfg80211.h"
#include "nl80211.h"
#include "utils_list.h"

#define ETH_ALEN  6
#define ETH_P_PAE 0x888E

#define RWNX_RXBUFF_MAX         (4 * 1)
#define IEEE80211_MIN_AMPDU_BUF 0x8
#define IEEE80211_MAX_AMPDU_BUF 0x40
#ifndef CFG_VIRT_DEV_MAX
#define CFG_VIRT_DEV_MAX 2
#endif

#define NX_VIRT_DEV_MAX         CFG_VIRT_DEV_MAX
#define NX_REMOTE_STA_MAX       CFG_STA_MAX
#define NX_REMOTE_STA_STORE_MAX (CFG_VIRT_DEV_MAX + CFG_STA_MAX)
#define RWNX_TX_LIFETIME_MS     100

#define RWNX_HWTXHDR_ALIGN_SZ  4
#define RWNX_HWTXHDR_ALIGN_MSK (RWNX_HWTXHDR_ALIGN_SZ - 1)
#define RWNX_HWTXHDR_ALIGN_PADS(x)                                                                 \
	((RWNX_HWTXHDR_ALIGN_SZ - ((x) & RWNX_HWTXHDR_ALIGN_MSK)) & RWNX_HWTXHDR_ALIGN_MSK)

#define le16_to_cpu(v16) (v16)
#define le32_to_cpu(v32) (v32)

#define REG_SW_SET_PROFILING(env, value)                                                           \
	do {                                                                                       \
	} while (0)
#define REG_SW_CLEAR_PROFILING(env, value)                                                         \
	do {                                                                                       \
	} while (0)

enum ieee80211_max_ampdu_length_exp {
	IEEE80211_HT_MAX_AMPDU_8K = 0,
	IEEE80211_HT_MAX_AMPDU_16K = 1,
	IEEE80211_HT_MAX_AMPDU_32K = 2,
	IEEE80211_HT_MAX_AMPDU_64K = 3
};

#define IEEE80211_WMM_IE_STA_QOSINFO_AC_VO (1 << 0)
#define IEEE80211_WMM_IE_STA_QOSINFO_AC_VI (1 << 1)
#define IEEE80211_WMM_IE_STA_QOSINFO_AC_BK (1 << 2)
#define IEEE80211_WMM_IE_STA_QOSINFO_AC_BE (1 << 3)

enum ieee80211_vht_mcs_support {
	IEEE80211_VHT_MCS_SUPPORT_0_7 = 0,
	IEEE80211_VHT_MCS_SUPPORT_0_8 = 1,
	IEEE80211_VHT_MCS_SUPPORT_0_9 = 2,
	IEEE80211_VHT_MCS_NOT_SUPPORTED = 3,
};

struct bl_dbginfo {
	BL_Mutex_t mutex;
	struct dbg_debug_dump_tag *buf;
	u32 dma_addr;
	int bufsz;
};

struct net_device_stats {
	unsigned long rx_packets;
	unsigned long tx_packets;
	unsigned long rx_bytes;
	unsigned long tx_bytes;
	unsigned long rx_errors;
	unsigned long tx_errors;
	unsigned long rx_dropped;
	unsigned long tx_dropped;
};

struct bl_sta {
	struct utils_list waiting_list;
	struct utils_list pending_list;
	struct mac_addr sta_addr;
	u8 is_used;
	u8 sta_idx;
	u8 vif_idx;
	u8 vlan_idx;
	u8 fc_ps;
	uint8_t qos;
	int8_t rssi;
	uint8_t data_rate;
	uint32_t tsflo;
	uint32_t tsfhi;
};

/* Forward-declare netif (Zephyr doesn't use lwIP netif directly) */
struct netif;

struct bl_vif {
	struct list_head list;
	struct netif *dev;
	bool up;
	u8 vif_idx;
	u8 links_num;
	u8 fixed_sta_idx;
	u8 fc_chan;
	u8 sta_ps;
};

enum bl_vif_id {
	BL_VIF_STA = 0,
	BL_VIF_AP = NX_VIRT_DEV_MAX - 1,
};

struct bl_hw {
	struct bl_cmd_mgr cmd_mgr;
	struct ipc_host_env_tag *ipc_env;
	struct list_head vifs;
	struct bl_vif vif_table[NX_VIRT_DEV_MAX];
	struct bl_sta sta_table[NX_REMOTE_STA_STORE_MAX];
	struct bl_mod_params *mod_params;
	struct ieee80211_sta_ht_cap ht_cap;

	/* Zephyr-side bookkeeping appended after the vendor ABI portion. */
	int is_up;
	unsigned long drv_flags;
	int vif_index_sta;
	int vif_index_ap;
	int sta_idx;
	int ap_bcmc_idx;
};

struct ethhdr {
	unsigned char h_dest[ETH_ALEN];
	unsigned char h_source[ETH_ALEN];
	__be16 h_proto;
} __attribute__((packed));

/// RF bands
enum {
	PHY_BAND_2G4,
	PHY_BAND_5G,
	PHY_BAND_MAX,
};

/// Channel bandwidths
enum {
	PHY_CHNL_BW_20,
	PHY_CHNL_BW_40,
	PHY_CHNL_BW_80,
	PHY_CHNL_BW_160,
	PHY_CHNL_BW_80P80,
	PHY_CHNL_BW_OTHER,
};

#endif /* __RWNX_DEFS_H__ */
