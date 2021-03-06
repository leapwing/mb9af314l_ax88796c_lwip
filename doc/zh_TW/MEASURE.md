## 速度量測 ##

### 1. ICMP echo ###
在命令列視窗中執行 `ping` 指令，如果 TCPIP stack 設定正確，所傳送的ICMP 請求後，就會回應ICMP 請求。
![ping_win](https://lh6.googleusercontent.com/-4VvpVTDf29E/UtjaPhIWRxI/AAAAAAAAAYs/G6flcgMFbzI/w669-h278-no/mb9af314l_ax88796c_ping_ip_windows.jpg)  
▲ ping in windows  
![ping_lunix](https://lh6.googleusercontent.com/-hk0TKsY3gs0/UtjaPTRDnLI/AAAAAAAAAZg/-GkmIekRVao/w667-h324-no/mb9af314l_ax88796c_ping_ip_linux.jpg)  
▲ ping in linux  

### 2. TCP/UDP server echo ###
另一測試網路流量的工具 [echo server][ECHOPING]，指令 `echoping` 是相似於 ping 的功能，但是是使用OSI 第四層。啟用 TCP 和 UDP port 7 來發回傳入的數據包。目的是要測試接收與發送工作之協議。  
![TCP_echoping](https://lh4.googleusercontent.com/-kQ0FDgIWWrA/UtjaL0EV0bI/AAAAAAAAAZQ/KfC_nOF2u5E/w667-h270-no/mb9af314l_ax88796c_echoping_tcp_linux.jpg)  
▲ echoping with TCP  
![UDP_echoping](https://lh6.googleusercontent.com/-HxsNlHVWDnM/UtjaLxcU1dI/AAAAAAAAAZY/jj0LkQAVIbo/w667-h198-no/mb9af314l_ax88796c_echoping_udp_linux.jpg)   
▲ echoping with UDP   

### 3. NetIO ###
免費的網路性能基準測試工具 [NetIO][NETIO]，在命令列執行指令。在lwipopts.h 設定有幾種不同參數下的得到結果：

![netio_1](https://lh3.googleusercontent.com/-Pnuoo8tB-Kk/UtjaNx98eLI/AAAAAAAAAYY/D9zh_jeIoYg/w669-h278-no/mb9af314l_ax88796c_netio_s2_536.jpg)   
▲ TCP\_MSS：536 ，TCP\_SND\_BUF： 2 * TCP\_MSS  

![netio_2](https://lh3.googleusercontent.com/-LDlpxx_PwYk/UtjaPG-bB8I/AAAAAAAAAYk/dABTpg0cILo/w669-h278-no/mb9af314l_ax88796c_netio_s4_536.jpg)  
▲ TCP\_MSS：536 ，TCP\_SND\_BUF： 4 * TCP\_MSS  

![netio_3](https://lh6.googleusercontent.com/-RNVqIR0lBqA/UtjaN1jZsLI/AAAAAAAAAYA/6VuNGrmuyzU/w669-h278-no/mb9af314l_ax88796c_netio_s2_1500.jpg)  
▲ TCP\_MSS：1500 ，TCP\_SND\_BUF： 2 * TCP\_MSS  

![netio_4](https://lh4.googleusercontent.com/-bwrQloVKOvs/UtjaOEgOtkI/AAAAAAAAAYc/eNR6QZYS-8o/w669-h278-no/mb9af314l_ax88796c_netio_s4_1500.jpg)  
▲ TCP\_MSS：1500 ，TCP\_SND\_BUF： 4 * TCP\_MSS  

以上都是有COE(Checksum Offload Engine)的效果，在 lwipopts.h 中啟用軟體校驗合計算，可將下列定義符號設為1，CHECKSUM_GEN\_IP, CHECKSUM\_GEN\_UDP, CHECKSUM\_GEN\_TCP, CHECKSUM\_CHECK\_IP, CHECKSUM\_CHECK\_UDP, CHECKSUM\_CHECK\_TCP, CHECKSUM\_CHECK\_ICMP。
這意味著相對於軟體解決方案，硬體引擎比較快。
![netio_5](https://lh3.googleusercontent.com/-ruXcbDv5A2E/UtjaOaZ-tEI/AAAAAAAAAYQ/EZAV8S5qta8/w669-h278-no/mb9af314l_ax88796c_netio_s4_1500_software.jpg)  
▲ TCP\_MSS：1500 ，TCP\_SND\_BUF： 4 * TCP\_MSS no COE  

### 4. Iperf ###
免費網路頻寬測試工具 [Iperf][IPERF]，`iperf` 常用於量測 TCP/UDP的吞吐量工具，可以作為Client/Server 端的測試。  
![iperf_clinet](https://lh4.googleusercontent.com/-wilW3cLlcZI/UtjaMU4YyLI/AAAAAAAAAXc/0MTZeKTmras/w669-h358-no/mb9af314l_ax88796c_ipref_client.jpg)    
▲ iperf client  
![iperf_server](https://lh6.googleusercontent.com/-63eLrWYWjDU/UtjaMnsRGMI/AAAAAAAAAX4/v3dZuewGgCw/w669-h358-no/mb9af314l_ax88796c_ipref_server.jpg)  
▲ iperf server  
 
### 5. HTTP 網頁瀏覽器   
  
HTTP 網頁瀏覽器：   
這裡我們使用兩種網頁的效能測試方式。  
第一種方式：  
預設頁面 index.html 是將存在記憶體的固定內容傳向瀏覽器的靜態網頁，包含一些 JavaScript 程式碼， 並允許網頁包含動態內容，需定時要求運行在背景中的小數據文件和改變HTML代碼中個別值，這種技術叫做AJAX，也就是不需要重新載入整個頁面來改變數據。AJAX 允許建立複雜的 Web 應用項目，類似桌面應用程式。  
第二種方式：  
另一頁面 simple.shtml 是一個靜態網頁，不需要可動態建立的 JavaScript，即是要改變數據需要每次重新載入。  
Webserver 是 LwIP 的 contrib-package 內的一部分，依文件擴展副檔名來決定是動態(.html)還是靜態(.shtml)。  
這兩個頁面都包含bigpicture.jpg 約100多KB的大圖形 ，連結到 `bigpicture.jpg?<number>` 是指要阻止網頁瀏覽器使用快取記憶體存取，安全起見，可以完全禁用瀏覽器快取。  

**Screenshot**  
![demo_1](https://lh4.googleusercontent.com/-eFfEOypyFNY/UtjaMzPj4TI/AAAAAAAAAX8/EUkxvHmKTZA/w620-h659-no/mb9af314l_ax88796c_lwip_demo1.jpg)  
▲ AJAX-enable demo webpage    

![demo_2](https://lh4.googleusercontent.com/-2EJV1tyEbKE/UtjaNKovw5I/AAAAAAAAAX0/mwxzR7hyJDM/w742-h659-no/mb9af314l_ax88796c_lwip_demo2.jpg)  
▲ sample webpage without JavaScript  

### 6. HTTP Wget ###
在命令列視窗中執行 [wget][WGET] 指令，它會顯示有關傳輸速度及運行時間的統計數據，重點在於下載所需花費的時間，不需理會內容，所以使用選項 `--output-document=/dev/null` ，可重複幾次測試，以獲得理想的統計數據。  
![wget](https://lh4.googleusercontent.com/-oBPgqnJVWM8/UtjaP0VxGyI/AAAAAAAAAY0/NTN_nIyBACU/w669-h438-no/mb9af314l_ax88796c_wget_bigjpg.jpg)  
▲ speed measurement with wget    

### 7. HTTP Curl ###
在命令列視窗中執行 [curl][CURL] 指令，它類似 `wget` 但顯示統計信息是不同，多種程式測試才能得到典型的平均值。  
![curl](https://lh4.googleusercontent.com/-OKG0xuSuEu4/UtjaLznGsCI/AAAAAAAAAXU/AuY1-5FbPSg/w669-h422-no/mb9af314l_ax88796c_curl_bigpicture.jpg)  
▲ speed measurement with curl  


[ECHOPING]:http://echoping.sourceforge.net/ "echoping"
[NETIO]: http://www.ars.de/ars/ars.nsf/docs/netio "NETIO  network throughput benchmark"
[IPERF]: http://sourceforge.net/projects/iperf/ "iperf"
[WGET]: http://sourceforge.net/projects/wget/ "wget"
[CURL]: http://sourceforge.net/projects/curl/ "curl"