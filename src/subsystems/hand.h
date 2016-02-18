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
	Talon tal_a;
	Solenoid sol_a;
};

#endif
