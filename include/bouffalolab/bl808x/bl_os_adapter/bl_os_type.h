/*
 * Copyright The Zephyr Project Contributors
 * SPDX-License-Identifier: Apache-2.0
 *
 * Based on Bouffalo Lab SDK bl_os_type.h (Apache-2.0)
 */

#ifndef _BL_OS_TYPE_H_
#define _BL_OS_TYPE_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void *BL_Timer_t;
typedef void *BL_TaskHandle_t;
typedef void *BL_Sem_t;
typedef void *BL_Mutex_t;
typedef void *BL_MessageQueue_t;
typedef void *BL_EventGroup_t;
typedef void *BL_TimeOut_t;
typedef uint32_t BL_TickType_t;

#ifdef __cplusplus
}
#endif

#endif /* _BL_OS_TYPE_H_ */
