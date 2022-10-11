#ifndef parameters_h
#define parameters_h

#include <cmath>

// Physical constants
const float pi = 3.1416;
const float g = 9.81;       // m/s^2

// constantes PWM = a2omega^2 + a1omega
const float a2 = 1.203e-07; // lab02
const float a1 = 2.516e-14; // lab02

const float kl = 1.607e-08; // constante de sustentação (lab03) -- roll (rolagem)
const float kd = 1.309e-10; // constante de arrasto (lab04) -- yaw (guinagem)

// Quadcopter dimensions
const float m = 30.0e-3;    // kg
const float I_xx = 16.0e-6; // kg.m^2
const float I_yy = 16.0e-6; // kg.m^2
const float I_zz = 29.0e-6; // kg.m^2 
const float l = 33.0e-3;    // m

const float dt = 0.002; // 2ms = 500Hz

#endif