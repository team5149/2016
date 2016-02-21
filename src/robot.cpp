#include "robot.h"

// instantiate static members
std::shared_ptr<Drivetrain> Robot::drive;
std::shared_ptr<Hand> Robot::hand;
std::shared_ptr<Shooter> Robot::shooter;

void Robot::RobotInit()
{
	drive.reset(new Drivetrain());
	hand.reset(new Hand());
	shooter.reset(new Shooter());
	printf("starting!\n");
}

void Robot::OperatorControl() {

	printf("into op control\n");
	// loop while the robot is running and drive control
	while(IsEnabled() && IsOperatorControl()){
		// only run when we get a new packet
		io.Run();

		// don't burn cpu
		Wait(0.001);
	}

	printf("out of op control\n");
}


void Robot::Autonomous() {
	while(IsEnabled() && IsAutonomous()){
		// TODO: put something here
		Wait(0.001);
	}
}

// macro to set up the main and such
START_ROBOT_CLASS(Robot)
