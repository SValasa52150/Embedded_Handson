#ifndef LWIP_INIT_H
#define LWIP_INIT_H

#include "lwip/netif.h"

extern struct netif gnetif;
void MX_LWIP_Init(void);

#endif
