/*
 * Copyright (C) Bouffalo Lab 2016-2018
 * SPDX-License-Identifier: Apache-2.0
 *
 * WiFi netif stubs — not used in Zephyr (uses net_if instead).
 */

#ifndef __WIFI_NETIF_H__
#define __WIFI_NETIF_H__

struct netif;

/* These are stubs — Zephyr uses its own networking stack */
int wifi_netif_dhcp_start(struct netif *netif);
int wifi_netif_dhcp_stop(struct netif *netif);

#endif /* __WIFI_NETIF_H__ */
