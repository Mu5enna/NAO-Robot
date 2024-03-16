#include "RobotOperator.h"
#include "Encryption.h"
#include <iostream>

//! Initialize the static instance with specific values
RobotOperator RobotOperator::instance("Operator", "Surname", 1234);

RobotOperator::RobotOperator(string name, string surname, unsigned int accessCode) :accessState(false) {
	this->name = name;
	this->surname = surname;
	this->accessCode = encryptCode(accessCode);

};

RobotOperator& RobotOperator::getInstance() {
	return instance;
}

/*!
* \param code the code to be encrypted
* \return encrypted code
* encrypts the given code using the Encryption class
*/
int RobotOperator::encryptCode(int code) {
	Encryption Encrypt;
	return Encrypt.encrypt(code);
}

/*!
* \param code the code to be decrypted
* \return decrypted code
* decrypts the given code using the Encryption class
*/
int RobotOperator::decryptCode(int code) {
	Encryption Encrypt;
	return Encrypt.decrypt(code);
}

/*!
* \param code the code to be checked
*/
bool RobotOperator::checkAccessCode(int code) {
	if (decryptCode(accessCode)==code) {
		accessState = true;
		return true;
	}
	else {
		accessState = false;
		return false;
	}
}

/*!
* prints the information about the robot operator
*/
void RobotOperator::print() {
	cout << "Name: " << name << " " << surname << endl;
	(accessState) ? cout << "Access State: Has Access" << endl : cout << "Access State: No Access" << endl;
}