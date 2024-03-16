/**
* @author Mustafa Eren NAKAS
* @date 08.01.2024
* @brief prints menu opstions and feedbacks
*
* MenuOutput class prints menu options and feedback of options
*/

#pragma once
#include <iostream>

using namespace std;

class MenuOutput {
public:
	//! Function to print main menu
	void mainMenu();
	//! Function to print connection menu
	void connectionMenu();
	//! Function to print connection menu feedbacks
	void connectionMenuCases(int slc);
	//! Function to print sensor menu
	void sensorMenu();
	//! Function to print sensor menu feedbacks
	void sensorMenuCases(int slc, double var1, double var2, bool check);
	//! Function to print user menu
	void userMenu();
	//! Function to print sensor adding menu
	void sensorAddMenu();
	//! Function to print sensor adding menu feedbacks
	void sensorAddMenuCases(int slc);
	void pathMenu();
	//! Function to print motion menu
	void motionMenu();
	//! Function to print motion menu feedbacks
	void motionMenuCases(int slc);
};

