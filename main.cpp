/*
Developer's Name: Joshua Perry
Date: 10/14/2023
Purpose: Systematically track and analyze the purchase frequency of grocery items, providing insights to optimze store layout and enhance customer shopping experience
*/

#include "GroceryTracker.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

int main() {
    GroceryTracker tracker;
    std::ifstream infile("C:\\Users\\jperr\\source\\repos\\Project3\\x64\\Debug\\CS210_Project_Three_Input_File.txt"); // Update to local location of input file
    std::string item;

    // Check if the file can be opened
    if (!infile.is_open()) {
        std::cerr << "Error: Could not open input file\n";
        return 1;  // non-zero return indicates an error
    }

    // Reading items from file and adding them to tracker
    while (infile >> item) {
        tracker.addItem(item);
    }
    infile.close();

    // Main loop for user interaction
    int option = 0;
    while (option != 4) {
        std::cout << "1. Get item frequency\n2. Print all frequencies\n3. Print histogram\n4. Exit\n";

        // Ensure input is an integer
        while (!(std::cin >> option)) {
            std::cin.clear(); // clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid input. Please enter a numeric value between 1 and 4: ";
        }

        // Ensure input is within the acceptable range
        while (option < 1 || option > 4) {
            std::cout << "Invalid choice. Please enter a number between 1 and 4: ";
            // Ensure input is an integer        }
            while (!(std::cin >> option)) {
                std::cin.clear();  // clear error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // discard invalid input
                std::cout << "Invalid input. Please enter an integer: ";
            }
        }

        switch (option) {
        case 1:
            std::cout << "Enter item: ";
            std::cin >> item;
            std::cout << item << ": " << tracker.getItemFrequency(item) << "\n";
            break;
        case 2:
            tracker.printAllFrequencies();
            break;
        case 3:
            tracker.printHistogram();
            break;
        case 4:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid option\n";
            break;
        }
    }

    // Save to file upon exit
    tracker.saveToFile("frequency.dat");

    return 0;
}
