#include "UsbSerial.h"
#include <HardwareSerial.h>

UsbSerial::UsbSerial( unsigned long baud )
{
	Serial.begin( baud );
}

uint16_t UsbSerial::transmit( uint8_t *data )
{
	Serial.write( (char*) data );
	return 0;
}

uint16_t UsbSerial::receive( uint8_t * )
{
	return 0;
}
