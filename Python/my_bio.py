import datetime
# Get the user's name as input
name = input("Enter your name: ")

# Get the user's date of birth as input
date_of_birth = input("Enter your date of birth (YYYY-MM-DD): ")

# Convert the date of birth to a datetime object
date_of_birth = datetime.datetime.strptime(date_of_birth, "%Y-%m-%d")

# Get the current date as a datetime object
current_date = datetime.datetime.today()

# Calculate the difference between the user's date of birth and the current date
age_in_days = int((current_date - date_of_birth).days) 
age_in_months = int((current_date - date_of_birth).days / 30.4167)
age_in_years = int((current_date - date_of_birth).days / (30.4167*12))

# Print the user's age in months
print(f"You are {age_in_years} years or {age_in_months} months or {age_in_days} old.")