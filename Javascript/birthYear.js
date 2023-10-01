const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

// Get the user's name as input and handle empty input
rl.question("Enter your name: ", function(name) {
  name = name.trim();

  // Validate name input
  while (!name) {
    console.log("Name cannot be empty.");
    name = rl.question("Enter your name: ").trim();
  }

  // Get the user's birth year as input and handle invalid input
  function getBirthYear() {
    rl.question("Enter your birth year: ", function(input) {
      const birthYear = parseInt(input);

      if (isNaN(birthYear)) {
        console.log("Invalid input. Please enter a valid year.");
        getBirthYear(); // Ask again if input is not a valid integer
      } else {
        // Calculate the user's age
        const currentYear = 2023; // You can change this to the current year
        const age = currentYear - birthYear;

        // Print the greeting with the user's name and age
        console.log(`Hello ${name}, your age is ${age} years old.`);
        rl.close();
      }
    });
  }

  getBirthYear(); // Start the birth year input process
});
