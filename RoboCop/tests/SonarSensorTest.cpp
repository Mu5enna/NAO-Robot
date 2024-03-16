/**
* @author Mustafa Eren NAKAS
* @date 30.12.2023
* @brief sonarSensor class test file
*
* this is the test file for sonarSensor class it tests if class takes the values correctly and return max and min values
*/

#include "NaoRobotAPI.h"
#include "SonarSensor.h"
#include <iostream>

using namespace std;

NaoRobotAPI* nao;
SonarSensor* sonarSensor;

int main() {
	//! create a NaoRobotAPI object and a SonarSensor object
	nao = new NaoRobotAPI();
	SonarSensor* sonarSensor = new SonarSensor(nao);

	//! connect to the robot
	nao->connect();

	//! give some time to connect
	Sleep(1000);

	//! update the sonar sensor and print the value
	sonarSensor->updateSensor();
	cout << "Sensor value before moving: " << sonarSensor->getRange(0) << " " << sonarSensor->getRange(1) << endl;
	int index{};
	cout << "Max value: " << sonarSensor->getMax(index) << " index: " << index << endl;
	cout << "Min value: " << sonarSensor->getMin(index) << " index: " << index << endl;

	Sleep(1000);

	//! move the robot and print the value
	nao->turnRobot(LEFT);
	Sleep(5000);
	sonarSensor->updateSensor();
	cout << "Sensor value after moving: " << sonarSensor->getRange(0) << " " << sonarSensor->getRange(1) << endl;
	cout << "Max value: " << sonarSensor->getMax(index) << " index: " << index << endl;
	cout << "Min value: " << sonarSensor->getMin(index) << " index: " << index << endl;

	nao->turnRobot(LEFT);
	Sleep(5000);
	sonarSensor->updateSensor();
	cout << "Sensor value after moving: " << sonarSensor->getRange(0) << " " << sonarSensor->getRange(1) << endl;
	cout << "Max value: " << sonarSensor->getMax(index) << " index: " << index << endl;
	cout << "Min value: " << sonarSensor->getMin(index) << " index: " << index << endl;

	//! disconnect from the robot
	nao->disconnect();
	
	
}