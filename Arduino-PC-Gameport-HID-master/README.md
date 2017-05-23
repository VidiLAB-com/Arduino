### Arduino Gameport to USB HID

Jednostavan Arduino Leonardo projekt. Omogućit će korištenje starog PC joysticka s Gameport DB15 interfaceom.

Arduino IDE koji vam treba je verzije 1.6.5 te ga skinite sa službenih stranica na adresi https://www.arduino.cc/en/Main/OldSoftwareReleases#previous
Nakon instalacije trebate zamijeniti dvije datoteke (USBAPI.h HID.cpp) koje možete preuzeti ovdje
https://github.com/VidiLAB-com/Arduino/tree/master/Arduino-PC-Gameport-HID-master/Arduino_USB_HID_Core
te ih prekopirati preko postojećih u folder gdje ste instalirali Arduino IDE 1.6.5, a to je najčešće C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino

U Schematic folderu nalazi se shema za spajanje uz pomoć breadboard ili možete izraditi Arduino shield.

Ukoliko koristite analogni joystick otvorite skicu iz Analog_Joystick ili iz Digital_Joystick za gamepad.

Sve sheme napravljene su uz pomoć fritzinga.

P.S. Analogni joystick možete podesiti ovim konstantama.

const int AXIS_MIN = 550;
const int AXIS_MAX = 1023;
const int AXIS_NUL = 720; 

Sve debug informacije idu na Arduino COM port.
