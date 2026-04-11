#ifndef BUZZER_H
#define BUZZER_H

#include <avr/io.h>
#include <stdint.h>

void buzzer_init();
void buzzer_tone(unsigned int freq);
void buzzer_off();
void buzzer_error();

#endif