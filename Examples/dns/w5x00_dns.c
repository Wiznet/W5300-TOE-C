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

#include "dns.h"

/**
 * ----------------------------------------------------------------------------------------------------
 * Macros
 * ----------------------------------------------------------------------------------------------------
 */
#define SOCKET_DNS 0

#define DNS_RETRY_COUNT 5

/**
 * ----------------------------------------------------------------------------------------------------
 * Variables
 * ----------------------------------------------------------------------------------------------------
 */
static uint8_t g_dns_buf[ETHERNET_BUF_MAX_SIZE] = {
    0,
};
static uint8_t g_dns_target_ip[4] = {
    0,
};
static uint8_t g_dns_target_domain[] = "www.wiznet.io";

/**
 * ----------------------------------------------------------------------------------------------------
 * Functions
 * ----------------------------------------------------------------------------------------------------
 */
static void repeating_timer_callback(void)
{
  DNS_time_handler();
}

void dns_demo(wiz_NetInfo *net_info)
{
  uint8_t dns_retry = 0;

  wizchip_network_initialize(net_info);
  wizchip_network_information(net_info);
  wizchip_1sec_timer_initialize(repeating_timer_callback);

  DNS_init(SOCKET_DNS, g_dns_buf);

  /* Infinite loop */
  while (1)
  {
    /* Get IP through DNS */
    if (DNS_run(net_info->dns, g_dns_target_domain, g_dns_target_ip) > 0)
    {
      printf(" DNS success\n");
      printf(" Target domain : %s\n", g_dns_target_domain);
      printf(" IP of target domain : %d.%d.%d.%d\n", g_dns_target_ip[0], g_dns_target_ip[1], g_dns_target_ip[2], g_dns_target_ip[3]);

      break;
    }
    else
    {
      dns_retry++;

      if (dns_retry <= DNS_RETRY_COUNT)
      {
        printf(" DNS timeout occurred and retry %d\n", dns_retry);
      }
    }

    if (dns_retry > DNS_RETRY_COUNT)
    {
      printf(" DNS failed\n");

      while (1)
        ;
    }

    wizchip_delay_msec(1000);
  }
}
