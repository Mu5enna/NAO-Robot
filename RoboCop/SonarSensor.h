/*!
* @file SonarSensor.h
* @author Mustafa Eren NAKAS
* @date 29.12.2023
* @brief BumperSensor class header file
*
* SonarSensor class supposed to do operations using sensors on the robot
*/

#pragma once
#include "NaoRobotAPI.h"
#include <vector>
#include "SensorInterface.h"
#include "NaoRobotSensorInterface.h"

class SonarSensor :public NaoRobotSensorInterface {
private:
	double ranges[2];
public:
	//! constructor 
	SonarSensor(NaoRobotAPI* robotApi) :ranges() { this->robotApi = robotApi; };
	//! return range for selected sensor
	double getRange(int index);
	//! return max range and update index
	double getMax(int& index);
	//! return max range and update index
	double getMin(int& index);
	//! updates range data for sensors
	void updateSensor() override;
	//! returns sensor name
	string getSensorType() override { return "Sonar"; };
	//! returns sensor values as a string
	string getSensorValue() override;
};