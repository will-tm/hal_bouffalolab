/*
 * Copyright (C) Bouffalo Lab 2016-2018
 * SPDX-License-Identifier: Apache-2.0
 *
 * IPC compatibility macros — ported from M1s SDK.
 */

#ifndef _IPC_H_
#define _IPC_H_

#include "bl_os_private.h"
#include <assert.h>

#undef IPC_WARN
#define IPC_WARN() bl_os_printf("%s:%d\r\n", __func__, __LINE__)

#define WARN_ON(condition)                                                                         \
	({                                                                                         \
		int __ret_warn_on = !!(condition);                                                 \
		if (__ret_warn_on)                                                                 \
			IPC_WARN();                                                                \
		__ret_warn_on;                                                                     \
	})

#define WARN_ON_ONCE(condition)                                                                    \
	({                                                                                         \
		static bool __warned;                                                              \
		int __ret_warn_once = !!(condition);                                               \
                                                                                                   \
		if (__ret_warn_once)                                                               \
			if (WARN_ON(!__warned))                                                    \
				__warned = true;                                                   \
		__ret_warn_once;                                                                   \
	})

#define __round_mask(x, y) ((__typeof__(x))((y) - 1))
#define round_up(x, y)     ((((x) - 1) | __round_mask(x, y)) + 1)
#define round_down(x, y)   ((x) & ~__round_mask(x, y))

#define ASSERT_ERR(condition) assert(condition)

#endif /* _IPC_H_ */
