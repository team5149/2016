#include "hand.h"
#include "../utils/constants.h"

Hand::Hand(){
	tal_a.reset(new Talon {Constants::HAND_MOTOR_A});
	sol_a.reset(new Solenoid {Constants::HAND_SOLENOID_A});
}

void Hand::setState(bool state) {
	sol_a->Set(state);
}
