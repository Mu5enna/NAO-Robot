#include "NaoRobotInterface.h"
#include <iostream>
using namespace std;

void NaoRobotInterface::turnLeft() {
	robotApi->turnRobot(LEFT);
}

void NaoRobotInterface::turnRight() {
	robotApi->turnRobot(RIGHT);
}

void NaoRobotInterface::forward() {
	robotApi->moveRobot(FORWARD);
}

void NaoRobotInterface::backward() {
	robotApi->moveRobot(BACKWARD);
}

void NaoRobotInterface::moveLeft() {
	robotApi->moveRobot(LEFT);
}

void NaoRobotInterface::moveRight() {
	robotApi->moveRobot(RIGHT);
}

void NaoRobotInterface::stop() {
	robotApi->stopRobot();
}

void NaoRobotInterface::print() {
	cout << "-------------------------POSITION-------------------------------------" << endl;
	cout << "POSE         : (X) " << robotApi->getX() << " meters, "
		<< "(Y) " << robotApi->getY() << " meters, "
		<< "(Th) " << robotApi->getTh() << " degrees" << endl << endl;
	cout << "----------------------------------------------------------------------" << endl;

}

Pose NaoRobotInterface::getPose() {
	return Pose::Pose(robotApi->getX(), robotApi->getY(), robotApi->getTh());
}