#include "robot.h"

// instantiate static members
std::shared_ptr<Drivetrain> Robot::drive;

void Robot::RobotInit(){
	// instantiate static variables
	drive.reset(new Drivetrain());
}

void Robot::TeleopPeriodic(){
	// run io each loop
	io.Run();
}


// macro to set up the main and such
START_ROBOT_CLASS(Robot)
