
#ifndef SERIAL_IMPL_H_
#define SERIAL_IMPL_H_

#include "comstack/SerialStack.h"

class SerialImpl : public SerialStack
{

public:
	SerialImpl( unsigned long baud  );

private:
	byte 	data_read();
	size_t 	data_write( Message::Payload * );
	boolean data_available();

	void handle_response( Message::Data * );
	void handle_request( Message::Data * );
	void handle_event( Message::Data * );
};

#endif /* SERIAL_IMPL_H_ */
