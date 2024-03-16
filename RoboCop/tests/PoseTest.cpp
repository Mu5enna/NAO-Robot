/**
* @author Nihat Deniz Özkan
* @date 30.12.2023
* @brief: Pose test
*/
#include "Pose.h"
#include "NaoRobotAPI.h"
#include <iostream>
Pose* position;
NaoRobotAPI* nao;


int main() {
	position = new Pose();
	nao = new NaoRobotAPI();
	Pose p1,p2;
	nao->connect();
	Sleep(1000);
	cout << "X= " << position->getX() << " Y= " << position->getY() << " TH= " << position->getTh()<<endl;
	nao->moveRobot(FORWARD);
	Sleep(8000);
	nao->stopRobot();
	position->setX(nao->getX());
	position->setY(nao->getY());
	position->setTh(nao->getTh());
	p1.setX(position->getX());
	p1.setY(position->getY());
	p1.setTh(position->getTh());
	cout << "X= " << position->getX() << " Y= " << position->getY() << " TH= " << position->getTh()<<endl;
	nao->turnRobot(RIGHT);
	Sleep(8000);
	nao->stopRobot();
	nao->moveRobot(FORWARD);
	Sleep(8000);
	nao->stopRobot();
	position->setX(nao->getX());
	position->setY(nao->getY());
	position->setTh(nao->getTh());
	p2.setX(position->getX());
	p2.setY(position->getY());
	p2.setTh(position->getTh());
	cout << "X= " << position->getX() << " Y= " << position->getY() << " TH= " << position->getTh() << endl;
	double distance = p1.findDistanceTo(p2);
	cout << "Distance: " << distance << std::endl;
	double angle = p1.findAngleTo(p2);
	cout << "Angle: " << angle << endl;
	nao->disconnect();
}
