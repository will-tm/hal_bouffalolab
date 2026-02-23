/*
 * Copyright The Zephyr Project Contributors
 * SPDX-License-Identifier: Apache-2.0
 *
 * Based on Bouffalo Lab SDK bl_os_log.h (Apache-2.0)
 */

#ifndef _BL_OS_LOG_H_
#define _BL_OS_LOG_H_

#include <bl_os_adapter/bl_os_adapter.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum _bl_os_log_leve {
	LOG_LEVEL_ALL = 0,
	LOG_LEVEL_DEBUG,
	LOG_LEVEL_INFO,
	LOG_LEVEL_WARN,
	LOG_LEVEL_ERROR,
	LOG_LEVEL_ASSERT,
	LOG_LEVEL_NEVER,
} bl_os_log_level_t;

#define bl_os_log_printf g_bl_ops_funcs._log_write

#ifndef __FILENAME__
#define __FILENAME__ __FILE__
#endif

#define bl_os_log_debug(M, ...)                                                                    \
	bl_os_log_printf(LOG_LEVEL_DEBUG, NULL, __FILENAME__, __LINE__, M, ##__VA_ARGS__);

#define bl_os_log_info(M, ...)                                                                     \
	bl_os_log_printf(LOG_LEVEL_INFO, NULL, __FILENAME__, __LINE__, M, ##__VA_ARGS__);

#define bl_os_log_warn(M, ...)                                                                     \
	bl_os_log_printf(LOG_LEVEL_WARN, NULL, __FILENAME__, __LINE__, M, ##__VA_ARGS__);

#define bl_os_log_error(M, ...)                                                                    \
	bl_os_log_printf(LOG_LEVEL_ERROR, NULL, __FILENAME__, __LINE__, M, ##__VA_ARGS__);

#ifdef __cplusplus
}
#endif

#endif /* _BL_OS_LOG_H_ */
