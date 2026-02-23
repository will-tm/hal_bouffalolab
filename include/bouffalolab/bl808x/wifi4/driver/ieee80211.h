/*
 * Copyright (C) Bouffalo Lab 2016-2018
 * SPDX-License-Identifier: Apache-2.0
 *
 * IEEE 802.11 definitions — ported from M1s SDK.
 */

#ifndef __IEEE80211_H__
#define __IEEE80211_H__
#include "lmac_types.h"

#ifndef cpu_to_le16
#define cpu_to_le16(v16) (v16)
#endif

#ifndef cpu_to_le32
#define cpu_to_le32(v32) (v32)
#endif

#define WLAN_SA_QUERY_TR_ID_LEN 2
#define WLAN_MEMBERSHIP_LEN     8
#define WLAN_USER_POSITION_LEN  16

#define FCS_LEN 4

#define IEEE80211_FCTL_VERS      0x0003
#define IEEE80211_FCTL_FTYPE     0x000c
#define IEEE80211_FCTL_STYPE     0x00f0
#define IEEE80211_FCTL_TODS      0x0100
#define IEEE80211_FCTL_FROMDS    0x0200
#define IEEE80211_FCTL_MOREFRAGS 0x0400
#define IEEE80211_FCTL_RETRY     0x0800
#define IEEE80211_FCTL_PM        0x1000
#define IEEE80211_FCTL_MOREDATA  0x2000
#define IEEE80211_FCTL_PROTECTED 0x4000
#define IEEE80211_FCTL_ORDER     0x8000
#define IEEE80211_FCTL_CTL_EXT   0x0f00

#define IEEE80211_SCTL_FRAG 0x000F
#define IEEE80211_SCTL_SEQ  0xFFF0

#define IEEE80211_FTYPE_MGMT 0x0000
#define IEEE80211_FTYPE_CTL  0x0004
#define IEEE80211_FTYPE_DATA 0x0008
#define IEEE80211_FTYPE_EXT  0x000c

/* management */
#define IEEE80211_STYPE_ASSOC_REQ    0x0000
#define IEEE80211_STYPE_ASSOC_RESP   0x0010
#define IEEE80211_STYPE_REASSOC_REQ  0x0020
#define IEEE80211_STYPE_REASSOC_RESP 0x0030
#define IEEE80211_STYPE_PROBE_REQ    0x0040
#define IEEE80211_STYPE_PROBE_RESP   0x0050
#define IEEE80211_STYPE_BEACON       0x0080
#define IEEE80211_STYPE_ATIM         0x0090
#define IEEE80211_STYPE_DISASSOC     0x00A0
#define IEEE80211_STYPE_AUTH         0x00B0
#define IEEE80211_STYPE_DEAUTH       0x00C0
#define IEEE80211_STYPE_ACTION       0x00D0

/* control */
#define IEEE80211_STYPE_CTL_EXT  0x0060
#define IEEE80211_STYPE_BACK_REQ 0x0080
#define IEEE80211_STYPE_BACK     0x0090
#define IEEE80211_STYPE_PSPOLL   0x00A0
#define IEEE80211_STYPE_RTS      0x00B0
#define IEEE80211_STYPE_CTS      0x00C0
#define IEEE80211_STYPE_ACK      0x00D0
#define IEEE80211_STYPE_CFEND    0x00E0
#define IEEE80211_STYPE_CFENDACK 0x00F0

/* data */
#define IEEE80211_STYPE_DATA               0x0000
#define IEEE80211_STYPE_DATA_CFACK         0x0010
#define IEEE80211_STYPE_DATA_CFPOLL        0x0020
#define IEEE80211_STYPE_DATA_CFACKPOLL     0x0030
#define IEEE80211_STYPE_NULLFUNC           0x0040
#define IEEE80211_STYPE_CFACK              0x0050
#define IEEE80211_STYPE_CFPOLL             0x0060
#define IEEE80211_STYPE_CFACKPOLL          0x0070
#define IEEE80211_STYPE_QOS_DATA           0x0080
#define IEEE80211_STYPE_QOS_DATA_CFACK     0x0090
#define IEEE80211_STYPE_QOS_DATA_CFPOLL    0x00A0
#define IEEE80211_STYPE_QOS_DATA_CFACKPOLL 0x00B0
#define IEEE80211_STYPE_QOS_NULLFUNC       0x00C0
#define IEEE80211_STYPE_QOS_CFACK          0x00D0
#define IEEE80211_STYPE_QOS_CFPOLL         0x00E0
#define IEEE80211_STYPE_QOS_CFACKPOLL      0x00F0

#define IEEE80211_SN_MASK   ((IEEE80211_SCTL_SEQ) >> 4)
#define IEEE80211_MAX_SN    IEEE80211_SN_MASK
#define IEEE80211_SN_MODULO (IEEE80211_MAX_SN + 1)

/* 802.11n HT capabilities masks */
#define IEEE80211_HT_CAP_LDPC_CODING      0x0001
#define IEEE80211_HT_CAP_SUP_WIDTH_20_40  0x0002
#define IEEE80211_HT_CAP_SM_PS            0x000C
#define IEEE80211_HT_CAP_SM_PS_SHIFT      2
#define IEEE80211_HT_CAP_GRN_FLD          0x0010
#define IEEE80211_HT_CAP_SGI_20           0x0020
#define IEEE80211_HT_CAP_SGI_40           0x0040
#define IEEE80211_HT_CAP_TX_STBC          0x0080
#define IEEE80211_HT_CAP_RX_STBC          0x0300
#define IEEE80211_HT_CAP_RX_STBC_SHIFT    8
#define IEEE80211_HT_CAP_DELAY_BA         0x0400
#define IEEE80211_HT_CAP_MAX_AMSDU        0x0800
#define IEEE80211_HT_CAP_DSSSCCK40        0x1000
#define IEEE80211_HT_CAP_40MHZ_INTOLERANT 0x4000
#define IEEE80211_HT_CAP_LSIG_TXOP_PROT   0x8000

#define IEEE80211_HT_AMPDU_PARM_FACTOR        0x03
#define IEEE80211_HT_AMPDU_PARM_DENSITY       0x1C
#define IEEE80211_HT_AMPDU_PARM_DENSITY_SHIFT 2

#define IEEE80211_HT_MCS_MASK_LEN 10

/* cipher suite selectors */
#define WLAN_CIPHER_SUITE_USE_GROUP 0x000FAC00
#define WLAN_CIPHER_SUITE_WEP40     0x000FAC01
#define WLAN_CIPHER_SUITE_TKIP      0x000FAC02
#define WLAN_CIPHER_SUITE_CCMP      0x000FAC04
#define WLAN_CIPHER_SUITE_WEP104    0x000FAC05
#define WLAN_CIPHER_SUITE_AES_CMAC  0x000FAC06
#define WLAN_CIPHER_SUITE_GCMP      0x000FAC08
#define WLAN_CIPHER_SUITE_GCMP_256  0x000FAC09
#define WLAN_CIPHER_SUITE_CCMP_256  0x000FAC0A

#define WLAN_CAPABILITY_BSS            (1 << 0)
#define WLAN_CAPABILITY_IBSS           (1 << 1)
#define WLAN_CAPABILITY_PRIVACY        (1 << 4)
#define WLAN_CAPABILITY_SHORT_PREAMBLE (1 << 5)
#define WLAN_CAPABILITY_SHORT_SLOT     (1 << 10)

enum ieee80211_reasoncode {
	WLAN_REASON_UNSPECIFIED = 1,
	WLAN_REASON_PREV_AUTH_NOT_VALID = 2,
	WLAN_REASON_DEAUTH_LEAVING = 3,
	WLAN_REASON_DISASSOC_DUE_TO_INACTIVITY = 4,
	WLAN_REASON_DISASSOC_AP_BUSY = 5,
	WLAN_REASON_CLASS2_FRAME_FROM_NONAUTH_STA = 6,
	WLAN_REASON_CLASS3_FRAME_FROM_NONASSOC_STA = 7,
	WLAN_REASON_DISASSOC_STA_HAS_LEFT = 8,
	WLAN_REASON_STA_REQ_ASSOC_WITHOUT_AUTH = 9,
	WLAN_REASON_INVALID_IE = 13,
	WLAN_REASON_MIC_FAILURE = 14,
	WLAN_REASON_4WAY_HANDSHAKE_TIMEOUT = 15,
	WLAN_REASON_GROUP_KEY_HANDSHAKE_TIMEOUT = 16,
	WLAN_REASON_IE_DIFFERENT = 17,
	WLAN_REASON_INVALID_GROUP_CIPHER = 18,
	WLAN_REASON_INVALID_PAIRWISE_CIPHER = 19,
	WLAN_REASON_INVALID_AKMP = 20,
	WLAN_REASON_UNSUPP_RSN_VERSION = 21,
	WLAN_REASON_INVALID_RSN_IE_CAP = 22,
	WLAN_REASON_IEEE8021X_FAILED = 23,
	WLAN_REASON_CIPHER_SUITE_REJECTED = 24,
	WLAN_REASON_TDLS_TEARDOWN_UNREACHABLE = 25,
	WLAN_REASON_TDLS_TEARDOWN_UNSPECIFIED = 26,
};

struct ieee80211_mcs_info {
	u8 rx_mask[IEEE80211_HT_MCS_MASK_LEN];
	__le16 rx_highest;
	u8 tx_params;
	u8 reserved[3];
};

struct ieee80211_ht_cap {
	__le16 cap_info;
	u8 ampdu_params_info;
	struct ieee80211_mcs_info mcs;
	__le16 extended_ht_cap_info;
	__le32 tx_BF_cap_info;
	u8 antenna_selection_info;
};

struct ieee80211_mgmt {
	__le16 frame_control;
	__le16 duration;
	u8 da[6];
	u8 sa[6];
	u8 bssid[6];
	__le16 seq_ctrl;
	union {
		struct {
			__le16 auth_alg;
			__le16 auth_transaction;
			__le16 status_code;
			u8 variable[0];
		} __attribute__((__packed__)) auth;
		struct {
			__le16 reason_code;
		} __attribute__((__packed__)) deauth;
		struct {
			__le16 capab_info;
			__le16 listen_interval;
			u8 variable[0];
		} __attribute__((__packed__)) assoc_req;
		struct {
			__le16 capab_info;
			__le16 status_code;
			__le16 aid;
			u8 variable[0];
		} __attribute__((__packed__)) assoc_resp, reassoc_resp;
		struct {
			__le16 reason_code;
		} __attribute__((__packed__)) disassoc;
		struct {
			__le64 timestamp;
			__le16 beacon_int;
			__le16 capab_info;
			u8 variable[0];
		} __attribute__((__packed__)) beacon;
		struct {
			u8 variable[0];
		} __attribute__((__packed__)) probe_req;
		struct {
			__le64 timestamp;
			__le16 beacon_int;
			__le16 capab_info;
			u8 variable[0];
		} __attribute__((__packed__)) probe_resp;
		struct {
			u8 category;
			union {
				struct {
					u8 action_code;
					u8 dialog_token;
					__le16 capab;
					__le16 timeout;
					__le16 start_seq_num;
				} __attribute__((__packed__)) addba_req;
				struct {
					u8 action_code;
					u8 dialog_token;
					__le16 status;
					__le16 capab;
					__le16 timeout;
				} __attribute__((__packed__)) addba_resp;
				struct {
					u8 action_code;
					__le16 params;
					__le16 reason_code;
				} __attribute__((__packed__)) delba;
				struct {
					u8 action;
					u8 trans_id[WLAN_SA_QUERY_TR_ID_LEN];
				} __attribute__((__packed__)) sa_query;
				struct {
					u8 action;
					u8 smps_control;
				} __attribute__((__packed__)) ht_smps;
				struct {
					u8 action_code;
					u8 chanwidth;
				} __attribute__((__packed__)) ht_notify_cw;
				struct {
					u8 action_code;
					u8 operating_mode;
				} __attribute__((__packed__)) vht_opmode_notif;
				struct {
					u8 action_code;
					u8 membership[WLAN_MEMBERSHIP_LEN];
					u8 position[WLAN_USER_POSITION_LEN];
				} __attribute__((__packed__)) vht_group_notif;
			} u;
		} __attribute__((__packed__)) action;
	} u;
} __attribute__((packed, aligned(2)));

static inline bool ieee80211_is_beacon(__le16 fc)
{
	return (fc & cpu_to_le16(IEEE80211_FCTL_FTYPE | IEEE80211_FCTL_STYPE)) ==
	       cpu_to_le16(IEEE80211_FTYPE_MGMT | IEEE80211_STYPE_BEACON);
}

static inline bool ieee80211_is_deauth(__le16 fc)
{
	return (fc & cpu_to_le16(IEEE80211_FCTL_FTYPE | IEEE80211_FCTL_STYPE)) ==
	       cpu_to_le16(IEEE80211_FTYPE_MGMT | IEEE80211_STYPE_DEAUTH);
}

static inline bool ieee80211_is_disassoc(__le16 fc)
{
	return (fc & cpu_to_le16(IEEE80211_FCTL_FTYPE | IEEE80211_FCTL_STYPE)) ==
	       cpu_to_le16(IEEE80211_FTYPE_MGMT | IEEE80211_STYPE_DISASSOC);
}

static inline bool ieee80211_is_action(__le16 fc)
{
	return (fc & cpu_to_le16(IEEE80211_FCTL_FTYPE | IEEE80211_FCTL_STYPE)) ==
	       cpu_to_le16(IEEE80211_FTYPE_MGMT | IEEE80211_STYPE_ACTION);
}

static inline int ieee80211_is_probe_resp(__le16 fc)
{
	return (fc & cpu_to_le16(IEEE80211_FCTL_FTYPE | IEEE80211_FCTL_STYPE)) ==
	       cpu_to_le16(IEEE80211_FTYPE_MGMT | IEEE80211_STYPE_PROBE_RESP);
}

static inline bool ieee80211_is_probe_req(__le16 fc)
{
	return (fc & cpu_to_le16(IEEE80211_FCTL_FTYPE | IEEE80211_FCTL_STYPE)) ==
	       cpu_to_le16(IEEE80211_FTYPE_MGMT | IEEE80211_STYPE_PROBE_REQ);
}

static inline bool ieee80211_is_data(__le16 fc)
{
	return (fc & cpu_to_le16(IEEE80211_FCTL_FTYPE)) == cpu_to_le16(IEEE80211_FTYPE_DATA);
}

static inline bool ieee80211_is_data_qos(__le16 fc)
{
	return (fc & cpu_to_le16(IEEE80211_FCTL_FTYPE | IEEE80211_STYPE_QOS_DATA)) ==
	       cpu_to_le16(IEEE80211_FTYPE_DATA | IEEE80211_STYPE_QOS_DATA);
}

#endif /* __IEEE80211_H__ */
