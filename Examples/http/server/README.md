# How to Test HTTP Server Example



## Step 1: Prepare software

The following serial terminal program is required for HTTP Server example test, download and install from below link.

- [**Tera Term**][link-tera_term]



## Step 2: Prepare hardware

1. Combine W5300 TOE Shield with STM32 Nucleo-144 board.

2. Connect ethernet cable to W5300 TOE Shield ethernet port.

3. Connect STM32 Nucleo-144 board to desktop or laptop using 5 pin micro USB cable.



## Step 3: Setup HTTP Server Example

To test the HTTP Server example, minor settings shall be done in code.

1. Select demo application.

To run the HTTP Server example, you must select the **demo application** in '**w5x00_demo.h**' in '**W5300-TOE-C/Examples/**' directory.

uncomment **APP_HTTP_SERVER** and comment the rest of the defined demo application macros.

```cpp
// ----------------------------------------------------------------------------------------------------
// The application you wish to use should be uncommented
// ----------------------------------------------------------------------------------------------------
//#define APP_DHCP
//#define APP_DNS
#define APP_HTTP_SERVER
//#define APP_MQTT_PUBLISH
//#define APP_MQTT_SUBSCRIBE
//#define APP_MQTT_PUBLISH_SUBSCRIBE
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



## Step 4: Build and Download

1. After completing the HTTP Server example configuration, build in the IDE you are using.

2. When the build is completed, download the firmware to the STM32 Nucleo-144 board.



## Step 5: Run

1. Connect to the serial COM port of STM32 Nucleo-144 board with Tera Term.

![][link-connect_to_serial_com_port]

2. Reset your board.

3. If the HTTP Server example works normally on STM32 Nucleo-144 board, you can see the network information of STM32 Nucleo-144 board and the HTTP server is open.

![][link-network_information_of_stm32_nucleo-144_board_and_open_http_server]

6. Connect to the open HTTP server, you can see the output on the web page. When connecting to the HTTP server, you need to enter is the IP that was configured in Step 3.

![][link-connect_to_http_server_1]

![][link-connect_to_http_server_2]



<!--
Link
-->

[link-tera_term]: https://osdn.net/projects/ttssh2/releases/
[link-connect_to_serial_com_port]: https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/images/http/server/connect_to_serial_com_port.png
[link-network_information_of_stm32_nucleo-144_board_and_open_http_server]: https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/images/http/server/network_information_of_stm32_nucleo-144_board_and_open_http_server.png
[link-connect_to_http_server_1]: https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/images/http/server/connect_to_http_server_1.png
[link-connect_to_http_server_2]: https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/images/http/server/connect_to_http_server_2.png
