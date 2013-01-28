#include <Arduino.h>
#include "UsbSerial.h"

unsigned long gTime = 0;
unsigned int  gSec  = 0;

UsbSerial *serialUsb;

void setup() {
	serialUsb = new UsbSerial(115200);
}

void loop() {
	serialUsb->alive();
}

int main(void) {
    init();
    setup();
    for (;;) {
        loop();
    }
}
