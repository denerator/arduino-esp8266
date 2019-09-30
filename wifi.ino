#include <SoftwareSerial.h>
#include "ESP8266.h"
#define DEBUG true

SoftwareSerial logger(10, 11);  // RX,TX

ESP8266 wifi(&logger, DEBUG);

void setup()
{

  Serial.begin(115200);
  logger.begin(9600);

  while (!logger) {}
  Serial.println("Ready");
  wifi.init();
  Serial.println("Enable station mode…");
  wifi.enableMode(1);
  Serial.println("Connecting to the AP...");
  wifi.connectToAP("OnePlus 5", "11117777");
  Serial.println("Get IP...");
  String IP = wifi.getIP();
  Serial.print("Your IP is ");
  Serial.println(IP);
  Serial.println("Starting server...");
  wifi.configureConnectionsMode(1);
  wifi.startServer(80);
}


void loop() {
}
