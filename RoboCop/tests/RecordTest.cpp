/**
* @author Eren Nusret ÇİZGEÇ
* @date 30.12.2023
* @brief: Record test
*/

#include "Record.h"
#include <iostream>

int main() {
    //! Create a Record object
    Record record("test.txt");

    //! Test of openFile function
    if (record.openFile()) {
        std::cout << "openFile test passed\n";
    } else {
        std::cout << "openFile test failed\n";
    }

    //! Test of closeFile function
    record.closeFile();
    if (!record.openFile()) {
        std::cout << "closeFile test passed\n";
    } else {
        std::cout << "closeFile test failed\n";
    }

    //! Test the setFileName function
    record.setFileName("new_test.txt");
    if (record.openFile()) {
        std::cout << "setFileName test passed\n";
    } else {
        std::cout << "setFileName test failed\n";
    }

    //! Test of readLine function
    std::string line = record.readLine();
    if (!line.empty()) {
        std::cout << "readLine test passed\n";
    } else {
        std::cout << "readLine test failed\n";
    }

    //! Test of writeLine function
    record.writeLine("Test line");
    line = record.readLine();
    if (line == "Test line") {
        std::cout << "writeLine test passed\n";
    } else {
        std::cout << "writeLine test failed\n";
    }

    //! Test of operator<< function
    record << "Test line";
    line = record.readLine();
    if (line == "Test line") {
        std::cout << "operator<< test passed\n";
    } else {
        std::cout << "operator<< test failed\n";
    }

    //! Test of operator>> function
    record >> line;
    if (line == "Test line") {
        std::cout << "operator>> test passed\n";
    } else {
        std::cout << "operator>> test failed\n";
    }

    return 0;
}