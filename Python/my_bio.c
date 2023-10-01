#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Include the stdbool.h library for boolean support
#include <string.h>  // Include the string.h header for strcspn

int main() {
    char name[100];  // Assuming a maximum name length of 100 characters
    int birth_year;

    // Get the user's name as input and handle empty input
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove the newline character

    while (name[0] == '\0') {
        printf("Name cannot be empty. Enter your name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';  // Remove the newline character
    }

    // Get the user's birth year as input and handle invalid input
    while (true) {
        printf("Enter your birth year: ");
        if (scanf("%d", &birth_year) != 1) {
            while (getchar() != '\n');  // Clear the input buffer
            printf("Invalid input. Please enter a valid year.\n");
        } else {
            break;  // Exit the loop if the input is a valid integer
        }
    }

    // Calculate the user's age
    int current_year = 2023;  // You can change this to the current year
    int age = current_year - birth_year;

    // Print the greeting with the user's name and age
    printf("Hello %s, your age is %d years old.\n", name, age);

        if (age >= 65) {
        printf("Congratulations, you are a senior citizen!\n");
    }

    // Add an option to print the age in months and days
    char response;
    printf("Do you want to see your age in months and days (y/n)? ");
    scanf(" %c", &response); // Read a single character, ignoring whitespace

    if (response == 'y' || response == 'Y') {
        int months = age * 12;
        int days = age * 365; // Assuming a year has 365 days
        printf("Your age is approximately %d months and %d days.\n", months, days);
    }

    return 0;
}
