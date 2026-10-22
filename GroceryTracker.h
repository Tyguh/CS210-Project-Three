#ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H

#include <map>
#include <string>

class GroceryTracker {
public:
	GroceryTracker(std::string inputFileName);

	bool LoadItems();
	int GetItemFrequency(std::string item) const;
	void PrintAllFrequencies() const;
	void PrintHistogram() const;
	bool WriteFrequencyFile(std::string outputFIleName) const;

private:
	std::string m_inputFileName;
	std::map<std::string, int> m_itemFrequency;
};

#endif