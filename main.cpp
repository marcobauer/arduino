#include <Arduino.h>
#include "SerialImpl.h"

unsigned long gTime = 0;
unsigned int  gSec  = 0;

SerialImpl *serialImpl;

void setup() {
	serialImpl = new SerialImpl(115200);
}

void loop()
{
	serialImpl->process();
}

int main(void) {
    init();
    setup();
    for (;;) {
        loop();
    }
}
