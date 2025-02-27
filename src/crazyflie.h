#ifndef crazyflie_h
#define crazyflie_h

// Crazyflie utility variables
#include "utils/pin_names.h"
#include "utils/parameters.h"

// Crazyflie 2.0 hardware abstraction layer
// #include "drivers/mpu9250.h"    // IMU sensor

// Flow deck hardware abstraction layer
// #include "drivers/vl53l0x.h"    // Range sensor
// #include "drivers/pmw3901.h"    // Optical flow sensor

// Crazyflie 2.1 hardware abstraction layer
#include "drivers/bmi088.h"     // IMU sensor

// Flow deck v2 hardware abstraction layer
#include "drivers/vl53l1x.h"    // Range sensor
#include "drivers/pmw3901.h"    // Optical flow sensor

//Incluindo a classe do mixer
#include "modules/mixer.h"

//Incluindo a classe estimadora de atitude
#include "modules/attitude_estimator.h"

//Incluindo a classe contrladora de atitude
#include "modules/attitude_controller.h"

//Incluindo a classe do estimador vertical
#include "modules/vertical_estimator.h"

//Incluindo a classe do controlador vertical
#include "modules/vertical_controller.h"

//Incluindo a classe do estimador horizontal
#include "modules/horizontal_estimator.h"

//Incluindo a classe do controlador horizontal
#include "modules/horizontal_controller.h"
#endif