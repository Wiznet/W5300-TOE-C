/**
 * Copyright (c) 2023 WIZnet Co.,Ltd
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * ----------------------------------------------------------------------------------------------------
 * Includes
 * ----------------------------------------------------------------------------------------------------
 */
#include "wizchip_conf.h"
#include "w5x00_network.h"
#include "w5x00_demo.h"

#include "httpServer.h"
#include "web_page.h"

/**
 * ----------------------------------------------------------------------------------------------------
 * Macros
 * ----------------------------------------------------------------------------------------------------
 */
#define HTTP_SOCKET_MAX_NUM 4

/**
 * ----------------------------------------------------------------------------------------------------
 * Variables
 * ----------------------------------------------------------------------------------------------------
 */
static uint8_t g_http_send_buf[ETHERNET_BUF_MAX_SIZE] = {
    0,
};
static uint8_t g_http_recv_buf[ETHERNET_BUF_MAX_SIZE] = {
    0,
};
static uint8_t g_http_socket_num_list[HTTP_SOCKET_MAX_NUM] = {0, 1, 2, 3};

/**
 * ----------------------------------------------------------------------------------------------------
 * Functions
 * ----------------------------------------------------------------------------------------------------
 */
void http_server_demo(wiz_NetInfo *net_info)
{
  uint8_t i = 0;

  wizchip_network_initialize(net_info);
  wizchip_network_information(net_info);

  httpServer_init(g_http_send_buf, g_http_recv_buf, HTTP_SOCKET_MAX_NUM, g_http_socket_num_list);

  reg_httpServer_webContent("index.html", index_page);

  /* Infinite loop */
  while (1)
  {
    for (i = 0; i < HTTP_SOCKET_MAX_NUM; i++)
    {
      /* Run HTTP server */
      httpServer_run(i);
    }
  }
}
