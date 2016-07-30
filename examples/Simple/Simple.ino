#include <ServerExceed.h>

WiFiServer server(80); // nodeMCU server : port 80
ServerExceed mcu("ssid", "password", "host", port, "group", &server);

void setup() {
  mcu.connectServer();
}

String data = "";

void loop() {
  if(Serial.available()) {
  	data = Serial.readStringUntil('\r');
  	Serial.flush();
  	mcu.sendDataFromBoardToServer(data);
  }
  mcu.sendDataFromServerToBoard();
  data = "";
}
