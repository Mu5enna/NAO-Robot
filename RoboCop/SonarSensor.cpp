#include "SonarSensor.h"

/*!
* \returns selected sonars range
*/
double SonarSensor::getRange(int index) {
	return this->ranges[index];
}

/*!
* \returns min range and updates index as min value sensors index
*/
double SonarSensor::getMin(int& index) {
	if (this->ranges[0] > this->ranges[1]) {
		index = 1;
		return this->ranges[1];
	}
	else {
		index = 0;
		return this->ranges[0];
	}
}

/*!
* \returns max range and updates index as max value sensors index
*/
double SonarSensor::getMax(int& index) {
	if (this->ranges[0] < this->ranges[1]) {
		index = 1;
		return this->ranges[1];
	}
	else {
		index = 0;
		return this->ranges[0];
	}
}

/*!
* \updates sensor status
*/
void SonarSensor::updateSensor() {
	this->robotApi->getSonarRange(this->ranges[0], this->ranges[1]);
}

/*!
* \returns distances for each sensor as a string
*/
string SonarSensor::getSensorValue() {
	string val1 = to_string(getRange(0)), val2 = to_string(getRange(1));
	string res = "Range of Sensor 0: " + val1 + " m, Range of Sensor 1: " + val2 + " m";
	return res;
}