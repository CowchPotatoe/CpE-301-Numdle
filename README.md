# Numdle
## Embedded Systems Puzzle Game
## 3rd Place Winner — UNLV Junior Design Competition (Spring 2026)
## Created By: Ivan Chen and Isaac Chen

---

# Overview
**Numdle** is a mathematical puzzle game implemented entirely on embedded hardware using the **ATmega328PB Xplained Mini** microcontroller platform.
Inspired by games such as **WORDLE** and **Mathler**, players are tasked with guessing a valid mathematical equation that evaluates to a displayed target number. The player has a limited number of attempts and receives real-time visual and audio feedback after each guess.
The project combines embedded systems programming, peripheral interfacing, interrupt-driven design, and user interaction into a playable standalone game.

---

# Gameplay
The player is shown a target number on the LCD display and must enter a valid mathematical equation that evaluates to the target value.

Players are given:
* 5 attempts
* 6 character inputs per attempt

After every guess:
* The system checks whether the equation evaluates correctly
* Correctly placed characters are displayed as feedback
* LEDs indicate success/failure
* The buzzer plays a corresponding sound effect
The rotary encoder allows users to scroll through previously entered guesses.

---
# Hardware Components
| Component                 | Purpose                     |
| ------------------------- | --------------------------- |
| ATmega328PB Xplained Mini | Main microcontroller        |
| 4x4 Matrix Keypad         | Equation input              |
| 16x2 I2C LCD              | User interface display      |
| Rotary Encoder (HW-040)   | Navigation through attempts |
| Passive Buzzer            | Audio feedback              |
| LEDs                      | Visual feedback             |

---

# System Architecture

## Inputs
* Matrix keypad for entering equations
* Rotary encoder for scrolling through guesses
## Outputs
* I2C LCD for displaying:
  * target number
  * current equation
  * feedback
  * game status
* LEDs for visual indicators
* PWM buzzer for audio feedback
---

# High-Level Design

The main game loop performs the following operations:
1. Randomly selects a target equation
2. Displays the target number on the LCD using the I2C protocol
3. Accepts user input from the keypad
4. Evaluates the equation
5. Provides visual/audio feedback
6. Stores previous attempts
7. Allows navigation through previous guesses using the rotary encoder
8. Resets after a win or loss

---

# Embedded Systems Concepts Used

This project integrates several important embedded systems concepts:
* GPIO interfacing
* Interrupt-driven programming
* PWM signal generation
* I2C communication protocol
* Matrix keypad scanning
* LCD interfacing
* Real-time user interaction
* Memory management in embedded C
* State-machine style game logic

---
# Acknowledgements

Special thanks to Professor Harris for guidance and support throughout the development of this project.

---
