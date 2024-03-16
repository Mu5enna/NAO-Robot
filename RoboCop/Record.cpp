#include "Record.h"

/**
 * @brief Constructs a Record object with the given file name.
 *
 * @param name The name of the file associated with the Record.
 */
Record::Record(std::string name) : fileName(name) {}

/**
 * @brief Opens the file for reading and writing.
 *
 * This function opens the file specified by the fileName member variable
 * for both reading and writing. It returns true if the file is successfully
 * opened, and false otherwise.
 *
 * @return true if the file is successfully opened, false otherwise.
 */
bool Record::openFile() {
    file.open(fileName);
    return file.is_open();
}

/**
 * @brief Closes the file associated with the Record object.
 *
 * This function closes the file that was previously opened by the Record object.
 *
 * @return true if the file is successfully closed, false otherwise.
 */
bool Record::closeFile() {
    file.close();
    return !file.is_open();
}

/**
 * @brief Sets the file name for the record.
 *
 * This function sets the file name for the record to the specified value.
 *
 * @param name The name of the file to set.
 */
void Record::setFileName(std::string name) {
    fileName = name;
}

/**
 * @brief Reads a line from the file and returns it as a string.
 *
 * @return The line read from the file as a string.
 */
std::string Record::readLine() {
    std::string line;
    std::getline(file, line);
    return line;
}

/**
 * @brief Writes a line of text to the file.
 *
 * This function writes the specified string followed by a newline character to the file.
 *
 * @param str The string to be written to the file.
 * @return Returns true if the write operation is successful, false otherwise.
 */
bool Record::writeLine(std::string str) {
    file << str << std::endl;
    return !file.fail();
}

/**
 * @class Record
 * @brief Represents a record for storing data.
 *
 * The Record class provides functionality to write data to a record.
 * It supports the insertion operator (<<) to write a string to the record.
 */
Record& Record::operator<<(const std::string& str) {
    writeLine(str);
    return *this;
}

/**
 * @class Record
 * @brief Represents a record in a data structure.
 *
 * The Record class provides functionality to read and write data to a record.
 */
Record& Record::operator>>(std::string& str) {
    str = readLine();
    return *this;
}


bool Record::recordPath() {
    for (int i = 0; i < path->getNumber(); i++) {
        file << path->getPos(i).getX() << "," << path->getPos(i).getY() << "," << path->getPos(i).getTh() << std::endl;
    }
    return true;
}

bool Record::recordSensor(std::string type) {
    vector <SensorInterface*>sensorlist = robot->getSensorList();
    for (SensorInterface* sensor : sensorlist) {
        if (sensor->getSensorType() == type) {
            file << sensor->getSensorValue() << std::endl;
        }
    }
    return true;
}