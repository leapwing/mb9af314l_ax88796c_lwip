# MB9AF314L\_AX88796C\_LwIP Firmware #

This example project is a port of the LwIP (Lightweight IP) TCP/IP suite
including a small webserver to the FUJITSU MB9AF314L & ASIX AX88796C.

### Hardware Info ###

Target MCU: [Fujitsu **MB9AF314L**][MB9AF314L]

Ethernet controller: [ASIX **AX88796C**][ASIX]

Library version: [**lwip 1.4.1**][LwIP]

More other info: [**Link**](/doc/hardware.md)

### Interface ###

SPI (MFS:CH7) `4MHz baudrate`   
UART (MFS:CH4) `115K baudrate`   
LED x3 (GPIO)    
Joystick x1 (GPIO)  
potentiomenter x1 (AN01)	  
AX88796C RESET & SPI_SS (GPIO)

### Link & Documents ###
- [Main Site](/)
- [Developer's blog][BLOG]
- [More Documents(Chinese)](/doc/zh_TW/) 
	- [About 關於](/doc/zh_TW/ABOUT.md)
	- [Speed Measure 速度量測](/doc/zh_TW/MEASURE.md)
	- [Other Info 其他訊息](/doc/zh_TW/OTHER.md)
  
### Screenshot ###
![demo_1](https://lh3.googleusercontent.com/j3KPC8NBFIZVUQrONxNBAEr2xg8ekddBjagJA1iWT0g=w639-h658-no)
▲ Demo1 Screen    
![demo_2](https://lh5.googleusercontent.com/-k_0SOv7cWm8/UqBGI4xMjHI/AAAAAAAAAM8/IcI6XvmnD-g/w782-h658-no/fm9baf314l_ax88796c_demo2.jpg)
▲ Demo2 Screen  

[MB9AF314L]: http://www.spansion.com/Products/microcontrollers/32-bit-ARM-Core/fm3/Pages/overview_32fm3.aspx "FM3 Family"
[ASIX]: http://www.asix.com.tw/index.php?&width=1152 "ASIX"
[LwIP]: http://savannah.nongnu.org/projects/lwip "A Lightweight TCP/IP stack"
[BLOG]: /