#ifndef ARM_H
#define ARM_H

#include "WPILib.h"
#include <list>

class Hand {
public:
	Hand();

	static constexpr bool HAND_CLOSED {false};
	static constexpr bool HAND_OPEN {true};

	void setMotor(float power);

	void grab();
	void release();

	void updateSwitch();

	bool atTop();

private:
	std::shared_ptr<Talon> tal_a;
	std::shared_ptr<DoubleSolenoid> gripper;

	std::shared_ptr<DigitalInput> limit_a;

	// filter for debouncing in input
	std::list<bool> stateQueue;
	int count;
	

};

#endif
