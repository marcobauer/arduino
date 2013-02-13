#include "SerialImpl.h"
#include <HardwareSerial.h>

#define BUFFER_LENGTH 30

SerialImpl::SerialImpl( unsigned long baud )
{
	Serial.begin( baud );
}

byte SerialImpl::data_read()
{
	return (byte) Serial.read();
}

size_t SerialImpl::data_write( Message::Payload *data  )
{
	return Serial.write( data->content, data->size );
}

boolean SerialImpl::data_available()
{
	return Serial.available();
}

void SerialImpl::handle_response( Message::Data *data )
{

}

void SerialImpl::handle_request( Message::Data *data )
{

}

void SerialImpl::handle_event( Message::Data *data )
{

}

//void UsbSerial::alive()
//{
//	uint8_t buf[BUFFER_LENGTH];
//
//    if( ( millis() - this->timestamp) >= 5000) {
//    	this->timestamp = millis();
//    	this->uptime += 5;
//    	size_t size = snprintf( (char*) &buf[0], BUFFER_LENGTH, "Uptime:%ld", this->uptime );
//    	this->transmit( &buf[0], size );
//    }
//}
//

