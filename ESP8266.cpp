#include "ESP8266.h"

ESP8266::ESP8266(Stream *log, boolean debug) {
  isDebug = debug;
  logger = log;
}

String ESP8266::init() {
  return sendData("AT+RST\r\n", 2000);
}

String ESP8266::enableMode(int mode) {
  String command = "AT+CWMODE=" + String(mode) + "\r\n";
  return sendData(command, 2000);
}

String ESP8266::connectToAP(String ssid, String password) {
  String command = "AT+CWJAP=\"OnePlus 5\",\"11117777\"\r\n";
  String altcommand = "AT+CWJAP=\"" + ssid + "\",\"" + password + "\""; // TODO:
  return sendData(command, 6000);
}

String ESP8266::getIP() {
  String res = sendData("AT+CIFSR\r\n" , 2000);
  String res = sendData("AT+CIFSR\r\n" , 2000);
  Serial.println(res);
}

String ESP8266::sendData(String command, int timeout) {
  String response = "";
  logger->print(command);
  long int time = millis();

  while ((time + timeout) > millis()) {
    while (logger->available()) {
      char c = logger->read();
      response += c;
    }
  }
  if ( isDebug ) {
    Serial.print(response);
  }
  return response;
}
