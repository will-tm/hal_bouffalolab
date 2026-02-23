/*
 * Copyright (C) Bouffalo Lab 2016-2018
 * SPDX-License-Identifier: Apache-2.0
 *
 * LMAC type definitions — ported from M1s SDK.
 */

#ifndef _LMAC_INT_H_
#define _LMAC_INT_H_

#include <stdint.h>
#include <stdbool.h>

typedef uint8_t u8_l;
typedef int8_t s8_l;
typedef bool bool_l;
typedef uint16_t u16_l;
typedef int16_t s16_l;
typedef uint32_t u32_l;
typedef int32_t s32_l;
typedef uint64_t u64_l;

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

typedef int32_t s32;
typedef int8_t s8;

typedef uint64_t __le64;
typedef uint32_t __le32;
typedef uint16_t __le16;

typedef uint32_t __be32;
typedef uint16_t __be16;

#endif /* _LMAC_INT_H_ */
