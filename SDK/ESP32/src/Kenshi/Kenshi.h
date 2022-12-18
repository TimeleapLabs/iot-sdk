/*
  Kenshi.h - Library for interacting with the Kenshi Deep Index.
  Created by Pouya Eghbali, December 9, 2022.
  Released under Apache-2.0 license.
*/
#ifndef Kenshi_h
#define Kenshi_h
#include "Arduino.h"
#include <ArduinoJson.h>
#include <WiFiClientSecure.h>

using MongoQuery = DynamicJsonDocument;
using MongoDocument = DynamicJsonDocument;
using MongoDocuments = JsonArray;

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
  PolygonMainnet
};

class MQL {
private:
  char *_apiKey;
  char *_owner;
  Blockchain _blockchain;

public:
  MQL(char *apiKey, char *owner, Blockchain blockchain);
  MongoQuery initQuery();
  MongoQuery initQuery(int size);
  MongoDocuments runQuery(MongoQuery query);
};

class SyncTask {
private:
  char *_taskId;

public:
  SyncTask(char *taskId);
  uint getLastSyncedBlock();
};

#endif