/*
 * Copyright (C) Bouffalo Lab 2016-2018
 * SPDX-License-Identifier: Apache-2.0
 *
 * cfg80211 structures — ported from M1s SDK.
 */

#ifndef __CFG80211_H__
#define __CFG80211_H__

#include "ieee80211.h"
#include "nl80211.h"
#include "lmac_types.h"

#ifndef BIT
#define BIT(n) (0x1U << (n))
#endif

enum ieee80211_channel_flags {
	IEEE80211_CHAN_DISABLED = 1 << 0,
	IEEE80211_CHAN_NO_IR = 1 << 1,
	IEEE80211_CHAN_RADAR = 1 << 3,
	IEEE80211_CHAN_NO_HT40PLUS = 1 << 4,
	IEEE80211_CHAN_NO_HT40MINUS = 1 << 5,
	IEEE80211_CHAN_NO_OFDM = 1 << 6,
	IEEE80211_CHAN_NO_80MHZ = 1 << 7,
	IEEE80211_CHAN_NO_160MHZ = 1 << 8,
};

struct ieee80211_channel {
	enum nl80211_band band;
	u16 center_freq;
	u16 hw_value;
	u32 flags;
	int max_antenna_gain;
	int max_power;
	int max_reg_power;
	bool beacon_found;
	u32 orig_flags;
	int orig_mag, orig_mpwr;
	enum nl80211_dfs_state dfs_state;
	unsigned long dfs_state_entered;
	unsigned int dfs_cac_ms;
};

struct ieee80211_sta_ht_cap {
	u16 cap;
	bool ht_supported;
	u8 ampdu_factor;
	u8 ampdu_density;
	struct ieee80211_mcs_info mcs;
};

struct key_params {
	const u8 *key;
	const u8 *seq;
	int key_len;
	int seq_len;
	u32 cipher;
};

struct cfg80211_crypto_settings {
	u32 wpa_versions;
	u32 cipher_group;
	int n_ciphers_pairwise;
	u32 ciphers_pairwise[NL80211_MAX_NR_CIPHER_SUITES];
	int n_akm_suites;
	u32 akm_suites[NL80211_MAX_NR_AKM_SUITES];
	bool control_port;
	__be16 control_port_ethertype;
	bool control_port_no_encrypt;
	struct key_params *wep_keys;
	int wep_tx_key;
};

struct cfg80211_bss_select_adjust {
	enum nl80211_band band;
	s8 delta;
};

struct cfg80211_bss_selection {
	enum nl80211_bss_select_attr behaviour;
	union {
		enum nl80211_band band_pref;
		struct cfg80211_bss_select_adjust adjust;
	} param;
};

struct cfg80211_connect_params {
	struct ieee80211_channel channel;
	struct ieee80211_channel *channel_hint;
	const u8 *bssid;
	const u8 *bssid_hint;
	const u8 *ssid;
	size_t ssid_len;
	enum nl80211_auth_type auth_type;
	const u8 *ie;
	size_t ie_len;
	bool privacy;
	enum nl80211_mfp mfp;
	struct cfg80211_crypto_settings crypto;
	const u8 *key;
	const u8 *pmk;
	u8 key_len, pmk_len, key_idx;
	u32 flags;
	int bg_scan_period;
	struct ieee80211_ht_cap ht_capa;
	struct ieee80211_ht_cap ht_capa_mask;
	bool pbss;
	struct cfg80211_bss_selection bss_select;
	const u8 *prev_bssid;
};

struct ieee80211_dot_d {
	const char *code;
	int channel_num;
	const struct ieee80211_channel *channels;
};

#endif /* __CFG80211_H__ */
