#include "Arduino.h"
#include "ServerExceed.h"

void ServerExceed::sendDataFromBoardToServer() {
  // Check if serial come
  if (!Serial.available()) {
    return;
  }
  // Read data from Serial
  String data = Serial.readStringUntil('\r');

  // Connect and send data to server
  WiFiClient client;
  client.setTimeout(50);
  client.connect(host, port);
  client.print(String("GET ") + "/" + group + "/sendData/" + data + " HTTP/1.0\r\n" +
    "Host: " + host + "\r\n" +
    "Connection: close\r\n\r\n");
  delay(50);
}