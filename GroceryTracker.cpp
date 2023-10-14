#include "GroceryTracker.h"
#include <iostream>
#include <fstream>
#include <algorithm>  // for transform
#include <cctype>  // for tolower

// Converts a string to lowercase.
std::string toLowerCase(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return lowerStr;
}

void GroceryTracker::addItem(const std::string& item) {
    itemFrequency[toLowerCase(item)]++;
}

int GroceryTracker::getItemFrequency(const std::string& item) {
    return itemFrequency[toLowerCase(item)];
}

void GroceryTracker::printAllFrequencies() const {
    for (const auto& pair : itemFrequency) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
}

void GroceryTracker::printHistogram() const {
    for (const auto& pair : itemFrequency) {
        std::cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void GroceryTracker::saveToFile(const std::string& filename) const {
    std::ofstream outfile(filename);
    for (const auto& pair : itemFrequency) {
        outfile << pair.first << " " << pair.second << std::endl;
    }
    outfile.close();
}
