/**
 * @Author: xcrowzz
 * @Date:   2018-09-29T18:21:05+02:00
 * @Last modified by:   xcrowzz
 * @Last modified time: 2018-09-29T19:28:36+02:00
 */

#ifndef __MITM_RAW_SOCKET_H__
#define __MITM_RAW_SOCKET_H__

// Set basic network info
// Gateway + inet : ?> ip route | grep default
typedef struct {
  char *gateway_ip;
  char *gateway_mac;
  char *target_ip;
  char *target_mac;
  char *iface;
} s_inet ;

void  set_inet(char**);
void  toggle_ip_forwarding(int);
char  *get_mac(char *);
void  restore_network(char *, char *, char *, char *);
void  arp_poison(char *, char *, char *, char *);

#endif
