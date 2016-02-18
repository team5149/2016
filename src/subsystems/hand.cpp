#include "hand.h"
#include "../utils/constants.h"

Hand::Hand() : 
	tal_a {new Talon {Constants::HAND_MOTOR_A}},
	sol_a {new Solenoid {Constants::HAND_SOLENOID_A}} {}

void Hand::setState(bool state) {
	sol_a->Set(state);
}
