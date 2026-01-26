#ifndef LWIP_ETHARP_H
#define LWIP_ETHARP_H

#include "lwip/err.h"
#include "lwip/netif.h"

err_t etharp_output(struct netif *netif, struct pbuf *q,
                    const ip4_addr_t *ipaddr);

void etharp_input(struct pbuf *p, struct netif *netif);

#endif /* LWIP_ETHARP_H */
