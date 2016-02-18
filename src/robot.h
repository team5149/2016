#ifndef ROBOT_H
#define ROBOT_H

#include "WPILib.h"

#include "subsystems/drivetrain.h"
//#include "subsystems/hand.h"
//#include "subsystems/shooter.h"

#include "IO.h"

// This is the main robot class
class Robot : public SampleRobot {
public:
	void RobotInit();

	void Autonomous();
	void OperatorControl();

	// Declare subsystems static for use in multiple places
	static std::shared_ptr<Drivetrain> drive;
	//static std::shared_ptr<Hand> hand;
	//static std::shared_ptr<Shooter> shooter;

private:

	IO io;
};

#endif
