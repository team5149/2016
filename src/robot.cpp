#include "robot.h"

// instantiate static members
Drivetrain Robot::drive;
Arm Robot::arm;
Shooter Robot::shooter;

void Robot::RobotInit() {}

void Robot::OperatorControl(){

	// loop while the robot is running and drive control
	while(IsEnabled() && IsOperatorControl()){
		// only run when we get a new packet
		if(IsNewDataAvailable()){
			io.Run();
		}

		// don't burn cpu
		Wait(0.001);
	}
}


void Robot::Autonomous(){
	while(IsEnabled() && IsAutonomous()){
		// TODO: put something here
		Wait(0.001);
	}
}

// macro to set up the main and such
START_ROBOT_CLASS(Robot)
