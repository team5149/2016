#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "WPILib.h"
namespace Constants {
	
	// IO
	constexpr uint32_t DRIVER_JOYSTICK {0};
	constexpr uint32_t MANIP_JOYSTICK {1};


	// DRIVE
	constexpr uint32_t RIGHT_DRIVE_PWM_A {0};
	constexpr uint32_t RIGHT_DRIVE_PWM_B {1};
	constexpr uint32_t LEFT_DRIVE_PWM_A {2};
	constexpr uint32_t LEFT_DRIVE_PWM_B {3};


	// SHOOTER
	constexpr uint32_t SHOOTER_FIRE_SOLENOID_A {0};
	constexpr uint32_t SHOOTER_RETRACT_SOLENOID_A {1};

	constexpr uint32_t SHOOTER_FIRE_SOLENOID_B {2};

	constexpr uint32_t SHOOTER_RAISE_SOLENOID {5};
	constexpr uint32_t SHOOTER_LOWER_SOLENOID {6};


	// HAND
	constexpr uint32_t HAND_MOTOR_A {4};

	constexpr uint32_t HAND_GRAB_SOLENOID_A {3};
	constexpr uint32_t HAND_RELEASE_SOLENOID_A {4};

	constexpr uint32_t LIMIT_SWITCH_HIGH {0};

	constexpr int LIMIT_SWITCH_HIGH_DEBOUNCE_COUNT {10};
}

#endif // constants
