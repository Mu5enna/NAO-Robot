/**
* @author Nihat Deniz Ozkan
* @date 08.01.2024
* @brief Abstract class for robot functions
*
* RobotInterface class supposed to provide the robot functions as abstract class
*/
#pragma once
#include "Pose.h"
#include <vector>
#include "SensorInterface.h"
class RobotInterface
{
private:
    Pose* position;
    int status;
    vector<SensorInterface*> sensorlist;
public:
    //! abstract turn left function
    virtual void turnLeft() = 0;
    //! abstract turn right function
    virtual void turnRight() = 0;
    //! abstract forward function
    virtual void forward() = 0;
    //! abstract backward function
    virtual void backward() = 0;
    //! abstract move left function
    virtual void moveLeft() = 0;
    //! abstract move right function
    virtual void moveRight() = 0;
    //! abstract stop function
    virtual void stop() = 0;
    //! abstract get pose function
    virtual Pose getPose() = 0;
    //! abstract print function
    virtual void print() = 0;
    //! updates the sensor values
    void updateSensors();
    //! Adds sensors into the sensorList
    void addSensor(SensorInterface* sensor);
    //! Checks if the sensor is in the sensorList
    bool checkSensor(SensorInterface* sensor);
    //! prints the sensor values
    void printSensor(string type);
    //! returns the sensor list
    vector<SensorInterface*> getSensorList() { return sensorlist; };
};
