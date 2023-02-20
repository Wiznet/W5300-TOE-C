# How to Test TCP Client over SSL Example



## Step 1: Prepare software

The following serial terminal program and SSL server are required for TCP Client over SSL example test, download and install from below links.

- [**Tera Term**][link-tera_term]
- [**OpenSSL**][link-openssl]



## Step 2: Prepare hardware

1. Combine W5300 TOE Shield with STM32 Nucleo-144 board.

2. Connect ethernet cable to W5300 TOE Shield ethernet port.

3. Connect STM32 Nucleo-144 board to desktop or laptop using 5 pin micro USB cable.



## Step 3: Setup TCP Client over SSL Example

To test the TCP Client over SSL example, minor settings shall be done in code.

1. Select demo application.

To run the TCP Client over SSL example, you must select the **demo application** in '**w5x00_demo.h**' in '**W5300-TOE-C/Examples/**' directory.

uncomment **APP_TCP_CLIENT_OVER_SSL** and comment the rest of the defined demo application macros.

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
#define APP_TCP_CLIENT_OVER_SSL
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

3. Setup SSL configuration.

Setup SSL server **port number** and **IP** in '**w5x00_tcp_client_over_ssl.c**' in '**W5300-TOE-C/Examples/tcp_client_over_ssl/**' directory.

The SSL server IP is the IP of your desktop or laptop where SSL server will be created.

```cpp
#define PORT_SSL 443

static uint8_t g_ssl_target_ip[4] = {192, 168, 11, 3};
```



## Step 4: Build and Download

1. After completing the TCP Client over SSL example configuration, build in the IDE you are using.

2. When the build is completed, download the firmware to the STM32 Nucleo-144 board.



## Step 5: Run

1. Connect to the serial COM port of STM32 Nucleo-144 board with Tera Term.

![][link-connect_to_serial_com_port]

2. Run OpenSSL to be used as the SSL server.

![][link-run_openssl]

3. Create SSL server using openSSL by entering the following command. If the SSL server is created normally, the SSL server's IP is the current IP of your desktop or laptop, and the port is 443 by default.

```bash
/* Setup the SSL server */
// create the private key
genrsa -des3 -out [key name].key 2048
// create the CSR(required for certificate signing request)
req -new -key [key name].key -out [csr name].csr
// create the certificate
x509 -req -days [days] -in [csr name].csr -signkey [key name].key -out [crt name].crt

// e.g.
genrsa -des3 -out server.key 2048
req -new -key server.key -out server.csr
x509 -req -days 365 -in server.csr -signkey server.key -out server.crt

/* Run the SSL server */
s_server -accept [port] -cert [crt name].crt -key [key name].key

// e.g.
s_server -accept 443 -cert server.crt -key server.key
```

![][link-create_ssl_server_using_openssl]

4. Reset your board.

5. If the TCP Client over SSL example works normally on STM32 Nucleo-144 board, you can see the network information of STM32 Nucleo-144 board, connecting to the SSL server and sending the message.

![][link-network_information_of_stm32_nucleo-144_board_connecting_to_ssl_server_and_sending_message_1]

![][link-network_information_of_stm32_nucleo-144_board_connecting_to_ssl_server_and_sending_message_2]

6. Once connected if you send data to the STM32 Nucleo-144 board from the SSL server, you should be able to receive the sent message on STM32 Nucleo-144 board.

![][link-receive_sent_message_1]

![][link-receive_sent_message_2]



## Appendix

- mbedTLS library was ported to use SSL/TLS, please refer to following link to find version of ported Mbed TLS.

    - [**Mbed TLS**][link-mbed_tls]



<!--
Link
-->

[link-tera_term]: https://osdn.net/projects/ttssh2/releases/
[link-openssl]: https://www.openssl.org/source/
[link-connect_to_serial_com_port]: https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/images/tcp_client_over_ssl/connect_to_serial_com_port.png
[link-run_openssl]: https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/images/tcp_client_over_ssl/run_openssl.png
[link-create_ssl_server_using_openssl]: https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/images/tcp_client_over_ssl/create_ssl_server_using_openssl.png
[link-network_information_of_stm32_nucleo-144_board_connecting_to_ssl_server_and_sending_message_1]: https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/images/tcp_client_over_ssl/network_information_of_stm32_nucleo-144_board_connecting_to_ssl_server_and_sending_message_1.png
[link-network_information_of_stm32_nucleo-144_board_connecting_to_ssl_server_and_sending_message_2]: https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/images/tcp_client_over_ssl/network_information_of_stm32_nucleo-144_board_connecting_to_ssl_server_and_sending_message_2.png
[link-receive_sent_message_1]: https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/images/tcp_client_over_ssl/receive_sent_message_1.png
[link-receive_sent_message_2]: https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/images/tcp_client_over_ssl/receive_sent_message_2.png
[link-mbed_tls]: https://github.com/Mbed-TLS/mbedtls/tree/8df2f8e7b9c7bb9390ac74bb7bace27edca81a2b
