#include "mbed.h"
#include "crazyflie.h"
#include "parameters.h"

PwmOut motor(MOTOR4);

// função para converter velocidade angular em duty cycle do PWM
float control_motor(float omega)
{
    return a2*omega*omega + a1*omega; // função obtida experimentalmente 
}

int main()
{
    motor.period(1.0/500.0); // frequencia do motor
    motor = control_motor(2500.0);
    //motor = 0.1;
    wait(5);
    motor = 0.0;
}