/*!
* @author Mustafa Eren NAKAS
* @date 06.01.2024
* @brief updates and check if any bumper sensor activated
*
* BumperSensor class supposed to check if any of the bumper sensors are activated or not and update them
*/

#pragma once
#include "NaoRobotAPI.h"
#include "SensorInterface.h"
#include "NaoRobotSensorInterface.h"

class BumperSensor : public NaoRobotSensorInterface {
private:
	bool states[4];
public:
	//! constructor 
	BumperSensor(NaoRobotAPI* robotApi) :states() { this->robotApi = robotApi; };
	//! Updates bumper sensor status
	void updateSensor() override;
	//! Gets selected sensor's state and returns if it's true or not
	bool getState(int index);
	//! Checks if any bumper sensor's statue changed
	bool checkTouch();
	//! Returns sensor type as a string
	string getSensorType() override { return "Bumper"; };
	//! Returns sensor states as string
	string getSensorValue() override;
};