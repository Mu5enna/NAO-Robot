#include "MenuOutput.h"

/*!
* prints main menu
*/
void MenuOutput::mainMenu() {
	cout << "Main Menu" << endl
		<< "1. Connection" << endl
		<< "2. Sensor" << endl
		<< "3. Motion" << endl
		<< "4. Path Access" << endl
		<< "5. User Access" << endl
		<< "6. Quit" << endl
		<< "Choose One: " << endl;
}

/*!
* prints connection menu
*/
void MenuOutput::connectionMenu() {
	cout << "Connection Menu" << endl
		<< "1. Connect Robot" << endl
		<< "2. Disconnect Robot" << endl
		<< "3. Back" << endl
		<< "Choose One: " << endl;
}

/*!
* \param slc is the operation selected
* prints connection menu feedbacks
*/
void MenuOutput::connectionMenuCases(int slc) {
	switch (slc) {
	case 1:
		cout << "Robot Connected" << endl;
		break;
	case 2:
		cout << "Robot Disconnected" << endl;
		break;
	}
}

/*!
* prints sensor menu
*/
void MenuOutput::sensorMenu() {
	cout << "Sensor Menu" << endl
		<< "1. Add Sensor" << endl
		<< "2. Bumper Sensor" << endl
		<< "3. Force Sensor" << endl
		<< "4. Sonar Sensor" << endl
		<< "5. Update All Sensors" << endl
		<< "6. Record Sensor" << endl
		<< "7. Back" << endl
		<< "Choose One: " << endl;
}

/*!
* \param slc is the operation selected
* prints sensor menu feedbacks
*/
void MenuOutput::sensorMenuCases(int slc, double var1, double var2, bool check) {
	switch (slc) {
	case 1:
		sensorAddMenu();
		break;
	case 2:
		cout << "Sensors Updated" << endl;
		if (check) {
			cout << "There is a Collision" << endl;
		}
		else {
			cout << "There isn't any Collision" << endl;
		}
		break;
	case 3:
		cout << "Sensors Updated" << endl;
		if (!check) {
			cout << "Robot Standing" << endl;
		}
		else {
			cout << "Robot Falled" << endl;
		}
		break;
	case 4:
		cout << "Sensors Updated" << endl;
		cout << "Min Range: " << var1 << endl;
		cout << "Max Range: " << var2 << endl;
		break;
	case 5:
		cout << "Added Sensors Updated\n"; 
		break;
	case 6:
		sensorAddMenu();
		break;
	}
}

/*
* prints user menu
*/
void MenuOutput::userMenu() {
	cout << "User Access Menu\n" <<
		"1. Open Access\n" <<
		"2. Close Access\n" <<
		"3. Print User\n" <<
		"4. Back\n" <<
		"Choose One: ";
}

/*
* prints sensor adding menu
*/
void MenuOutput::sensorAddMenu() {
	cout << "Choose a Sensor\n" <<
		"1. Bumper Sensor\n" <<
		"2. Force Sensor\n" <<
		"3. Sonar Sensor\n" <<
		"4. Back\n" <<
		"Choose One: ";
}

/*
* \param slc is the operation selected
* prints sensor adding menu feedbacks
*/
void MenuOutput::sensorAddMenuCases(int slc) {
	switch (slc) {
	case 1:
		cout << "Bumper Sensor added\n";
		break;
	case 2:
		cout << "Force Sensor added\n";
		break;
	case 3:
		cout << "Sonar Sensor added\n";
		break;
	}
}

void MenuOutput::pathMenu() {
	cout << "Path Menu\n"
		<< "1. Add Path\n"
		<< "2. Clear Path\n"
		<< "3. Record Path\n"
		<< "4. Back\n"
		<< "Choose One: ";
}

/*!
* prints motion menu
*/
void MenuOutput::motionMenu() {
	cout << "Motion Menu" << endl
		<< "1. Move Forward" << endl
		<< "2. Move Backward" << endl
		<< "3. Move Left" << endl
		<< "4. Move Right" << endl
		<< "5. Turn Left" << endl
		<< "6. Turn Right" << endl
		<< "7. Print Position" << endl
		<< "8. Back" << endl
		<< "Choose One: " << endl;
}

/*!
* \param slc is the operation selected
* prints motion menu feedbacks
*/
void MenuOutput::motionMenuCases(int slc) {
	switch (slc) {
	case 1:
		cout << "Moving Forward" << endl;
		break;
	case 2:
		cout << "Moving Backward" << endl;
		break;
	case 3:
		cout << "Moving Left" << endl;
		break;
	case 4:
		cout << "Moving Right" << endl;
		break;
	case 5:
		cout << "Robot Turned Left" << endl;
		break;
	case 6:
		cout << "Robot Turned Right" << endl;
		break;
	}
}