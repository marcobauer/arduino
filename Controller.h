
#ifndef DATASTACK_H_
#define DATASTACK_H_

#include "comstack/MessageHandler.h"

class Controller : public ComStack::MessageHandler
{

public:
	Controller( unsigned long baud  );

	void alive();

private:
	byte 	data_read();
	size_t  data_write( byte data );
	size_t 	data_write( byte *, byte );
	boolean data_available();

	void response( ComStack::RxMessage * );
	void request( ComStack::RxMessage * );
	void event( ComStack::RxMessage * );
	void error( ComStack::Error::Type );
	void warn( ComStack::Warning::Type );

	unsigned int 	upTime;
	unsigned long 	lastTime;
	boolean			ledState;
};

#endif /* DATASTACK_H_ */
