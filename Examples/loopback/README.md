# How to Test Loopback Example



## Step 1: Prepare software

The following serial terminal programs are required for Loopback example test, download and install from below links.

- [**Tera Term**][link-tera_term]
- [**Hercules**][link-hercules]



## Step 2: Prepare hardware

1. Combine W5300 TOE Shield with STM32 Nucleo-144 board.

2. Connect ethernet cable to W5300 TOE Shield ethernet port.

3. Connect STM32 Nucleo-144 board to desktop or laptop using 5 pin micro USB cable.



## Step 3: Setup Loopback Example

To test the Loopback example, minor settings shall be done in code.

1. Select demo application.

To run the Loopback example, you must select the **demo application** in '**w5x00_demo.h**' in '**W5300-TOE-C/Examples/**' directory.

uncomment **APP_LOOPBACK** and comment the rest of the defined demo application macros.

```cpp
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
#define APP_LOOPBACK
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

3. Setup Loopback configuration.

Setup loopback server **port number** in '**w5x00_loopback.c**' in '**W5300-TOE-C/Examples/loopback/**' directory.

```cpp
#define PORT_LOOPBACK 5000
```



## Step 4: Build and Download

1. After completing the Loopback example configuration, build in the IDE you are using.

2. When the build is completed, download the firmware to the STM32 Nucleo-144 board.



## Step 5: Run

1. Connect to the serial COM port of STM32 Nucleo-144 board with Tera Term.

![][link-connect_to_serial_com_port]

2. Reset your board.

3. If the Loopback example works normally on STM32 Nucleo-144 board, you can see the network information of STM32 Nucleo-144 board and the loopback server is open.

![][link-network_information_of_stm32_nucleo-144_board_and_open_loopback_server]

4. Connect to the open loopback server using Hercules TCP client. When connecting to the loopback server, you need to enter is the IP that was configured in Step 3, the port is 5000 by default.

![][link-connect_to_loopback_server_using_hercules_tcp_client_1]

![][link-connect_to_loopback_server_using_hercules_tcp_client_2]

5. Once connected if you send data to the loopback server, you should be able to receive back the sent message.

![][link-receive_back_sent_message]



<!--
Link
-->

[link-tera_term]: https://osdn.net/projects/ttssh2/releases/
[link-hercules]: https://www.hw-group.com/software/hercules-setup-utility
[link-connect_to_serial_com_port]: https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/images/loopback/connect_to_serial_com_port.png
[link-network_information_of_stm32_nucleo-144_board_and_open_loopback_server]: https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/images/loopback/network_information_of_stm32_nucleo-144_board_and_open_loopback_server.png
[link-connect_to_loopback_server_using_hercules_tcp_client_1]: https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/images/loopback/connect_to_loopback_server_using_hercules_tcp_client_1.png
[link-connect_to_loopback_server_using_hercules_tcp_client_2]: https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/images/loopback/connect_to_loopback_server_using_hercules_tcp_client_2.png
[link-receive_back_sent_message]: https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/images/loopback/receive_back_sent_message.png
