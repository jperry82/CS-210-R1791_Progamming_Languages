#ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H

#include <map>
#include <string>

class GroceryTracker {
private:
	std::map < std::string, int > itemFrequency;

public:
	// Adds an item to the tracker.
	void addItem(const std::string& item);

	// Return the frequency of the given item
	int getItemFrequency(const std::string& item);

	// Prints all item frequencies
	void printAllFrequencies() const;

	// Prints a histogram of all item frequencies
	void printHistogram() const;

	// Saves all item frequencies to a file
	void saveToFile(const std::string& filename) const;
};

#endif
