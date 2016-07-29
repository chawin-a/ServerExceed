#include <ServerExceed.h>

WiFiServer server(80); // nodeMCU server : port 80
ServerExceed mcu("ssid", "password", "host", port, "group", &server);

void setup() {
  Serial.begin(115200);
  mcu.connectServer();
}

void loop() {
  mcu.sendDataFromBoardToServer();
  mcu.sendDataFromServerToBoard();
}
