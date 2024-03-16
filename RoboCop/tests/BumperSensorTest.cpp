/**
* @author Mustafa Eren NAKAS
* @date 30.12.2023
* @brief bumperSensor test class
*
* this is the file to test if the bumper sensor class works properly and if there is a collision
*/

#include "NaoRobotAPI.h"
#include "BumperSensor.h"
#include <iostream>

using namespace std;

NaoRobotAPI* nao;
BumperSensor* bumperSensor;

int main(void) {
	//! create a NaoRobotAPI object and a ForceSensor object
	nao = new NaoRobotAPI();
	BumperSensor* bumperSensor = new BumperSensor(nao);

	//! connect to the robot
	nao->connect();

	//! give some time to connect
	Sleep(1000);

	bumperSensor->updateSensor();
	cout << "Bumper sensor states: " << bumperSensor->getState(0) << " " << bumperSensor->getState(1) 
		 << " " << bumperSensor->getState(2) << " " << bumperSensor->getState(3) << endl;
	(bumperSensor->checkTouch())? cout << "There is a collision" << endl : cout << "There isn't any collision" << endl;

	while (1) {
		bumperSensor->updateSensor();
		nao->moveRobot(FORWARD);
		if (bumperSensor->checkTouch()) {
			cout << "There was a collision" << endl;
			break;
		}
	}

	//! disconnect from the robot
	nao->disconnect();
}
