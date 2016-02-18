#ifndef ARM_H
#define ARM_H

#include "WPILib.h"

class Hand {
public:
	Hand();

	static constexpr bool HAND_CLOSED {false};
	static constexpr bool HAND_OPEN {true};

	void setState(bool state);

private:
	std::shared_ptr<Talon> tal_a;
	std::shared_ptr<Solenoid> sol_a;
};

#endif
