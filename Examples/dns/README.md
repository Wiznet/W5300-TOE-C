# How to Test DNS Example



## Step 1: Prepare software

The following serial terminal program is required for DNS example test, download and install from below link.

- [**Tera Term**][link-tera_term]



## Step 2: Prepare hardware

1. Combine W5300 TOE Shield with STM32 Nucleo-144 board.

2. Connect ethernet cable to W5300 TOE Shield ethernet port.

3. Connect STM32 Nucleo-144 board to desktop or laptop using 5 pin micro USB cable.



## Step 3: Setup DNS Example

To test the DNS example, minor settings shall be done in code.

1. Select demo application.

To run the DNS example, you must select the **demo application** in '**w5x00_demo.h**' in '**W5300-TOE-C/Examples/**' directory.

uncomment **APP_DNS** and comment the rest of the defined demo application macros.

```cpp
// ----------------------------------------------------------------------------------------------------
// The application you wish to use should be uncommented
// ----------------------------------------------------------------------------------------------------
//#define APP_DHCP
#define APP_DNS
//#define APP_HTTP_SERVER
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

3. Setup DNS configuration.

Setup the **domain name** that you want to get IP in '**w5x00_dns.c**' in '**W5300-TOE-C/Examples/dns/**' directory.

```cpp
static uint8_t g_dns_target_domain[] = "www.wiznet.io";
```



## Step 4: Build and Download

1. After completing the DNS example configuration, build in the IDE you are using.

2. When the build is completed, download the firmware to the STM32 Nucleo-144 board.



## Step 5: Run

1. Connect to the serial COM port of STM32 Nucleo-144 board with Tera Term.

![][link-connect_to_serial_com_port]

2. Reset your board.

3. If the DNS example works normally on STM32 Nucleo-144 board, you can see the network information of STM32 Nucleo-144 board and the IP get from the domain name.

![][link-network_information_of_stm32_nucleo-144_board_and_get_ip_through_dns]



<!--
Link
-->

[link-tera_term]: https://osdn.net/projects/ttssh2/releases/
[link-connect_to_serial_com_port]: https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/images/dns/connect_to_serial_com_port.png
[link-network_information_of_stm32_nucleo-144_board_and_get_ip_through_dns]: https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/images/dns/network_information_of_stm32_nucleo-144_board_and_get_ip_through_dns.png
