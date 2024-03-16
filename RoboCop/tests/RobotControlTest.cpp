/**
* @author Nihat Deniz Özkan
* @date 30.12.2023
* @brief: RobotControl test
*/
#include "NaoRobotAPI.h"
#include "RobotControl.h"
#include <iostream>
NaoRobotAPI* nao;
RobotControl* robotcont;
int main() {
	nao->connect();
	robotcont = new RobotControl();
	robotcont->forward();
	Sleep(8000);
	robotcont->stop();
	robotcont->backward();
	Sleep(8000);
	robotcont->stop();
	robotcont->moveLeft();
	Sleep(8000);
	robotcont->print();
	nao->disconnect();
}