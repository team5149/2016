#include "robot.h"

// instantiate static members
std::shared_ptr<Drivetrain> Robot::drive;
//std::shared_ptr<Hand> Robot::hand { new Hand{} };
//std::shared_ptr<Shooter> Robot::shooter { new Shooter{} };

void Robot::RobotInit()
{
	drive.reset(new Drivetrain());
}

void Robot::OperatorControl() {

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


void Robot::Autonomous() {
	while(IsEnabled() && IsAutonomous()){
		// TODO: put something here
		Wait(0.001);
	}
}

// macro to set up the main and such
START_ROBOT_CLASS(Robot)
