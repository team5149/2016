#include "hand.h"
#include "../utils/constants.h"

Hand::Hand(){
	tal_a.reset(new Talon {Constants::HAND_MOTOR_A});
	gripper.reset(new DoubleSolenoid {Constants::HAND_GRAB_SOLENOID_A, Constants::HAND_RELEASE_SOLENOID_A});

	limit_a.reset(new DigitalInput { Constants::LIMIT_SWITCH_HIGH });

	count = 0;

	printf("starting hand\n");
}

void Hand::grab(){
	gripper->Set(DoubleSolenoid::Value::kReverse);
}

void Hand::release(){
	gripper->Set(DoubleSolenoid::Value::kForward);
}

void Hand::setMotor(float power) {
	tal_a->Set(power);
}

void Hand::updateSwitch() {
	stateQueue.push_front(limit_a->Get());
	if(stateQueue.front()) { count++; }

	if(stateQueue.size() > Constants::LIMIT_SWITCH_HIGH_DEBOUNCE_COUNT) {
		if(stateQueue.back()) { count--; }
		stateQueue.pop_back();
	}
}

