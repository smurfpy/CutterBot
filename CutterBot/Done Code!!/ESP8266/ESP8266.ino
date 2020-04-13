#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
     
const char* ssid = "Zone stop";
const char* password = "0857750502";

ESP8266WebServer server(80);
MDNSResponder mdns;
     
String webPage = "";

void setup(void){
     
  Serial.begin(115200);
  while (!Serial) {
  }
  
  // ปริ้นค่าสถานะต่างๆ
  Serial.println("");
  Serial.println("ESP8266 board info:");
  Serial.print("\tChip ID: ");
  Serial.println(ESP.getFlashChipId());
  Serial.print("\tCore Version: ");
  Serial.println(ESP.getCoreVersion());
  Serial.print("\tChip Real Size: ");
  Serial.println(ESP.getFlashChipRealSize());
  Serial.print("\tChip Flash Size: ");
  Serial.println(ESP.getFlashChipSize());
  Serial.print("\tChip Flash Speed: ");
  Serial.println(ESP.getFlashChipSpeed());
  Serial.print("\tChip Speed: ");
  Serial.println(ESP.getCpuFreqMHz());
  Serial.print("\tChip Mode: ");
  Serial.println(ESP.getFlashChipMode());
  Serial.print("\tSketch Size: ");
  Serial.println(ESP.getSketchSize());
  Serial.print("\tSketch Free Space: ");
  Serial.println(ESP.getFreeSketchSpace());

  // แสดงบนหน้าเว็บ
  webPage += "<h1><font color= blue >Cutter Bot</h1></font>";
  webPage += "<p>Control Motor <a href=\"FORWARD\"><button>FORWARD</button></a>&nbsp;<a href=\"RIGHT\"><button>RIGHT</button></a>&nbsp;<a href=\"LEFT\"><button>LEFT</button></a>&nbsp;<a href=\"BACKWARD\"><button>BACKWARD</button></a>&nbsp;<a href=\"STOP\"><button>STOP</button></a></p>";
  webPage += "<p>Cutter Control <a href=\"ON\"><button>ON</button></a>&nbsp;<a href=\"OFF\"><button>OFF</button></a>";
  webPage += "<br><img src= https://www.234.in.th/images/2020/04/07/laffy.jpg align = center></br>";
  // เริ่มการเชื่อมต่อไวไฟ
  WiFi.begin(ssid, password);
  Serial.println("");
     

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");  //  
  Serial.println(ssid);
  Serial.print("IP address: ");  //  
  Serial.println(WiFi.localIP());

  if (mdns.begin("esp8266", WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }
     
  server.on("/", [](){
    server.send(200, "text/html", webPage);
  });
  
  server.on("/FORWARD", [](){
    server.send(100, "text/html", webPage);
    Serial.println("[FORWARD]");
  });
  
  server.on("/RIGHT", [](){
    server.send(100, "text/html", webPage);
    Serial.println("[RIGHT]");
  });

    server.on("/LEFT", [](){
    server.send(200, "text/html", webPage);
    Serial.println("[LEFT]");
  });
  
    server.on("/BACKWARD", [](){
    server.send(100, "text/html", webPage);
    Serial.println("[BACKWARD]");
  });
  
    server.on("/STOP", [](){
    server.send(100, "text/html", webPage);
    Serial.println("[STOP]");
  }); 
     
    server.on("/ON", [](){
    server.send(100, "text/html", webPage);
    Serial.println("[ON]");
  });
  
    server.on("/OFF", [](){
    server.send(100, "text/html", webPage);
    Serial.println("[OFF]");
  });
  server.begin();
  Serial.println("HTTP server started");
  
}
     
void loop(void)
{
  server.handleClient();
}
