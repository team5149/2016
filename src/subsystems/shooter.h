#ifndef SHOOTER_H
#define SHOOTER_H

#include "WPILib.h"

class Shooter {
public:
	Shooter();

	void setState(bool state);

	const static bool FIRE = true;
	const static bool RETRACT = false; 

private:
	std::shared_ptr<Solenoid> sol_a, sol_b;
};

#endif
