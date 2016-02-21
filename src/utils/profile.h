#ifndef MOTION_PROFILE_H
#define MOTION_PROFILE_H

#include "WPILib.h"

class MotionProfile {
public:

	// this class allows an open loop motor to go into a hard stop or limit switch softly
	// it makes motor power a function of time, assumes initial power is zero
	MotionProfile(float max_accel, float time_goal, float max_deccel = -1, float end_power = 0);

	// starts the motion profile, sets up the timing
	void start();

	// stops the motion profile, resets the internal timer
	void stop();

	// gets the next step on the profile
	float getNext();

	bool isRunning();

protected:

	Timer timer;
	float max_accel, max_deccel, time_goal, end_power;

	bool running;

};

#endif
