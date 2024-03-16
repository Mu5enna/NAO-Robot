/**
* @author Serhat Aydin
* @date 08.01.2024
* @brief uses nao robot api to control the robot
*
* This class is used to control the robot using nao robot api. 
*/
#pragma once
#include "RobotInterface.h"
#include "NaoRobotAPI.h"
#include "Pose.h"
class NaoRobotInterface:public RobotInterface{
private:
	//! nao robot api
	NaoRobotAPI* robotApi;
public:
	//! constructor
	NaoRobotInterface(NaoRobotAPI* robotApi) :robotApi(robotApi) {};
	void turnLeft() override;
	void turnRight() override;
	void forward() override;
	void backward() override;
	void moveLeft() override;
	void moveRight() override;
	void stop() override;
	Pose getPose() override;
	void print() override;
};

