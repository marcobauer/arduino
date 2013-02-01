
#ifndef USBSERIAL_H_
#define USBSERIAL_H_

#include "comstack/SerialStack.h"

#define MAX_BUFFER 32

class UsbSerial : public SerialStack {

public:
	UsbSerial( unsigned long baud  );
	void checkRxBuffer();
	void alive();

private:
	uint16_t writeData( uint8_t * );
	uint8_t buffer[MAX_BUFFER];
	uint8_t buffer_size;

	uint32_t uptime, timestamp;
};

#endif /* USBSERIAL_H_ */
