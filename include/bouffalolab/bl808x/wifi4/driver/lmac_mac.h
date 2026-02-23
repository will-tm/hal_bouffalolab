/*
 * Copyright (C) Bouffalo Lab 2016-2018
 * SPDX-License-Identifier: Apache-2.0
 *
 * MAC definitions — ported from M1s SDK.
 */

#ifndef _MAC_H_
#define _MAC_H_

#include "lmac_types.h"
#include <string.h>

#define TU_DURATION               1024
#define MAC_DOMAINCHANNEL_24G_MAX 14
#define MAC_DOMAINCHANNEL_5G_MAX  45
#define MAC_BASIC_RATE            0x80
#define WORD_ALIGN                3
#define MAX_AMSDU_LENGTH          7935

#define MAC_ADDR_CMP(addr1_ptr, addr2_ptr)                                                         \
	((*(((u8 *)(addr1_ptr)) + 0) == *(((u8 *)(addr2_ptr)) + 0)) &&                             \
	 (*(((u8 *)(addr1_ptr)) + 1) == *(((u8 *)(addr2_ptr)) + 1)) &&                             \
	 (*(((u8 *)(addr1_ptr)) + 2) == *(((u8 *)(addr2_ptr)) + 2)) &&                             \
	 (*(((u8 *)(addr1_ptr)) + 3) == *(((u8 *)(addr2_ptr)) + 3)) &&                             \
	 (*(((u8 *)(addr1_ptr)) + 4) == *(((u8 *)(addr2_ptr)) + 4)) &&                             \
	 (*(((u8 *)(addr1_ptr)) + 5) == *(((u8 *)(addr2_ptr)) + 5)))

#define MAC_ADDR_CMP_PACKED(__a1, __a2) (memcmp(__a1, __a2, MAC_ADDR_LEN) == 0)

#define MAC_ADDR_CPY(addr1_ptr, addr2_ptr)                                                         \
	*(((u16 *)(addr1_ptr)) + 0) = *(((u16 *)(addr2_ptr)) + 0);                                 \
	*(((u16 *)(addr1_ptr)) + 1) = *(((u16 *)(addr2_ptr)) + 1);                                 \
	*(((u16 *)(addr1_ptr)) + 2) = *(((u16 *)(addr2_ptr)) + 2)

#define MAC_SSID_CMP(ssid1_ptr, ssid2_ptr)                                                         \
	(((ssid1_ptr)->length == (ssid2_ptr)->length) &&                                           \
	 (memcmp((&(ssid1_ptr)->array[0]), (&(ssid2_ptr)->array[0]), (ssid1_ptr)->length) == 0))

#define MAC_ADDR_GROUP(mac_addr_ptr) ((*(mac_addr_ptr)) & 1)

#define MAC_ADDR_LEN 6

struct mac_addr {
	u8_l array[MAC_ADDR_LEN];
};

#define MAC_SSID_LEN 32

struct mac_ssid {
	u8_l length;
	u8_l array[MAC_SSID_LEN];
	u8_l array_tail[1];
};

#define MAC_RATESET_LEN          12
#define MAC_OFDM_PHY_RATESET_LEN 8
#define MAC_EXT_RATES_OFF        8

struct mac_rateset {
	u8_l length;
	u8_l array[MAC_RATESET_LEN];
};

#define MAC_MCS_WORD_CNT 3

struct mac_rates {
	u32 mcs[MAC_MCS_WORD_CNT];
	u16 legacy;
};

#define MAC_IV_LEN  4
#define MAC_EIV_LEN 4

struct rx_seciv {
	u8 iv[MAC_IV_LEN];
	u8 ext_iv[MAC_EIV_LEN];
};

#define MAX_MCS_LEN 16

struct mac_mcsset {
	u8 length;
	u8 array[MAX_MCS_LEN];
};

#define MAC_SEC_KEY_LEN 32

struct mac_sec_key {
	u8_l length;
	u32_l array[MAC_SEC_KEY_LEN / 4];
};

#define MAC_MAX_CH 40

struct mac_ch_list {
	u16 nbr;
	u8 list[MAC_MAX_CH];
};

struct mac_htcapability {
	u16_l ht_capa_info;
	u8_l a_mpdu_param;
	u8_l mcs_rate[MAX_MCS_LEN];
	u16_l ht_extended_capa;
	u32_l tx_beamforming_capa;
	u8_l asel_capa;
};

struct mac_vhtcapability {
	u32_l vht_capa_info;
	u16_l rx_mcs_map;
	u16_l rx_highest;
	u16_l tx_mcs_map;
	u16_l tx_highest;
};

struct mac_htoprnelmt {
	u8 prim_channel;
	u8 ht_oper_1;
	u16 ht_oper_2;
	u16 ht_oper_3;
	u8 mcs_rate[MAX_MCS_LEN];
};

#define MAC_RAW_RSN_IE_LEN 34

struct mac_raw_rsn_ie {
	u8 data[2 + MAC_RAW_RSN_IE_LEN];
};

struct mac_qoscapability {
	u8 qos_info;
};

struct mac_edca_param_set {
	u8 qos_info;
	u32 ac_be_param_record;
	u32 ac_bk_param_record;
	u32 ac_vi_param_record;
	u32 ac_vo_param_record;
};

struct mac_bss_load {
	u16 sta_cnt;
	u8 ch_utilization;
	u16 avail_adm_capacity;
};

struct mac_twenty_fourty_bss {
	u8 bss_coexistence;
};

struct mac_scan_result {
	struct mac_addr bssid;
	u16 bsstype;
	u16 ch_nbr;
	u16 beacon_period;
	u32 timestamp_high;
	u32 timestamp_low;
	u16 dtim_period;
	u16 ibss_parameter;
	u16 cap_info;
	struct mac_rateset rate_set;
	struct mac_bss_load bss_load;
	u8 country_element[3];
	struct mac_edca_param_set edca_param;
	struct mac_raw_rsn_ie rsn_ie;
	struct mac_qoscapability qos_cap;
	struct mac_htcapability ht_cap;
	u8 sec_ch_oft;
	struct mac_twenty_fourty_bss twenty_fourty_bss;
	bool valid_flag;
	u8 rssi;
};

struct mac_version {
	char mac_sw_version[16];
	char mac_sw_version_date[48];
	char mac_sw_build_date[48];
	u32 mac_hw_version1;
	u32 mac_hw_version2;
};

/// Traffic ID enumeration
enum {
	TID_0,
	TID_1,
	TID_2,
	TID_3,
	TID_4,
	TID_5,
	TID_6,
	TID_7,
	TID_MGT,
	TID_MAX
};

/// Access Category enumeration
enum {
	AC_BK = 0,
	AC_BE,
	AC_VI,
	AC_VO,
	AC_MAX
};

/// SCAN type
enum {
	SCAN_PASSIVE,
	SCAN_ACTIVE
};

/// Station flags
enum {
	STA_QOS_CAPA = 1 << 0,
	STA_HT_CAPA = 1 << 1,
	STA_VHT_CAPA = 1 << 2,
	STA_MFP_CAPA = 1 << 3,
	STA_OPMOD_NOTIF = 1 << 4,
};

/// Connection flags
enum {
	CONTROL_PORT_HOST = 1 << 0,
	CONTROL_PORT_NO_ENC = 1 << 1,
	DISABLE_HT = 1 << 2,
	WPA_WPA2_IN_USE = 1 << 3,
	MFP_IN_USE = 1 << 4,
};

extern const u8 mac_tid2ac[];
extern const u8 mac_id2rate[];
extern const u16 mac_mcs_params_20[];
extern const u16 mac_mcs_params_40[];

#endif /* _MAC_H_ */
