/**
 * @Author: xcrowzz
 * @Date:   2018-09-29T17:49:20+02:00
 * @Last modified by:   xcrowzz
 * @Last modified time: 2018-09-29T20:05:34+02:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mitm_raw_socket.h"

// SYS: Ubuntu 16.04
// USAGE: sudo ./mitm_raw_socket GATEWAY_IP TARGET_IP

int main(int ac, char **av) {
  if (ac != 3) {
    fprintf(stderr, "[!] Usage : sudo ./mitm_raw_socket GATEWAY_IP TARGET_IP\n");
    return -1;
  }
  fprintf(stdout, "[*] Starting program: mitm_raw_socket\n");
  toggle_ip_forwarding(1);
  set_inet(av);
  restore_network(NULL, NULL, NULL, NULL);
  fprintf(stdout, "[*] Done. Exiting...\n");
  return 0;
}

void set_inet(char **av) {
  s_inet  inet;

  fprintf(stdout, "[*] Initializing INET struct.\n");
  if ((inet.gateway_ip = malloc(strlen(av[1]) + 1)) == NULL) {
    fprintf(stderr, "[!] Memory allocation failed.\n");
    exit(EXIT_FAILURE);
  } else {
    if ((inet.gateway_ip = strncat(inet.gateway_ip, av[1], strlen(av[1]) + 1)) == NULL) {
      fprintf(stderr, "[!] Gateway IP setting failed to initialize.\n");
      exit(EXIT_FAILURE);
    }
  }
  if ((inet.target_ip = malloc(strlen(av[2]) + 1)) == NULL) {
    fprintf(stderr, "[!] Memory allocation failed.\n");
    exit(EXIT_FAILURE);
  } else {
    if ((inet.target_ip = strncat(inet.target_ip, av[2], strlen(av[2]) + 1)) == NULL) {
      fprintf(stderr, "[!] Target IP setting failed to initialize.\n");
      exit(EXIT_FAILURE);
    }
  }
  fprintf(stdout, "[*] INET struct initialized.\n");
  fprintf(stdout, "[+] Gateway IP : %s\n", inet.gateway_ip);
  fprintf(stdout, "[+] Target IP : %s\n", inet.target_ip);
  return;
}

void toggle_ip_forwarding(int state) {
  if (state == 1 ) {
    fprintf(stdout, "[*] Enabling IP forwarding.\n");
    if ((system("sysctl -w net.ipv4.ip_forward=1")) == -1) {
      fprintf(stderr, "[!] Failed to enable IP forwarding.\n");
      exit(EXIT_FAILURE);
    }
    fprintf(stdout, "[*] IP forwarding enabled.\n");
  } else if (state == 0) {
    fprintf(stdout, "[*] Disabling IP forwarding.\n");
    if ((system("sysctl -w net.ipv4.ip_forward=0")) == -1) {
      fprintf(stderr, "[!] Failed to disable IP forwarding.\n");
      exit(EXIT_FAILURE);
    }
    fprintf(stdout, "[*] IP forwarding disabled.\n");
  } else {
    fprintf(stderr, "[!] Failed to toggle IP forwarding.\n");
    exit(EXIT_FAILURE);
  }
  return ;
}

char *get_mac(char *ip) {
  return NULL;
}

void restore_network(char *gateway_ip, char *gateway_mac, char *target_ip, char *target_mac) {
  fprintf(stdout, "[*] Restoring network information.\n");
  toggle_ip_forwarding(0);
  return ;
}

void arp_poison(char *gateway_ip, char *gateway_mac, char *target_ip, char *target_mac) {
  return ;
}
