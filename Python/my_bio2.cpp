#include <iostream>
#include <string>
#include <ctime>
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
            time_t current_time;
            time(&current_time);
            struct tm *current_tm = localtime(&current_time);
            int current_year = current_tm->tm_year + 1900;
            
            if (birth_year < 1900 || birth_year > current_year) {
                cout << "Invalid birth year. Please enter a reasonable year." << endl;
            } else {
                break; // Exit the loop if the input is a valid integer
            }
        }
    }

    // Calculate the user's age in days
    time_t current_time;
    time(&current_time);
    struct tm *current_tm = localtime(&current_time);
    int current_year = current_tm->tm_year + 1900;
    int current_month = current_tm->tm_mon + 1;
    int current_day = current_tm->tm_mday;
    
    struct tm birth_tm = {0};
    birth_tm.tm_year = birth_year - 1900;
    birth_tm.tm_mon = 0;
    birth_tm.tm_mday = 1;
    time_t birth_time = mktime(&birth_tm);

    double age_seconds = difftime(current_time, birth_time);
    double age_days = age_seconds / (60 * 60 * 24); // Convert seconds to days

    // Calculate age in months and days
    int age_months = static_cast<int>(age_days / 30.44); // Average days per month
    int age_remaining_days = static_cast<int>(age_days) % 30;

    // Print the greeting with the user's name and age
    cout << "Hello " << name << ", your age is approximately " << age_months << " months and " << age_remaining_days << " days." << endl;

    return 0;
}
