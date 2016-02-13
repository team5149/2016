#include "IO.h"
#include "utils/constants.h"
#include "robot.h"

IO::IO() {
	r_stick.reset(new Joystick(Constants::RIGHT_JOYSTICK));
	l_stick.reset(new Joystick(Constants::LEFT_JOYSTICK));
}

void IO::Run(){
		
	// TODO: Drivetrain will be "tank drive", meaning each joystick
	// controls the power on one side. To do this, set the right joystick
	// y-axis to the power for the right side of the drivetrain, and do 
	// the corresponding operation for the left side. 
	
	// call the drivetrain object this way 
	// Robot::drive->setPower(left_power, right_power);
}
