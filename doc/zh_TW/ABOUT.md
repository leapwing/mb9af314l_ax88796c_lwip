## MB9AF314L\_AX88796C\_LwIP Firmware ##

硬體平台：MB9AF314L + AX88796C  
軟體平台：LwIP 1.4.1 

介面:  
1. SPI baudrate 4MHz MFS:CH7  
2. UART baudrate 115200 MFS:CH4  
3. LED x 3(GPIO)  
4. Joystick x 1(GPIO)  
5. potentiomenter x 1(AN01)	  
6. GPIO for AX88796C RESET & SPI_SS
 
### 1. HTTP 網頁瀏覽器   
  
使用實驗版來連線電腦網頁顯示狀態  

Screenshot  
![demo_1](https://lh3.googleusercontent.com/j3KPC8NBFIZVUQrONxNBAEr2xg8ekddBjagJA1iWT0g=w639-h658-no)  
▲ Demo1 Screen    

![demo_2](https://lh5.googleusercontent.com/-k_0SOv7cWm8/UqBGI4xMjHI/AAAAAAAAAM8/IcI6XvmnD-g/w782-h658-no/fm9baf314l_ax88796c_demo2.jpg)  
▲ Demo2 Screen  

### 2. PING ###

### 3. IPFER ###

### 4. ###

### 5. NETIO ###

測試網路速度  
工具：[**NETIO**][NETIO]  
將firmware中NETIO_SERVER功能打開  
執行netio程式測試速度
測試結果： 

![netio_1](https://lh3.googleusercontent.com/-54aWEkk8spk/UqBGPHQDTHI/AAAAAAAAANw/a2uX-aCCDQU/w669-h294-no/fm9baf314l_ax88796c_netio_s2_536.jpg) 
▲ TCP\_MSS：536 ，TCP\_SND\_BUF： 2 * TCP\_MSS  

![netio_2](https://lh4.googleusercontent.com/-DJuXn3cXaX4/UqBGPr7yZiI/AAAAAAAAAOA/8U3GW3FvZQ8/w669-h294-no/fm9baf314l_ax88796c_netio_s4_536.jpg)  
▲ TCP\_MSS：536 ，TCP\_SND\_BUF： 4 * TCP\_MSS  

![netio_3](https://lh4.googleusercontent.com/-o_RYqiJ7D1k/UqBGPFD6XHI/AAAAAAAAAN4/N5OF0sVqXJc/w669-h294-no/fm9baf314l_ax88796c_netio_s2_1536.jpg)  
▲ TCP\_MSS：1536 ，TCP\_SND\_BUF： 2 * TCP\_MSS  

![netio_4](https://lh5.googleusercontent.com/-uw8EMsHMcxg/UqBGPNfzzTI/AAAAAAAAAN8/oDD-RKbC_AU/w669-h294-no/fm9baf314l_ax88796c_netio_s4_1536.jpg)  
▲ TCP\_MSS：1536 ，TCP\_SND\_BUF： 4 * TCP\_MSS  


![netio_5](https://lh4.googleusercontent.com/-mfVDNkNYMaE/UqBGKJ-47ZI/AAAAAAAAANI/6htFF9jcivA/w669-h294-no/fm9baf314l_ax88796c_netio_s4_1536_software.jpg)  
▲ TCP\_MSS：1536 ，TCP\_SND\_BUF： 4 * TCP\_MSS no COE 


### 6. WGET ###

### 7. CURL ###


[NETIO]: http://www.ars.de/ars/ars.nsf/docs/netio "NETIO  network throughput benchmark"

[ECHOPING]:http://echoping.sourceforge.net/ "echoping"

