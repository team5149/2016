#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "WPILib.h"
class Constants {
public:

	static const uint32_t RIGHT_JOYSTICK = 0;
	static const uint32_t LEFT_JOYSTICK = 1;

	static const uint32_t RIGHT_DRIVE_PWM_A = 0;
	static const uint32_t RIGHT_DRIVE_PWM_B = 1;
	static const uint32_t LEFT_DRIVE_PWM_A = 2;
	static const uint32_t LEFT_DRIVE_PWM_B = 3;

	static const uint32_t SHOOTER_SOLENOID_A = 0;
	static const uint32_t SHOOTER_SOLENOID_B = 1;

	static const uint32_t HAND_MOTOR_A = 4;

};

#endif // constants
