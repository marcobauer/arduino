
#ifndef USBSERIAL_H_
#define USBSERIAL_H_

#include "comstack/SerialStack.h"

class UsbSerial : public SerialStack {

public:
	UsbSerial( unsigned long baud  );

private:
	uint16_t transmit( uint8_t * );
	uint16_t receive( uint8_t * );

};

#endif /* USBSERIAL_H_ */
