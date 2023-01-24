/*
  Kenshi.h - Library for interacting with the Kenshi Deep Index.
  Created by Pouya Eghbali, December 9, 2022.
  Released under Apache-2.0 license.
*/
#ifndef Kenshi_h
#define Kenshi_h
#include "Arduino.h"
#include "Client.h"
#include <ArduinoJson.h>

using MongoQuery = DynamicJsonDocument;
using MongoDocument = DynamicJsonDocument;
using MongoDocuments = JsonArray;

/**
 * @brief Blockchain enum.
 * Contains all Kenshi MQL supported
 * blockchains. Use this to initialize
 * your MQL objects.
 */
enum Blockchain {
  FantomTestnet,
  FantomMainnet,
  BinanceTestnet,
  BinanceMainnet,
  EthereumGoerli,
  EthereumMainnet,
  AvalancheTestnet,
  AvalancheMainnet,
  PolygonMumbai,
  PolygonMainnet,
  AuroraTestnet,
  AuroraMainnet
};

class MQL {
private:
  char *_apiKey;
  char *_owner;
  Blockchain _blockchain;

public:
  /**
   * @brief Construct a new MQL object
   *
   * @param apiKey: Your MQL API key
   * @param owner: Your MQL API key owner
   * @param blockchain: Blockchain to query
   * (Use the Blockchain enum)
   */
  MQL(char *apiKey, char *owner, Blockchain blockchain);
  /**
   * @brief Returns an instance of MongoQuery
   * for you to fill. Use this to create your
   * query.
   * @note Assigns 1024 bytes to the query object
   * @return MongoQuery
   */
  MongoQuery initQuery();
  /**
   * @brief Returns an instance of MongoQuery
   * for you to fill. Use this to create your
   * query.
   * @param size: Assign `size` bytes to the
   * query object
   * @return MongoQuery
   */
  MongoQuery initQuery(int size);
  /**
   * @brief Get the payload string for a query
   *
   * @param query: A MongoQuery instance, returned
   * from an `initQuery` call.
   * @return String: JSON representation of `query`
   */
  String getPayload(MongoQuery query);
  /**
   * @brief Runs `query` against the Kenshi data
   * clusters and return the results
   * @note Use this on Arduino
   * @param client:  An instance of Arduino
   * Client (e.g. WiFiClient, EthernetClient
   * and GSMClient.)
   * @param query: A MongoQuery instance, returned
   * from an `initQuery` call.
   * @return MongoDocuments: An instance of JsonArray.
   * Read Kenshi MQL docs for the schema.
   */
  MongoDocuments runQuery(Client &client, MongoQuery query);
  /**
   * @brief Runs `query` against the Kenshi data
   * clusters and return the results
   * @note Use this on ESP32
   * @param query: A MongoQuery instance, returned
   * from an `initQuery` call.
   * @return MongoDocuments: An instance of JsonArray.
   * Read Kenshi MQL docs for the schema.
   */
  MongoDocuments runQuery(MongoQuery query);
};

class SyncTask {
private:
  char *_taskId;

public:
  /**
   * @brief Construct a new Sync Task object
   *
   * @param taskId: Your Kenshi Sync task ID
   */
  SyncTask(char *taskId);
  /**
   * @brief Get the last synced block number
   * @note Use this on ESP32 boards
   * @return uint: Last synced block number
   */
  uint getLastSyncedBlock();
  /**
   * @brief Get the last synced block number
   * @note Use this on Arduino boards
   * @param client: An instance of Arduino
   * Client (e.g. WiFiClient, EthernetClient
   * and GSMClient.)
   * @return uint: Last synced block number
   */
  uint getLastSyncedBlock(Client &client);
};

extern char *kenshiRootCert;

#endif
