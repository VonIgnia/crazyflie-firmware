#include "horizontal_estimator.h"

// Class constructor
HorizontalEstimator ::HorizontalEstimator() : flow(PA_7, PA_6, PA_5, PB_4) {
  x, y, u, v = 0;
}

// Initialize class
void HorizontalEstimator::init() { flow.init(); }

// Predict horizontal positions and velocities from model
void HorizontalEstimator::predict(float phi, float theta) {

  x += u * dt;
  y += v * dt;
  u += g * theta * dt;
  v -= g * phi * dt;

}

// Correct horizontal velocities with measurements
void HorizontalEstimator::correct(float phi, float theta, float p, float q, float z) {
  
  float div = cos(phi) * cos(theta);
  if (div > 0.5) {
    flow.read();
    float d = z / div;
    float u_m = (sigma * flow.px + q) * d;
    float v_m = (sigma * flow.py - p) * d;
    u += l_eh * dt * (u_m - u);
    v += l_eh * dt * (v_m - v);
  }
  
}