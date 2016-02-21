#ifndef SHOOTER_H
#define SHOOTER_H

#include "WPILib.h"

class Shooter {
public:
	Shooter();

	void setState(bool state);

	// controlling actual shooter 
	void fire();
	void retract();

	// controlling angle pos
	void up();
	void down();


private:
	std::shared_ptr<DoubleSolenoid> fire_double;
	std::shared_ptr<Solenoid> fire_single;

	std::shared_ptr<DoubleSolenoid> pos_sol;
};

#endif
