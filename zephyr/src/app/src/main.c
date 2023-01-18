/*
 * Copyright (c) 2016 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <errno.h>
#include <zephyr/kernel.h>

#include <inttypes.h>
#include <stdio.h>

#include <zephyr/drivers/gpio.h>

#include <zephyr/net/net_event.h>
#include <zephyr/net/net_if.h>
#include <zephyr/net/net_mgmt.h>
#include <zephyr/net/wifi.h>
#include <zephyr/net/wifi_mgmt.h>

#include <kenshi/kenshi.h>

#define AUTO_CONNECT_SSID "WIFI_SSID_HERE"
#define AUTO_CONNECT_SSID_PSK "WIFI_PSK_HERE"

static int connected;
static struct net_mgmt_event_callback wifi_shell_mgmt_cb;

static void handle_wifi_connect_result(struct net_mgmt_event_callback *cb) {
  const struct wifi_status *status = (const struct wifi_status *)cb->info;

  if (status->status) {
    printk("Connection request failed (%d)\n", status->status);
  } else {
    printk("WIFI Connected\n");
    struct net_if *iface = net_if_get_default();
  }
}

static void wifi_mgmt_event_handler(struct net_mgmt_event_callback *cb,
                                    uint32_t mgmt_event, struct net_if *iface) {
  switch (mgmt_event) {
  case NET_EVENT_WIFI_CONNECT_RESULT:
    handle_wifi_connect_result(cb);
    break;
  case NET_EVENT_IPV4_ADDR_ADD:

    char hr_addr[NET_IPV4_ADDR_LEN];
    printk("IP obtained.\n");

    for (int i = 0; i < NET_IF_MAX_IPV4_ADDR; i++) {

      struct net_if_addr *if_addr = &iface->config.ip.ipv4->unicast[i];

      if (if_addr->addr_type != NET_ADDR_DHCP || !if_addr->is_used) {
        continue;
      }

      printk("IPv4 address: %s\n",
             net_addr_ntop(AF_INET, &if_addr->address.in_addr, hr_addr,
                           NET_IPV4_ADDR_LEN));

      connected = 1;
      break;
    }
    break;
  default:
    break;
  }
}

void wifi_connect(void) {
  int nr_tries = 10;
  int ret = 0;

  net_mgmt_init_event_callback(&wifi_shell_mgmt_cb, wifi_mgmt_event_handler,
                               NET_EVENT_IPV4_ADDR_ADD);

  net_mgmt_add_event_callback(&wifi_shell_mgmt_cb);

  struct net_if *iface = net_if_get_default();

  net_dhcpv4_start(iface);

  static struct wifi_connect_req_params cnx_params = {
      .ssid = AUTO_CONNECT_SSID,
      .ssid_length = 0,
      .psk = AUTO_CONNECT_SSID_PSK,
      .psk_length = 0,
      //.sae_password = AUTO_CONNECT_SSID_PSK,
      //.sae_password_length = 0,
      .channel = 0,
      .security = WIFI_SECURITY_TYPE_PSK,
  };

  cnx_params.ssid_length = strlen(AUTO_CONNECT_SSID);
  cnx_params.psk_length = strlen(AUTO_CONNECT_SSID_PSK);
  // cnx_params.sae_password_length = strlen(AUTO_CONNECT_SSID_PSK);

  connected = 0;

  printk("WIFI try connecting to %s...\n", AUTO_CONNECT_SSID);

  /* Let's wait few seconds to allow wifi device be on-line */
  while (nr_tries-- > 0) {
    ret = net_mgmt(NET_REQUEST_WIFI_CONNECT, iface, &cnx_params,
                   sizeof(struct wifi_connect_req_params));
    if (ret == 0) {
      break;
    }

    printk("Connect request failed %d. Waiting iface be up...\n", ret);
    k_msleep(500);
  }

  printk("Connection requested.\n");
}

MQL_INIT(kenshi_query, 24, from, to)
MQL_CALLBACK(kenshi_query, entries) { printk("%s\n", entries[0].block.hash); }

void main(void) {

  MQL_QUERY(kenshi_query, query_string,
            {.blockchain = "binance-mainnet",
             .apikey = "fSDjCXCTyq+cx7+HLXKBA5oGIfqyMwztb+0/7pvTK8I=",
             .owner = "0x51DD193630806aDCFFa9E72569a71A9c12591C33",
             .query = {
                 .block_address = "0x42f9c5a27a2647a64f7d3d58d8f896c60a727b0f",
                 .block_number = {.gte = 17633890, .lte = 17633892},
             }});

  wifi_connect();

  while (!connected) {
    k_msleep(500);
  }

  MQL_GET_EVENTS(kenshi_query, query_string, 2048);
}
