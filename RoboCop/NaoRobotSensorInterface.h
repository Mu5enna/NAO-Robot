/**
* @author Serhat Aydin
* @date 07.01.2024
* @brief parent class for Nao robot sensor interfaces
* 
* This class is used as a parent class for Nao robot sensor interfaces. It has a pointer to Nao robot api to use int the code.
*/

#pragma once
#include "NaoRobotAPI.h"
#include "SensorInterface.h"
class NaoRobotSensorInterface :public SensorInterface {
protected:
	NaoRobotAPI* robotApi;
};
