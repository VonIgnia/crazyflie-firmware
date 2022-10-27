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

const float dt = 0.002; // 2ms = 500Hz (lab07)
const float wc = 1; // frequencia de corte do filtro passa baixa em rad/s (lab 07)
const float alpha = (wc*dt)/(1+wc*dt); // fator de suavização


// Controlador de atitude
const float Ts_phi = 0.3;   // tempo de acomodação
const float UP_phi = 0.005; // ultrapassagem percentual
const float zeta_phi = abs(log(UP_phi))/sqrt((log(UP_phi)*log(UP_phi)) + pi*pi);  // fator de amortecimento
const float wn_phi = 4/(zeta_phi*Ts_phi);   // frequência angular
const float kp_phi = wn_phi*wn_phi; // ganho kp
const float kd_phi = 2*zeta_phi*wn_phi;  // ganho kd

/*
const float Ts_theta = 0.3;   // tempo de acomodação
const float UP_theta = 0.005; // ultrapassagem percentual
const float zeta_theta = abs(log(UP_theta))/sqrt((log(UP_theta)*log(UP_theta)) + pi*pi);  // fator de amortecimento
const float wn_theta = 4/(zeta_theta*Ts_theta);   // frequência angular
const float kp_theta = wn_theta*wn_theta; // ganho kp
const float kd_theta = 2*zeta_theta*wn_theta;  // ganho kd
*/
const float kp_theta = kp_phi; // ganho kp
const float kd_theta = kd_phi;  // ganho kd

const float Ts_psi= 0.7;   // tempo de acomodação
const float UP_psi = 0.008; // ultrapassagem percentual
const float zeta_psi = abs(log(UP_phi))/sqrt((log(UP_phi)*log(UP_phi)) + pi*pi);  // fator de amortecimento
const float wn_psi = 4/(zeta_phi*Ts_phi);   // frequência angular
const float kp_psi = wn_phi*wn_phi; // ganho kp
const float kd_psi = 2*zeta_phi*wn_phi;  // ganho kd

// estimador vertical
const float dt_range = 0.05;// 50 ms
const float wc_ve = 10.0;// frequencia de corte do estimador vertical
const float l_ve = wc_ve;//Ganho do Estimador vertical
const float zeta_ve = sqrt(2.0)/2.0;
const float l_1 = wc_ve*wc_ve;
const float l_2 = 2.0*zeta_ve*wc_ve;

#endif