// Copyright (c) 2025 Gustav I
// Created By: Gustav I
// Date: May 19, 2025
// This program calculates the volume of a square pyramid using user input
// and demonstrates function overloading, input validation, and loops.

#include <iostream>
#include <limits>  // For numeric_limits
#include <string>

// Constants
const float MAX_VALUE = 1000.0;
const float MIN_VALUE = 0.0;

// Function to calculate volume (user-defined input)
void calculateVolume(float base, float height) {
    float volume = (1.0 / 3.0) * base * base * height;
    std::cout << "Volume of the square pyramid: "
              << volume << " cubic units.\n";
}

// Overloaded function for demo (default values)
void calculateVolume() {
    float base = 5.0;
    float height = 10.0;
    float volume = (1.0 / 3.0) * base * base * height;
    std::cout << "[Demo] Using Base = 5.0, Height = 10.0\n";
    std::cout << "[Demo] Volume of the square pyramid: "
              << volume << " cubic units.\n";
}

int main() {
    int numTries;

    std::cout << "Welcome to the Square Pyramid Volume Calculator!\n";

    // Input number of calculations
    while (true) {
        std::cout << "How many calculations would you like to do? ";
        std::cin >> numTries;

        if (std::cin.fail() || numTries <= 0) {
            std::cin.clear();  // clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid number. Please enter a positive integer.\n";
        } else {
            break;
        }
    }

    for (int i = 0; i < numTries; i++) {
        std::string demoChoice;

        // Ask for demo mode
        while (true) {
            std::cout << "\nWould you like a demo? (yes/no): ";
            std::cin >> demoChoice;

            if (demoChoice == "yes") {
                calculateVolume();  // Call overloaded function
                break;

            } else if (demoChoice == "no") {
                float base, height;

                // Input base with validation
                while (true) {
                    std::cout << "Enter the base length (0 - 1000): ";
                    std::cin >> base;

                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits
                            <std::streamsize>::max(), '\n');
                        std::cout << "Invalid input."
                        "Please enter a floating-point number.\n";
                    } else if (base > MIN_VALUE && base
                        <= MAX_VALUE) {
                        break;
                    } else {
                        std::cout << "Base must be greater than 0"
                        "and less than or equal to 1000.\n";
                    }
                }

                // Input height with validation
                while (true) {
                    std::cout << "Enter the height (0 - 1000): ";
                    std::cin >> height;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits
                            <std::streamsize>::max(), '\n');
                        std::cout << "Invalid input. Please"
                        "enter a floating-point number.\n";
                    } else if (height > MIN_VALUE && height
                        <= MAX_VALUE) {
                        break;
                    } else {
                        std::cout << "Height must be greater than"
                        "0 and less than or equal to 1000.\n";
                    }
                }

                calculateVolume(base, height);  // Call function with user input
                break;

            } else {
                std::cout << "Please type only 'yes' or 'no'.\n";
            }
        }
    }
}  // More style placeholder