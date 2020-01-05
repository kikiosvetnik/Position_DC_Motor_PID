# Position_DC_Motor_PID
 This my code example for PID controller for DC motors with incremental encoder on shaft of motor.\n
 Example is written in MBED online compiler in C++, using Nucleo Board with STM32F411RE microcontroller.
 It demonstrates how to use PID controller to rotate a DC motor in certain position.
 It uses incremental encoder as input so it can calculate position of shaft.
 For this example I used 1 PWM(for DC motor speed control), 1 InterruptIn(for encoder counting)
 and 2 DigitalIn pins(1 for DC motor direction contol, and 1 for second channel of encoder)
 I also used Ticker class in MBED compiler, its actually a timer interrupt which occurs at certain time.

