# ServerExceed
`ServerExceed` เป็น class สำหรับ `nodeMCU` ที่ใช้ในค่าย `eXceed 13` ซึ่งรวมคำสั่งที่ใช้ในการส่งข้อมูลระหว่างบอร์ด `Galileo Gen 2` กับ `Web Server` และการต่อ `Wifi`

ไม่ต้อง `include "ESP8266WiFi.h"` แบบด้านล่าง เนื่องจาก library นี้ได้จัดการให้เรียบร้อยแล้ว

## Constructor

default constructor คือ **ServerExceed**

กำหนดค่าเริ่มต้นของ class ผ่าน constructor
```C
ServerExceed(
  char* _ssid,
  char* _password,
  char* _host,
  int _port,
  String _group,
  WiFiServer* _server
)
```

## Getter And Setter

กำหนด ssid ที่ใช้ในการต่อ wifi
```C
void setSsid(char* _ssid)
```

return ค่า ssid ที่ใช้ในการต่อ wifi ออกมา
```C
char* getSsid()
```

กำหนด password ที่ใช้ในการต่อ wifi
```C
void setPassword(char* _password)
```

return ค่า password ที่ใช้ในการต่อ wifi ออกมา
```C
char* getPassword()
```

กำหนด host ของ server ที่ใช้ส่งข้อมูล
```C
void setHost(char* _host)
```

return host ของ server ที่ใช้ส่งข้อมูล
```C
char* getHost()
```

กำหนด port ของ host
```C
void setPort(int _port)
```

return port ของ host
```C
int getPort()
```

กำหนดชื่อกลุ่ม
```C
void setGroup(String _group)
```

return ชื่อกลุ่ม
```C
String getGroup()
```

กำหนด nodeMCU server
```C
void setServer(WiFiServer* _server)
```

return nodeMCU server
```C
WiFiServer* getServer()
```

# Function

**connectServer** ใช้ใน setup เพื่อต่อ wifi และลงทะเบียน localIP ของ nodeMCU ให้กับ web server
```C
void connectServer()
```

**sendDataFromServerToBoard** ใช้ใน loop เพื่อรอข้อมูลจาก Server แล้วส่งไปที่ Board
```C
void sendDataFromServerToBoard()
```

**sendDataFromBoardToServer** ใช้ใน loop เพื่อส่ง data จาก Board ไปที่ Server
```C
void sendDataFromBoardToServer(String &data)
```
