#include "MenuFunctionality.h"

/*
* \param strslc is the operation selected
* \return if input valid true, if not false
*/
bool MenuFunctionality::isValid(string& strslc) {
	if (strslc.length() == 1) {
		try {
			stoi(strslc);
			return true;
		}
		catch (invalid_argument&) {
			return false;
		}
		catch (out_of_range&) {
			return false;
		}
	}
	else {
		return false;
	}
}

/*
* \param strslc is the operation selected
* does the selected functions of main menu
*/
void MenuFunctionality::mainMenu(string strslc) {
	int slc;
	if (isValid(strslc)) {
		slc = stoi(strslc);
	}
	else {
		slc = -1;
	}
	try {
		if (!this->robotControl.getAccess() && (slc == 1 || slc == 2 || slc == 3 || slc == 4)) {
			throw runtime_error("No access to robot! Use 'User Access' menu to gain access.");
		}
	}
	catch (const runtime_error& e) {
		system("cls");
		cout << e.what() << endl;
		Sleep(3000);
		system("cls");
		this->menuOutput.mainMenu();
		cin >> strslc;
		mainMenu(strslc);
	}
	switch (slc) {
	case 1:
		system("cls");
		this->menuOutput.connectionMenu();
		cin >> strslc;
		connectionMenu(strslc);
		break;
	case 2:
		system("cls");
		this->menuOutput.sensorMenu();
		cin >> strslc;
		sensorMenu(strslc);
		break;
	case 3:
		system("cls");
		this->menuOutput.motionMenu();
		cin >> strslc;
		motionMenu(strslc);
		break;
	case 4:
		system("cls");
		this->menuOutput.pathMenu();
		cin >> strslc;
		pathMenu(strslc);
		break;
	case 5:
		system("cls");
		this->menuOutput.userMenu();
		cin >> strslc;
		userMenu(strslc);
		break;
	case 6:
		this->robotApi->disconnect();
		exit(true);
		break;
	default:
		system("cls");
		cout << "Not a valid entry! Please choose again.\n";
		Sleep(3000);
		system("cls");
		this->menuOutput.mainMenu();
		cin >> strslc;
		mainMenu(strslc);
		break;
	}
}

/*
* \param strslc is the operation selected
* does the selected functions of user menu
*/
void MenuFunctionality::userMenu(string strslc) {
	int slc;
	int pcode;
	if (isValid(strslc)) {
		slc = stoi(strslc);
	}
	else {
		slc = -1;
	}
	switch (slc) {
	case 1:
		system("cls");
		cout << "Enter the code: ";
		cin >> pcode;
		if (this->robotControl.openAccess(pcode)) { cout << "Opened Access\n"; }
		else { cout << "Invalid Code\n"; }
		Sleep(2000);
		system("cls");
		this->menuOutput.userMenu();
		cin >> strslc;
		userMenu(strslc);
		break;
	case 2:
		system("cls");
		cout << "Enter the code: ";
		cin >> pcode;
		if (this->robotControl.closeAccess(pcode)) { cout << "Closed Access\n"; }
		else { cout << "Invalid Code\n"; }
		Sleep(2000);
		system("cls");
		this->menuOutput.userMenu();
		cin >> strslc;
		userMenu(strslc);
		break;
	case 3:
		system("cls");
		robotOperator.print();
		Sleep(3000);
		system("cls");
		this->menuOutput.userMenu();
		cin >> strslc;
		userMenu(strslc);
		break;
	case 4:
		system("cls");
		menuOutput.mainMenu();
		cin >> strslc;
		mainMenu(strslc);
		break;
	default:
		system("cls");
		cout << "Not a valid entry! Please choose again.\n";
		Sleep(3000);
		system("cls");
		this->menuOutput.userMenu();
		cin >> strslc;
		userMenu(strslc);
		break;
	}
}

/*
* \param strslc is the operation selected
* does the selected functions of connection menu
*/
void MenuFunctionality::connectionMenu(string strslc) {
	int slc;
	if (isValid(strslc)) {
		slc = stoi(strslc);
	}
	else {
		slc = -1;
	}
	switch (slc) {
	case 1:
		this->robotApi->connect();
		this->menuOutput.connectionMenuCases(1);
		Sleep(2000);
		system("cls");
		this->menuOutput.connectionMenu();
		cin >> strslc;
		connectionMenu(strslc);
		break;
	case 2:
		this->robotApi->disconnect();
		this->menuOutput.connectionMenuCases(2);
		Sleep(2000);
		system("cls");
		this->menuOutput.connectionMenu();
		cin >> strslc;
		connectionMenu(strslc);
		break;
	case 3:
		system("cls");
		this->menuOutput.mainMenu();
		cin >> strslc;
		mainMenu(strslc);
		break;
	default:
		system("cls");
		cout << "Not a valid entry! Please choose again.\n";
		Sleep(3000);
		system("cls");
		this->menuOutput.connectionMenu();
		cin >> strslc;
		connectionMenu(strslc);
		break;
	}
}

/*
* \param strslc is the operation selected
* does the selected function of sensor menu
*/
void MenuFunctionality::sensorMenu(string strslc) {
	double var1 = 0, var2 = 0;
	int index = 0;
	bool check = false;
	int slc;
	if (isValid(strslc)) {
		slc = stoi(strslc);
	}
	else {
		slc = -1;
	}
	switch (slc) {
	case 1:
		system("cls");
		this->menuOutput.sensorMenuCases(1, var1, var2, check);
		cin >> strslc;
		sensorAddMenu(strslc);
		break;
	case 2:
		if (this->robotControl.checkSensor(bumperSensor)) {
			bumperSensor->updateSensor();
			robotControl.printSensor("bumper");
			check = bumperSensor->checkTouch();
			menuOutput.sensorMenuCases(2, var1, var2, check);
			this->robotControl.printSensor("Bumper");
		}
		Sleep(2000);
		system("cls");
		this->menuOutput.sensorMenu();
		cin >> strslc;
		sensorMenu(strslc);
		break;
	case 3:
		if (this->robotControl.checkSensor(forceSensor)) {
			forceSensor->updateSensor();
			var1 = forceSensor->getForce();
			check = forceSensor->checkFall();
			menuOutput.sensorMenuCases(3, var1, var2, check);
			this->robotControl.printSensor("Force");
		}
		Sleep(2000);
		system("cls");
		this->menuOutput.sensorMenu();
		cin >> strslc;
		sensorMenu(strslc);
		break;
	case 4:
		if (this->robotControl.checkSensor(sonarSensor)) {
			sonarSensor->updateSensor();
			var1 = sonarSensor->getMax(index);
			var2 = sonarSensor->getMin(index);
			menuOutput.sensorMenuCases(4, var2, var1, check);
			this->robotControl.printSensor("Sonar");
		}
		Sleep(2000);
		system("cls");
		this->menuOutput.sensorMenu();
		cin >> strslc;
		sensorMenu(strslc);
		break;
	case 5:
		this->robotControl.updateSensors();
		this->menuOutput.sensorMenuCases(5, var2, var1, check);
		Sleep(2000);
		system("cls");
		this->menuOutput.sensorMenu();
		cin >> strslc;
		sensorMenu(strslc);
		break;
	case 6:
		system("cls");
		this->menuOutput.sensorAddMenu();
		cin >> strslc;
		recordSensorMenu(strslc);
		break;
	case 7:
		system("cls");
		this->menuOutput.mainMenu();
		cin >> strslc;
		mainMenu(strslc);
		break;
	default:
		system("cls");
		cout << "Not a valid entry! Please choose again.\n";
		Sleep(3000);
		system("cls");
		this->menuOutput.sensorMenu();
		cin >> strslc;
		sensorMenu(strslc);
		break;
	}
}

void MenuFunctionality::recordSensorMenu(string strslc) {
	int slc;
	record->openFile();
	if (isValid(strslc)) {
		slc = stoi(strslc);
	}
	else {
		slc = -1;
	}
	switch (slc) {
	case 1:
		this->robotControl.recordSensor("Bumper");
		record->closeFile();
		Sleep(2000);
		system("cls");
		this->menuOutput.sensorAddMenu();
		cin >> strslc;
		sensorAddMenu(strslc);
		break;
	case 2:
		this->robotControl.recordSensor("Force");
		record->closeFile();
		Sleep(2000);
		system("cls");
		this->menuOutput.sensorAddMenu();
		cin >> strslc;
		sensorAddMenu(strslc);
		break;
	case 3:
		this->robotControl.recordSensor("Sonar");
		record->closeFile();
		Sleep(2000);
		system("cls");
		this->menuOutput.sensorAddMenu();
		cin >> strslc;
		sensorAddMenu(strslc);
		break;
	case 4:
		record->closeFile();
		Sleep(2000);
		system("cls");
		this->menuOutput.sensorMenu();
		cin >> strslc;
		sensorMenu(strslc);
		break;
	default:
		system("cls");
		cout << "Not a valid entry! Please choose again.\n";
		record->closeFile();
		Sleep(3000);
		system("cls");
		this->menuOutput.sensorAddMenu();
		cin >> strslc;
		sensorAddMenu(strslc);
		break;
	}
}

/*
* \param strslc is the operation selected
* does the selected functions of sensor add menu
*/
void MenuFunctionality::sensorAddMenu(string strslc) {
	int slc;
	if (isValid(strslc)) {
		slc = stoi(strslc);
	}
	else {
		slc = -1;
	}
	switch (slc) {
	case 1:
		this->robotControl.addSensor(this->bumperSensor);
		this->menuOutput.sensorAddMenuCases(1);
		Sleep(2000);
		system("cls");
		this->menuOutput.sensorAddMenu();
		cin >> strslc;
		sensorAddMenu(strslc);
		break;
	case 2:
		this->robotControl.addSensor(this->forceSensor);
		this->menuOutput.sensorAddMenuCases(2);
		Sleep(2000);
		system("cls");
		this->menuOutput.sensorAddMenu();
		cin >> strslc;
		sensorAddMenu(strslc);
		break;
	case 3:
		this->robotControl.addSensor(this->sonarSensor);
		this->menuOutput.sensorAddMenuCases(3);
		Sleep(2000);
		system("cls");
		this->menuOutput.sensorAddMenu();
		cin >> strslc;
		sensorAddMenu(strslc);
		break;
	case 4:
		system("cls");
		this->menuOutput.sensorMenu();
		cin >> strslc;
		sensorMenu(strslc);
	default:
		system("cls");
		cout << "Not a valid entry! Please choose again.\n";
		Sleep(3000);
		system("cls");
		this->menuOutput.sensorAddMenu();
		cin >> strslc;
		sensorAddMenu(strslc);
		break;
	}
}

void MenuFunctionality::pathMenu(string strslc) {
	int slc;
	if (isValid(strslc)) {
		slc = stoi(strslc);
	}
	else {
		slc = -1;
	}
	switch (slc) {
	case 1:
		system("cls");
		this->robotControl.addToPath();
		cout << "Added to Path\n";
		Sleep(2000);
		system("cls");
		this->menuOutput.pathMenu();
		cin >> strslc;
		pathMenu(strslc);
		break;
	case 2:
		system("cls");
		this->robotControl.clearPath();
		cout << "Path Cleared\n";
		Sleep(2000);
		system("cls");
		this->menuOutput.pathMenu();
		cin >> strslc;
		pathMenu(strslc);
		break;
	case 3:
		system("cls");
		this->robotControl.recordPath();
		cout << "Recorded\n";
		Sleep(2000);
		system("cls");
		this->menuOutput.pathMenu();
		cin >> strslc;
		pathMenu(strslc);
		break;
	case 4:
		system("cls");
		this->menuOutput.mainMenu();
		cin >> strslc;
		mainMenu(strslc);
		break;
	default:
		system("cls");
		cout << "Not a valid entry! Please choose again.\n";
		Sleep(3000);
		system("cls");
		this->menuOutput.pathMenu();
		cin >> strslc;
		pathMenu(strslc);
		break;
	}
}

/*
* \param strslc is the operation selected
* does the selected function of motion menu
*/
void MenuFunctionality::motionMenu(string strslc) {
	int slc;
	if (isValid(strslc)) {
		slc = stoi(strslc);
	}
	else {
		slc = -1;
	}
	switch (slc) {
	case 1:
		this->robotControl.forward();
		this->menuOutput.motionMenuCases(1);
		Sleep(2000);
		system("cls");
		this->menuOutput.motionMenu();
		cin >> strslc;
		motionMenu(strslc);
		break;
	case 2:
		this->robotControl.backward();
		this->menuOutput.motionMenuCases(2);
		Sleep(2000);
		system("cls");
		this->menuOutput.motionMenu();
		cin >> strslc;
		motionMenu(strslc);
		break;
	case 3:
		this->robotControl.moveLeft();
		this->menuOutput.motionMenuCases(3);
		Sleep(2000);
		system("cls");
		this->menuOutput.motionMenu();
		cin >> strslc;
		motionMenu(strslc);
		break;
	case 4:
		this->robotControl.moveRight();
		this->menuOutput.motionMenuCases(4);
		Sleep(2000);
		system("cls");
		this->menuOutput.motionMenu();
		cin >> strslc;
		motionMenu(strslc);
		break;
	case 5:
		this->robotControl.turnLeft();
		this->menuOutput.motionMenuCases(5);
		Sleep(2000);
		system("cls");
		this->menuOutput.motionMenu();
		cin >> strslc;
		motionMenu(strslc);
		break;
	case 6:
		this->robotControl.turnRight();
		this->menuOutput.motionMenuCases(6);
		Sleep(2000);
		system("cls");
		this->menuOutput.motionMenu();
		cin >> strslc;
		motionMenu(strslc);
		break;
	case 7:
		system("cls");
		this->robotControl.print();
		Sleep(3000);
		system("cls");
		this->menuOutput.motionMenu();
		cin >> strslc;
		motionMenu(strslc);
		break;
	case 8:
		system("cls");
		this->menuOutput.mainMenu();
		cin >> strslc;
		mainMenu(strslc);
		break;
	default:
		system("cls");
		cout << "Not a valid entry! Please choose again.\n";
		Sleep(3000);
		system("cls");
		this->menuOutput.motionMenu();
		cin >> strslc;
		motionMenu(strslc);
		break;
	}
}