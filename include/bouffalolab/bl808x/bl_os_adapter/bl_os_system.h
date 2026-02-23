/*
 * Copyright The Zephyr Project Contributors
 * SPDX-License-Identifier: Apache-2.0
 *
 * Based on Bouffalo Lab SDK bl_os_system.h (Apache-2.0)
 */

#ifndef _BL_OS_SYSTEM_H_
#define _BL_OS_SYSTEM_H_

#include <bl_os_adapter/bl_os_adapter.h>

#ifdef __cplusplus
extern "C" {
#endif

#define bl_os_enter_critical()                                                                     \
	{                                                                                          \
		uint32_t _bl_os_flag;                                                              \
		_bl_os_flag = g_bl_ops_funcs._enter_critical();

#define bl_os_exit_critical()                                                                      \
	g_bl_ops_funcs._exit_critical(_bl_os_flag);                                                \
	}

#define bl_os_printf(M, ...) g_bl_ops_funcs._printf(M, ##__VA_ARGS__)
#define bl_os_puts(S)        g_bl_ops_funcs._puts(S)
#define bl_os_msleep         g_bl_ops_funcs._msleep
#define bl_os_sleep          g_bl_ops_funcs._sleep

#define bl_os_event_group_create g_bl_ops_funcs._event_group_create
#define bl_os_event_group_delete g_bl_ops_funcs._event_group_delete
#define bl_os_event_group_send   g_bl_ops_funcs._event_group_send
#define bl_os_event_group_wait   g_bl_ops_funcs._event_group_wait
#define bl_os_event_register     g_bl_ops_funcs._event_register
#define bl_os_event_notify       g_bl_ops_funcs._event_notify

#define bl_os_task_create           g_bl_ops_funcs._task_create
#define bl_os_task_delete           g_bl_ops_funcs._task_delete
#define bl_os_task_get_current_task g_bl_ops_funcs._task_get_current_task
#define bl_os_task_notify_create    g_bl_ops_funcs._task_notify_create
#define bl_os_task_notify           g_bl_ops_funcs._task_notify
#define bl_os_task_wait             g_bl_ops_funcs._task_wait

#define bl_os_irq_attach  g_bl_ops_funcs._irq_attach
#define bl_os_irq_enable  g_bl_ops_funcs._irq_enable
#define bl_os_irq_disable g_bl_ops_funcs._irq_disable

#define bl_os_workqueue_create    g_bl_ops_funcs._workqueue_create
#define bl_os_workqueue_submit_hp g_bl_ops_funcs._workqueue_submit_hp
#define bl_os_workqueue_submit_lp g_bl_ops_funcs._workqueue_submit_lp

#define bl_os_timer_create         g_bl_ops_funcs._timer_create
#define bl_os_timer_delete         g_bl_ops_funcs._timer_delete
#define bl_os_timer_start_once     g_bl_ops_funcs._timer_start_once
#define bl_os_timer_start_periodic g_bl_ops_funcs._timer_start_periodic

#define bl_os_sem_create g_bl_ops_funcs._sem_create
#define bl_os_sem_delete g_bl_ops_funcs._sem_delete
#define bl_os_sem_take   g_bl_ops_funcs._sem_take
#define bl_os_sem_give   g_bl_ops_funcs._sem_give

#define bl_os_mutex_create g_bl_ops_funcs._mutex_create
#define bl_os_mutex_delete g_bl_ops_funcs._mutex_delete
#define bl_os_mutex_lock   g_bl_ops_funcs._mutex_lock
#define bl_os_mutex_unlock g_bl_ops_funcs._mutex_unlock

#define bl_os_queue_create    g_bl_ops_funcs._queue_create
#define bl_os_queue_delete    g_bl_ops_funcs._queue_delete
#define bl_os_queue_send_wait g_bl_ops_funcs._queue_send_wait
#define bl_os_queue_send      g_bl_ops_funcs._queue_send
#define bl_os_queue_recv      g_bl_ops_funcs._queue_recv

#define bl_os_malloc g_bl_ops_funcs._malloc
#define bl_os_free   g_bl_ops_funcs._free
#define bl_os_zalloc g_bl_ops_funcs._zalloc

#define bl_os_get_time_ms g_bl_ops_funcs._get_time_ms
#define bl_os_get_tick    g_bl_ops_funcs._get_tick

#ifdef __cplusplus
}
#endif

#endif /* _BL_OS_SYSTEM_H_ */
