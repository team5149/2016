#include "robot.h"


Robot::Robot() : drive(0,1), stick(0){
	
}
void Robot::RobotInit(){
	printf("hello world!\n");
}

void Robot::Disabled(){
	printf("FROM US!!!\n");
	drive.SetExpiration(0.1);
}

void Robot::OperatorControl(){
	while(IsOperatorControl() && IsEnabled()){
		Wait(0.005);
		drive.ArcadeDrive(stick); 	
	}

}

// macro to set up the main and such
START_ROBOT_CLASS(Robot)
