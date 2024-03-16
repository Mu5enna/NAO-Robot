#include "RobotInterface.h"
#include <iostream>

void RobotInterface::updateSensors() {
	for (SensorInterface* a : sensorlist) {
		a->updateSensor();
	}
}

void RobotInterface::addSensor(SensorInterface* sensor) {
    bool check = false;
    for (SensorInterface* temp : sensorlist) {
        if (temp == sensor) {
            check = true;
        }
    }
    if (!check) {
        sensorlist.push_back(sensor);
    }
    else {
        cout << "Sensor Already in List\n";
        return;
    }
}

bool RobotInterface::checkSensor(SensorInterface* sensor) {
    for (SensorInterface* temp : sensorlist) {
        if (temp == sensor) {
            return true;
        }
    }
    cout << "Sensor is not added\n";
    return false;
}

void RobotInterface::printSensor(string type) {
    for (SensorInterface* sensor : sensorlist) {
        if (sensor->getSensorType() == type) {
            cout << sensor->getSensorValue();
        }
    }
}