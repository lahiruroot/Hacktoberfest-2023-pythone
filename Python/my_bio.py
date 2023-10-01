import datetime

# Get the user's name as input and handle empty input
name = input("Enter your name: ").strip()

# Validate name input
while not name:
    print("Name cannot be empty.")
    name = input("Enter your name: ").strip()

# Get the user's birth year as input and handle invalid input
while True:
    try:
        birth_year = int(input("Enter your birth year: "))
        current_year = datetime.date.today().year
        if birth_year < 1900 or birth_year > current_year:
            print("Invalid birth year. Please enter a reasonable year.")
        else:
         break  # Exit the loop if the input is a valid integer
    except ValueError:
        print("Invalid input. Please enter a valid year.")

# Calculate the user's age
age = current_year - birth_year

# Print the greeting with the user's name and age
print(f"Hello {name}, your age is {age} years old.")

# Check and display a special message for seniors (e.g., over 65)
if age >= 65:
    print("Congratulations, you are a senior citizen!")

# Add an option to print the age in months and days
response = input("Do you want to see your age in months and days (y/n)? ").strip().lower()
if response == 'y':
    months = age * 12
    days = age * 365  # Assuming a year has 365 days
    print(f"Your age is approximately {months} months and {days} days.")

