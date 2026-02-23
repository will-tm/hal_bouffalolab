/*
 * Copyright (C) Bouffalo Lab 2016-2018
 * SPDX-License-Identifier: Apache-2.0
 *
 * LMAC message structures — ported from M1s SDK.
 */

#ifndef LMAC_MSG_H_
#define LMAC_MSG_H_

#include "lmac_types.h"
#include <bl60x_fw_api.h>
#include <wifi_mgmr_ext.h>
#include "lmac_mac.h"

/// Interface types
enum {
	MM_STA,
	MM_IBSS,
	MM_AP,
	MM_MESH_POINT,
};

#define MAX_PSK_PASS_PHRASE_LEN 64

#define DRV_TASK_ID 100
#define MSG_T(msg)  (((msg) >> 10))
#define MSG_I(msg)  ((msg) & ((1 << 10) - 1))

#ifndef TDLS_ENABLE
#define TDLS_ENABLE 0
#endif

/*
 * Message structure for A2E commands.
 *
 * The vendor SDK builds this type with -fshort-enums, which produces an
 * 8-byte wire header:
 *   [id:2] [dest_id:1] [src_id:1] [param_len:4]
 *
 * Zephyr does not use -fshort-enums, so represent the wire layout explicitly
 * instead of relying on enum size.
 */
struct lmac_msg {
	u16_l id;
	u8_l dest_id;
	u8_l src_id;
	u32_l param_len;
	u32 param[];
};

/// Status/error codes
enum {
	CO_OK,
	CO_FAIL,
	CO_EMPTY,
	CO_FULL,
	CO_BAD_PARAM,
	CO_NOT_FOUND,
	CO_NO_MORE_ELT_AVAILABLE,
	CO_NO_ELT_IN_USE,
	CO_BUSY,
	CO_OP_IN_PROGRESS,
};

/// PHY configuration
#define PHY_CFG_BUF_SIZE 16

struct phy_cfg_tag {
	u32_l parameters[PHY_CFG_BUF_SIZE];
};

struct mm_monitor_cfm {
	uint32_t status;
	uint32_t enable;
	uint32_t data[8];
};

struct mm_start_req {
	struct phy_cfg_tag phy_cfg;
	u32_l uapsd_timeout;
	u16_l lp_clk_accuracy;
};

struct mm_set_channel_req {
	u8_l band;
	u8_l type;
	u16_l prim20_freq;
	u16_l center1_freq;
	u16_l center2_freq;
	u8_l index;
	s8_l tx_power;
};

struct mm_set_channel_cfm {
	u8_l radio_idx;
	s8_l power;
};

struct mm_set_beacon_int_req {
	u16_l beacon_int;
	u8_l inst_nbr;
};

struct mm_set_beacon_int_cfm {
	u8_l status;
};

struct mm_set_basic_rates_req {
	u32_l rates;
	u8_l inst_nbr;
	u8_l band;
};

struct mm_set_bssid_req {
	struct mac_addr bssid;
	u8_l inst_nbr;
};

struct mm_add_if_req {
	u8_l type;
	struct mac_addr addr;
	bool_l p2p;
};

struct mm_set_edca_req {
	u32_l ac_param;
	bool_l uapsd;
	u8_l hw_queue;
	u8_l inst_nbr;
};

struct mm_set_idle_req {
	u8_l hw_idle;
};

struct mm_set_vif_state_req {
	u16_l aid;
	bool_l active;
	u8_l inst_nbr;
};

struct mm_add_if_cfm {
	u8_l status;
	u8_l inst_nbr;
};

struct mm_remove_if_req {
	u8_l inst_nbr;
};

struct mm_version_cfm {
	u32_l version_lmac;
	u32_l version_machw_1;
	u32_l version_machw_2;
	u32_l version_phy_1;
	u32_l version_phy_2;
	u32_l features;
};

struct mm_sta_add_req {
	u32_l paid_gid;
	u16_l ampdu_size_max_ht;
	struct mac_addr mac_addr;
	u8_l ampdu_spacing_min;
	u8_l inst_nbr;
};

struct mm_sta_add_cfm {
	u8_l status;
	u8_l sta_idx;
	u8_l hw_sta_idx;
};

struct mm_sta_del_req {
	u8_l sta_idx;
};

struct mm_sta_del_cfm {
	u8_l status;
};

struct mm_setpowermode_req {
	u8_l mode;
	u8_l sta_idx;
};

struct mm_monitor_req {
	uint32_t enable;
};

struct mm_monitor_channel_req {
	uint32_t freq;
};

struct mm_monitor_channel_cfm {
	uint32_t status;
	uint32_t freq;
	uint32_t data[8];
};

struct mm_chan_ctxt_add_req {
	u8_l band;
	u8_l type;
	u16_l prim20_freq;
	u16_l center1_freq;
	u16_l center2_freq;
	s8_l tx_power;
};

struct mm_chan_ctxt_add_cfm {
	u8_l status;
	u8_l index;
};

struct mm_connection_loss_ind {
	u8_l inst_nbr;
};

struct mm_channel_switch_ind {
	u8_l chan_index;
	bool_l roc;
	u8_l vif_index;
	bool_l roc_tdls;
};

struct mm_set_ps_mode_req {
	u8_l new_state;
};

struct mm_set_denoise_req {
	u8_l denoise_mode;
};

struct mm_rssi_status_ind {
	u8_l vif_index;
	bool_l rssi_status;
	s8_l rssi;
};

/// Scan definitions
#define SCAN_SSID_MAX     1
#define SCAN_CHANNEL_2G4  14
#define SCAN_CHANNEL_5G   28
#define SCAN_CHANNEL_MAX  (SCAN_CHANNEL_2G4 + SCAN_CHANNEL_5G)
#define SCAN_PASSIVE_BIT  BIT(0)
#define SCAN_DISABLED_BIT BIT(1)

#ifndef BIT
#define BIT(n) (0x1U << (n))
#endif

struct scan_chan_tag {
	u16_l freq;
	u8_l band;
	u8_l flags;
	s8_l tx_power;
};

struct scan_start_req {
	struct scan_chan_tag chan[SCAN_CHANNEL_MAX];
	struct mac_ssid ssid[SCAN_SSID_MAX];
	struct mac_addr bssid;
	struct mac_addr mac;
	u32_l add_ies;
	u16_l add_ie_len;
	u8_l vif_idx;
	u8_l chan_cnt;
	u8_l ssid_cnt;
	bool no_cck;
};

struct scan_start_cfm {
	u8_l status;
};

struct scanu_start_req {
	struct scan_chan_tag chan[SCAN_CHANNEL_MAX];
	struct mac_ssid ssid[SCAN_SSID_MAX];
	struct mac_addr bssid;
	struct mac_addr mac;
	u32_l add_ies;
	u16_l add_ie_len;
	u8_l vif_idx;
	u8_l chan_cnt;
	u8_l ssid_cnt;
	bool no_cck;
	uint32_t flags;
	uint32_t duration_scan;
};

struct scanu_start_cfm {
	u8_l status;
};

struct scanu_result_ind {
	uint16_t length;
	uint16_t framectrl;
	uint16_t center_freq;
	uint8_t band;
	uint8_t sta_idx;
	uint8_t inst_nbr;
	uint8_t sa[6];
	uint32_t tsflo;
	uint32_t tsfhi;
	int8_t rssi;
	int8_t ppm_abs;
	int8_t ppm_rel;
	uint8_t flags;
	uint8_t data_rate;
	uint32_t payload[];
};

struct me_config_req {
	struct mac_htcapability ht_cap;
	struct mac_vhtcapability vht_cap;
	u16_l tx_lft;
	bool_l ht_supp;
	bool_l vht_supp;
	bool_l ps_on;
};

struct me_chan_config_req {
	struct scan_chan_tag chan2G4[SCAN_CHANNEL_2G4];
	u8_l chan2G4_cnt;
};

struct me_sta_add_req {
	struct mac_addr mac_addr;
	struct mac_rateset rate_set;
	struct mac_htcapability ht_cap;
	struct mac_vhtcapability vht_cap;
	u32_l flags;
	u16_l aid;
	u8_l uapsd_queues;
	u8_l max_sp_len;
	u8_l opmode;
	u8_l vif_idx;
#if (TDLS_ENABLE)
	bool_l tdls_sta;
#endif
	uint32_t tsflo;
	uint32_t tsfhi;
	int8_t rssi;
	uint8_t data_rate;
};

struct me_sta_add_cfm {
	u8_l sta_idx;
	u8_l status;
	u8_l pm_state;
};

struct me_sta_del_req {
	u8_l sta_idx;
#if (TDLS_ENABLE)
	bool_l tdls_sta;
#endif
};

struct me_rc_set_rate_req {
	u8_l sta_idx;
	u16_l fixed_rate_cfg;
	u16_l power_table_req;
};

/// SM connect
struct sm_connect_req {
	struct mac_ssid ssid;
	struct mac_addr bssid;
	struct scan_chan_tag chan;
	u32_l flags;
	u16_l ctrl_port_ethertype;
	u16_l listen_interval;
	bool_l dont_wait_bcmc;
	u8_l auth_type;
	u8_l uapsd_queues;
	u8_l vif_idx;
	u8_l counter_retry_auth_assoc;
	bool is_supplicant_enabled;
	uint8_t phrase[MAX_PSK_PASS_PHRASE_LEN];
	uint8_t phrase_pmk[MAX_PSK_PASS_PHRASE_LEN];
};

struct sm_connect_cfm {
	u8_l status;
};

#define SM_ASSOC_IE_LEN 800

struct sm_connect_ind {
	u16_l status_code;
	u16_l reason_code;
	struct mac_addr bssid;
	bool_l roamed;
	u8_l vif_idx;
	u8_l ap_idx;
	u8_l ch_idx;
	bool_l qos;
	u8_l acm;
	u16_l assoc_req_ie_len;
	u16_l assoc_rsp_ie_len;
	u32_l assoc_ie_buf[SM_ASSOC_IE_LEN / 4];
	u16_l aid;
	u8_l band;
	u16_l center_freq;
	u8_l width;
	u32_l center_freq1;
	u32_l center_freq2;
	u32_l ac_param[AC_MAX];
	struct sm_tlv_list connect_diagnose;
};

struct sm_disconnect_req {
	u8_l vif_idx;
};

struct sm_disconnect_ind {
	u16_l status_code;
	u16_l reason_code;
	u8_l vif_idx;
	bool_l ft_over_ds;
	struct sm_tlv_list connect_diagnose;
};

struct sm_connect_abort_req {
	uint8_t vif_idx;
};

struct sm_connect_abort_cfm {
	uint8_t status;
};

struct cfg_start_req {
	uint32_t ops;
	union {
		struct {
			uint32_t task;
			uint32_t element;
		} get[0];
		struct {
			uint32_t task;
			uint32_t element;
		} reset[0];
		struct {
			uint32_t task;
			uint32_t element;
			uint32_t type;
			uint32_t length;
			uint32_t buf[];
		} set[0];
	} u;
};

struct cfg_start_cfm {
	uint8_t status;
};

struct apm_start_req {
	struct mac_rateset basic_rates;
	struct scan_chan_tag chan;
	u32_l center_freq1;
	u32_l center_freq2;
	u8_l ch_width;
	u8_l hidden_ssid;
	u32_l bcn_addr;
	u16_l bcn_len;
	u16_l tim_oft;
	u16_l bcn_int;
	u32_l flags;
	u16_l ctrl_port_ethertype;
	u8_l tim_len;
	u8_l vif_idx;
	bool apm_emb_enabled;
	struct mac_rateset rate_set;
	uint8_t beacon_period;
	uint8_t qos_supported;
	struct mac_ssid ssid;
	uint8_t ap_sec_type;
	uint8_t phrase[MAX_PSK_PASS_PHRASE_LEN];
	uint8_t phrase_tail[1];
	uint8_t bcn_buf_len;
	uint8_t bcn_buf[64];
};

struct apm_start_cfm {
	u8_l status;
	u8_l vif_idx;
	u8_l ch_idx;
	u8_l bcmc_idx;
};

struct apm_stop_req {
	u8_l vif_idx;
};

struct apm_conf_max_sta_req {
	u8_l max_sta_supported;
};

struct apm_sta_del_req {
	u8_l vif_idx;
	u8_l sta_idx;
};

struct apm_sta_del_cfm {
	u8_l status;
	u8_l vif_idx;
	u8_l sta_idx;
};

struct apm_sta_add_ind {
	uint32_t flags;
	struct mac_addr sta_addr;
	uint8_t vif_idx;
	uint8_t sta_idx;
	int8_t rssi;
	uint32_t tsflo;
	uint32_t tsfhi;
	uint8_t data_rate;
};

struct apm_sta_del_ind {
	uint16_t status_code;
	uint16_t reason_code;
	uint8_t sta_idx;
};

struct sm_disconnect_cfm {
	u8_l status;
};

struct scanu_raw_send_req {
	uint8_t *pkt;
	uint32_t len;
};

struct scanu_raw_send_cfm {
	u8_l status;
};

struct mm_set_ps_mode_cfm {
	u8_l status;
};

#endif /* LMAC_MSG_H_ */
