#ifndef ROBOT_H
#define ROBOT_H

#include "WPILib.h"

class Robot : public SampleRobot {
public:
	Robot();
	void RobotInit();
	void Disabled();
	void OperatorControl();
	/*
	void Autonomous(){};
	void OperatorControl(){};
	void Test(){};
	void RobotMain(){};
	*/
private:
	RobotDrive drive;
	Joystick stick;
};
#endif
