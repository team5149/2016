#include "IO.h"
#include "utils/constants.h"
#include "robot.h"
#include <cassert>

IO::IO() {
	r_stick.reset(new Joystick(Constants::RIGHT_JOYSTICK));
	l_stick.reset(new Joystick(Constants::LEFT_JOYSTICK));
}

void IO::Run() {
	const float left_power {l_stick->GetY()};
	const float right_power {r_stick->GetY()};
	
	// Define NDEBUG to get rid of these checks.
	// I only included them as the documentation offered no
	// information on the range of values JoyStick::GetY() can return.
	assert(left_power >= -1.0);
	assert(left_power <= 1.0);

	assert(right_power >= -1.0);
	assert(right_power <= 1.0);

	Robot::drive->setPower(left_power, right_power);
}
