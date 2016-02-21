#include "IO.h"
#include "utils/constants.h"
#include "robot.h"
#include <cassert>

IO::IO(){
	driver_stick.reset(new Joystick{Constants::DRIVER_JOYSTICK});
	manip_stick.reset(new Joystick{Constants::MANIP_JOYSTICK});

	printf("stick has %d axis\n", driver_stick->GetAxisCount());

}

void IO::Run() {

	// DRIVE 
	const float left_power {driver_stick->GetY()};
	const float right_power {driver_stick->GetX()};

	Robot::drive->setPower(left_power, right_power);


	// ARM 
	const float arm_power { manip_stick->GetY() };
	if(fabs(arm_power) > 0.2){
		Robot::hand->setMotor(arm_power);
	}

	const bool grip { manip_stick->GetRawButton(4) };
	if(grip) { Robot::hand->grab(); }
	else { Robot::hand->release(); }	


	// SHOOTER 
	const bool shoot { manip_stick->GetRawButton(3) };
	if(shoot) { Robot::shooter->fire(); }
	else { Robot::shooter->retract(); }

	const bool arm_up { manip_stick->GetRawButton(2) };
	if(arm_up) { Robot::shooter->up(); }
	else { Robot::shooter->down(); }

}
