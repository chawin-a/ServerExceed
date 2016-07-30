#include "Arduino.h"
#include "ServerExceed.h"

void ServerExceed::connectServer() {
  Serial.begin(115200);
  delay(10);

  // Connect to WiFi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  // Start the server
  server->begin();
  
  // Register IP address to server
  WiFiClient client;
  client.setTimeout(50);
  client.connect(host, port);
  client.print(String("GET ") + "/" + group + "/register/" + " HTTP/1.0\r\n" +
    "Host: " + host + "\r\n" +
    "Connection: close\r\n\r\n");
  delay(50);
}