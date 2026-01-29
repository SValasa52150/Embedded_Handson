#include "lwip/opt.h"
#include "lwip/init.h"
#include "lwip/netif.h"     // <<< THIS IS THE FIX
#include "ethernetif.h"

struct netif gnetif;

void MX_LWIP_Init(void)
{
    ip4_addr_t ipaddr, netmask, gw;

    IP4_ADDR(&ipaddr, 192,168,1,50);
    IP4_ADDR(&netmask, 255,255,255,0);
    IP4_ADDR(&gw, 192,168,1,1);

    lwip_init();

    netif_add(&gnetif, &ipaddr, &netmask, &gw,NULL, ethernetif_init, ethernet_input);


    netif_set_default(&gnetif);
    netif_set_up(&gnetif);
}
