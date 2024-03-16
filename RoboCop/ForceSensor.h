/**
* @author Serhat Aydin
* @date 07.01.2024
* @brief get force sensor data from Nao robot and check if the robot is fallen
*
* This class is used to get force sensor data from Nao robot and check if the robot is fallen.
*/

#pragma once
#include "NaoRobotAPI.h"
#include "SensorInterface.h"
#include "NaoRobotSensorInterface.h"

class ForceSensor : public NaoRobotSensorInterface {
private:
	//! Force sensor data
	double force;
public:
	//! constructor 
	ForceSensor(NaoRobotAPI* robotApi) :force(NULL) { this->robotApi = robotApi; };
	//! function to update the force sensor variable
	void updateSensor(void) override;
	//! function to return the force sensor variable
	double getForce();
	//! function to check if the robot is fallen
	bool checkFall();
	//! returns sensor type as a string
	string getSensorType() override { return "Force"; };
	//! returns force sensor value as string
	string getSensorValue() override;
};