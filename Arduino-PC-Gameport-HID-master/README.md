### Arduino Gameport to USB HID

Jednostavan Arduino Leonardo projekt. Omogućit će korištenje starog PC joysticka s Gameport DB15 interfaceom.

Using modified Arduino USB HID core from. Link contain files for old Arduino IDE, repo contain new version with slightly modify logging. Replace files from Arduino folder Arduino\hardware\arduino\cores\arduino\ with new version from Arduino_USB_HID_Core (USBAPI.h HID.cpp).

Build Arduino shield or using breadboard with schematic from Schematic folder.

If you are using analog joystick open sketch from Analog_Joystick or get Digital_Joystick for gamepad.

All schematic create with fritzing. Slightly mess with ortogonal lines ;(.

P.S. Analog joystick may be need slightly tuning with constants.

const int AXIS_MIN = 550;
const int AXIS_MAX = 1023;
const int AXIS_NUL = 720; 

All debug information route to Arduino COM port.
