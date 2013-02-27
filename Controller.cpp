#include "Controller.h"
#include "Arduino.h"
#include <HardwareSerial.h>
#include "port_defines.h"

using namespace ComStack;

#define TOGGLE_LED0 ( digitalRead( PORT_P0 ) == LOW ) ? digitalWrite( PORT_P0, HIGH ) : digitalWrite( PORT_P0, LOW )

Controller::Controller( unsigned long baud ) : upTime(0), lastTime(0), ledState(false), delayStartup(true)
{
	Serial.begin( baud );
	lastTime = millis();
}

byte Controller::data_read()
{
	return (byte) Serial.read();
}

size_t Controller::data_write( byte data )
{
	return Serial.write( data );
}

size_t Controller::data_write( byte *data, byte size  )
{
	return Serial.write( data, size );
}

boolean Controller::data_available()
{
	return Serial.available();
}

void Controller::response( ComStack::RxMessage *data )
{

}

void Controller::request( ComStack::RxMessage *data )
{

}

void Controller::event( ComStack::RxMessage *data )
{

}

void Controller::error( ComStack::Error::Type error )
{
	switch( error )
	{
		case ComStack::Error::buffer_rx_full:
		break;

		case ComStack::Error::buffer_tx_full:
		break;

		case ComStack::Error::msg_crc_error:
		break;

		default:
			// unknown error;
			break;
	}
}

void Controller::warn( ComStack::Warning::Type warning )
{
	switch( warning )
	{
		case ComStack::Warning::buffer_tx_overload:
		break;

		case ComStack::Warning::buffer_rx_overload:
		break;

		case ComStack::Warning::buffer_rx_cleanup:
		break;

		default:
			break;
	}
}

void Controller::alive()
{
	if( delayStartup )
	{
		if( ( millis() - lastTime ) >= 10000)
			delayStartup = false;

		return;
	}

    if( ( millis() - lastTime ) >= 5000)
    {
    	lastTime = millis();
    	upTime += 5;

    	TOGGLE_LED0;

    	TxMessage* msgTx = newMessage( Message::event, Instruction::uptime );
    	msgTx->add( (byte)(upTime>>8) & 0xFF );
    	msgTx->add( (byte)(upTime) & 0xFF );
    	msgTx->send();
    }
}
