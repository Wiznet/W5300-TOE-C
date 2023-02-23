# Getting Started

These sections will guide you through a series of steps from configuring development environment to running W5300 TOE examples.

- [**Hardware Requirements**](#hardware_requirements)
- [**Development Environment Configuration**](#development_environment_configuration)
    - [**Setup ST-LINK**](#setup_st-link)
- [**Example Structure**](#example_structure)
- [**Example Testing**](#example_testing)



<a name="hardware_requirements"></a>
## Hardware Requirements

- [**W5300 TOE Shield**][link-w5300_toe_shield]
- **One of the STM32 Nucleo-144 Boards**
    - [**NUCLEO-F429ZI**][link-nucleo-f429zi]
    - [**NUCLEO-F439ZI**][link-nucleo-f439zi]
- **Desktop or Laptop**
- **USB Type-B Micro 5 Pin Cable**

**※ Currently, W5300 TOE examples only support NUCLEO-F429ZI and NUCLEO-F439ZI, so please refer to this.**



<a name="development_environment_configuration"></a>
## Development Environment Configuration



<a name="setup_st-link"></a>
### Setup ST-LINK

The ST-LINK pin was changed due to overlapping use of the FMC(Flexible Memory controller) data pin to control the W5300 built in the W5300 TOE Shield and the ST-LINK pin of the STM32 Nucleo-144 board.

- STLK_RX[STM32F103CBT6_PA3] : PD8 → **PC10**
- STLK_TX[STM32F103CBT6_PA2] : PD9 → **PC11**

Therefore, in order to use the ST-LINK of the STM32 Nucleo-144 board, minor settings are required for the W5300 TOE Shield and STM32 Nucleo-144 board.

1. Remove SB5 and SB6 from the top of the STM32 Nucleo-144 board.

<p align="center"><img src="https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/images/getting_started/stm32_nucleo-144_board_sb5_sb6.png"></p>

2. With the W5300 TOE Shield and STM32 Nucleo-144 board combined, connect PC10, PC11 of the W5300 TOE Shield and CN5 TX, RX of the top of the STM32 Nucleo-144 board with jumper cables.

- W5300 TOE Shield : **PC10** - STM32 Nucleo-144 board : **RX**
- W5300 TOE Shield : **PC11** - STM32 Nucleo-144 board : **TX**

<p align="center"><img src="https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/images/getting_started/stm32_nucleo-144_board_cn5_tx_rx.png"></p>



<a name="example_structure"></a>
## Example Structure

- [**DHCP**][link-dhcp]
- [**DNS**][link-dns]
- [**HTTP**][link-http]
    - [**Server**][link-http_server]
- [**Loopback**][link-loopback]
- [**MQTT**][link-mqtt]
    - [**Publish**][link-mqtt_publish]
    - [**Publish & Subscribe**][link-mqtt_publish_subscribe]
    - [**Subscribe**][link-mqtt_subscribe]
- [**SNTP**][link-sntp]
- [**TCP Client over SSL**][link-tcp_client_over_ssl]



<a name="example_testing"></a>
## Example Testing

Please refer to 'README.md' in each example directory to detail guide for testing examples.



<!--
Link
-->

[link-w5300_toe_shield]: fill_in_the_blank
[link-nucleo-f429zi]: https://www.st.com/en/evaluation-tools/nucleo-f429zi.html
[link-nucleo-f439zi]: https://www.st.com/en/evaluation-tools/nucleo-f439zi.html
[link-dhcp]: https://github.com/Wiznet/W5300-TOE-C/tree/main/Examples/dhcp
[link-dns]: https://github.com/Wiznet/W5300-TOE-C/tree/main/Examples/dns
[link-http]: https://github.com/Wiznet/W5300-TOE-C/tree/main/Examples/http
[link-http_server]: https://github.com/Wiznet/W5300-TOE-C/tree/main/Examples/http/server
[link-loopback]: https://github.com/Wiznet/W5300-TOE-C/tree/main/Examples/loopback
[link-mqtt]: https://github.com/Wiznet/W5300-TOE-C/tree/main/Examples/mqtt
[link-mqtt_publish]: https://github.com/Wiznet/W5300-TOE-C/tree/main/Examples/mqtt/publish
[link-mqtt_publish_subscribe]: https://github.com/Wiznet/W5300-TOE-C/tree/main/Examples/mqtt/publish_subscribe
[link-mqtt_subscribe]: https://github.com/Wiznet/W5300-TOE-C/tree/main/Examples/mqtt/subscribe
[link-sntp]: https://github.com/Wiznet/W5300-TOE-C/tree/main/Examples/sntp
[link-tcp_client_over_ssl]: https://github.com/Wiznet/W5300-TOE-C/tree/main/Examples/tcp_client_over_ssl
