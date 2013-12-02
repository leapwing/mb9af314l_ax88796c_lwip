## MB9AF314L\_AX88796C\_LwIP Firmware ##

簡易的Webserver測試程式

硬體平台：MB9AF314L + AX88796C  
軟體平台：LwIP 1.4.1 

介面:  
1. SPI baudrate 4MHz MFS:CH7  
2. UART baudrate 115200 MFS:CH4  
3. LED x 3(GPIO)  
4. Joystick x 1(GPIO)  
5. potentiomenter x 1(AN01)	  
6. GPIO for AX88796C RESET & SPI_SS

使用：   
使用實驗版來連線電腦網頁顯示狀態  

Screenshot  
![demo_1]()  
▲ Demo1 Screen    
![demo_2]()  
▲ Demo2 Screen  

### NETIO ###

測試網路速度  
工具：[**NETIO**][NETIO]  
將firmware中NETIO_SERVER功能打開  
執行netio程式測試速度
測試結果： 

![netio_1](https://lh3.googleusercontent.com/--uuOtNB31JY/Upwl5jEJkzI/AAAAAAAAAKY/Qicq_NwzMMo/w669-h294-no/netio_s2_536.jpg)  
▲ TCP\_MSS：536 ，TCP\_SND\_BUF： 2 * TCP\_MSS  
![netio_2](https://lh5.googleusercontent.com/-xc7kJjG71jU/Upwl6Tcg5iI/AAAAAAAAAKQ/dG8c1mUA8hM/w669-h294-no/netio_s4_536.jpg)  
▲ TCP\_MSS：536 ，TCP\_SND\_BUF： 4 * TCP\_MSS  
![netio_3](https://lh3.googleusercontent.com/-EYP5l2RAVJ0/Upwl5_D0SiI/AAAAAAAAAKU/81XDxCwtsgk/w669-h294-no/netio_s2_1536.jpg)  
▲ TCP\_MSS：1536 ，TCP\_SND\_BUF： 2 * TCP\_MSS  
![netio_4](https://lh4.googleusercontent.com/-_86wn2lgIN4/Upwl5pm2Q7I/AAAAAAAAAKI/p94AYli-XLw/w669-h294-no/netio_s4_1536.jpg)  
▲ TCP\_MSS：1536 ，TCP\_SND\_BUF： 4 * TCP\_MSS  



[NETIO]: http://www.ars.de/ars/ars.nsf/docs/netio "NETIO  network throughput benchmark"


[ECHOPING]:http://echoping.sourceforge.net/ "echoping"