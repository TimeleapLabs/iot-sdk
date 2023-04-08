#include "Kenshi.h"
#include "Arduino.h"
#include "Client.h"
#include <ArduinoJson.h>

#ifdef ESP32
#include <HTTPClient.h>
#else
#include <ArduinoHttpClient.h>
#endif

const char *apiDomain = "api.kenshi.io";
const char *mqlPath = "/index/mql";
const char *indexInfoPath = "/index/info/";
const char *mqlEndpoint = "https://api.kenshi.io/index/mql";
const char *indexInfoEndpoint = "https://api.kenshi.io/index/info/";

char *kenshiRootCert =
    "-----BEGIN CERTIFICATE-----\n"
    "MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF\n"
    "ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6\n"
    "b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL\n"
    "MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv\n"
    "b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj\n"
    "ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM\n"
    "9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw\n"
    "IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6\n"
    "VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L\n"
    "93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm\n"
    "jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC\n"
    "AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA\n"
    "A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI\n"
    "U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs\n"
    "N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv\n"
    "o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU\n"
    "5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy\n"
    "rqXRfboQnoZsG4q5WTP468SQvvG5\n"
    "-----END CERTIFICATE-----;\n";

SyncTask::SyncTask(char *taskId) { _taskId = taskId; }

uint SyncTask::getLastSyncedBlock(Client &client) {
#ifdef ESP32
  HTTPClient http;

  String endpoint = String(indexInfoEndpoint) + String(_taskId);
  http.begin(endpoint, kenshiRootCert);

  int httpResponseCode = http.GET();

  DynamicJsonDocument response(256);
  deserializeJson(response, http.getStream());

  http.end();

#else
  HttpClient http(client, apiDomain, 443);
  String path = String(indexInfoPath) + String(_taskId);
  http.get(path);

  DynamicJsonDocument response(256);
  deserializeJson(response, http.responseBody());
#endif
  return response["lastSyncedBlock"].as<uint>();
}

uint SyncTask::getLastSyncedBlock() {
#ifdef ESP32
  HTTPClient http;

  String endpoint = String(indexInfoEndpoint) + String(_taskId);
  http.begin(endpoint, kenshiRootCert);

  int httpResponseCode = http.GET();

  DynamicJsonDocument response(256);
  deserializeJson(response, http.getStream());

  http.end();
  return response["lastSyncedBlock"].as<uint>();
#else
  return 0;
#endif
}

MQL::MQL(char *apiKey, char *owner, Blockchain blockchain) {
  _apiKey = apiKey;
  _owner = owner;
  _blockchain = blockchain;
}

String blockchainToString(Blockchain blockchain) {
  switch (blockchain) {
  case FantomTestnet:
    return "fantom-testnet";
  case FantomMainnet:
    return "fantom-mainnet";
  case BinanceMainnet:
    return "binance-mainnet";
  case BinanceTestnet:
    return "binance-testnet";
  case EthereumGoerli:
    return "ethereum-goerli";
  case EthereumMainnet:
    return "ethereum-mainnet";
  case ArbitrumGoerli:
    return "arbitrum-goerli";
  case ArbitrumMainnet:
    return "arbitrum-mainnet";
  case AvalancheTestnet:
    return "avalanche-testnet";
  case AvalancheMainnet:
    return "avalanche-mainnet";
  case PolygonMumbai:
    return "polygon-mumbai";
  case PolygonMainnet:
    return "polygon-mainnet";
  case AuroraTestnet:
    return "aurora-testnet";
  case AuroraMainnet:
    return "aurora-mainnet";
  case BitgertTestnet:
    return "bitgert-testnet";
  case BitgertMainnet:
    return "bitgert-mainnet";
  default:
    return "";
  }
}

MongoQuery MQL::initQuery() { return DynamicJsonDocument(1024); }
MongoQuery MQL::initQuery(int size) { return DynamicJsonDocument(size); }

String MQL::getPayload(MongoQuery query) {
  DynamicJsonDocument request(4096);
  request["owner"] = _owner;
  request["apikey"] = _apiKey;
  request["blockchain"] = blockchainToString(_blockchain);
  request["query"] = query;

  String payload;
  serializeJson(request, payload);

  return payload;
}

MongoDocuments MQL::runQuery(Client &client, MongoQuery query) {
  String payload = getPayload(query);

#ifdef ESP32
  HTTPClient http;
  http.begin(mqlEndpoint, kenshiRootCert);
  http.addHeader("Content-Type", "application/json");

  int httpResponseCode = http.POST(payload);
  DynamicJsonDocument response(8196);
  deserializeJson(response, http.getStream());

  http.end();
#else
  HttpClient http(client, apiDomain, 443);
  http.post(mqlPath, "application/json", payload);

  DynamicJsonDocument response(8196);
  deserializeJson(response, http.responseBody());
#endif

  return response.as<JsonArray>();
}

MongoDocuments MQL::runQuery(MongoQuery query) {
#ifdef ESP32
  HTTPClient http;
  http.begin(mqlEndpoint, kenshiRootCert);
  http.addHeader("Content-Type", "application/json");

  String payload = getPayload(query);

  int httpResponseCode = http.POST(payload);
  DynamicJsonDocument response(8196);
  deserializeJson(response, http.getStream());

  http.end();
  return response.as<JsonArray>();
#else
  return DynamicJsonDocument(0).as<JsonArray>();
#endif
}
