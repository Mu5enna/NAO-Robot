/**
* @author Serhat Aydin
* @date 30.12.2023
* @brief robotOperator class test
*
* this file tests the robotOperator class, encrypts and decrypts the access code, and checks the access code.
*/

#include "RobotOperator.h"

using namespace std;

int main() {
	RobotOperator robotOperator("Serhat", "Aydin", 1234);
	robotOperator.print();
	robotOperator.checkAccessCode(1234);
	robotOperator.print();
	robotOperator.checkAccessCode(1235);
	robotOperator.print();
	return 0;
}