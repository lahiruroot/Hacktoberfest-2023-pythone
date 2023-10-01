using System;

class Program
{
    static void Main()
    {
        string name;
        int birthYear;

        // Get the user's name as input and handle empty input
        Console.Write("Enter your name: ");
        name = Console.ReadLine().Trim();

        while (string.IsNullOrEmpty(name))
        {
            Console.WriteLine("Name cannot be empty.");
            Console.Write("Enter your name: ");
            name = Console.ReadLine().Trim();
        }

        // Get the user's birth year as input and handle invalid input
        while (true)
        {
            Console.Write("Enter your birth year: ");
            if (int.TryParse(Console.ReadLine(), out birthYear))
            {
                break;  // Exit the loop if the input is a valid integer
            }
            else
            {
                Console.WriteLine("Invalid input. Please enter a valid year.");
            }
        }

        // Calculate the user's age
        int currentYear = 2023;  // You can change this to the current year
        int age = currentYear - birthYear;

        // Print the greeting with the user's name and age
        Console.WriteLine($"Hello {name}, your age is {age} years old.");
    }
}
