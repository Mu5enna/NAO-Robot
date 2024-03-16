#include "BumperSensor.h"

/*!
* \updates sensor status
*/
void BumperSensor::updateSensor() {
	this->robotApi->getFootBumpers(this->states[0], this->states[1], this->states[2], this->states[3]);
}

/*!
* \returns selected sensors statue
*/
bool BumperSensor::getState(int index) {
	return this->states[index];
}

/*!
* \checks if any bumper sensor activated
*/
bool BumperSensor::checkTouch() {
	for (int i = 0; i < 4; i++) {
		if (this->states[i]) {
			return true;
		}
	}
	return false;
}

/*!
* \returns states for each sensor as a string
*/
string BumperSensor::getSensorValue() {
	string res = "Bumper Sensor States: [0] " + to_string(getState(0)) + ", [1] " + to_string(getState(1)) + ", [2] " + to_string(getState(2)) + ", [3] " + to_string(getState(3)) + "\n";
	return res;
}