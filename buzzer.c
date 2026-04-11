#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "buzzer.h"

// Initialize buzzer pin
void buzzer_init() {
    BUZZER_DDR |= (1 << BUZZER_PIN);
    //buzzer initally off
    BUZZER_PORT &= ~(1 << BUZZER_PIN);
}

// Turn buzzer ON
void buzzer_on() {
    BUZZER_PORT |= (1 << BUZZER_PIN);
}

// Turn buzzer OFF
void buzzer_off() {
    BUZZER_PORT &= ~(1 << BUZZER_PIN);
}

// Error sound (multiple beeps)
void buzzer_error() {
    for(int i = 0; i < 3; i++){
        buzzer_on();
        _delay_ms(100);
        buzzer_off();
        _delay_ms(100);
    }
}
