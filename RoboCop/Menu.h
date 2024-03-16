/*!
* @author Mustafa Eren NAKAS
* @date 08.01.2024
* @brief creates usable menu function
*
* Menu class uses MenuFunctionality to create usable menu function
*/

#pragma once
#include "MenuFunctionality.h"
#include "MenuOutput.h"

class Menu {
private:
	MenuFunctionality& menuFunctionality;
	MenuOutput menuOutput;
public:
	//! constructor function of Menu class
	Menu(MenuFunctionality& menuFunctionality) :menuFunctionality(menuFunctionality) {}
	//! creates usable menu function
	void menuOperator();
};