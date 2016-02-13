#include "drivetrain.h"
#include "../utils/constants.h"

Drivetrain::Drivetrain() { 
	tal_left_a.reset(new Talon(Constants::LEFT_DRIVE_PWM_A));
	tal_left_b.reset(new Talon(Constants::LEFT_DRIVE_PWM_B)); 
	tal_right_a.reset(new Talon(Constants::RIGHT_DRIVE_PWM_A)); 
	tal_right_b.reset(new Talon(Constants::RIGHT_DRIVE_PWM_B));
	
}

void Drivetrain::setPower(float left_pwr, float right_pwr){
	// TODO set the output power
}

Drivetrain::~Drivetrain(){}
