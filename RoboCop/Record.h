/*!
* @file Record.h
* @author Eren Nusret �izge�
* @date 30.12.2023
* @brief provide the save options for app
*
* This class supposed to do operations of saving process
*/

#pragma once

#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <fstream>
#include "Path.h"
#include "SensorInterface.h"
#include "RobotInterface.h"

class Record {
private:
    std::string fileName = "output.txt";
    std::fstream file;
    Record* record;
    Path* path;
    RobotInterface* robot;

public:
    Record() {}
    Record(std::string name);
    //! Opens the file in read and write mode.
    bool openFile();
    //! Closes the file.
    bool closeFile();
    //! Sets the file name for this Record object.
    void setFileName(std::string name);
    //! Reads a line from the file.
    std::string readLine();
    //! Writes a line to the file.
    bool writeLine(std::string str);
    //! Overloaded left shift operator to write a line to the file.
    Record& operator<<(const std::string& str);
    //! Overloaded right shift operator to read a line from the file.
    Record& operator>>(std::string& str);
    //! Records path to file
    bool recordPath();
    //! records the sensor values
    bool recordSensor(std::string type);
};

#endif // RECORD_H

