/**
* @author Serhat Aydin
* @date 08.01.2024
* @brief keeps information about robot operators
*
* RobotOperator class is a class that keeps information about robot operators,
* encrypts and decrypts the access code, and checks the access code.
*/

#pragma once
#include <iostream>
using namespace std;
class RobotOperator{
private:
	//! name of the robot operator
	string name;
	//! surname of the robot operator
	string surname;
	//! access code of the robot operator (encrypted)
	unsigned int accessCode;
	//! access state of the robot operator
	bool accessState;
	//! Private constructor to prevent instantiation
	RobotOperator(string name, string surname, unsigned int accessCode);
	//! Static instance of the singleton class
	static RobotOperator instance;
	
public:
	//! Static method to get the instance of the singleton class
	static RobotOperator& getInstance();
	//!encrypts the given code
	int encryptCode(int code);
	//!decrypts the given code
	int decryptCode(int code);
	/*! compares the access code(encrypted) with the code given as a parameter(decrypts before checking(were not sure whether to decrypt))
	and gives access if they are equal*/
	bool checkAccessCode(int code);
	//! prints the information about the robot operator
	void print();
};

