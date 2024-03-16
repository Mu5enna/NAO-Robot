#include "RobotControl.h"
#include "NaoRobotAPI.h"
#include "RobotOperator.h"
#include <iostream>

RobotControl::RobotControl() {
    position = new Pose();
    nao = new NaoRobotAPI();
    state = 0;
    hasAccess = false;
    robotInterface = new NaoRobotInterface(nao);
    robotinterface = new NaoRobotInterface(nao);
    path = new Path();
}

void RobotControl::turnLeft() {
    robotInterface->turnLeft();
}

void RobotControl::turnRight() {
    robotInterface->turnRight();
}
void RobotControl::forward() {
    robotInterface->forward();
}

void RobotControl::print() {
    robotInterface->print();
}

void RobotControl::backward() {
    robotInterface->backward();
}
/*!
* \ return robots position
*/
Pose RobotControl::getPose() {
    return robotInterface->getPose();
}

void RobotControl::moveLeft() {
    robotInterface->moveLeft();
}

void RobotControl::moveRight() {
    robotInterface->moveRight();
}

void RobotControl::stop() {
    robotInterface->stop();
}

void RobotControl::printSensor(string type) {
    robotinterface->printSensor(type);
}

void RobotControl::updateSensors() {
    for (SensorInterface* sensor : sensorList) {
        sensor->updateSensor();
    }
}

void RobotControl::addSensor(SensorInterface* sensor) {
    robotinterface->addSensor(sensor);
}

bool RobotControl::checkSensor(SensorInterface* sensor) {
    return robotinterface->checkSensor(sensor);
}

bool RobotControl::openAccess(int code) {
    RobotOperator& robotOperator = RobotOperator::getInstance();
    if (robotOperator.checkAccessCode(code)) {
        hasAccess = true;
        return true;
    }
    else {
        return false;
    }
}

bool RobotControl::closeAccess(int code) {
    RobotOperator& robotOperator = RobotOperator::getInstance();
    if (robotOperator.checkAccessCode(code)) {
        hasAccess = false;
        return true;
    }
    else {
        return false;
    }
}


bool RobotControl::addToPath() {
    path->addPos(robotInterface->getPose());
    return true;
}

void RobotControl::clearPath() {
    path->clear();
}

bool RobotControl::recordPath() {
    record->recordPath();
    return true;
}

bool RobotControl::recordSensor(string type) {
    record->recordSensor(type);
    return true;
}