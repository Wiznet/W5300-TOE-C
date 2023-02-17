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
#include <string.h>

#include "wizchip_conf.h"
#include "w5x00_network.h"
#include "w5x00_timer.h"
#include "w5x00_demo.h"
#include "w5x00_mqtt_info.h"

#include "mqtt_interface.h"
#include "MQTTClient.h"

/**
 * ----------------------------------------------------------------------------------------------------
 * Macros
 * ----------------------------------------------------------------------------------------------------
 */

/**
 * ----------------------------------------------------------------------------------------------------
 * Variables
 * ----------------------------------------------------------------------------------------------------
 */
static uint8_t g_mqtt_send_buf[ETHERNET_BUF_MAX_SIZE] = {
    0,
};
static uint8_t g_mqtt_recv_buf[ETHERNET_BUF_MAX_SIZE] = {
    0,
};
static uint8_t g_mqtt_broker_ip[4] = {192, 168, 11, 3};
static Network g_mqtt_network;
static MQTTClient g_mqtt_client;
static MQTTPacket_connectData g_mqtt_packet_connect_data = MQTTPacket_connectData_initializer;
static MQTTMessage g_mqtt_message;

/**
 * ----------------------------------------------------------------------------------------------------
 * Functions
 * ----------------------------------------------------------------------------------------------------
 */
void mqtt_publish_demo(wiz_NetInfo *net_info)
{
  int retval = 0;
  uint32_t start_msec = 0;
  uint32_t end_msec = 0;

  wizchip_network_initialize(net_info);
  wizchip_network_information(net_info);

  NewNetwork(&g_mqtt_network, SOCKET_MQTT);

  retval = ConnectNetwork(&g_mqtt_network, g_mqtt_broker_ip, PORT_MQTT);

  if (retval != 1)
  {
    printf(" Network connect failed\n");

    while (1)
      ;
  }

  MQTTClientInit(&g_mqtt_client, &g_mqtt_network, MQTT_TIMEOUT, g_mqtt_send_buf, ETHERNET_BUF_MAX_SIZE, g_mqtt_recv_buf, ETHERNET_BUF_MAX_SIZE);

  g_mqtt_packet_connect_data.MQTTVersion = 3;
  g_mqtt_packet_connect_data.cleansession = 1;
  g_mqtt_packet_connect_data.willFlag = 0;
  g_mqtt_packet_connect_data.keepAliveInterval = MQTT_KEEP_ALIVE;
  g_mqtt_packet_connect_data.clientID.cstring = MQTT_CLIENT_ID;
  g_mqtt_packet_connect_data.username.cstring = MQTT_USERNAME;
  g_mqtt_packet_connect_data.password.cstring = MQTT_PASSWORD;

  retval = MQTTConnect(&g_mqtt_client, &g_mqtt_packet_connect_data);

  if (retval < 0)
  {
    printf(" MQTT connect failed : %d\n", retval);

    while (1)
      ;
  }

  printf(" MQTT connected\n");

  g_mqtt_message.qos = QOS0;
  g_mqtt_message.retained = 0;
  g_mqtt_message.dup = 0;
  g_mqtt_message.payload = MQTT_PUBLISH_PAYLOAD;
  g_mqtt_message.payloadlen = strlen(g_mqtt_message.payload);

  /* Infinite loop */
  while (1)
  {
    if ((retval = MQTTYield(&g_mqtt_client, g_mqtt_packet_connect_data.keepAliveInterval)) < 0)
    {
      printf(" Yield error : %d\n", retval);

      while (1)
        ;
    }

    end_msec = wizchip_get_msec_tick();

    if (end_msec > start_msec + MQTT_PUBLISH_PERIOD)
    {
      /* Publish */
      retval = MQTTPublish(&g_mqtt_client, MQTT_PUBLISH_TOPIC, &g_mqtt_message);

      if (retval < 0)
      {
        printf(" Publish failed : %d\n", retval);

        while (1)
          ;
      }

      printf(" Published\n");

      start_msec = wizchip_get_msec_tick();
    }
  }
}
