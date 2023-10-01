#include <stdio.h>
#include <stdlib.h>

// Function to get a valid integer input from the user
int getValidIntegerInput() {
    int value;
    char buffer[100];
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            exit(1);  // Handle EOF (e.g., Ctrl+D on Unix) gracefully
        }
        if (sscanf(buffer, "%d", &value) == 1) {
            return value;  // Return the valid integer
        } else {
            printf("Invalid input. Please enter a valid number: ");
        }
    }
}

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

    // Get the user's birth year as input
    printf("Enter your birth year: ");
    birth_year = getValidIntegerInput();

    // Calculate the user's age
    int current_year = 2023;  // You can change this to the current year
    int age = current_year - birth_year;

    // Print the greeting with the user's name and age
    printf("Hello %s, your age is %d years old.\n", name, age);

    return 0;
}
