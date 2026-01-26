
#ifndef LWIPOPTS_H
#define LWIPOPTS_H

#define NO_SYS                 1
#define LWIP_ARP               1
#define LWIP_ETHERNET          1
#define LWIP_ICMP              1
#define LWIP_RAW               1

#define MEM_ALIGNMENT          4
#define MEM_SIZE               16000
#define PBUF_POOL_SIZE         16

#define LWIP_NETIF_STATUS_CALLBACK 1

#define LWIP_HTTPD             1
#define HTTPD_USE_CUSTOM_FSDATA 0

#define IP_ADDR0 192
#define IP_ADDR1 168
#define IP_ADDR2 1
#define IP_ADDR3 50

#endif
