#include <iostream>
#include <limits>
#include <string>
#include "GroceryTracker.h"

using namespace std;

int main() {
	GroceryTracker groceryTracker("CS210_Project_Three_Input_File.txt");

	// Read and count all grocery items.
	if (!groceryTracker.LoadItems()) {
		cout << "Error: Could not open input file." << endl;
		return 1;
	}

	// Create the required backup data file.
	if (!groceryTracker.WriteFrequencyFile("frequency.dat")) {
		cout << "Error: Could not create frequency.dat." << endl;
		return 1;
	}

	int menuChoice = 0;

	while (menuChoice != 4) {
		cout << endl;
		cout << "Corner Grocer Item Tracker" << endl;
		cout << "1. Search for an item" << endl;
		cout << "2. Display all item frequencies" << endl;
		cout << "3. Display item histogram" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: ";

		cin >> menuChoice;

		// Validate that the user entered a number.
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid choice. Please enter 1 through 4." << endl;
			continue;
		}

		if (menuChoice == 1) {
			string item;

			cout << "enter the item you wish to look for : ";
			cin >> item;

			cout << item << " "
				<< groceryTracker.GetItemFrequency(item) << endl;
		}
		else if (menuChoice == 2) {
			cout << endl;
			groceryTracker.PrintAllFrequencies();
		}
		else if (menuChoice == 3) {
			cout << endl;
			groceryTracker.PrintHistogram();
		}
		else if (menuChoice == 4) {
			cout << "Exiting program." << endl;
		}
		else {
			cout << "Invalid choice. Please enter 1 through 4." << endl;
		}
	}

	return 0;
}