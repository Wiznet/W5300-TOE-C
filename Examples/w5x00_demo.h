/**
 * Copyright (c) 2023 WIZnet Co.,Ltd
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _W5X00_DEMO_H_
#define _W5X00_DEMO_H_

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * ----------------------------------------------------------------------------------------------------
 * Includes
 * ----------------------------------------------------------------------------------------------------
 */

/**
 * ----------------------------------------------------------------------------------------------------
 * Macros
 * ----------------------------------------------------------------------------------------------------
 */
// ----------------------------------------------------------------------------------------------------
// The application you wish to use should be uncommented
// ----------------------------------------------------------------------------------------------------
//#define APP_DHCP
//#define APP_DNS
//#define APP_HTTP_SERVER
//#define APP_MQTT_PUBLISH
//#define APP_MQTT_SUBSCRIBE
//#define APP_MQTT_PUBLISH_SUBSCRIBE
//#define APP_SNTP
//#define APP_TCP_CLIENT_OVER_SSL
#define APP_LOOPBACK
// ----------------------------------------------------------------------------------------------------

/**
 * ----------------------------------------------------------------------------------------------------
 * Variables
 * ----------------------------------------------------------------------------------------------------
 */

/**
 * ----------------------------------------------------------------------------------------------------
 * Functions
 * ----------------------------------------------------------------------------------------------------
 */
void dhcp_demo(wiz_NetInfo *net_info);
void dns_demo(wiz_NetInfo *net_info);
void http_server_demo(wiz_NetInfo *net_info);
void mqtt_publish_demo(wiz_NetInfo *net_info);
void mqtt_subscribe_demo(wiz_NetInfo *net_info);
void mqtt_publish_subscribe_demo(wiz_NetInfo *net_info);
void sntp_demo(wiz_NetInfo *net_info);
void tcp_client_over_ssl_demo(wiz_NetInfo *net_info);
void loopback_demo(wiz_NetInfo *net_info);

#ifdef __cplusplus
}
#endif

#endif /* _W5X00_DEMO_H_ */
