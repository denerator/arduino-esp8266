#include "ESP8266.h"

const String lineBreak = "\r\n";

ESP8266::ESP8266(Stream *log, boolean debug) {
  isDebug = debug;
  logger = log;
}

String ESP8266::init() {
  String command = "AT+RST";
  command += lineBreak;
  return sendData(command, 2000);
}

String ESP8266::enableMode(int mode) {
  String command = "AT+CWMODE=" + String(mode) + lineBreak;
  return sendData(command, 2000);
}

String ESP8266::connectToAP(String ssid, String password) {
  String command = "AT+CWJAP=\"";
  command += ssid;
  command += "\",\"";
  command += password;
  command += "\"";
  command += lineBreak;
  return sendData(command, 6000);
}

String ESP8266::getIP() {
  String command = "AT+CIFSR";
  command += lineBreak;
  return sendData(command, 4000);
}

String ESP8266::configureConnectionsMode(int mode) {
  String command = "AT+CIPMUX=" + String(mode) + lineBreak;
  return sendData(command, 2000);
}

String ESP8266::startServer(int port) {
  String command = "AT+CIPSERVER=1," + String(port) + lineBreak;
  return sendData(command, 4000);
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
