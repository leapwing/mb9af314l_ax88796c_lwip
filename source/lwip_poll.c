/*---------------------------------------------------------------------------*/
/* include files                                                             								  */
/*---------------------------------------------------------------------------*/
#include "lwip_poll.h"
#include "lwipopts.h"
#include "lwip/memp.h"
#include "lwIP/ip_frag.h"
#include "lwIP/tcp.h"
#include "lwIP/udp.h"
#include "lwIP/tcpip.h"
#include "lwip/tcp_impl.h"
#include "netif/etharp.h"
#include "lwIP/dhcp.h"
#include "ethernetif.h"
#include "httpd.h"
#include "ajax.h"
#include "netio.h"
#include "ax88796c_spi.h"

#include "uart.h"
#include <stdio.h>
#include "scheduler.h"

/*---------------------------------------------------------------------------*/
/* local defines                                                             */
/*---------------------------------------------------------------------------*/
#ifdef LWIP_DHCP
#define MAX_DHCP_TRIES        4
#endif
/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/


#if ((LWIP_DHCP == 0) && (DHCP_ENABLE == 1))
#warning "DHCP test Enable selected in lwip_poll.h but not activated in lwipopts.h!"
#endif

/*---------------------------------------------------------------------------*/
/* local functions prototypes                                                */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* global data                                                               */
/*---------------------------------------------------------------------------*/
struct netif lwip_netif;
uint16_t eth_link;

/*---------------------------------------------------------------------------*/
/* global functions                                                          */
/*---------------------------------------------------------------------------*/
#ifdef TCPUDP_ECHO_DEMO
extern void echo_init(void);//for intialization of TCP echo server
extern void udp_echo_init(void);//for intialization of UDP echo server
#endif
#ifdef	IPERF_SERVER
extern void iperf_server_init(void);
#endif
#ifdef	IPERF_CLIENT
extern void iperf_client_init(void);
extern void iperf_send(void);
#endif
#ifdef	TCP_RXTX
extern void tcp_server_init(void);
#endif
#ifdef DNS_TCP_CLIENT_DEMO
extern void dns_client_init(void);
extern void tcp_client_init(void);
#endif
/*!
 ******************************************************************************
 ** \brief  initialize the LwIP
 **
 ** \param
 **
 ******************************************************************************
*/
void LwIP_Init(void)
{
	struct ip_addr ipaddr;
	struct ip_addr netmask;
	struct ip_addr gw;

	/* Initializes the dynamic memory heap defined by MEM_SIZE.*/
	mem_init();
	/* Initializes the memory pools defined by MEMP_NUM_x.*/
	memp_init();


#if ((LWIP_DHCP) && (DHCP_ENABLE == 1))
	IP4_ADDR(&ipaddr, 0, 0, 0, 0);
	IP4_ADDR(&netmask, 0, 0, 0, 0);
	IP4_ADDR(&gw, 0, 0, 0, 0);
	netif_add(&lwip_netif, &ipaddr, &netmask, &gw, 0, &ethernetif_init, &ethernet_input);
	netif_set_default(&lwip_netif);
	dhcp_start(&lwip_netif);
#else // static IP address
	IP4_ADDR(&ipaddr, 192, 168, 1, 99);
	IP4_ADDR(&netmask, 255, 255 , 255, 0);
	IP4_ADDR(&gw, 192, 168, 1, 1);
	netif_add(&lwip_netif, &ipaddr, &netmask, &gw, 0, &ethernetif_init, &ethernet_input);
	netif_set_default(&lwip_netif);
	netif_set_up(&lwip_netif);
#endif // DHCP or static IP address

#ifdef	IPERF_SERVER
	iperf_server_init();
#endif
#ifdef	IPERF_CLIENT
	iperf_client_init();/*iperf_send() must be called in the main loop to send out data*/
#endif

#ifdef	TCP_RXTX
	tcp_server_init();
#endif

#ifdef TCPUDP_ECHO_DEMO
	udp_echo_init();   //udp echo server Init
	echo_init();// tcp echo server Init
#endif
#ifdef DNS_TCP_CLIENT_DEMO
	dns_client_init();
	tcp_client_init();
#endif

#ifdef NETIO_SERVER
	netio_init();
#endif

	httpd_init();
	Ajax_Init();
	eth_link = 0;
}

/** Returns the current time in milliseconds,
 * may be the same as sys_jiffies or at least based on it.
 *
 * Declaration in sys.h
 */
u32_t sys_now(void){
	return Scheduler_GetSystemTime();
}

/*---------------------------------------------------------------------------*/
/* local functions                                                                                                              */
/*---------------------------------------------------------------------------*/
#if 0
/*!
******************************************************************************
** \brief  LwIP periodic tasks
**
** This function is not used in this example as it uses an efficient,
** dedicated scheduler. The setup is implemented in main.c.
**
** However, this function might be useful as a reference if used with
** an operationg system
**
******************************************************************************
*/
void LwIP_Tmr_Handle()
{
#if IP_FRAG
	/* IP reassesment timer, periodic process every second */
	if (g_u32SystemTime - m_u32IpReAssessTimer >= IP_TMR_INTERVAL)
    {
		m_u32IpReAssessTimer =  g_u32SystemTime;
        ip_reass_tmr();
    }
#endif

#if LWIP_TCP
    /* TCP periodic process every 250 ms */
    if (g_u32SystemTime - m_u32TCPTimer >= TCP_TMR_INTERVAL)
    {
        m_u32TCPTimer =  g_u32SystemTime;
        tcp_tmr();
    }
#endif

    /* ARP periodic process every 5s */
    if ((g_u32SystemTime - m_u32ARPTimer) >= ARP_TMR_INTERVAL)
    {
        m_u32ARPTimer =  g_u32SystemTime;
        etharp_tmr();
    }

#if (LWIP_DHCP != 0)
    /* Fine DHCP periodic process every 500ms */
    if (g_u32SystemTime - m_u32DHCPfineTimer >= DHCP_FINE_TIMER_MSECS)
    {
        m_u32DHCPfineTimer =  g_u32SystemTime;
        dhcp_fine_tmr();
    }

    /* DHCP Coarse periodic process every 60s */
    if (g_u32SystemTime - m_u32DHCPcoarseTimer >= DHCP_COARSE_TIMER_MSECS)
    {
        DHCPcoarseTimer =  g_u32SystemTime;
        dhcp_coarse_tmr();
    }

#endif
}
#endif
/*!
******************************************************************************
** \brief  LwIP periodic polling received package
** \param none
**
******************************************************************************
*/
void LwIP_Input_Handle(void)
{
	volatile int32_t ax88796c_isr, pkt_cnt;
	volatile int32_t loop_cnt = 20;
	ax88796c_isr = ax88796c_check_int();
	if(ax88796c_isr & ISR_LINK){
		if(!ax88796c_check_media()){
			printf ("Link down.\n");
			eth_link = 0;
		}else{
			uint16_t bmcr;
			bmcr = ax88796c_mdio_read(PHY_ID, MII_BMCR);
			printf("Link up, %sMbps, %s-duplex\n",(bmcr & BMCR_SPEED100) ? "100" : "10", \
				(bmcr & BMCR_FULLDPLX) ? "full" : "half");
			eth_link = 1;
		}
	}
	if(ax88796c_isr & ISR_RXPCT){
		while(--loop_cnt){
			pkt_cnt = ax88796c_CheckPacketReceive();
			if(pkt_cnt == 0){
				break;
			}else if(pkt_cnt > 0){
				ethernetif_input(&lwip_netif);	
			}
		}
	}
	ax88796c_clear_int(ax88796c_isr);
#ifdef	IPERF_CLIENT
	iperf_send();
#endif
}

/*****************************************************************************/
/* END OF FILE */
