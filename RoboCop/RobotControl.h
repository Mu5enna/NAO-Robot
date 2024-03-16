/**
* @author Nihat Deniz Özkan
* @date 08.01.2024
* @brief: This class has the task of keeping and managing the robot's location information
*
* creates its functions using functions from the  NaoRobotAPI class
*/

#pragma once
#ifndef RobotControl_h
#define RobotControl_h

#include "Pose.h"
#include "NaoRobotAPI.h"
#include "RobotInterface.h"
#include "NaoRobotInterface.h"
#include "Path.h"
#include "Record.h"

class RobotControl : public RobotInterface {
private:
    Pose* position;
    NaoRobotAPI* nao;
    int state;
    vector<SensorInterface*> sensorList;
    bool hasAccess;
    NaoRobotInterface* robotInterface;
    RobotInterface* robotinterface;
    Path* path;
    Record* record;
public:
    //! constructor for RobotControl
    RobotControl();
    //! rotates the robot to the left
    void turnLeft();
    //! rotates the robot to the right
    void turnRight();
    //! moves the robot forward
    void forward();
    //! prints the current position of the robot
    void print();
    //! moves the robot backward
    void backward();
    //! returns the current pose of the robot
    Pose getPose();
    //! moves the robot to the left
    void moveLeft();
    //! moves the robot to the right
    void moveRight();
    //! stops the robot
    void stop();
    //! prints the sensor values
    void printSensor(string type);
    //! updates the sensor values
    void updateSensors();
    //! Adds sensors into the sensorList
    void addSensor(SensorInterface* sensor);
    //! Checks if the sensor is in the sensorList
    bool checkSensor(SensorInterface* sensor);
    //! opens access for the operator
    bool openAccess(int code);
    //! closes access for the operator
    bool closeAccess(int code);
    //! Returns the access state of the operator
    bool getAccess() { return hasAccess; };
    //! Adds to path
    bool addToPath();
    //! clears the path
    void clearPath();
    //! records the path to file
    bool recordPath();
    //! records the sensor values
    bool recordSensor(string type);
};

#endif