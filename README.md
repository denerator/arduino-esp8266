# Arduino - ES8266

![Connection schema](https://hackster.imgix.net/uploads/attachments/743851/esp-uno-diagram_FhozIF3OCj.png?auto=compress%2Cformat&w=680&h=510&fit=max)

ESP8266 is a self-standing microcontroller. This means it can be programmed directly as Arduino or we can manage it by AT commands. This is an example of the second variant. 

> **SoftwareSerial** library works great as long as the transmission speed is less than 19200 baud. But, there’s a small problem here. The ESP8266 module comes from the factory programmed to communicate at speed 115200 baud which is somehow hard at the **SoftwareSerial** library to communicate at. So, we need to reprogram our wifi module to set the communication speed to 9600 baud which works pretty good with the “SoftwareSerial” library.

In order to do it use this command.

```c++
  AT+UART_DEF=<baud>,8,1,0,0
```

For communication between Arduino and ESP8266 use Serial thread. Create an instance and pass its reference to the ESP8266.

```c++
  SoftwareSerial logger(10, 11);  // RX,TX
  ESP8266 wifi(&logger, DEBUG);
```
