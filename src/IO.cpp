#include "IO.h"

#include "utils/constants.h"
#include "utils/functions.h"

#include "robot.h"

IO::IO(){
	driver_stick.reset(new Joystick{Constants::DRIVER_JOYSTICK});
	manip_stick.reset(new Joystick{Constants::MANIP_JOYSTICK});

	printf("stick has %d axis\n", driver_stick->GetAxisCount());

}

void IO::Run() {

	// DRIVE 
	const float left_power {driver_stick->GetY()};
	const float right_power {driver_stick->GetZ()};

	Robot::drive->setPower(
			utils::bound(utils::deadband(left_power)), 
			utils::bound(utils::deadband(right_power)));


	// ARM 
	const float arm_power { manip_stick->GetY() };
	Robot::hand->setMotor(utils::bound(utils::deadband(arm_power, 0.2)));

	const bool grip { manip_stick->GetRawButton(4) };
	if(grip) { Robot::hand->grab(); }
	else { Robot::hand->release(); }	


	// SHOOTER 
	const bool shoot { manip_stick->GetRawButton(3) };
	if(shootLatch(shoot)) {
		if(Robot::shooter->isShooting()){ Robot::shooter->retract(); }
		else { Robot::shooter->fire(); }
	}

	const bool arm_up { manip_stick->GetRawButton(2) };
	if(angleLatch(arm_up)){
		if(Robot::shooter->isUp()) { 
			printf("up\n");
			Robot::shooter->down(); 
		}
		else { 
			printf("down\n");
			Robot::shooter->up(); 
		}
	}
}
