#include "Menu.h"

/*
* \param strslc is used to determine which menu option choosed
* Creates first menu and starts the program
*/
void Menu::menuOperator() {
	string strslc;
	menuOutput.mainMenu();
	cin >> strslc;
	menuFunctionality.mainMenu(strslc);
}
