#ifndef ServerExceed_h
#define ServerExceed_h

#include "Arduino.h"
#include "ESP8266WiFi.h"

class ServerExceed
{
  private:
    char* ssid;
    char* password;
    char* host;
    int port;
    String group;
    WiFiServer* server;
  public:
    // Constructor
    ServerExceed();
    ServerExceed(char* _ssid, char* _password, char* _host, int _port, String _group, WiFiServer* _server);
    // Setter And Getter
    void setSsid(char* _ssid);
    char* getSsid();
    void setPassword(char* _password);
    char* getPassword();
    void setHost(char* _host);
    char* getHost();
    void setPort(int _port);
    int getPort();
    void setGroup(String _group);
    String getGroup();
    void setServer(WiFiServer* _server);
    WiFiServer* getServer();
    // Function
    void connectServer();
    void sendDataFromServerToBoard();
    void sendDataFromBoardToServer();
};

#endif