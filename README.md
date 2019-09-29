# Arduino - ES8266

![Connection schema](https://hackster.imgix.net/uploads/attachments/743851/esp-uno-diagram_FhozIF3OCj.png?auto=compress%2Cformat&w=680&h=510&fit=max)

ESP8266 is a self-standing microcontroller. This means it can be programmed directly as Arduino or we can manage it by AT commands. This is an example of the second variant. 

For communication between Arduino and ESP8266 use Serial thread. Create an instance and pass its reference to the ESP8266.

```c++
  SoftwareSerial logger(10, 11);  // RX,TX
  ESP8266 wifi(&logger, DEBUG);
```
