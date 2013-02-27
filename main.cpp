#include <Arduino.h>
#include "Controller.h"
#include "port_defines.h"

Controller *controller;

void setup() {
	pinMode(PORT_P0, OUTPUT);
	pinMode(PORT_P1, OUTPUT);
	pinMode(PORT_P2, OUTPUT);
	pinMode(PORT_P3, OUTPUT);
	controller = new Controller(115200);
}

void loop()
{
	controller->threadRead();
	controller->threadWrite();
	controller->alive();
}

int main(void) {

    init();
    setup();
    for (;;) {
        loop();
    }
}
