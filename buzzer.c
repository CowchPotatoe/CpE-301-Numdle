#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "buzzer.h"

// Initialize Timer1 PWM on OC1A (PB1)
void buzzer_init() {
	// OC1A pin as output
	DDRB |= (1 << PB1);   
	// Non-inverted PWM on OC1A + Fast PWM mode
	TCCR1A |= (1 << COM1A1) | (1 << WGM11);
    // Fast PWM (ICR1 as TOP)
	TCCR1B |= (1 << WGM13) | (1 << WGM12);   
	// Initialize counter
	TCNT1 = 0;  
	// Initially buzzer off
    buzzer_off();
}

// Set tone frequency
void buzzer_tone(unsigned int freq) {
	if (freq == 0) return;
	//TOP = (F_CPU / (N * freq)) - 1
	// F_CPU = system clock (16 MHz)
	// N     = prescaler (e.g., 64)
	// freq  = desired buzzer frequency (Hz)
	uint32_t top = (F_CPU / (64 * freq)) - 1;
	ICR1 = top;
	OCR1A = top / 2;
	//timer1 start
	TCCR1B |= (1 << CS11) | (1 << CS10); // prescaler 64
}

// Turn buzzer off
void buzzer_off() {
	// stop timer
	TCCR1B &= ~((1 << CS12) | (1 << CS11) | (1 << CS10));
	// turn output low
	PORTB &= ~(1 << PB1);
}

void buzzer_error() {
	for (int i = 0; i < 3; i++) {
		buzzer_tone(800);
		_delay_ms(150);
		buzzer_off();
		_delay_ms(100);
	}
}