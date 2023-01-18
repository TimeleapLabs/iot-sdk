#include <zephyr/logging/log.h>
#include <zephyr/net/net_ip.h>
#include <zephyr/net/socket.h>
#include <zephyr/net/tls_credentials.h>

#include <kenshi/kenshi.h>

LOG_MODULE_REGISTER(kenshi, CONFIG_KENSHI_LOG_LEVEL);

struct zsock_addrinfo *mql_dns_resolve() {

  int rc = -EINVAL;
  int retries = 3;

  static struct zsock_addrinfo hints;
  static struct zsock_addrinfo *haddr;

  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;

  while (retries--) {
    rc = getaddrinfo(MQL_HTTP_HOST, MQL_HTTP_PORT, &hints, &haddr);

    if (rc == 0) {
      LOG_INF("DNS resolved for %s:%s.", MQL_HTTP_HOST, MQL_HTTP_PORT);
      char hr_addr[INET_ADDRSTRLEN];
      LOG_INF(
          "%s address: %s.", (haddr->ai_family == AF_INET ? "IPv4" : "IPv6"),
          net_addr_ntop(haddr->ai_family, &net_sin(haddr->ai_addr)->sin_addr,
                        hr_addr, sizeof(hr_addr)));
      break;
    }

    LOG_INF("Err %d -- DNS not resolved for %s:%s, retrying...", rc,
            MQL_HTTP_HOST, MQL_HTTP_PORT);
  }

  return haddr;
}

static bool registered = false;

int mql_register_tls() {
  if (registered) {
    return 0;
  }

  registered = true;

  int err =
      tls_credential_add(MQL_CA_CERTIFICATE_TAG, TLS_CREDENTIAL_CA_CERTIFICATE,
                         kenshi_ca_certificate, sizeof(kenshi_ca_certificate));
  if (err < 0) {
    LOG_ERR("Failed to register public certificate: %d", err);
  }

  return err;
}

int mql_get_sock() {

  mql_register_tls();

  struct zsock_addrinfo *haddr = mql_dns_resolve();
  int sock = socket(haddr->ai_family, haddr->ai_socktype, IPPROTO_TLS_1_2);

  LOG_INF("Initialized MQL socket.");

  sec_tag_t sec_tag_opt[] = {
      MQL_CA_CERTIFICATE_TAG,
  };

  setsockopt(sock, SOL_TLS, TLS_SEC_TAG_LIST, sec_tag_opt, sizeof(sec_tag_opt));
  setsockopt(sock, SOL_TLS, TLS_HOSTNAME, MQL_HTTP_HOST, sizeof(MQL_HTTP_HOST));
  connect(sock, haddr->ai_addr, haddr->ai_addrlen);

  LOG_INF("MQL socket connected.");

  return sock;
}