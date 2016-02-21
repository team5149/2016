#include "profile.h"

MotionProfile::MotionProfile(float max_accel_, float time_goal_, float max_deccel_, float end_power_){
	max_accel = max_accel_;	
	time_goal = time_goal_; 
	if(max_deccel_ < 0.5) { max_deccel = max_accel; }
	else { max_deccel = max_deccel_; }

	end_power = end_power_;

	running = false;
}

float MotionProfile::getNext(){
	if(!isRunning()) { 
		printf("warning: motion profile not started\n");
		return 0.0;
	}

	float output = max_accel * timer.Get();

	// check if it is climbing up to max vel (1.0)
	if(output < max_accel) { return output; }

	// get the time remaining in the profile
	float time_remaining = time_goal - timer.Get();	

	// if the profile is out of time
	if(time_remaining < 0) { return end_power; }

	// if the profile is climing down
	float deccel_power = 1 - time_remaining * max_deccel;
	if(deccel_power <= end_power){ return deccel_power; }

	// else if is at the max vel
	return 1.0;
}

void MotionProfile::start() {
	running = true;

 	timer.Reset();	
	timer.Start();
}

void MotionProfile::stop() {
	running = false;
	timer.Stop();
}

bool MotionProfile::isRunning() {
	return running;
}
