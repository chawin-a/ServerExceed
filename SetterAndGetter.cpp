#include "Arduino.h"
#include "ServerExceed.h"

void ServerExceed::setSsid(char* _ssid) {
  ssid = _ssid;
}

void ServerExceed::setPassword(char* _password){
  password = _password;
}

void ServerExceed::setHost(char* _host) {
  host = _host;
}

void ServerExceed::setPort(int _port) {
  port = _port;
}

void ServerExceed::setGroup(String _group)  {
	group = _group;
}

void ServerExceed::setServer(WiFiServer* _server) {
	server = _server;
}

char* ServerExceed::getSsid() {
	return ssid;
}

char* ServerExceed::getPassword() {
	return password;
}

char* ServerExceed::getHost() {
	return host;
}

int ServerExceed::getPort() {
	return port;
}

String ServerExceed::getGroup() {
	return group;
}

WiFiServer* ServerExceed::getServer() {
	return server;
}