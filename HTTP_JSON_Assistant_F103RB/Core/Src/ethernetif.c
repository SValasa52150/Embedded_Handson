
#include "ethernetif.h"
#include "enc28j60.h"
#include "lwip/etharp.h"
#include <stdio.h>

static struct netif *netif_ptr;

err_t ethernetif_init(struct netif *netif)
{
    netif_ptr = netif;
    netif->hwaddr_len = 6;
    netif->hwaddr[0]=0x02;
    netif->hwaddr[1]=0x12;
    netif->hwaddr[2]=0x34;
    netif->hwaddr[3]=0x56;
    netif->hwaddr[4]=0x78;
    netif->hwaddr[5]=0x9A;
    netif->mtu = 1500;
    netif->flags = NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP;

    enc28j60_init(netif->hwaddr);
    //printf("ENC28J60 init OK\r\n");

    return ERR_OK;
}

void ethernetif_input(struct netif *netif)
{
    uint16_t len;
    struct pbuf *p;

    len = enc28j60_packet_receive(NULL, 0);
    if(len > 0)
    {
        printf("RX packet len=%d\r\n", len);
        p = pbuf_alloc(PBUF_RAW, len, PBUF_POOL);
        if(p)
        {
            enc28j60_packet_receive(p->payload, len);
            netif->input(p, netif);
        }
    }
}
