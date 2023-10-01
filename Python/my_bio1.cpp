#include <iostream>
#include <string>
#include <cstdlib> // For clearing the input buffer
using namespace std;

int main() {
    string name;
    int birth_year;

    // Get the user's name as input and handle empty input
    cout << "Enter your name: ";
    getline(cin, name);

    while (name.empty()) {
        cout << "Name cannot be empty. Enter your name: ";
        getline(cin, name);
    }

    // Get the user's birth year as input and handle invalid input
    while (true) {
        cout << "Enter your birth year: ";
        if (!(cin >> birth_year)) {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
            cout << "Invalid input. Please enter a valid year." << endl;
        } else {
            break; // Exit the loop if the input is a valid integer
        }
    }

    // Calculate the user's age
    int current_year = 2023; // You can change this to the current year
    int age = current_year - birth_year;

    // Print the greeting with the user's name and age
    cout << "Hello " << name << ", your age is " << age << " years old." << endl;

    if (age >= 65) {
        cout << "Congratulations, you are a senior citizen!" << endl;
    }

    // Add an option to print the age in months and days
    char response;
    cout << "Do you want to see your age in months and days (y/n)? ";
    cin >> response;

    if (response == 'y' || response == 'Y') {
        int months = age * 12;
        int days = age * 365; // Assuming a year has 365 days
        cout << "Your age is approximately " << months << " months and " << days << " days." << endl;
    }

    return 0;
}
