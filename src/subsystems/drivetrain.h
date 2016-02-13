#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "WPILib.h"

class Drivetrain {
public:
	Drivetrain();
	~Drivetrain();

	// set left and right drive output power on scale -1 to 1
	void setPower(float left, float right);
private:

	std::shared_ptr<Talon> tal_left_a, tal_left_b,
		tal_right_a, tal_right_b;	
};

#endif
