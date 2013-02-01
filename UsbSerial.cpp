#include "UsbSerial.h"
#include <HardwareSerial.h>

UsbSerial::UsbSerial( unsigned long baud ) : buffer_size(0), timestamp( 0 ), uptime( 0 )
{
	Serial.begin( baud );
}

uint16_t UsbSerial::writeData( uint8_t *data )
{
	Serial.write( (char*) data );
	return 0;
}

void UsbSerial::alive()
{
	uint8_t buf[30];
	uint32_t upTime = millis();

    if( ( upTime - this->timestamp) >= 5000) {
    	this->timestamp = upTime;
    	this->uptime += 5;
    	snprintf( (char*) &buf[0], 128, "Uptime:%ld", this->uptime );
    	this->transmit( &buf[0] );
    }
}

void UsbSerial::checkRxBuffer()
{
	boolean newData = false;

	while (Serial.available()) {
		newData = true;
		this->buffer[this->buffer_size++] = (uint8_t) Serial.read();
	}

	if( newData )
	{
		this->receive( this->buffer, this->buffer_size );
		this->buffer_size = 0;
	}
}
