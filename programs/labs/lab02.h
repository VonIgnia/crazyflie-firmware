#include "mbed.h"
#include "crazyflie.h"

PwmOut motor4(MOTOR4);

// função para converter velocidade angular em duty cycle do PWM
float control_motor(float omega)
{
    return a2*omega*omega + a1*omega; // função obtida experimentalmente 
}

int main()
{
    motor4.period(1.0/500.0); // frequencia do motor
    motor4 = control_motor(1000.0);
    wait(0.5);
    motor4 = 0.0;
}