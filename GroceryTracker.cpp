#include <fstream>
#include <iostream>
#include "GroceryTracker.h"

using namespace std;

// Stores the name of the input file.
GroceryTracker::GroceryTracker(string inputFileName) {
	m_inputFileName = inputFileName;
}

// Reads each grocery item from the input file and counts its frequency.
bool GroceryTracker::LoadItems() {
	ifstream inputFile;
	string item;

	inputFile.open(m_inputFileName);

	if (!inputFile.is_open()) {
		return false;
	}

	while (inputFile >> item) {
		m_itemFrequency[item]++;
	}

	inputFile.close();
	return true;
}

// Returns the number of times a specific item was purchased
int GroceryTracker::GetItemFrequency(string item) const {
	auto itemFound = m_itemFrequency.find(item);

	if (itemFound != m_itemFrequency.end()) {
		return itemFound->second;
	}

	return 0;
}

// Prints every grocery item and its frequency.
void GroceryTracker::PrintAllFrequencies() const {
	for (const auto& item : m_itemFrequency) {
		cout << item.first << " " << item.second << endl;
	}
}

// Prints every grocery item as a histogram.
void GroceryTracker::PrintHistogram() const {
	for (const auto& item : m_itemFrequency) {
		cout << item.first << " ";

		for (int i = 0; i < item.second; ++i) {
			cout << "*";
		}

		cout << endl;
	}
}

// Creates frequency.dat contating every item and its frequency.
bool GroceryTracker::WriteFrequencyFile(string outputFileName) const {
	ofstream outputFile;

	outputFile.open(outputFileName);

	if (!outputFile.is_open()) {
		return false;
	}

	for (const auto& item : m_itemFrequency) {
		outputFile << item.first << " " << item.second << endl;
	}

	outputFile.close();
	return true;
}