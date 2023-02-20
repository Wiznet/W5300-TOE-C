# How to Test MQTT Publish & Subscribe Example



## Step 1: Prepare software

The following serial terminal program and MQTT broker are required for MQTT Publish & Subscribe example test, download and install from below links.

- [**Tera Term**][link-tera_term]
- [**Mosquitto**][link-mosquitto]



## Step 2: Prepare hardware

1. Combine W5300 TOE Shield with STM32 Nucleo-144 board.

2. Connect ethernet cable to W5300 TOE Shield ethernet port.

3. Connect STM32 Nucleo-144 board to desktop or laptop using 5 pin micro USB cable.



## Step 3: Setup MQTT Publish & Subscribe Example

To test the MQTT Publish & Subscribe example, minor settings shall be done in code.

1. Select demo application.

To run the MQTT Publish & Subscribe example, you must select the **demo application** in '**w5x00_demo.h**' in '**W5300-TOE-C/Examples/**' directory.

uncomment **APP_MQTT_PUBLISH_SUBSCRIBE** and comment the rest of the defined demo application macros.

```cpp
// ----------------------------------------------------------------------------------------------------
// The application you wish to use should be uncommented
// ----------------------------------------------------------------------------------------------------
//#define APP_DHCP
//#define APP_DNS
//#define APP_HTTP_SERVER
//#define APP_MQTT_PUBLISH
//#define APP_MQTT_SUBSCRIBE
#define APP_MQTT_PUBLISH_SUBSCRIBE
//#define APP_SNTP
//#define APP_TCP_CLIENT_OVER_SSL
//#define APP_LOOPBACK
// ----------------------------------------------------------------------------------------------------
```

2. Setup network configuration.

Setup **network configuration** such as IP in '**main.c**' in '**W5300-TOE-C/Projects/NUCLEO-F429ZI/Core/Src/**' directory.

```cpp
  wiz_NetInfo net_info =
      {
          .mac = {0x00, 0x08, 0xDC, 0x12, 0x34, 0x56}, // MAC address
          .ip = {192, 168, 11, 2},                     // IP address
          .sn = {255, 255, 255, 0},                    // Subnet Mask
          .gw = {192, 168, 11, 1},                     // Gateway
          .dns = {8, 8, 8, 8},                         // DNS server
#ifdef APP_DHCP
          .dhcp = NETINFO_DHCP                         // Dynamic IP
#else
          .dhcp = NETINFO_STATIC                       // Static IP
#endif
      };
```

3. Setup MQTT configuration.

In the MQTT configuration, the **broker IP** is the IP of your desktop or laptop where broker will be created.

You can modify it in '**w5x00_mqtt_publish_subscribe.c**' in '**W5300-TOE-C/Examples/mqtt/publish_subscribe/**' directory.

```cpp
static uint8_t g_mqtt_broker_ip[4] = {192, 168, 11, 3};
```

And setup information such as broker **port number**, **publush topic** and **subscribe topic** in '**w5x00_mqtt_info.h**' in '**W5300-TOE-C/Examples/mqtt/**' directory.

```cpp
#define PORT_MQTT 1883

#define MQTT_CLIENT_ID "w5300-toe"
#define MQTT_USERNAME "wiznet"
#define MQTT_PASSWORD "0123456789"
#define MQTT_PUBLISH_TOPIC "publish_topic"
#define MQTT_PUBLISH_PAYLOAD "Hello, World!"
#define MQTT_PUBLISH_PERIOD (1000 * 10) // unit : millisecond
#define MQTT_SUBSCRIBE_TOPIC "subscribe_topic"
#define MQTT_KEEP_ALIVE 60      // unit : second
#define MQTT_TIMEOUT (1000 * 1) // unit : millisecond
```



## Step 4: Build and Download

1. After completing the MQTT Publish & Subscribe example configuration, build in the IDE you are using.

2. When the build is completed, download the firmware to the STM32 Nucleo-144 board.



## Step 5: Run

1. Connect to the serial COM port of STM32 Nucleo-144 board with Tera Term.

![][link-connect_to_serial_com_port]

2. Run Mosquitto to be used as the broker.

![][link-run_mosquitto]

3. Create broker using Mosquitto by entering the following command. If the broker is created normally, the broker's IP is the current IP of your desktop or laptop, and the port is 1883 by default.

```cpp
mosquitto -c mosquitto.conf -v
```

![][link-create_broker_using_mosquitto]

4. Reset your board.

5. If the MQTT Publish & Subscribe example works normally on STM32 Nucleo-144 board, you can see the network information of STM32 Nucleo-144 board, connecting to the broker, subscribing to the subscribe topic and publishing the message.

![][link-network_information_of_stm32_nucleo-144_board_connecting_to_broker_subscribing_to_subscribe_topic_and_publishing_message_1]

![][link-network_information_of_stm32_nucleo-144_board_connecting_to_broker_subscribing_to_subscribe_topic_and_publishing_message_2]



## Appendix

- In Mosquitto versions earlier than 2.0 the default is to allow clients to connect without authentication. In 2.0 and up, you must choose your authentication options explicitly before clients can connect. Therefore, if you are using version 2.0 or later, refer to following link to setup 'mosquitto.conf' in the directory where Mosquitto is installed.

    - [**Authentication Methods**][link-authentication_methods]



<!--
Link
-->

[link-tera_term]: https://osdn.net/projects/ttssh2/releases/
[link-mosquitto]: https://mosquitto.org/download/
[link-connect_to_serial_com_port]: https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/images/mqtt/publish_subscribe/connect_to_serial_com_port.png
[link-run_mosquitto]: https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/images/mqtt/publish_subscribe/run_mosquitto.png
[link-create_broker_using_mosquitto]: https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/images/mqtt/publish_subscribe/create_broker_using_mosquitto.png
[link-network_information_of_stm32_nucleo-144_board_connecting_to_broker_subscribing_to_subscribe_topic_and_publishing_message_1]: https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/images/mqtt/publish_subscribe/network_information_of_stm32_nucleo-144_board_connecting_to_broker_subscribing_to_subscribe_topic_and_publishing_message_1.png
[link-network_information_of_stm32_nucleo-144_board_connecting_to_broker_subscribing_to_subscribe_topic_and_publishing_message_2]: https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/images/mqtt/publish_subscribe/network_information_of_stm32_nucleo-144_board_connecting_to_broker_subscribing_to_subscribe_topic_and_publishing_message_2.png
[link-authentication_methods]: https://mosquitto.org/documentation/authentication-methods/
