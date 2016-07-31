#include <ServerExceed.h>

WiFiServer server(80); // nodeMCU server : port 80
char ssid[] = "your-ssid";
char password[] = "your-password";
char host[] = "your-host";
int port = 8080;
String group = "your-group"; 

ServerExceed mcu(ssid, password, host, port, group, &server);

void setup() {
  Serial.begin(115200);
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
}
