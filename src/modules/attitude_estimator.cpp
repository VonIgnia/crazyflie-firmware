#include "attitude_estimator.h"
// Class constructor
AttitudeEstimator ::AttitudeEstimator() : imu(IMU_SDA, IMU_SCL) {
  phi = 0;
  theta = 0;
  psi = 0;
  p = 0;
  q = 0;
  r = 0;
}

// Initialize class
void AttitudeEstimator ::init() {
    imu.init();
    
    float soma_x;
    float soma_y;
    float soma_z;

    for(int i=1; i<=500;i++){
        if (i!=500){
        imu.read();
        soma_x += imu.gx;
        soma_y += imu.gy;
        soma_z += imu.gz;
        }
        else{
        p_bias = soma_x/500;
        q_bias = soma_y/500;
        r_bias = soma_z/500;
        }
        wait(dt);
    }
}

// Estimate Euler angles (rad ) and angular velocities ( rad /s)
void AttitudeEstimator ::estimate() {
  imu.read();
  p =  imu.gx - p_bias;
  q =  imu.gy - q_bias;
  r =  imu.gz - r_bias;

  
  //Código comentado de acordo com a etapa 5
  float phi_a = atan2(-imu.ay,-imu.az);
  float theta_a = atan2(imu.ax,-((imu.az>0)-(imu.az<0))*sqrt(imu.ay*imu.ay+imu.az*imu.az));
  

  float phi_g = phi + (p + sin(phi)*tan(theta)*q + cos(phi)*tan(theta)*r) * dt;
  float theta_g = theta + (cos(phi)*q-sin(phi)*r)*dt;
  float psi_g = psi +(sin(phi)/cos(theta)*q+cos(phi)/cos(theta)*r)*dt;


  phi =  (1-alpha)*phi_g + alpha*phi_a;
  theta =  (1-alpha)*theta_g + alpha*theta_a;
  psi =  psi_g;

  
}