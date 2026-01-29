#ifndef LWIPOPTS_H
#define LWIPOPTS_H

#define NO_SYS                     1
#define LWIP_SOCKET                0
#define LWIP_NETCONN               0

#define MEM_ALIGNMENT              4
#define MEM_SIZE                   (8 * 1024)
#define PBUF_POOL_SIZE             8
#define MEMP_NUM_TCP_PCB           5
#define MEMP_NUM_TCP_SEG           16

#define LWIP_TCP                   1
#define LWIP_UDP                   1
#define LWIP_ICMP                  1
#define LWIP_DHCP                  1

#define TCP_MSS                    1460
#define TCP_SND_BUF                (4 * TCP_MSS)
#define TCP_WND                    (4 * TCP_MSS)

#define LWIP_HTTPD                 0

#define LWIP_DEBUG                 0

#endif
