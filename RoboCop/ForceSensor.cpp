#include "ForceSensor.h"

/*!
* Gets the force data from force sensors and updates the force variable.
*/
void ForceSensor::updateSensor(void){
	force = robotApi->getFootForce();
	
}

/*!
* \return force sensor data
*/
double ForceSensor::getForce() {
	return this->force;
}

/*!
* \return if the robot is fallen true, if not false
*/
bool ForceSensor::checkFall() {
	if (this->force < 2.0) {
		return true;
	}
	else {
		return false;
	}
}

/*!
* \returns force value as a string
*/
string ForceSensor::getSensorValue() {
	string res = "Current Force Applying to Sensor: " + to_string(getForce()) + " kg.f\n";
	return res;
}