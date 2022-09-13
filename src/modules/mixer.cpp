#include "mixer.h"

// Class constructor
Mixer::Mixer()
    : motor_1(MOTOR1), motor_2(MOTOR2), motor_3(MOTOR3), motor_4(MOTOR4) {
  motor_1.period(1.0 / 500.0);
  motor_2.period(1.0 / 500.0);
  motor_3.period(1.0 / 500.0);
  motor_4.period(1.0 / 500.0);
  motor_1 = 0.0;
  motor_2 = 0.0;
  motor_3 = 0.0;
  motor_4 = 0.0;
}

// Actuate motors with desired total trust force (N) and torques (N.m)
void Mixer::actuate(float f_t, float tau_phi, float tau_theta, float tau_psi) {
  if (armed){
  mixer(f_t, tau_phi, tau_theta, tau_psi);
  motor_1 = control_motor(omega_1);
  motor_2 = control_motor(omega_2);
  motor_3 = control_motor(omega_3);
  motor_4 = control_motor(omega_4);
  }
}

// Convert total trust force (N) and torques (N.m) to angular velocities ( rad
// /s)
void Mixer ::mixer(float f_t, float tau_phi, float tau_theta, float tau_psi) {
  float a = 0.25 / (kl), b = 0.25 / (kl * l), c = 0.25 / (kd);
  float omegas2[4];

  omegas2[0] = a * f_t - b * tau_phi - b * tau_theta - c * tau_psi;
  omegas2[1] = a * f_t - b * tau_phi + b * tau_theta + c * tau_psi;
  omegas2[2] = a * f_t + b * tau_phi + b * tau_theta - c * tau_psi;
  omegas2[3] = a * f_t + b * tau_phi - b * tau_theta + c * tau_psi;

  float omegas[4];

  for (int i = 0; i < 4; i++) {
    omegas[i] =
        (omegas2[i] < 0) ? 0 : sqrt(omegas2[i]); // se for negativo, não rodar
  }

  omega_1 = omegas[0];
  omega_2 = omegas[1];
  omega_3 = omegas[2];
  omega_4 = omegas[3];
}

// Convert desired angular velocity ( rad /s) to PWM signal (%)
float Mixer ::control_motor(float omega) {
  return a2 * omega * omega + a1 * omega; // função obtida experimentalmente
}

void Mixer ::arm() { 
    armed = true; 
}

void Mixer ::disarm() { 
    actuate(0, 0, 0, 0);
    armed = false; 
}
