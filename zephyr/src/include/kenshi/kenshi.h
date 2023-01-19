#pragma once

#include "cJSON.h"
#include <inttypes.h>

#include <zephyr/logging/log.h>
#include <zephyr/net/http/client.h>
#include <zephyr/net/socket.h>

#define MQL_HTTP_HOST "api.kenshi.io"
#define MQL_HTTP_PORT "443"
#define MQL_HTTP_PATH "/index/mql"

static const unsigned char kenshi_ca_certificate[] = {
    0x30, 0x82, 0x03, 0x41, 0x30, 0x82, 0x02, 0x29, 0xa0, 0x03, 0x02, 0x01,
    0x02, 0x02, 0x13, 0x06, 0x6c, 0x9f, 0xcf, 0x99, 0xbf, 0x8c, 0x0a, 0x39,
    0xe2, 0xf0, 0x78, 0x8a, 0x43, 0xe6, 0x96, 0x36, 0x5b, 0xca, 0x30, 0x0d,
    0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x0b, 0x05,
    0x00, 0x30, 0x39, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06,
    0x13, 0x02, 0x55, 0x53, 0x31, 0x0f, 0x30, 0x0d, 0x06, 0x03, 0x55, 0x04,
    0x0a, 0x13, 0x06, 0x41, 0x6d, 0x61, 0x7a, 0x6f, 0x6e, 0x31, 0x19, 0x30,
    0x17, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x10, 0x41, 0x6d, 0x61, 0x7a,
    0x6f, 0x6e, 0x20, 0x52, 0x6f, 0x6f, 0x74, 0x20, 0x43, 0x41, 0x20, 0x31,
    0x30, 0x1e, 0x17, 0x0d, 0x31, 0x35, 0x30, 0x35, 0x32, 0x36, 0x30, 0x30,
    0x30, 0x30, 0x30, 0x30, 0x5a, 0x17, 0x0d, 0x33, 0x38, 0x30, 0x31, 0x31,
    0x37, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x5a, 0x30, 0x39, 0x31, 0x0b,
    0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x55, 0x53, 0x31,
    0x0f, 0x30, 0x0d, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x13, 0x06, 0x41, 0x6d,
    0x61, 0x7a, 0x6f, 0x6e, 0x31, 0x19, 0x30, 0x17, 0x06, 0x03, 0x55, 0x04,
    0x03, 0x13, 0x10, 0x41, 0x6d, 0x61, 0x7a, 0x6f, 0x6e, 0x20, 0x52, 0x6f,
    0x6f, 0x74, 0x20, 0x43, 0x41, 0x20, 0x31, 0x30, 0x82, 0x01, 0x22, 0x30,
    0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x01,
    0x05, 0x00, 0x03, 0x82, 0x01, 0x0f, 0x00, 0x30, 0x82, 0x01, 0x0a, 0x02,
    0x82, 0x01, 0x01, 0x00, 0xb2, 0x78, 0x80, 0x71, 0xca, 0x78, 0xd5, 0xe3,
    0x71, 0xaf, 0x47, 0x80, 0x50, 0x74, 0x7d, 0x6e, 0xd8, 0xd7, 0x88, 0x76,
    0xf4, 0x99, 0x68, 0xf7, 0x58, 0x21, 0x60, 0xf9, 0x74, 0x84, 0x01, 0x2f,
    0xac, 0x02, 0x2d, 0x86, 0xd3, 0xa0, 0x43, 0x7a, 0x4e, 0xb2, 0xa4, 0xd0,
    0x36, 0xba, 0x01, 0xbe, 0x8d, 0xdb, 0x48, 0xc8, 0x07, 0x17, 0x36, 0x4c,
    0xf4, 0xee, 0x88, 0x23, 0xc7, 0x3e, 0xeb, 0x37, 0xf5, 0xb5, 0x19, 0xf8,
    0x49, 0x68, 0xb0, 0xde, 0xd7, 0xb9, 0x76, 0x38, 0x1d, 0x61, 0x9e, 0xa4,
    0xfe, 0x82, 0x36, 0xa5, 0xe5, 0x4a, 0x56, 0xe4, 0x45, 0xe1, 0xf9, 0xfd,
    0xb4, 0x16, 0xfa, 0x74, 0xda, 0x9c, 0x9b, 0x35, 0x39, 0x2f, 0xfa, 0xb0,
    0x20, 0x50, 0x06, 0x6c, 0x7a, 0xd0, 0x80, 0xb2, 0xa6, 0xf9, 0xaf, 0xec,
    0x47, 0x19, 0x8f, 0x50, 0x38, 0x07, 0xdc, 0xa2, 0x87, 0x39, 0x58, 0xf8,
    0xba, 0xd5, 0xa9, 0xf9, 0x48, 0x67, 0x30, 0x96, 0xee, 0x94, 0x78, 0x5e,
    0x6f, 0x89, 0xa3, 0x51, 0xc0, 0x30, 0x86, 0x66, 0xa1, 0x45, 0x66, 0xba,
    0x54, 0xeb, 0xa3, 0xc3, 0x91, 0xf9, 0x48, 0xdc, 0xff, 0xd1, 0xe8, 0x30,
    0x2d, 0x7d, 0x2d, 0x74, 0x70, 0x35, 0xd7, 0x88, 0x24, 0xf7, 0x9e, 0xc4,
    0x59, 0x6e, 0xbb, 0x73, 0x87, 0x17, 0xf2, 0x32, 0x46, 0x28, 0xb8, 0x43,
    0xfa, 0xb7, 0x1d, 0xaa, 0xca, 0xb4, 0xf2, 0x9f, 0x24, 0x0e, 0x2d, 0x4b,
    0xf7, 0x71, 0x5c, 0x5e, 0x69, 0xff, 0xea, 0x95, 0x02, 0xcb, 0x38, 0x8a,
    0xae, 0x50, 0x38, 0x6f, 0xdb, 0xfb, 0x2d, 0x62, 0x1b, 0xc5, 0xc7, 0x1e,
    0x54, 0xe1, 0x77, 0xe0, 0x67, 0xc8, 0x0f, 0x9c, 0x87, 0x23, 0xd6, 0x3f,
    0x40, 0x20, 0x7f, 0x20, 0x80, 0xc4, 0x80, 0x4c, 0x3e, 0x3b, 0x24, 0x26,
    0x8e, 0x04, 0xae, 0x6c, 0x9a, 0xc8, 0xaa, 0x0d, 0x02, 0x03, 0x01, 0x00,
    0x01, 0xa3, 0x42, 0x30, 0x40, 0x30, 0x0f, 0x06, 0x03, 0x55, 0x1d, 0x13,
    0x01, 0x01, 0xff, 0x04, 0x05, 0x30, 0x03, 0x01, 0x01, 0xff, 0x30, 0x0e,
    0x06, 0x03, 0x55, 0x1d, 0x0f, 0x01, 0x01, 0xff, 0x04, 0x04, 0x03, 0x02,
    0x01, 0x86, 0x30, 0x1d, 0x06, 0x03, 0x55, 0x1d, 0x0e, 0x04, 0x16, 0x04,
    0x14, 0x84, 0x18, 0xcc, 0x85, 0x34, 0xec, 0xbc, 0x0c, 0x94, 0x94, 0x2e,
    0x08, 0x59, 0x9c, 0xc7, 0xb2, 0x10, 0x4e, 0x0a, 0x08, 0x30, 0x0d, 0x06,
    0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x0b, 0x05, 0x00,
    0x03, 0x82, 0x01, 0x01, 0x00, 0x98, 0xf2, 0x37, 0x5a, 0x41, 0x90, 0xa1,
    0x1a, 0xc5, 0x76, 0x51, 0x28, 0x20, 0x36, 0x23, 0x0e, 0xae, 0xe6, 0x28,
    0xbb, 0xaa, 0xf8, 0x94, 0xae, 0x48, 0xa4, 0x30, 0x7f, 0x1b, 0xfc, 0x24,
    0x8d, 0x4b, 0xb4, 0xc8, 0xa1, 0x97, 0xf6, 0xb6, 0xf1, 0x7a, 0x70, 0xc8,
    0x53, 0x93, 0xcc, 0x08, 0x28, 0xe3, 0x98, 0x25, 0xcf, 0x23, 0xa4, 0xf9,
    0xde, 0x21, 0xd3, 0x7c, 0x85, 0x09, 0xad, 0x4e, 0x9a, 0x75, 0x3a, 0xc2,
    0x0b, 0x6a, 0x89, 0x78, 0x76, 0x44, 0x47, 0x18, 0x65, 0x6c, 0x8d, 0x41,
    0x8e, 0x3b, 0x7f, 0x9a, 0xcb, 0xf4, 0xb5, 0xa7, 0x50, 0xd7, 0x05, 0x2c,
    0x37, 0xe8, 0x03, 0x4b, 0xad, 0xe9, 0x61, 0xa0, 0x02, 0x6e, 0xf5, 0xf2,
    0xf0, 0xc5, 0xb2, 0xed, 0x5b, 0xb7, 0xdc, 0xfa, 0x94, 0x5c, 0x77, 0x9e,
    0x13, 0xa5, 0x7f, 0x52, 0xad, 0x95, 0xf2, 0xf8, 0x93, 0x3b, 0xde, 0x8b,
    0x5c, 0x5b, 0xca, 0x5a, 0x52, 0x5b, 0x60, 0xaf, 0x14, 0xf7, 0x4b, 0xef,
    0xa3, 0xfb, 0x9f, 0x40, 0x95, 0x6d, 0x31, 0x54, 0xfc, 0x42, 0xd3, 0xc7,
    0x46, 0x1f, 0x23, 0xad, 0xd9, 0x0f, 0x48, 0x70, 0x9a, 0xd9, 0x75, 0x78,
    0x71, 0xd1, 0x72, 0x43, 0x34, 0x75, 0x6e, 0x57, 0x59, 0xc2, 0x02, 0x5c,
    0x26, 0x60, 0x29, 0xcf, 0x23, 0x19, 0x16, 0x8e, 0x88, 0x43, 0xa5, 0xd4,
    0xe4, 0xcb, 0x08, 0xfb, 0x23, 0x11, 0x43, 0xe8, 0x43, 0x29, 0x72, 0x62,
    0xa1, 0xa9, 0x5d, 0x5e, 0x08, 0xd4, 0x90, 0xae, 0xb8, 0xd8, 0xce, 0x14,
    0xc2, 0xd0, 0x55, 0xf2, 0x86, 0xf6, 0xc4, 0x93, 0x43, 0x77, 0x66, 0x61,
    0xc0, 0xb9, 0xe8, 0x41, 0xd7, 0x97, 0x78, 0x60, 0x03, 0x6e, 0x4a, 0x72,
    0xae, 0xa5, 0xd1, 0x7d, 0xba, 0x10, 0x9e, 0x86, 0x6c, 0x1b, 0x8a, 0xb9,
    0x59, 0x33, 0xf8, 0xeb, 0xc4, 0x90, 0xbe, 0xf1, 0xb9};

#define MQL_CA_CERTIFICATE_TAG 308203

struct zsock_addrinfo *mql_dns_resolve();
int mql_register_tls();
int mql_get_sock();

struct MQL_block_range {
  uint64_t gt;
  uint64_t gte;
  uint64_t lt;
  uint64_t lte;
};

#define MQL_JSON_NESTED(name, outer, inner)                                    \
  JSON_OBJ_DESCR_PRIM_NAMED(struct name, #outer "." #inner, outer##_##inner,   \
                            JSON_TOK_STRING)

#define MQL_NO_ARG , ,

#define MQL_ARG(arg) char *event_args_##arg;
#define GET_MQL_ARG_MACRO(_1, _2, _3, _4, _5, _6, _7, _8, NAME, ...) NAME

#define MQL_ARGS2(_1, _2)                                                      \
  MQL_ARG(_1);                                                                 \
  MQL_ARG(_2);

#define MQL_ARGS3(_1, _2, _3)                                                  \
  MQL_ARGS2(_1, _2);                                                           \
  MQL_ARG(_3);

#define MQL_ARGS4(_1, _2, _3, _4)                                              \
  MQL_ARGS4(_1, _2, _3);                                                       \
  MQL_ARG(_4);

#define MQL_ARGS5(_1, _2, _3, _4, _5)                                          \
  MQL_ARGS4(_1, _2, _3, _4);                                                   \
  MQL_ARG(_5);

#define MQL_ARGS6(_1, _2, _3, _4, _5, _6)                                      \
  MQL_ARGS5(_1, _2, _3, _4, _5);                                               \
  MQL_ARG(_6);

#define MQL_ARGS7(_1, _2, _3, _4, _5, _6, _7)                                  \
  MQL_ARGS6(_1, _2, _3, _4, _5, _6);                                           \
  MQL_ARG(_7);

#define MQL_ARGS8(_1, _2, _3, _4, _5, _6, _7, _8)                              \
  MQL_ARGS7(_1, _2, _3, _4, _5, _6, _7);                                       \
  MQL_ARG(_8);

#define MQL_ARGS(...)                                                          \
  GET_MQL_ARG_MACRO(__VA_ARGS__, MQL_ARGS8, MQL_ARGS7, MQL_ARGS6, MQL_ARGS5,   \
                    MQL_ARGS4, MQL_ARGS3, MQL_ARGS2, MQL_ARG)                  \
  (__VA_ARGS__)

#define MQL_ENTRY_ARG(arg) char arg[131];
#define GET_MQL_ENTRY_ARG_MACRO(_1, _2, _3, _4, _5, _6, _7, _8, NAME, ...) NAME

#define MQL_ENTRY_ARGS2(_1, _2)                                                \
  MQL_ENTRY_ARG(_1);                                                           \
  MQL_ENTRY_ARG(_2);

#define MQL_ENTRY_ARGS3(_1, _2, _3)                                            \
  MQL_ENTRY_ARGS2(_1, _2);                                                     \
  MQL_ENTRY_ARG(_3);

#define MQL_ENTRY_ARGS4(_1, _2, _3, _4)                                        \
  MQL_ENTRY_ARGS4(_1, _2, _3);                                                 \
  MQL_ENTRY_ARG(_4);

#define MQL_ENTRY_ARGS5(_1, _2, _3, _4, _5)                                    \
  MQL_ENTRY_ARGS4(_1, _2, _3, _4);                                             \
  MQL_ENTRY_ARG(_5);

#define MQL_ENTRY_ARGS6(_1, _2, _3, _4, _5, _6)                                \
  MQL_ENTRY_ARGS5(_1, _2, _3, _4, _5);                                         \
  MQL_ENTRY_ARG(_6);

#define MQL_ENTRY_ARGS7(_1, _2, _3, _4, _5, _6, _7)                            \
  MQL_ENTRY_ARGS6(_1, _2, _3, _4, _5, _6);                                     \
  MQL_ENTRY_ARG(_7);

#define MQL_ENTRY_ARGS8(_1, _2, _3, _4, _5, _6, _7, _8)                        \
  MQL_ENTRY_ARGS7(_1, _2, _3, _4, _5, _6, _7);                                 \
  MQL_ENTRY_ARG(_8);

#define MQL_ENTRY_ARGS(...)                                                    \
  GET_MQL_ARG_MACRO(__VA_ARGS__, MQL_ENTRY_ARGS8, MQL_ENTRY_ARGS7,             \
                    MQL_ENTRY_ARGS6, MQL_ENTRY_ARGS5, MQL_ENTRY_ARGS4,         \
                    MQL_ENTRY_ARGS3, MQL_ENTRY_ARGS2, MQL_ENTRY_ARG)           \
  (__VA_ARGS__)

#define MQL_ARG_SERIALIZE(arg)                                                 \
  if (query->event_args_##arg) {                                               \
    cJSON *event_args_##arg = cJSON_CreateString(query->event_args_##arg);     \
    cJSON_AddItemToObject(query_doc, "event.args." #arg, event_args_##arg);    \
  }

#define GET_MQL_ARG_SERIALIZE_MACRO(_1, _2, _3, _4, _5, _6, _7, _8, NAME, ...) \
  NAME

#define MQL_ARGS_SERIALIZE2(_1, _2)                                            \
  MQL_ARG_SERIALIZE(_1);                                                       \
  MQL_ARG_SERIALIZE(_2);

#define MQL_ARGS_SERIALIZE3(_1, _2, _3)                                        \
  MQL_ARGS_SERIALIZE2(_1, _2);                                                 \
  MQL_ARG_SERIALIZE(_3);

#define MQL_ARGS_SERIALIZE4(_1, _2, _3, _4)                                    \
  MQL_ARGS_SERIALIZE4(_1, _2, _3);                                             \
  MQL_ARG_SERIALIZE(_4);

#define MQL_ARGS_SERIALIZE5(_1, _2, _3, _4, _5)                                \
  MQL_ARGS_SERIALIZE4(_1, _2, _3, _4);                                         \
  MQL_ARG_SERIALIZE(_5);

#define MQL_ARGS_SERIALIZE6(_1, _2, _3, _4, _5, _6)                            \
  MQL_ARGS_SERIALIZE5(_1, _2, _3, _4, _5);                                     \
  MQL_ARG_SERIALIZE(_6);

#define MQL_ARGS_SERIALIZE7(_1, _2, _3, _4, _5, _6, _7)                        \
  MQL_ARGS_SERIALIZE6(_1, _2, _3, _4, _5, _6);                                 \
  MQL_ARG_SERIALIZE(_7);

#define MQL_ARGS_SERIALIZE8(_1, _2, _3, _4, _5, _6, _7, _8)                    \
  MQL_ARGS_SERIALIZE7(_1, _2, _3, _4, _5, _6, _7);                             \
  MQL_ARG_SERIALIZE(_8);

#define MQL_ARGS_SERIALIZE(args...)                                            \
  GET_MQL_ARG_MACRO(args, MQL_ARGS_SERIALIZE8, MQL_ARGS_SERIALIZE7,            \
                    MQL_ARGS_SERIALIZE6, MQL_ARGS_SERIALIZE5,                  \
                    MQL_ARGS_SERIALIZE4, MQL_ARGS_SERIALIZE3,                  \
                    MQL_ARGS_SERIALIZE2, MQL_ARG_SERIALIZE)                    \
  (args)

#define MQL_STR_DESERIALIZE(parent, key)                                       \
  strcpy(entry->parent.key,                                                    \
         cJSON_GetObjectItemCaseSensitive(parent, #key)->valuestring);

#define MQL_INT_DESERIALIZE(parent, key)                                       \
  entry->parent.key =                                                          \
      cJSON_GetObjectItemCaseSensitive(parent, #key)->valuedouble;

#define MQL_ARG_DESERIALIZE(arg)                                               \
  strcpy(entry->event.args.arg,                                                \
         cJSON_GetObjectItemCaseSensitive(args, #arg)->valuestring);

#define GET_MQL_ARG_DESERIALIZE_MACRO(_1, _2, _3, _4, _5, _6, _7, _8, NAME,    \
                                      ...)                                     \
  NAME

#define MQL_ARGS_DESERIALIZE2(_1, _2)                                          \
  MQL_ARG_DESERIALIZE(_1);                                                     \
  MQL_ARG_DESERIALIZE(_2);

#define MQL_ARGS_DESERIALIZE3(_1, _2, _3)                                      \
  MQL_ARGS_DESERIALIZE2(_1, _2);                                               \
  MQL_ARG_DESERIALIZE(_3);

#define MQL_ARGS_DESERIALIZE4(_1, _2, _3, _4)                                  \
  MQL_ARGS_DESERIALIZE4(_1, _2, _3);                                           \
  MQL_ARG_DESERIALIZE(_4);

#define MQL_ARGS_DESERIALIZE5(_1, _2, _3, _4, _5)                              \
  MQL_ARGS_DESERIALIZE4(_1, _2, _3, _4);                                       \
  MQL_ARG_DESERIALIZE(_5);

#define MQL_ARGS_DESERIALIZE6(_1, _2, _3, _4, _5, _6)                          \
  MQL_ARGS_DESERIALIZE5(_1, _2, _3, _4, _5);                                   \
  MQL_ARG_DESERIALIZE(_6);

#define MQL_ARGS_DESERIALIZE7(_1, _2, _3, _4, _5, _6, _7)                      \
  MQL_ARGS_DESERIALIZE6(_1, _2, _3, _4, _5, _6);                               \
  MQL_ARG_DESERIALIZE(_7);

#define MQL_ARGS_DESERIALIZE8(_1, _2, _3, _4, _5, _6, _7, _8)                  \
  MQL_ARGS_DESERIALIZE7(_1, _2, _3, _4, _5, _6, _7);                           \
  MQL_ARG_DESERIALIZE(_8);

#define MQL_ARGS_DESERIALIZE(args...)                                          \
  GET_MQL_ARG_MACRO(args, MQL_ARGS_DESERIALIZE8, MQL_ARGS_DESERIALIZE7,        \
                    MQL_ARGS_DESERIALIZE6, MQL_ARGS_DESERIALIZE5,              \
                    MQL_ARGS_DESERIALIZE4, MQL_ARGS_DESERIALIZE3,              \
                    MQL_ARGS_DESERIALIZE2, MQL_ARG_DESERIALIZE)                \
  (args)

#define MQL_SERIALIZE_NESTED(outer, inner)                                     \
  if (req.query.outer##_##inner) {                                             \
    cJSON *outer##_##inner = cJSON_CreateString(req.query.outer##_##inner);    \
    cJSON_AddItemToObject(query_doc, #outer "." #inner, outer##_##inner);      \
  }

#define MQL_SERIALIZE(key)                                                     \
  if (req.key) {                                                               \
    cJSON *key##_value = cJSON_CreateString(req.key);                          \
    cJSON_AddItemToObject(req_doc, #key, key##_value);                         \
  }

#define MQL_SERIALIZE_BLOCK_NUMBER(key)                                        \
  if (req.query.block_number.key) {                                            \
    cJSON *block_number_##key =                                                \
        cJSON_CreateNumber(req.query.block_number.key);                        \
    cJSON_AddItemToObject(block_number, "$" #key, block_number_##key);         \
  }

struct mql_block {
  char address[43];
  int64_t number;
  char hash[67];
};

struct mql_log {
  char index[9];
};

struct mql_transaction {
  char hash[67];
  char index[9];
};

#define MQL_QUERY_INIT(mql_name, event_count, struct_args, entry_args,         \
                       serialize_args, deserialize_args)                       \
                                                                               \
  struct mql_name {                                                            \
    char *block_address;                                                       \
    char *block_hash;                                                          \
    struct MQL_block_range block_number;                                       \
    char *transaction_hash;                                                    \
    char *transaction_index;                                                   \
    char *log_index;                                                           \
    char *event_name;                                                          \
    char *event_signature;                                                     \
    struct_args                                                                \
  };                                                                           \
                                                                               \
  struct mql_name##_request {                                                  \
    char *owner;                                                               \
    char *blockchain;                                                          \
    char *apikey;                                                              \
    struct mql_name query;                                                     \
  };                                                                           \
                                                                               \
  struct mql_name##_mql_event_args {                                           \
    entry_args                                                                 \
  };                                                                           \
                                                                               \
  struct mql_name##_mql_event {                                                \
    char name[21];                                                             \
    char signature[121];                                                       \
    struct mql_name##_mql_event_args args;                                     \
  };                                                                           \
                                                                               \
  struct mql_name##_mql_entry {                                                \
    char created_at[25];                                                       \
    struct mql_log log;                                                        \
    struct mql_transaction transaction;                                        \
    struct mql_block block;                                                    \
    struct mql_name##_mql_event event;                                         \
  };                                                                           \
                                                                               \
  void serialize_##mql_name##_args(cJSON *query_doc, struct mql_name *query) { \
    serialize_args                                                             \
  }                                                                            \
                                                                               \
  char *serialize_##mql_name(struct mql_name##_request req) {                  \
    cJSON *req_doc = cJSON_CreateObject();                                     \
                                                                               \
    MQL_SERIALIZE(owner);                                                      \
    MQL_SERIALIZE(apikey);                                                     \
    MQL_SERIALIZE(blockchain);                                                 \
                                                                               \
    cJSON *query_doc = cJSON_CreateObject();                                   \
                                                                               \
    MQL_SERIALIZE_NESTED(block, address);                                      \
    MQL_SERIALIZE_NESTED(block, hash);                                         \
    MQL_SERIALIZE_NESTED(transaction, hash);                                   \
    MQL_SERIALIZE_NESTED(transaction, index);                                  \
    MQL_SERIALIZE_NESTED(log, index);                                          \
    MQL_SERIALIZE_NESTED(event, name);                                         \
    MQL_SERIALIZE_NESTED(event, signature);                                    \
                                                                               \
    serialize_kenshi_query_args(query_doc, &req.query);                        \
                                                                               \
    if (req.query.block_number.gt || req.query.block_number.gte ||             \
        req.query.block_number.lt || req.query.block_number.gt) {              \
      cJSON *block_number = cJSON_CreateObject();                              \
      MQL_SERIALIZE_BLOCK_NUMBER(gt);                                          \
      MQL_SERIALIZE_BLOCK_NUMBER(gte);                                         \
      MQL_SERIALIZE_BLOCK_NUMBER(lt);                                          \
      MQL_SERIALIZE_BLOCK_NUMBER(lte);                                         \
      cJSON_AddItemToObject(query_doc, "block.number", block_number);          \
    }                                                                          \
                                                                               \
    cJSON_AddItemToObject(req_doc, "query", query_doc);                        \
                                                                               \
    char *string = cJSON_PrintUnformatted(req_doc);                            \
    cJSON_Delete(req_doc);                                                     \
    return string;                                                             \
  }                                                                            \
                                                                               \
  static void deserialize_##mql_name(struct mql_name##_mql_entry *entries,     \
                                     char *data) {                             \
    cJSON *parsed = cJSON_Parse(data);                                         \
    int index = 0;                                                             \
    const cJSON *item = NULL;                                                  \
                                                                               \
    cJSON_ArrayForEach(item, parsed) {                                         \
      struct mql_name##_mql_entry *entry = &entries[index++];                  \
                                                                               \
      cJSON *block = cJSON_GetObjectItemCaseSensitive(item, "block");          \
      cJSON *log = cJSON_GetObjectItemCaseSensitive(item, "log");              \
      cJSON *event = cJSON_GetObjectItemCaseSensitive(item, "event");          \
      cJSON *transaction =                                                     \
          cJSON_GetObjectItemCaseSensitive(item, "transaction");               \
      cJSON *args = cJSON_GetObjectItemCaseSensitive(event, "args");           \
                                                                               \
      MQL_INT_DESERIALIZE(block, number);                                      \
      MQL_STR_DESERIALIZE(block, hash);                                        \
      MQL_STR_DESERIALIZE(block, address);                                     \
      MQL_STR_DESERIALIZE(transaction, hash);                                  \
      MQL_STR_DESERIALIZE(transaction, index);                                 \
      MQL_STR_DESERIALIZE(log, index);                                         \
      MQL_STR_DESERIALIZE(event, name);                                        \
      MQL_STR_DESERIALIZE(event, signature);                                   \
                                                                               \
      deserialize_args                                                         \
    }                                                                          \
                                                                               \
    cJSON_Delete(parsed);                                                      \
  }                                                                            \
                                                                               \
  static void mql_callback_##mql_name(struct mql_name##_mql_entry *entries);   \
                                                                               \
  static void mql_name##_response_cb(struct http_response *rsp,                \
                                     enum http_final_call final_data,          \
                                     void *user_data) {                        \
    LOG_MODULE_DECLARE(kenshi, CONFIG_KENSHI_LOG_LEVEL);                       \
                                                                               \
    if (final_data == HTTP_DATA_MORE) {                                        \
      LOG_ERR("Parsing partial MQL HTTP packets is not supported yet.");       \
      return;                                                                  \
    } else if (final_data == HTTP_DATA_FINAL) {                                \
      LOG_INF("All MQL data received (%zd bytes): %s", rsp->data_len,          \
              rsp->body_frag_start);                                           \
      struct mql_name##_mql_entry entries[event_count];                        \
      deserialize_##mql_name(entries, rsp->body_frag_start);                   \
      mql_callback_##mql_name(entries);                                        \
    }                                                                          \
  }

#define MQL_INIT(mql_name, event_count, args...)                               \
  MQL_QUERY_INIT(mql_name, event_count, MQL_ARGS(args), MQL_ENTRY_ARGS(args),  \
                 MQL_ARGS_SERIALIZE(args), MQL_ARGS_DESERIALIZE(args))

#define MQL_QUERY(mql_name, buf_name, values...)                               \
  struct mql_name##_request query_##buf_name = values;                         \
  char *buf_name = serialize_##mql_name(query_##buf_name);

#define MQL_CALLBACK(mql_name, entries)                                        \
  static void mql_callback_##mql_name(struct mql_name##_mql_entry *entries)

#define MQL_GET_EVENTS(mql_name, query, buffer_size)                           \
  do {                                                                         \
    LOG_MODULE_DECLARE(kenshi, CONFIG_KENSHI_LOG_LEVEL);                       \
                                                                               \
    int sock = mql_get_sock();                                                 \
    struct http_request req;                                                   \
    memset(&req, 0, sizeof(req));                                              \
                                                                               \
    const char *headers[] = {"Content-Type: application/json\r\n", NULL};      \
                                                                               \
    static uint8_t recv_buf_ipv4[buffer_size];                                 \
    int32_t timeout = 3 * MSEC_PER_SEC;                                        \
                                                                               \
    req.method = HTTP_POST;                                                    \
    req.url = MQL_HTTP_PATH;                                                   \
    req.host = MQL_HTTP_HOST;                                                  \
    req.protocol = "HTTP/1.1";                                                 \
    req.response = mql_name##_response_cb;                                     \
    req.header_fields = headers;                                               \
    req.payload = query;                                                       \
    req.payload_len = strlen(query);                                           \
    req.recv_buf = recv_buf_ipv4;                                              \
    req.recv_buf_len = sizeof(recv_buf_ipv4);                                  \
                                                                               \
    int ret = http_client_req(sock, &req, timeout, NULL);                      \
                                                                               \
    if (ret == 0) {                                                            \
      LOG_ERR("Failed to send MQL data.");                                     \
    }                                                                          \
                                                                               \
    free(query);                                                               \
    close(sock);                                                               \
  } while (0)
