#include "Arduino.h"
#include "ServerExceed.h"

void ServerExceed::sendDataFromServerToBoard() {
  // Check if a client has connected
  WiFiClient client = server->available();
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  client.flush();
  // Match the request
  String data;
  if (req.indexOf("/") != -1) {
    data = req.substring(req.indexOf("/") + 1, req.indexOf(" ", req.indexOf(" ") + 1));
  }
  else {
    client.stop();
    return;
  } 
  client.flush();
  // Send date to board
  Serial.println(data + "\r");
  // Prepare the response
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\n";
  s += data;
  s += "</html>\n";

  // Send the response to the client
  client.print(s);
  delay(1);

  // The client will actually be disconnected 
  // when the function returns and 'client' object is detroyed
}