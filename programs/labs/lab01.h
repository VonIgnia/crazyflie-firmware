#include "mbed.h"
#include "crazyflie.h"

// Define all LEDs as digital output objects
DigitalOut led_azulL(LED_BLUE_L,!false);
DigitalOut led_verdeL(LED_GREEN_L,!false);
DigitalOut led_verdeR(LED_GREEN_R,!false);
DigitalOut led_vermL(LED_RED_L,!false);
DigitalOut led_vermR(LED_RED_R,!false);

// Define all motors as PWM objects
PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);

// Main program
int main()
{
    // Blink blue LED indicating inicialization (5 seconds)
    led_azulL = !led_azulL;
    wait(5);

    // Turn on red LEDs indicating motors are armed
    led_vermL = !led_vermL;
    led_vermR = !led_vermR;

    // Test all motors with different frequencies (to make different noises)
    motor1.period(0.5/264.0);
    motor2.period(1.0/264.0);
    motor3.period(2.0/264.0);
    motor4.period(4.0/264.0);
    while(1){
        motor1 = 0.1;
        wait(0.1);
        motor1 = 0.0;

        motor2 = 0.1;
        wait(0.1);
        motor2 = 0.0;

        motor3 = 0.1;
        wait(0.1);
        motor3 = 0.0;

        motor4 = 0.1;
        wait(0.1);
        motor4 = 0.0;

        wait(3);
    }

    // Turn off red LEDs indicating motors are disarmed
    led_vermL = !led_vermL;
    led_vermR = !led_vermR;

    wait(3);

    // Blink green LEDs indicating end of program
    led_verdeL = !led_verdeL;
    led_verdeR = !led_verdeR;
    /*
    while(true)
    {
        
    }
    */
}
