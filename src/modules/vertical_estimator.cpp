#include "vertical_estimator.h"

// Class constructor
VerticalEstimator ::VerticalEstimator() : range(E_SDA, E_SCL) {
  z = 0;
  w = 0; //(Velocidade linear de subida)
}

// Initialize class
void VerticalEstimator ::init() { range.init(); }

// Predict vertical position and velocity from model
void VerticalEstimator ::predict(float f_t) {
  // observador ordem 1
  // z = z;

  // observador ordem 2
  // z = z + w * dt;
  /// w = w;

  // observador ordem 2 com entrada 
  z += w*dt;
  if (z > 0.05)
  {
    w += (-g + (1/m)*f_t)*dt;
  }
}

// Correct vertical position and velocity with measurement
void VerticalEstimator ::correct(float phi, float theta) {
  range.read();
  if (range.d < 4.0) {
    // observador ordem 1
    // float z_m = range.d*cos(phi)*cos(theta);
    // z += l_ve*dt_range*(z_m-z);

    // observador ordem 2 sem entrada
    // float z_m = range.d * cos(phi) * cos(theta);
    // w += l_1 * dt_range * (z_m - z);
    // z += l_2 * dt_range * (z_m - z);

    // observador ordem 2 com entrada
    float z_m = range.d * cos(phi) * cos(theta);
    w += l_1*dt_range*(z_m - z);
    z += l_2*dt_range*(z_m - z);
  }
}