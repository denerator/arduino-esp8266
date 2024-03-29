#include "Arduino.h"

class ESP8266 {
  private:
    boolean isDebug;
    Stream *logger;
    String sendData(String command, int timeout);
    boolean isOK(String response);

  public:
    ESP8266(Stream *log, boolean debug);
    String init();
    String enableMode(int mode);
    String connectToAP(String sssid, String password);
    String getIP();
    String configureConnectionsMode(int mode);
    String startServer(int port);
};
