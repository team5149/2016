#include "drivetrain.h"
#include "../utils/constants.h"

Drivetrain::Drivetrain():
	tal_left_a {Constants::LEFT_DRIVE_PWM_A},
	tal_left_b {Constants::LEFT_DRIVE_PWM_B}, 
	tal_right_a {Constants::RIGHT_DRIVE_PWM_A}, 
	tal_right_b {Constants::RIGHT_DRIVE_PWM_B}
{
 
	// Are we going to use the Talon safety features?
	// tal_controller.SetSafetyEnabled(true)?
	// TODO: find out if setting the motor safety matters
	
}

// Set left and right drive output power on scale -1 to 1
// Caller responsibility to ensure that left_pwr and right_pwr are in between -1 and 1.
void Drivetrain::setPower(float left_pwr, float right_pwr) {
	tal_left_a.Set(left_pwr);
	tal_left_b.Set(left_pwr);
	tal_right_a.Set(right_pwr);
	tal_right_b.Set(right_pwr);
}

Drivetrain::~Drivetrain(){}
