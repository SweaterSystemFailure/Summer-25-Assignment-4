#include <iostream>
#include "functions.h"
using namespace std;

void mainMenu() {
	cout << "Would you like to: " << endl;
	cout << "1. Add an item." << endl;
	cout << "2. View items." << endl;
	cout << "3. Exit" << endl;

	switch (unsignedValidator("Please make your selection: [1-3]", 1, 3)) {
	case 1:
		addItem();
		mainMenu();
		break;
	case 2:
		displayItems();
		mainMenu();
		break;
	case 3:
		cout << "Exiting...";
		cout << endl;
		break;
	default:
		cout << "It looks like something went wrong. Let's try again." << endl;
		cout << endl;
	}
}

void addItem() {
	cout << "Item added!" << endl;
	cout << endl;
}

void displayItems() {
	cout << "Displaying Items..." << endl;
	cout << endl;
}

unsigned unsignedValidator(const string& prompt, unsigned min, unsigned max) {
	unsigned number;
	while (true) {
		cout << prompt << endl;
		cin >> number;
		if (cin.fail()) {
			cout << "Enter a valid number." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (number < min || number > max) {
			cout << "Number must be between " << min << " and " << max << "." << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}
	return number;
}