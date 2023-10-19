from datetime import datetime as dt

# Get the user's name as input 
name = input("Enter your name: ").strip()

# Validate name input
while not name:
    print("Name cannot be empty. Please try again.")
    name = input("Enter your name: ").strip()

# Get the current date (runtime) in the current_date variable 
current_date = dt.now()
current_year = current_date.year
current_month = current_date.month

# handle invalid user input birth year and month
while True:
    try:
        # Get the user's birth year and month as input
        birth_year = int(input("Enter your birth year: "))
        birth_month = int(input("Enter your birth month: "))
        
        if current_year < birth_year or (current_year == birth_year and current_month < birth_month):
            print("Invalid input. Birth cannot be in the future.")
        else:
            break  # Exit the loop if the input is a valid year and month.
    except ValueError:
        print("Invalid input. Please enter a valid year and month.")

# Calculate the user's age, taking into account the birth month
age = current_year - birth_year - ((current_month, current_date.day) < (birth_month, 1)) 

# Print the greeting with the user's name and age
print(f"Hello {name}, your age is {age} years old.") 