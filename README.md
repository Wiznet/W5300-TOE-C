# W5300 TOE Examples

- [**Overview**](#overview)
- [**Directory Structure**](#directory_structure)
- [**Getting Started**](#getting_started)
- [**Appendix**](#appendix)
    - [**Datasheet**](#datasheet)
    - [**Other Examples**](#other_examples)



<a name="overview"></a>
## Overview

The W5300 TOE examples use **W5300 TOE Shield** - ethernet I/O shield compatible with STM32 Nucleo-144 board built on WIZnet's [**W5300**][link-w5300] ethernet chip, and STM32 Nucleo-144 board.

- [**W5300 TOE Shield**][link-w5300_toe_shield]

<p align="center"><img src="https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/images/w5300_toe_shield_main.png"></p>

STM32 Nucleo-144 boards support the list below.

- [**NUCLEO-F207ZG**][link-nucleo-f207zg]
- [**NUCLEO-F429ZI**][link-nucleo-f429zi]
- [**NUCLEO-F439ZI**][link-nucleo-f439zi]
- [**NUCLEO-F722ZE**][link-nucleo-f722ze]
- [**NUCLEO-F756ZG**][link-nucleo-f756zg]
- [**NUCLEO-F767ZI**][link-nucleo-f767zi]

And W5300 TOE Examples supports two IDEs.

**※ Please select and use the IDE according to the environment you are using.**

<table>
  <tr>
    <td align=center>Board</td>
    <td align=center>Example</td>
    <td align=center>Description</td>
  </tr>
  <tr>
    <td align=center rowspan="2">NUCLEO-F207ZG</td>
    <td align=center><a href="https://github.com/Wiznet/W5300-TOE-C/tree/main/Projects/NUCLEO-F207ZG/MDK-ARM"><b>MDK-ARM</b></td>
    <td>C-based example implemented using <a href="https://www2.keil.com/mdk5/uvision/">MDK-ARM.</td>
  </tr>
  <tr>
    <td align=center><a href="https://github.com/Wiznet/W5300-TOE-C/tree/main/Projects/NUCLEO-F207ZG/STM32CubeIDE"><b>STM32CubeIDE</b></td></td>
    <td>C-based example implemented using <a href="https://www.st.com/en/development-tools/stm32cubeide.html">STM32CubeIDE.</td>
  </tr>
  <tr>
    <td align=center rowspan="2">NUCLEO-F429ZI</td>
    <td align=center><a href="https://github.com/Wiznet/W5300-TOE-C/tree/main/Projects/NUCLEO-F429ZI/MDK-ARM"><b>MDK-ARM</b></td>
    <td>C-based example implemented using <a href="https://www2.keil.com/mdk5/uvision/">MDK-ARM.</td>
  </tr>
  <tr>
    <td align=center><a href="https://github.com/Wiznet/W5300-TOE-C/tree/main/Projects/NUCLEO-F429ZI/STM32CubeIDE"><b>STM32CubeIDE</b></td></td>
    <td>C-based example implemented using <a href="https://www.st.com/en/development-tools/stm32cubeide.html">STM32CubeIDE.</td>
  </tr>
  <tr>
    <td align=center rowspan="2">NUCLEO-F439ZI</td>
    <td align=center><a href="https://github.com/Wiznet/W5300-TOE-C/tree/main/Projects/NUCLEO-F439ZI/MDK-ARM"><b>MDK-ARM</b></td>
    <td>C-based example implemented using <a href="https://www2.keil.com/mdk5/uvision/">MDK-ARM.</td>
  </tr>
  <tr>
    <td align=center><a href="https://github.com/Wiznet/W5300-TOE-C/tree/main/Projects/NUCLEO-F439ZI/STM32CubeIDE"><b>STM32CubeIDE</b></td></td>
    <td>C-based example implemented using <a href="https://www.st.com/en/development-tools/stm32cubeide.html">STM32CubeIDE.</td>
  </tr>
  <tr>
    <td align=center rowspan="2">NUCLEO-F722ZE</td>
    <td align=center><a href="https://github.com/Wiznet/W5300-TOE-C/tree/main/Projects/NUCLEO-F722ZE/MDK-ARM"><b>MDK-ARM</b></td>
    <td>C-based example implemented using <a href="https://www2.keil.com/mdk5/uvision/">MDK-ARM.</td>
  </tr>
  <tr>
    <td align=center><a href="https://github.com/Wiznet/W5300-TOE-C/tree/main/Projects/NUCLEO-F722ZE/STM32CubeIDE"><b>STM32CubeIDE</b></td></td>
    <td>C-based example implemented using <a href="https://www.st.com/en/development-tools/stm32cubeide.html">STM32CubeIDE.</td>
  </tr>
  <tr>
    <td align=center rowspan="2">NUCLEO-F756ZG</td>
    <td align=center><a href="https://github.com/Wiznet/W5300-TOE-C/tree/main/Projects/NUCLEO-F756ZG/MDK-ARM"><b>MDK-ARM</b></td>
    <td>C-based example implemented using <a href="https://www2.keil.com/mdk5/uvision/">MDK-ARM.</td>
  </tr>
  <tr>
    <td align=center><a href="https://github.com/Wiznet/W5300-TOE-C/tree/main/Projects/NUCLEO-F756ZG/STM32CubeIDE"><b>STM32CubeIDE</b></td></td>
    <td>C-based example implemented using <a href="https://www.st.com/en/development-tools/stm32cubeide.html">STM32CubeIDE.</td>
  </tr>
  <tr>
    <td align=center rowspan="2">NUCLEO-F767ZI</td>
    <td align=center><a href="https://github.com/Wiznet/W5300-TOE-C/tree/main/Projects/NUCLEO-F767ZI/MDK-ARM"><b>MDK-ARM</b></td>
    <td>C-based example implemented using <a href="https://www2.keil.com/mdk5/uvision/">MDK-ARM.</td>
  </tr>
  <tr>
    <td align=center><a href="https://github.com/Wiznet/W5300-TOE-C/tree/main/Projects/NUCLEO-F767ZI/STM32CubeIDE"><b>STM32CubeIDE</b></td></td>
    <td>C-based example implemented using <a href="https://www.st.com/en/development-tools/stm32cubeide.html">STM32CubeIDE.</td>
  </tr>
</table>



<a name="directory_structure"></a>
## Directory Structure

```
W5300-TOE-C
┣ Examples
┃   ┣ dhcp
┃   ┣ dns
┃   ┣ http
┃   ┃   ┗ server
┃   ┣ loopback
┃   ┣ mqtt
┃   ┃   ┣ publish
┃   ┃   ┣ publish_subscribe
┃   ┃   ┗ subscribe
┃   ┣ sntp
┃   ┗ tcp_client_over_ssl
┣ Libraries
┃   ┣ ioLibrary_Driver
┃   ┗ mbedtls
┣ Port
┃   ┣ ioLibrary_Driver
┃   ┃   ┣ inc
┃   ┃   ┗ src
┃   ┣ mbedtls
┃   ┃   ┗ inc
┃   ┗ timer
┃       ┣ inc
┃       ┗ src
┣ Projects
┃   ┣ NUCLEO-F207ZG
┃   ┃   ┣ Core
┃   ┃   ┣ Drivers
┃   ┃   ┣ MDK-ARM
┃   ┃   ┗ STM32CubeIDE
┃   ┣ NUCLEO-F429ZI
┃   ┃   ┣ Core
┃   ┃   ┣ Drivers
┃   ┃   ┣ MDK-ARM
┃   ┃   ┗ STM32CubeIDE
┃   ┣ NUCLEO-F439ZI
┃   ┃   ┣ Core
┃   ┃   ┣ Drivers
┃   ┃   ┣ MDK-ARM
┃   ┃   ┗ STM32CubeIDE
┃   ┣ NUCLEO-F722ZE
┃   ┃   ┣ Core
┃   ┃   ┣ Drivers
┃   ┃   ┣ MDK-ARM
┃   ┃   ┗ STM32CubeIDE
┃   ┣ NUCLEO-F756ZG
┃   ┃   ┣ Core
┃   ┃   ┣ Drivers
┃   ┃   ┣ MDK-ARM
┃   ┃   ┗ STM32CubeIDE
┃   ┗ NUCLEO-F767ZI
┃       ┣ Core
┃       ┣ Drivers
┃       ┣ MDK-ARM
┃       ┗ STM32CubeIDE
┗ Static
    ┣ documents
    ┗ images
```



<a name="getting_started"></a>
## Getting Started

Please refer to [**Getting Started**][link-getting_started] for how to configure development environment or examples usage.



<a name="appendix"></a>
## Appendix



<a name="datasheet"></a>
### Datasheet

- [**W5300**][link-datasheet_w5300]
- [**W5300 TOE Shield**][link-datasheet_w5300_toe_shield]



<a name="other_examples"></a>
### Other Examples

- Arduino
    - [**W5300-TOE-Arduino**][link-w5300-toe-arduino]
- MicroPython
    - [**W5300-TOE-MicroPython**][link-w5300-toe-micropython]



<!--
Link
-->

[link-w5300]: https://docs.wiznet.io/Product/iEthernet/W5300
[link-w5300_toe_shield]: https://docs.wiznet.io/Product/iEthernet/W5300/W5300-TOE-Shield
[link-nucleo-f207zg]: https://www.st.com/en/evaluation-tools/nucleo-f207zg.html
[link-nucleo-f429zi]: https://www.st.com/en/evaluation-tools/nucleo-f429zi.html
[link-nucleo-f439zi]: https://www.st.com/en/evaluation-tools/nucleo-f439zi.html
[link-nucleo-f722ze]: https://www.st.com/en/evaluation-tools/nucleo-f722ze.html
[link-nucleo-f756zg]: https://www.st.com/en/evaluation-tools/nucleo-f756zg.html
[link-nucleo-f767zi]: https://www.st.com/en/evaluation-tools/nucleo-f767zi.html
[link-getting_started]: https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/documents/getting_started.md
[link-datasheet_w5300]: https://docs.wiznet.io/img/products/w5300/W5300_DS_V134E.pdf
[link-datasheet_w5300_toe_shield]: https://docs.wiznet.io/Product/iEthernet/W5300/W5300-TOE-Shield
[link-w5300-toe-arduino]: https://github.com/Wiznet/W5300-TOE-Arduino
[link-w5300-toe-micropython]: https://github.com/Wiznet/W5300-TOE-MicroPython
