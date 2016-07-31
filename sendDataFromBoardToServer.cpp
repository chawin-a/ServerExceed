#include "Arduino.h"
#include "ServerExceed.h"

void ServerExceed::sendDataFromBoardToServer(String &data) {
  // Connect and send data to server
  WiFiClient client;
  client.setTimeout(50);
  client.connect(host, port);
  client.print(String("GET ") + "/" + group + "/" + data + " HTTP/1.1\r\n" +
    "Host: " + host + "\r\n" +
    "Connection: close\r\n\r\n");
  delay(50);
}