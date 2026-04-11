#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "i2c.h"

// Initialize the i2c protocol
void i2c_init(void){
	TWSR = 0x00;
	TWBR = 72;          // ~100kHz for 16MHz
	TWCR = (1 << TWEN);
}

// Start i2c communication
void i2c_start(void) {
	// Clear interrupt flag, enable TWI, enable start bit
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
}

// Stop i2c communication
void i2c_stop() {
	// Clear interrupt flag, enable TWI, enable stop condition
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
	_delay_us(10);
}

// Write
void i2c_write(unsigned char data) {
	// Set data register as data
	TWDR = data;
	// Clear interrupt flag, enable TWI
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
}
