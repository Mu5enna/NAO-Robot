/*!
* @author Mustafa Eren NAKAS
* @date 08.01.2024
* @brief Performs the functions of menu functions
*
* MenuFunctionality class supposed to perform functions of menus
*/

#pragma once
#include <string>
#include "Record.h"
#include "NaoRobotAPI.h"
#include "MenuOutput.h"
#include "RobotControl.h"
#include "SonarSensor.h"
#include "ForceSensor.h"
#include "BumperSensor.h"
#include "RobotOperator.h"

class MenuFunctionality {
private:
	MenuOutput menuOutput;
	NaoRobotAPI* robotApi;
	Record* record;
	RobotOperator& robotOperator = RobotOperator::getInstance();
	RobotControl robotControl;
	SonarSensor* sonarSensor = new SonarSensor(robotApi);
	ForceSensor* forceSensor = new ForceSensor(robotApi);
	BumperSensor* bumperSensor = new BumperSensor(robotApi);
public:
	//! to perform main menu functions
	void mainMenu(string strslc);
	//! to perform user menu functions
	void userMenu(string strslc);
	//! to perform connection menu functions
	void connectionMenu(string strslc);
	//! to perform sensor menu functions
	void sensorMenu(string strslc);
	void recordSensorMenu(string strslc);
	//! to perform sensor adding menu functions
	void sensorAddMenu(string slc);
	void pathMenu(string strslc);
	//! to perform motion menu functions
	void motionMenu(string strslc);
	//! to check if given entry valid
	bool isValid(string& strslc);
};

