/**
* @author Serhat Aydin
* @date 30.12.2023
* @brief forceSensor class test file
*
* this is the test file for forceSensor class it test if class takes the values correctly and if it can detect when robot is falllen
*/

#include "NaoRobotAPI.h"
#include "ForceSensor.h"
#include <iostream>

using namespace std;

NaoRobotAPI* nao;
ForceSensor* forceSensor;

int main(void) {
	//! create a NaoRobotAPI object and a ForceSensor object
	nao = new NaoRobotAPI();
	ForceSensor* forceSensor = new ForceSensor(nao);

	//! connect to the robot
	nao->connect();

	//! give some time to connect
	Sleep(1000);

	//! update the force sensor and print the value
	forceSensor->updateSensor();
	cout << "Sensor value before moving: " << forceSensor->getForce() << endl;
	(forceSensor->checkFall()) ? cout << "Robot is fallen" << endl : cout << "Robot is not fallen" << endl;

	Sleep(1000);

	//! move the robot forward to see if the sensor value changes
	nao->moveRobot(FORWARD);

	//! give some time to move and update the force sensor and print the value
	//! the values shouldn't change much if the robot is not fallen
	Sleep(1000);
	forceSensor->updateSensor();
	cout << "Sensor value whilest moving: " << forceSensor->getForce() << endl;
	(forceSensor->checkFall()) ? cout << "Robot is fallen" << endl : cout << "Robot is not fallen" << endl;

	Sleep(3000);
	forceSensor->updateSensor();
	cout << "Sensor value whilest moving: " << forceSensor->getForce() << endl;
	(forceSensor->checkFall()) ? cout << "Robot is fallen" << endl : cout << "Robot is not fallen" << endl;

	Sleep(3000);
	forceSensor->updateSensor();
	cout << "Sensor value whilest moving: " << forceSensor->getForce() << endl;
	(forceSensor->checkFall()) ? cout << "Robot is fallen" << endl : cout << "Robot is not fallen" << endl;
	
	cout << "Press enter when you make the robot fall" << endl;
	cin.get();

	//! update the force sensor and print the value
	cout << "After Falling:" << endl;
	forceSensor->updateSensor();
	cout << "Sensor value after falling: " << forceSensor->getForce() << endl;
	(forceSensor->checkFall())? cout << "Robot is fallen" << endl : cout << "Robot is not fallen" << endl;
	

	nao->disconnect();
}