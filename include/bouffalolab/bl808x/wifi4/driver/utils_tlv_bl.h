/*
 * Copyright (C) Bouffalo Lab 2016-2018
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __UTILS_TLV_BL_H__
#define __UTILS_TLV_BL_H__

#include <stdint.h>
#include <stdbool.h>

int utils_tlv_bl_pack_bool(uint32_t *buf, int buf_sz, bool val);
int utils_tlv_bl_pack_uint32(uint32_t *buf, int buf_sz, uint32_t val);
int utils_tlv_bl_unpack_bool(uint32_t *buf, int buf_sz, bool *val);
int utils_tlv_bl_unpack_uint32(uint32_t *buf, int buf_sz, uint32_t *val);
int utils_tlv_bl_pack_auto(uint32_t *buf, int buf_sz, uint16_t type, void *arg1);
int utils_tlv_bl_unpack_auto(uint32_t *buf, int buf_sz, uint16_t type, void *arg1, void *arg2);

enum CFG_ELEMENT_TYPE_OPS {
	CFG_ELEMENT_TYPE_OPS_SET,
	CFG_ELEMENT_TYPE_OPS_GET,
	CFG_ELEMENT_TYPE_OPS_RESET,
	CFG_ELEMENT_TYPE_OPS_DUMP_DEBUG,
	CFG_ELEMENT_TYPE_OPS_UNKNOWN,
};

#endif /* __UTILS_TLV_BL_H__ */
