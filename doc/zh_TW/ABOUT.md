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
 
HTTP 網頁瀏覽器：   
這裡我們使用兩種網頁的效能測試方式。  
第一種方式：  
預設頁面 index.html 是將存在記憶體的固定內容傳向瀏覽器的靜態網頁，包含一些 JavaScript 程式碼， 並允許網頁包含動態內容，需定時要求運行在背景中的小數據文件和改變HTML代碼中個別值，這種技術叫做AJAX，也就是不需要重新載入整個頁面來改變數據。AJAX 允許建立複雜的 Web 應用項目，類似桌面應用程式。  
第二種方式：  
另一頁面 simple.shtml  是一個靜態網頁，不需要可動態建立的 JavaScript，即是要改變數據需要每次重新載入。  

**Screenshot**  
![demo_1](https://lh4.googleusercontent.com/-eFfEOypyFNY/UtjaMzPj4TI/AAAAAAAAAX8/EUkxvHmKTZA/w620-h659-no/mb9af314l_ax88796c_lwip_demo1.jpg)  
▲ Demo1 Screen    

![demo_2](https://lh4.googleusercontent.com/-2EJV1tyEbKE/UtjaNKovw5I/AAAAAAAAAX0/mwxzR7hyJDM/w742-h659-no/mb9af314l_ax88796c_lwip_demo2.jpg)  
▲ Demo2 Screen  

