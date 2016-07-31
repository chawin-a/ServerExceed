// #define BLYNK_PRINT Serial // Enables Serial Monitor
#include <ServerExceed.h>
#include <SPI.h>
#include <BlynkSimpleEsp8266.h>

// Setting for Server
WiFiServer server(80); // nodeMCU server : port 80
char ssid[] = "your-ssid";
char password[] = "your-password";
char host[] = "your-host";
int port = 8080;
String group = "your-group";
ServerExceed mcu(ssid, password, host, port, group, &server);

// Setting for Blynk
char auth[] = "your-authentication";
char blynk_host[] = "your-blynk-host";
int blynk_port = 18442;

void setup() {
  Serial.begin(115200);
  mcu.connectServer();
  Blynk.config(auth, blynk_host, blynk_port);
}

String data = "";
String blynk_data = "";
String server_data = "";

void loop() {
  if(Serial.available()) {
  	data = Serial.readStringUntil('\r');
  	Serial.flush();
  	// YOUR CODE HERE
  	
  	mcu.sendDataFromBoardToServer(data);
  }
  mcu.sendDataFromServerToBoard();
  Blynk.run();
}
