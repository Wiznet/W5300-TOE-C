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

#include "dhcp.h"

/**
 * ----------------------------------------------------------------------------------------------------
 * Macros
 * ----------------------------------------------------------------------------------------------------
 */
#define SOCKET_DHCP 0

#define DHCP_RETRY_COUNT 5

/**
 * ----------------------------------------------------------------------------------------------------
 * Variables
 * ----------------------------------------------------------------------------------------------------
 */
static wiz_NetInfo *g_net_info;

static uint8_t g_dhcp_buf[ETHERNET_BUF_MAX_SIZE] = {
    0,
};

/**
 * ----------------------------------------------------------------------------------------------------
 * Functions
 * ----------------------------------------------------------------------------------------------------
 */
static void repeating_timer_callback(void)
{
  DHCP_time_handler();
}

static void wizchip_dhcp_assign(void)
{
  getIPfromDHCP(g_net_info->ip);
  getGWfromDHCP(g_net_info->gw);
  getSNfromDHCP(g_net_info->sn);
  getDNSfromDHCP(g_net_info->dns);

  ctlnetwork(CN_SET_NETINFO, (void *)g_net_info);

  wizchip_network_information(g_net_info);
  printf(" DHCP leased time : %ld seconds\n", getDHCPLeasetime());
}

static void wizchip_dhcp_conflict(void)
{
  printf(" Conflict IP from DHCP\n");

  // halt or reset or any...
  while (1)
    ; // this example is halt.
}

static void wizchip_dhcp_init(void)
{
  printf(" DHCP client running\n");

  DHCP_init(SOCKET_DHCP, g_dhcp_buf);

  reg_dhcp_cbfunc(wizchip_dhcp_assign, wizchip_dhcp_assign, wizchip_dhcp_conflict);
}

void dhcp_demo(wiz_NetInfo *net_info)
{
  int retval = 0;
  uint8_t dhcp_retry = 0;

  g_net_info = net_info;

  wizchip_network_initialize(g_net_info);
  wizchip_1sec_timer_initialize(repeating_timer_callback);

  if (g_net_info->dhcp == NETINFO_DHCP) // DHCP
  {
    wizchip_dhcp_init();
  }
  else // static
  {
    ctlnetwork(CN_SET_NETINFO, (void *)g_net_info);

    wizchip_network_information(g_net_info);
  }

  /* Infinite loop */
  while (1)
  {
    /* Assigned IP through DHCP */
    if (g_net_info->dhcp == NETINFO_DHCP)
    {
      retval = DHCP_run();

      if (retval == DHCP_IP_LEASED)
      {
        printf(" DHCP success\n");

        break;
      }
      else if (retval == DHCP_FAILED)
      {
        dhcp_retry++;

        if (dhcp_retry <= DHCP_RETRY_COUNT)
        {
          printf(" DHCP timeout occurred and retry %d\n", dhcp_retry);
        }
      }

      if (dhcp_retry > DHCP_RETRY_COUNT)
      {
        printf(" DHCP failed\n");

        DHCP_stop();

        while (1)
          ;
      }

      wizchip_delay_msec(1000);
    }
  }
}
