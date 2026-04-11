#ifndef LCD_H
#define LCD_H

// I2C functions
void i2c_init(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_write(uint8_t data);

// LCD helper functions
void lcd_expander_write(uint8_t data);
void lcd_pulse(uint8_t data);
void lcd_write4(uint8_t nibble, uint8_t mode);
void lcd_send(uint8_t value, uint8_t mode);

// LCD high-level functions
void lcdCommanda(unsigned char cmd);
void lcdData(unsigned char data);
void lcd_init(void);
void lcd_print(unsigned char *str);
void lcd_gotoxy(unsigned char x, unsigned char y);

#endif
