#include "Arduino.h"
#include "ServerExceed.h"

ServerExceed::ServerExceed() {}

ServerExceed::ServerExceed(char* _ssid, char* _password, char* _host, int _port, String _group, WiFiServer* _server) {
	ssid = _ssid;
	password = _password;
	host = _host;
	port = _port;
	group = _group;
	server = _server;
}