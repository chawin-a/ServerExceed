# ServerExceed
ServerExceed เป็น class สำหรับ nodeMCU ที่ใช้ในค่าย Exceed 13 ซึ่งรวมคำสั่งที่ใช้ในการส่งข้อมูลระหว่างบอร์ด galileo gen2 กับ web server และการต่อ wifi (#include "ESP8266WiFi.h" ไว้แล้ว ไม่ต้อง include เพิ่ม) ไว้แล้ว เพื่อให้ง่ายต่อการใช้งาน

# Constructor

ServerExceed() // default constructor

ServerExceed(char* _ssid, char* _password, char* _host, int _port, String _group, WiFiServer* _server) // กำหนดค่าเริ่มต้นของ class ผ่าน constructor

# Getter And Setter

void setSsid(char* _ssid) // กำหนด ssid ที่ใช้ในการต่อ wifi

char* getSsid() // return ค่า ssid ที่ใช้ในการต่อ wifi ออกมา

void setPassword(char* _password) // กำหนด password ที่ใช้ในการต่อ wifi

char* getPassword() // return ค่า password ที่ใช้ในการต่อ wifi ออกมา

void setHost(char* _host) // กำหนด host ของ server ที่ใช้ส่งข้อมูล

char* getHost() // return host ของ server ที่ใช้ส่งข้อมูล

void setPort(int _port) // กำหนด port ของ host

int getPort() // return port ของ host

void setGroup(String _group) // กำหนดชื่อกลุ่ม

String getGroup() // return ชื่อกลุ่ม

void setServer(WiFiServer* _server) // กำหนด nodeMCU server

WiFiServer* getServer() // return nodeMCU server

# Function

void connectServer()

// ใช้ใน setup เพื่อต่อ wifi และลงทะเบียน localIP ของ nodeMCU ให้กับ web server

void sendDataFromServerToBoard()

// ใช้ใน loop เพื่อรอข้อมูลจาก Server แล้วส่งไปที่ Board

void sendDataFromBoardToServer()

// ใช้ใน loop เพื่อรอข้อมูลจาก Board แล้วส่งไปที่ Server
