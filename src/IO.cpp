#include "IO.h"
#include "utils/constants.h"
#include "robot.h"
#include <cassert>

IO::IO(){
	driver_stick.reset(new Joystick{Constants::DRIVER_JOYSTICK});
	//manip_stick.reset(new Joystick{Constants::MANIP_JOYSTICK});


}

void IO::Run() {
	const float left_power {driver_stick->GetY()};
	const float right_power {driver_stick->GetTwist()};
	
	// Define NDEBUG to get rid of these checks.
	// I only included them as the documentation offered no
	// information on the range of values JoyStick::GetY() can return.
	assert(left_power >= -1.0);
	assert(left_power <= 1.0);

	assert(right_power >= -1.0);
	assert(right_power <= 1.0);

	Robot::drive->setPower(left_power, right_power);


	// TODO: arm control
	
	
	// TODO: shooter control
}
