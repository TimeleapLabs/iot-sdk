#include "blinky.h"
#include <Kenshi.h>
#include <WiFiNINA.h>

const char *ssid = WIFI_SSID;
const char *password = WIFI_PASSWORD;

// Variables to keep track of events
uint lastSyncedBlock;
uint lastProcessedBlock;

// Secure Wifi Client
WiFiSSLClient wifiSecure;

// Create an instance of Kenshi Sync Task and MQL
SyncTask task(KENSHI_TASK_ID);
MQL mql(KENSHI_API_KEY, KENSHI_API_OWNER, FantomTestnet);

// Connect to WiFi
void initWiFi() {
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.print(' ');
  Serial.println(WiFi.localIP());
}

// Set LED pins to OUTPUT (So we can blink them!)
void initPins() {
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
}

// Blink a LED, once
void blinkLed(uint8_t pin) {
  digitalWrite(pin, HIGH);
  delay(200);
  digitalWrite(pin, LOW);
}

// Our setup function:
// 1. Enables Serial logging
// 2. Calls our init functions (WiFi and pins)
// 3. Gets the latest synced block from our sync task
void setup() {
  Serial.begin(115200);
  initPins();
  initWiFi();
  // Process only future events!
  lastProcessedBlock = task.getLastSyncedBlock(wifiSecure);
}

// Main loop
void loop() {

  // Get last synced block and init a query object
  lastSyncedBlock = task.getLastSyncedBlock(wifiSecure);
  MongoQuery query = mql.initQuery();

  // Populate the query fields: We are looking for a
  // Blink event, emitted in a block ranging from the
  // last block we processed, and the last block synced
  // by the Kenshi Deep Index
  query["event.name"] = "Blink";
  query["block.number"]["$gt"] = lastProcessedBlock;
  query["block.number"]["$lte"] = lastSyncedBlock;

  // Run the query and get the results
  MongoDocuments entries = mql.runQuery(wifiSecure, query);

  uint length = entries.size();
  uint maxBlock = lastProcessedBlock;

  for (MongoDocument entry : entries) {
    // Get the "led" arg from our Blink event
    String ledArg = entry["event"]["args"]["led"];
    // Determine which led to blink based on the led argument
    uint8_t pin = ledArg == "0x00" ? GREEN_LED_PIN : RED_LED_PIN;
    // Blink the led!
    blinkLed(pin);

    if (maxBlock < entry["block"]["number"]) {
      maxBlock = entry["block"]["number"];
    }
  }

  // Keep track of the last block we processed
  if (maxBlock > lastProcessedBlock) {
    lastProcessedBlock = maxBlock;
  }

  if (length == 0) {
    delay(500);
  }
}
