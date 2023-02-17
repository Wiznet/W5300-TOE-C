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

- [**NUCLEO-F429ZI**][link-nucleo-f429zi]

And W5300 TOE Examples supports two IDEs.

**※ Please select and use the IDE according to the environment you are using.**

<table>
  <tr>
    <td align=center>Board</td>
    <td align=center>Example</td>
    <td align=center>Description</td>
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
┃   ┗ sntp
┣ Libraries
┃   ┗ ioLibrary_Driver
┣ Port
┃   ┣ ioLibrary_Driver
┃   ┃   ┣ inc
┃   ┃   ┗ src
┃   ┗ Timer
┃       ┣ inc
┃       ┗ src
┣ Projects
┃   ┗ NUCLEO-F429ZI
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
[link-w5300_toe_shield]: fill_in_the_blank
[link-nucleo-f429zi]: https://www.st.com/en/evaluation-tools/nucleo-f429zi.html
[link-getting_started]: https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/documents/getting_started.md
[link-datasheet_w5300]: https://docs.wiznet.io/img/products/w5300/W5300_DS_V134E.pdf
[link-datasheet_w5300_toe_shield]: fill_in_the_blank
[link-w5300-toe-arduino]: https://github.com/Wiznet/W5300-TOE-Arduino
[link-w5300-toe-micropython]: https://github.com/Wiznet/W5300-TOE-MicroPython
