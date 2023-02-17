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
#include <stdio.h>

#include "wizchip_conf.h"
#include "w5x00_network.h"
#include "w5x00_timer.h"
#include "w5x00_demo.h"

#include "sntp.h"

/**
 * ----------------------------------------------------------------------------------------------------
 * Macros
 * ----------------------------------------------------------------------------------------------------
 */
#define SOCKET_SNTP 0

#define TIMEZONE 40 // Korea

#define STNP_TIMEOUT (1000 * 10) // 10 seconds

/**
 * ----------------------------------------------------------------------------------------------------
 * Variables
 * ----------------------------------------------------------------------------------------------------
 */
static uint8_t g_sntp_buf[ETHERNET_BUF_MAX_SIZE] = {
    0,
};
static uint8_t g_sntp_server_ip[4] = {216, 239, 35, 0}; // time.google.com

/**
 * ----------------------------------------------------------------------------------------------------
 * Functions
 * ----------------------------------------------------------------------------------------------------
 */
void sntp_demo(wiz_NetInfo *net_info)
{
  int retval = 0;
  uint32_t start_msec = 0;
  datetime time;

  wizchip_network_initialize(net_info);
  wizchip_network_information(net_info);

  SNTP_init(SOCKET_SNTP, g_sntp_server_ip, TIMEZONE, g_sntp_buf);

  start_msec = wizchip_get_msec_tick();

  /* Get time */
  do
  {
    retval = SNTP_run(&time);

    if (retval == 1)
    {
      break;
    }
  } while (wizchip_get_msec_tick() - start_msec < STNP_TIMEOUT);

  if (retval != 1)
  {
    printf(" SNTP failed : %d\n", retval);

    while (1)
      ;
  }

  printf(" Current time : %d-%d-%d, %d:%d:%d\n", time.yy, time.mo, time.dd, time.hh, time.mm, time.ss);

  /* Infinite loop */
  while (1)
  {
    ;
  }
}
