/*!
* @author Mustafa Eren NAKAS
* @date 04.01.2024
* @brief SensorInterface abstract class header file
*
* SensorInterface class used to hold sensors under a main structure
*/

#pragma once
#include <string>

using namespace std;

class SensorInterface {
private:
	string sensorType;
public:
	//! Updates sensor values
	virtual void updateSensor() = 0;
	//! Returns sensor type as a string
	virtual string getSensorType() = 0;
	//! returns sensor values as a string
	virtual string getSensorValue() = 0;
};

