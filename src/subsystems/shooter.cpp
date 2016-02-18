#include "shooter.h"
#include "../utils/constants.h"

Shooter::Shooter(): 
	sol_a {Constants::SHOOTER_SOLENOID_A}, 
	sol_b {Constants::SHOOTER_SOLENOID_B} {}

void Shooter::setState(bool state){
	sol_a.Set(state);
	sol_b.Set(state);
}
