# Chapters 0-5: C++ Foundations & Data Types - Your Programming Journey Begins

## Welcome to C++ Programming: From Zero to Variables

This comprehensive guide introduces you to the world of C++ programming, starting from absolute basics and building up to working with data, variables, and user interaction. Whether you're completely new to programming or coming from another language, this foundation will set you up for success.

---

## Chapter 0: Introduction to Programming - Why C++?

### 0.1 - What is Programming?

Programming is the art of giving precise instructions to a computer to solve problems and create useful applications. Think of it as writing a recipe that a computer can follow perfectly every time.

```cpp
// Your very first C++ program
#include <iostream>

int main() 
{
    std::cout << "Welcome to C++ programming!\n";
    std::cout << "You're about to embark on an exciting journey.\n";
    return 0;
}
```

### 0.2 - Why Choose C++?

**C++ is a powerful choice because it offers:**

- **Performance**: C++ programs run extremely fast
- **Control**: Direct access to system resources and memory
- **Versatility**: Used for games, operating systems, browsers, databases
- **Career opportunities**: High demand in software engineering
- **Foundation**: Understanding C++ makes learning other languages easier

**Real-world applications of C++:**
- **Games**: Unreal Engine, Call of Duty, World of Warcraft
- **Browsers**: Google Chrome, Mozilla Firefox
- **Operating Systems**: Windows, macOS components, Linux
- **Databases**: MySQL, MongoDB, PostgreSQL
- **Finance**: High-frequency trading systems
- **Embedded Systems**: IoT devices, automotive software

### 0.3 - The Development Process

#### From Code to Execution

```
Source Code (.cpp) → Compiler → Machine Code → Executable Program
```

1. **Write**: Create source code in a text editor or IDE
2. **Compile**: Translate human-readable code to machine language
3. **Link**: Combine your code with necessary libraries
4. **Execute**: Run the final program

#### Setting Up Your Environment

```cpp
// Test your setup with this simple program
#include <iostream>

int main() 
{
    std::cout << "Setup successful! C++ is ready to go.\n";
    std::cout << "Compiler version: " << __cplusplus << '\n';
    return 0;
}
```

**Popular Development Environments:**
- **Beginner-friendly**: Code::Blocks, Dev-C++, Visual Studio Community
- **Professional**: Visual Studio, CLion, Qt Creator
- **Cross-platform**: VS Code with C++ extensions
- **Online**: Repl.it, CodePen, OnlineGDB (for quick testing)

---

## Chapter 1: Statements and Program Structure - Building Your First Programs

### 1.1 - C++ Program Structure

Every C++ program follows a consistent structure:

```cpp
// 1. Preprocessor directives (includes)
#include <iostream>
#include <string>

// 2. Using declarations (optional but common)
using namespace std;

// 3. Function declarations (prototypes)
void greetUser();

// 4. Main function (program entry point)
int main() 
{
    cout << "Program starting...\n";
    
    greetUser();  // Function call
    
    cout << "Program ending...\n";
    return 0;  // Success indicator
}

// 5. Function definitions
void greetUser() 
{
    cout << "Hello, welcome to C++!\n";
}
```

### 1.2 - Statements and Expressions

#### What is a Statement?

A statement is a complete instruction that tells the computer what to do:

```cpp
#include <iostream>

int main() 
{
    // Expression statements (end with semicolon)
    std::cout << "Hello World";           // Output statement
    int age = 25;                         // Declaration + initialization
    age = age + 1;                        // Assignment statement
    
    // Compound statement (block)
    {
        int localVariable = 10;           // Only exists in this block
        std::cout << localVariable << '\n';
    }
    
    // Return statement
    return 0;
}
```

#### Common Beginner Mistakes

```cpp
#include <iostream>

int main() 
{
    // ❌ Missing semicolon
    // std::cout << "Hello"
    
    // ✅ Correct
    std::cout << "Hello";
    
    // ❌ Missing quotes for text
    // std::cout << Hello World;
    
    // ✅ Correct
    std::cout << "Hello World";
    
    // ❌ Wrong slash direction in comments
    // std::cout << "Test"; \\ This won't work
    
    // ✅ Correct comment
    std::cout << "Test"; // This works fine
    
    return 0;
}
```

### 1.3 - Comments and Documentation

#### Types of Comments

```cpp
#include <iostream>

/*
 * Multi-line comment for program description
 * Program: Grade Calculator
 * Author: Student Name
 * Date: Today's Date
 * Purpose: Calculate student average grade
 */

int main() 
{
    // Single-line comment for quick notes
    std::cout << "Welcome to Grade Calculator\n";
    
    int score1 = 85;  // First test score
    int score2 = 92;  // Second test score
    int score3 = 78;  // Third test score
    
    /* 
       Calculate the average of three scores
       Formula: (score1 + score2 + score3) / 3
    */
    double average = (score1 + score2 + score3) / 3.0;
    
    std::cout << "Your average grade is: " << average << '\n';
    
    return 0;  // Indicate successful program completion
}
```

#### Documentation Best Practices

```cpp
#include <iostream>

int main() 
{
    // ✅ Good comments explain WHY, not just WHAT
    const double TAX_RATE = 0.08;  // State sales tax rate (8%)
    
    double price = 29.99;
    
    // Calculate final price including tax for customer receipt
    double finalPrice = price + (price * TAX_RATE);
    
    std::cout << "Item price: $" << price << '\n';
    std::cout << "Tax: $" << (price * TAX_RATE) << '\n';
    std::cout << "Total: $" << finalPrice << '\n';
    
    return 0;
}
```

---

## Chapter 2: Functions and Files - Your First Real Programs

### 2.1 - Introduction to Functions

Functions are reusable blocks of code that perform specific tasks:

```cpp
#include <iostream>

// Function to display welcome message
void showWelcome() 
{
    std::cout << "================================\n";
    std::cout << "     Welcome to My Program!     \n";
    std::cout << "================================\n";
}

// Function to display goodbye message
void showGoodbye() 
{
    std::cout << "================================\n";
    std::cout << "    Thanks for using my app!    \n";
    std::cout << "================================\n";
}

// Function to display menu options
void showMenu() 
{
    std::cout << "\nMain Menu:\n";
    std::cout << "1. Start calculator\n";
    std::cout << "2. View help\n";
    std::cout << "3. Exit program\n";
    std::cout << "Choose an option: ";
}

int main() 
{
    showWelcome();    // Call welcome function
    showMenu();       // Call menu function
    
    // Simulate user interaction
    std::cout << "2\n";  // User chooses help
    
    std::cout << "\nHelp: This program demonstrates basic C++ structure.\n";
    
    showGoodbye();    // Call goodbye function
    
    return 0;
}
```

### 2.2 - The main() Function

The `main()` function is special - it's where your program begins execution:

```cpp
#include <iostream>

int main()  // Return type 'int' indicates success/failure to operating system
{
    std::cout << "Program execution starts here!\n";
    
    // Your program logic goes here
    std::cout << "Doing some work...\n";
    std::cout << "More work...\n";
    std::cout << "Almost done...\n";
    
    std::cout << "Program execution ends here!\n";
    
    return 0;  // 0 typically means "success"
               // Non-zero values indicate errors
}
```

#### Understanding Return Values

```cpp
#include <iostream>

int main() 
{
    std::cout << "Testing different return scenarios:\n";
    
    bool simulateError = false;  // Change to true to simulate error
    
    if (simulateError) 
    {
        std::cout << "Error occurred! Exiting with error code.\n";
        return 1;  // Non-zero return indicates error
    }
    
    std::cout << "Program completed successfully!\n";
    return 0;  // Zero indicates success
}
```

### 2.3 - Preprocessor and #include

#### Understanding #include

```cpp
// System includes (angle brackets)
#include <iostream>    // For input/output operations
#include <string>      // For string class
#include <cmath>       // For mathematical functions
#include <iomanip>     // For output formatting

// User-defined includes (quotes) - for your own header files
// #include "myheader.h"  // Would include your custom header

int main() 
{
    // Demonstrate different library features
    
    // From <iostream>
    std::cout << "Hello World!\n";
    
    // From <string>
    std::string name = "C++ Programmer";
    std::cout << "Name: " << name << '\n';
    
    // From <cmath>
    double result = std::sqrt(16.0);
    std::cout << "Square root of 16: " << result << '\n';
    
    // From <iomanip>
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Pi approximately: " << 3.14159 << '\n';  // Shows 3.14
    
    return 0;
}
```

#### Preprocessor Directives

```cpp
#include <iostream>

// Define constants using #define (older C-style)
#define PI 3.14159
#define PROGRAM_VERSION "1.0"

// Conditional compilation
#define DEBUG_MODE 1

int main() 
{
    std::cout << "Program Version: " << PROGRAM_VERSION << '\n';
    std::cout << "Value of PI: " << PI << '\n';
    
    #if DEBUG_MODE
        std::cout << "Debug: Program is running in debug mode\n";
    #endif
    
    // Modern C++ prefers const variables over #define
    const double BETTER_PI = 3.14159265359;
    std::cout << "Better PI: " << BETTER_PI << '\n';
    
    return 0;
}
```

---

## Chapter 3: Object Sizes and the sizeof Operator - Understanding Memory

### 3.1 - Computer Memory Basics

Understanding how data is stored in memory is crucial for effective programming:

```cpp
#include <iostream>

int main() 
{
    std::cout << "Understanding Memory and Data Sizes\n";
    std::cout << "===================================\n";
    
    // Different data types take different amounts of memory
    std::cout << "Memory sizes on this system:\n";
    std::cout << "bool:        " << sizeof(bool) << " byte(s)\n";
    std::cout << "char:        " << sizeof(char) << " byte(s)\n";
    std::cout << "int:         " << sizeof(int) << " byte(s)\n";
    std::cout << "float:       " << sizeof(float) << " byte(s)\n";
    std::cout << "double:      " << sizeof(double) << " byte(s)\n";
    std::cout << "long:        " << sizeof(long) << " byte(s)\n";
    std::cout << "long long:   " << sizeof(long long) << " byte(s)\n";
    
    std::cout << "\nWhy does this matter?\n";
    std::cout << "- Larger types can hold bigger values\n";
    std::cout << "- But they also use more memory\n";
    std::cout << "- Choose the right type for your needs\n";
    
    return 0;
}
```

### 3.2 - The sizeof Operator

The `sizeof` operator tells you how much memory a type or variable uses:

```cpp
#include <iostream>
#include <string>

int main() 
{
    // Using sizeof with types
    std::cout << "Type sizes:\n";
    std::cout << "sizeof(int): " << sizeof(int) << " bytes\n";
    std::cout << "sizeof(double): " << sizeof(double) << " bytes\n";
    
    // Using sizeof with variables
    int number = 42;
    double decimal = 3.14159;
    std::string text = "Hello World";
    
    std::cout << "\nVariable sizes:\n";
    std::cout << "sizeof(number): " << sizeof(number) << " bytes\n";
    std::cout << "sizeof(decimal): " << sizeof(decimal) << " bytes\n";
    std::cout << "sizeof(text): " << sizeof(text) << " bytes\n";
    
    // Arrays and sizeof
    int numbers[10];
    std::cout << "\nArray sizes:\n";
    std::cout << "sizeof(numbers): " << sizeof(numbers) << " bytes\n";
    std::cout << "sizeof(numbers[0]): " << sizeof(numbers[0]) << " bytes\n";
    std::cout << "Array length: " << sizeof(numbers) / sizeof(numbers[0]) << " elements\n";
    
    return 0;
}
```

### 3.3 - Memory Layout and Efficiency

Understanding memory usage helps you write efficient programs:

```cpp
#include <iostream>

// Demonstrate memory-efficient vs memory-wasteful approaches
int main() 
{
    std::cout << "Memory Efficiency Examples\n";
    std::cout << "==========================\n";
    
    // Example 1: Choosing appropriate data types
    
    // ❌ Memory wasteful for small values
    long long studentAge = 20;        // 8 bytes for a value that fits in 1 byte
    double simpleCounter = 5;         // 8 bytes for integer data
    
    // ✅ Memory efficient
    unsigned char betterAge = 20;     // 1 byte (can hold 0-255)
    int betterCounter = 5;            // 4 bytes, appropriate for integers
    
    std::cout << "Wasteful approach: " << sizeof(studentAge) + sizeof(simpleCounter) << " bytes\n";
    std::cout << "Efficient approach: " << sizeof(betterAge) + sizeof(betterCounter) << " bytes\n";
    
    // Example 2: Understanding the impact with large datasets
    const int ARRAY_SIZE = 1000;
    
    double largeArray[ARRAY_SIZE];         // 8000 bytes (8 * 1000)
    float smallerArray[ARRAY_SIZE];        // 4000 bytes (4 * 1000)
    
    std::cout << "\nFor " << ARRAY_SIZE << " elements:\n";
    std::cout << "double array: " << sizeof(largeArray) << " bytes\n";
    std::cout << "float array: " << sizeof(smallerArray) << " bytes\n";
    std::cout << "Memory saved: " << sizeof(largeArray) - sizeof(smallerArray) << " bytes\n";
    
    return 0;
}
```

---

## Chapter 4: Variable Assignment and Initialization - Working with Data

### 4.1 - Introduction to Variables

Variables are named storage locations that hold data:

```cpp
#include <iostream>

int main() 
{
    std::cout << "Understanding Variables\n";
    std::cout << "======================\n";
    
    // Variable declaration and initialization
    int playerScore = 100;        // Declare and initialize
    std::string playerName;       // Declare only
    playerName = "Alex";          // Assign later
    
    bool gameRunning = true;      // Boolean variable
    double accountBalance = 1250.75; // Decimal number
    
    // Display variable values
    std::cout << "Player: " << playerName << '\n';
    std::cout << "Score: " << playerScore << '\n';
    std::cout << "Balance: $" << accountBalance << '\n';
    std::cout << "Game Running: " << (gameRunning ? "Yes" : "No") << '\n';
    
    // Variables can change (that's why they're called "variable"!)
    playerScore += 50;  // Add 50 points
    accountBalance -= 25.00; // Spend $25
    
    std::cout << "\nAfter some gameplay:\n";
    std::cout << "New Score: " << playerScore << '\n';
    std::cout << "New Balance: $" << accountBalance << '\n';
    
    return 0;
}
```

### 4.2 - Variable Assignment vs Initialization

Understanding the difference between assignment and initialization:

```cpp
#include <iostream>

int main() 
{
    // INITIALIZATION (happens when variable is created)
    int score = 100;              // Direct initialization
    int lives(3);                 // Parentheses initialization
    int level{1};                 // Brace initialization (C++11)
    
    std::cout << "Initial values:\n";
    std::cout << "Score: " << score << ", Lives: " << lives << ", Level: " << level << '\n';
    
    // ASSIGNMENT (happens after variable exists)
    score = 150;                  // Change score to 150
    lives = lives - 1;            // Lose a life
    level = level + 1;            // Level up
    
    std::cout << "\nAfter assignment:\n";
    std::cout << "Score: " << score << ", Lives: " << lives << ", Level: " << level << '\n';
    
    // Multiple variable declaration and initialization
    int x = 10, y = 20, z = 30;  // All in one line
    std::cout << "\nMultiple variables: x=" << x << ", y=" << y << ", z=" << z << '\n';
    
    // Uninitialized variables (dangerous!)
    int dangerous;                // Contains garbage value
    std::cout << "Uninitialized variable: " << dangerous << " (undefined behavior!)\n";
    
    return 0;
}
```

### 4.3 - Variable Scope and Lifetime

Variables exist within certain scopes and have limited lifetimes:

```cpp
#include <iostream>

// Global variable (avoid when possible)
int globalCounter = 0;

int main() 
{
    std::cout << "Variable Scope Demonstration\n";
    std::cout << "============================\n";
    
    // Local variable in main function
    int mainVariable = 10;
    
    std::cout << "Main variable: " << mainVariable << '\n';
    std::cout << "Global counter: " << globalCounter << '\n';
    
    // Block scope
    {
        int blockVariable = 20;           // Only exists in this block
        mainVariable = 15;                // Can modify outer variable
        globalCounter++;                  // Can modify global variable
        
        std::cout << "\nInside block:\n";
        std::cout << "Block variable: " << blockVariable << '\n';
        std::cout << "Main variable: " << mainVariable << '\n';
        std::cout << "Global counter: " << globalCounter << '\n';
        
        // Another nested block
        {
            int deepVariable = 30;
            std::cout << "Deep variable: " << deepVariable << '\n';
        }
        // deepVariable no longer exists here!
    }
    // blockVariable no longer exists here!
    
    std::cout << "\nBack in main:\n";
    std::cout << "Main variable: " << mainVariable << '\n';
    std::cout << "Global counter: " << globalCounter << '\n';
    
    // This would cause an error:
    // std::cout << blockVariable;  // Error: not in scope
    
    return 0;
}
```

### 4.4 - Best Practices for Variables

```cpp
#include <iostream>
#include <string>

int main() 
{
    std::cout << "Variable Best Practices\n";
    std::cout << "=======================\n";
    
    // ✅ Good: Meaningful names
    int studentAge = 20;
    double accountBalance = 1500.75;
    std::string firstName = "Alice";
    bool isLoggedIn = false;
    
    // ❌ Bad: Cryptic names
    int x = 20;           // What does x represent?
    double d = 1500.75;   // What kind of data?
    std::string s = "Alice"; // String of what?
    
    // ✅ Good: Initialize when declaring
    int score = 0;        // Start with known value
    bool gameActive = true; // Clear initial state
    
    // ❌ Bad: Uninitialized variables
    int badScore;         // Contains garbage
    bool badState;        // Unpredictable
    
    // ✅ Good: Use const for values that shouldn't change
    const int MAX_LIVES = 3;
    const double PI = 3.14159;
    const std::string GAME_TITLE = "Super Adventure";
    
    std::cout << "Game: " << GAME_TITLE << '\n';
    std::cout << "Max Lives: " << MAX_LIVES << '\n';
    std::cout << "Player: " << firstName << " (Age: " << studentAge << ")\n";
    std::cout << "Account Balance: $" << accountBalance << '\n';
    std::cout << "Logged In: " << (isLoggedIn ? "Yes" : "No") << '\n';
    
    // Using const prevents accidental changes
    // MAX_LIVES = 5;  // Error: cannot modify const variable
    
    return 0;
}
```

---

## Chapter 5: Introduction to iostream - Talking to Users

### 5.1 - Basic Input and Output

The iostream library provides tools for communicating with users:

```cpp
#include <iostream>
#include <string>

int main() 
{
    std::cout << "Welcome to Input/Output Basics!\n";
    std::cout << "===============================\n";
    
    // Basic output with cout
    std::cout << "This is a line of text.\n";
    std::cout << "Numbers: " << 42 << " and " << 3.14159 << '\n';
    
    // Chaining output
    std::string name = "Alice";
    int age = 25;
    std::cout << "Name: " << name << ", Age: " << age << " years old\n";
    
    // Basic input with cin
    std::string userName;
    int userAge;
    
    std::cout << "\nLet's get to know you!\n";
    std::cout << "What's your name? ";
    std::cin >> userName;
    
    std::cout << "How old are you? ";
    std::cin >> userAge;
    
    // Display what we learned
    std::cout << "\nNice to meet you, " << userName << "!\n";
    std::cout << "You are " << userAge << " years old.\n";
    
    return 0;
}
```

### 5.2 - Output with std::cout

#### Formatting Output

```cpp
#include <iostream>
#include <iomanip>
#include <string>

int main() 
{
    std::cout << "Advanced Output Formatting\n";
    std::cout << "==========================\n";
    
    // Different ways to create new lines
    std::cout << "Method 1: Using \\n" << '\n';
    std::cout << "Method 2: Using std::endl" << std::endl;  // Flushes buffer too
    
    // Formatting numbers
    double price = 19.99;
    double tax = 1.6;
    double total = price + tax;
    
    std::cout << std::fixed << std::setprecision(2);  // 2 decimal places
    std::cout << "Item Price: $" << price << '\n';
    std::cout << "Tax:        $" << tax << '\n';
    std::cout << "Total:      $" << total << '\n';
    
    // Formatting with width and alignment
    std::cout << "\nFormatted Table:\n";
    std::cout << std::left << std::setw(12) << "Product" 
              << std::right << std::setw(8) << "Price" << '\n';
    std::cout << std::left << std::setw(12) << "Laptop" 
              << std::right << std::setw(8) << "$899.99" << '\n';
    std::cout << std::left << std::setw(12) << "Mouse" 
              << std::right << std::setw(8) << "$24.99" << '\n';
    
    // Boolean values
    bool inStock = true;
    bool onSale = false;
    
    std::cout << "\nBoolean Display:\n";
    std::cout << "In Stock: " << inStock << " (numeric)\n";  // Shows 1
    std::cout << std::boolalpha;  // Switch to text display
    std::cout << "In Stock: " << inStock << " (text)\n";     // Shows true
    std::cout << "On Sale: " << onSale << " (text)\n";       // Shows false
    
    return 0;
}
```

#### Special Characters and Escape Sequences

```cpp
#include <iostream>

int main() 
{
    std::cout << "Special Characters and Escape Sequences\n";
    std::cout << "=======================================\n";
    
    // Common escape sequences
    std::cout << "Tab character: Hello\tWorld\n";
    std::cout << "New line: Hello\nWorld\n";
    std::cout << "Carriage return: Hello\rWorld\n";
    std::cout << "Backslash: C:\\Program Files\\\n";
    std::cout << "Quote marks: He said \"Hello World\"\n";
    std::cout << "Single quote: It\\'s a beautiful day\n";
    
    // Creating formatted output
    std::cout << "\nCreating a simple box:\n";
    std::cout << "+----------+\n";
    std::cout << "|  Hello   |\n";
    std::cout << "|  World   |\n";
    std::cout << "+----------+\n";
    
    // ASCII art example
    std::cout << "\nSimple ASCII Art:\n";
    std::cout << "    /\\_/\\  \n";
    std::cout << "   ( o.o ) \n";
    std::cout << "    > ^ <  \n";
    
    return 0;
}
```

### 5.3 - Input with std::cin

#### Basic Input Techniques

```cpp
#include <iostream>
#include <string>

int main() 
{
    std::cout << "Input Techniques Demonstration\n";
    std::cout << "==============================\n";
    
    // Single word input
    std::string firstName;
    std::cout << "Enter your first name: ";
    std::cin >> firstName;
    
    // Numeric input
    int age;
    std::cout << "Enter your age: ";
    std::cin >> age;
    
    // Multiple inputs in one line
    int day, month, year;
    std::cout << "Enter your birth date (DD MM YYYY): ";
    std::cin >> day >> month >> year;
    
    // Display results
    std::cout << "\nWhat you entered:\n";
    std::cout << "Name: " << firstName << '\n';
    std::cout << "Age: " << age << '\n';
    std::cout << "Birth date: " << day << "/" << month << "/" << year << '\n';
    
    // Full line input (after clearing buffer)
    std::cin.ignore();  // Clear any leftover input
    std::string fullName;
    std::cout << "\nEnter your full name: ";
    std::getline(std::cin, fullName);
    
    std::cout << "Full name: " << fullName << '\n';
    
    return 0;
}
```

#### Handling Input Problems

```cpp
#include <iostream>
#include <string>
#include <limits>

int main() 
{
    std::cout << "Input Validation Example\n";
    std::cout << "========================\n";
    
    int number;
    bool validInput = false;
    
    while (!validInput) 
    {
        std::cout << "Please enter a whole number: ";
        std::cin >> number;
        
        if (std::cin.fail()) 
        {
            std::cout << "That's not a valid number! Try again.\n";
            
            // Clear the error flag
            std::cin.clear();
            
            // Remove the bad input from the buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } 
        else 
        {
            validInput = true;
        }
    }
    
    std::cout << "Great! You entered: " << number << '\n';
    
    // Demonstrating the whitespace problem with getline
    std::cout << "\nDemonstrating input buffer issues:\n";
    
    int favoriteNumber;
    std::string favoriteColor;
    
    std::cout << "Enter your favorite number: ";
    std::cin >> favoriteNumber;
    
    // This is needed to consume the leftover newline
    std::cin.ignore();
    
    std::cout << "Enter your favorite color: ";
    std::getline(std::cin, favoriteColor);
    
    std::cout << "Number: " << favoriteNumber << ", Color: " << favoriteColor << '\n';
    
    return 0;
}
```

### 5.4 - Building Interactive Programs

#### Simple Calculator

```cpp
#include <iostream>
#include <iomanip>

int main() 
{
    std::cout << "Simple Calculator\n";
    std::cout << "=================\n";
    
    double num1, num2;
    char operation;
    
    // Get input from user
    std::cout << "Enter first number: ";
    std::cin >> num1;
    
    std::cout << "Enter operation (+, -, *, /): ";
    std::cin >> operation;
    
    std::cout << "Enter second number: ";
    std::cin >> num2;
    
    // Perform calculation
    double result = 0;
    bool validOperation = true;
    
    switch (operation) 
    {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) 
            {
                result = num1 / num2;
            } 
            else 
            {
                std::cout << "Error: Cannot divide by zero!\n";
                validOperation = false;
            }
            break;
        default:
            std::cout << "Error: Unknown operation!\n";
            validOperation = false;
    }
    
    // Display result
    if (validOperation) 
    {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << num1 << " " << operation << " " << num2 << " = " << result << '\n';
    }
    
    return 0;
}
```

#### Personal Information Collector

```cpp
#include <iostream>
#include <string>
#include <iomanip>

int main() 
{
    std::cout << "Personal Information Collector\n";
    std::cout << "==============================\n";
    
    // Collect various types of information
    std::string firstName, lastName, city;
    int age, birthYear;
    double height, weight;
    char gender;
    bool hasJob;
    
    // Name information
    std::cout << "Enter your first name: ";
    std::cin >> firstName;
    
    std::cout << "Enter your last name: ";
    std::cin >> lastName;
    
    // Numeric information
    std::cout << "Enter your age: ";
    std::cin >> age;
    
    std::cout << "Enter your birth year: ";
    std::cin >> birthYear;
    
    std::cout << "Enter your height (in meters): ";
    std::cin >> height;
    
    std::cout << "Enter your weight (in kg): ";
    std::cin >> weight;
    
    // Character information
    std::cout << "Enter your gender (M/F): ";
    std::cin >> gender;
    
    // Boolean information (1 for true, 0 for false)
    std::cout << "Do you have a job? (1 for yes, 0 for no): ";
    std::cin >> hasJob;
    
    // Clear buffer for getline
    std::cin.ignore();
    
    // String with spaces
    std::cout << "Enter your city: ";
    std::getline(std::cin, city);
    
    // Calculate BMI
    double bmi = weight / (height * height);
    
    // Display collected information
    std::cout << "\n" << std::string(40, '=') << '\n';
    std::cout << "PERSONAL INFORMATION SUMMARY\n";
    std::cout << std::string(40, '=') << '\n';
    
    std::cout << "Name: " << firstName << " " << lastName << '\n';
    std::cout << "Age: " << age << " (Born in " << birthYear << ")\n";
    std::cout << "City: " << city << '\n';
    std::cout << "Gender: " << gender << '\n';
    std::cout << "Employment: " << (hasJob ? "Employed" : "Unemployed") << '\n';
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Height: " << height << " m\n";
    std::cout << "Weight: " << weight << " kg\n";
    std::cout << "BMI: " << bmi;
    
    // BMI categories
    if (bmi < 18.5) 
    {
        std::cout << " (Underweight)";
    } 
    else if (bmi < 25) 
    {
        std::cout << " (Normal weight)";
    } 
    else if (bmi < 30) 
    {
        std::cout << " (Overweight)";
    } 
    else 
    {
        std::cout << " (Obese)";
    }
    std::cout << '\n';
    
    return 0;
}
```

### 5.5 - Common Input/Output Patterns

#### Menu-Driven Program Structure

```cpp
#include <iostream>
#include <string>

int main() 
{
    std::cout << "Restaurant Order System\n";
    std::cout << "=======================\n";
    
    bool continueOrdering = true;
    double totalCost = 0.0;
    int itemCount = 0;
    
    while (continueOrdering) 
    {
        // Display menu
        std::cout << "\n--- MENU ---\n";
        std::cout << "1. Burger ($8.99)\n";
        std::cout << "2. Pizza ($12.50)\n";
        std::cout << "3. Salad ($6.75)\n";
        std::cout << "4. Drink ($2.25)\n";
        std::cout << "5. View Order\n";
        std::cout << "6. Checkout\n";
        std::cout << "Choose an option (1-6): ";
        
        int choice;
        std::cin >> choice;
        
        switch (choice) 
        {
            case 1:
                std::cout << "Added Burger to your order!\n";
                totalCost += 8.99;
                itemCount++;
                break;
                
            case 2:
                std::cout << "Added Pizza to your order!\n";
                totalCost += 12.50;
                itemCount++;
                break;
                
            case 3:
                std::cout << "Added Salad to your order!\n";
                totalCost += 6.75;
                itemCount++;
                break;
                
            case 4:
                std::cout << "Added Drink to your order!\n";
                totalCost += 2.25;
                itemCount++;
                break;
                
            case 5:
                std::cout << "\nCurrent Order:\n";
                std::cout << "Items: " << itemCount << '\n';
                std::cout << std::fixed << std::setprecision(2);
                std::cout << "Total: $" << totalCost << '\n';
                break;
                
            case 6:
                continueOrdering = false;
                break;
                
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    }
    
    // Final checkout
    std::cout << "\n--- FINAL ORDER ---\n";
    std::cout << "Items ordered: " << itemCount << '\n';
    std::cout << "Subtotal: $" << totalCost << '\n';
    
    double tax = totalCost * 0.08;  // 8% tax
    double finalTotal = totalCost + tax;
    
    std::cout << "Tax (8%): $" << tax << '\n';
    std::cout << "Final Total: $" << finalTotal << '\n';
    std::cout << "\nThank you for your order!\n";
    
    return 0;
}
```

#### Data Collection and Analysis

```cpp
#include <iostream>
#include <iomanip>

int main() 
{
    std::cout << "Student Grade Analyzer\n";
    std::cout << "======================\n";
    
    int numStudents;
    std::cout << "How many students? ";
    std::cin >> numStudents;
    
    if (numStudents <= 0) 
    {
        std::cout << "Invalid number of students!\n";
        return 1;
    }
    
    double totalGrades = 0;
    double highestGrade = 0;
    double lowestGrade = 100;
    int passingStudents = 0;
    
    // Collect grades
    for (int i = 1; i <= numStudents; i++) 
    {
        double grade;
        std::cout << "Enter grade for student " << i << ": ";
        std::cin >> grade;
        
        // Validate grade
        if (grade < 0 || grade > 100) 
        {
            std::cout << "Invalid grade! Please enter 0-100.\n";
            i--;  // Don't count this iteration
            continue;
        }
        
        // Update statistics
        totalGrades += grade;
        
        if (grade > highestGrade) 
        {
            highestGrade = grade;
        }
        
        if (grade < lowestGrade) 
        {
            lowestGrade = grade;
        }
        
        if (grade >= 60) 
        {
            passingStudents++;
        }
        
        // Show grade classification
        std::cout << "  Grade: " << grade;
        if (grade >= 90) std::cout << " (A)";
        else if (grade >= 80) std::cout << " (B)";
        else if (grade >= 70) std::cout << " (C)";
        else if (grade >= 60) std::cout << " (D)";
        else std::cout << " (F)";
        std::cout << '\n';
    }
    
    // Calculate and display statistics
    double average = totalGrades / numStudents;
    double passRate = (static_cast<double>(passingStudents) / numStudents) * 100;
    
    std::cout << "\n--- GRADE STATISTICS ---\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Number of students: " << numStudents << '\n';
    std::cout << "Average grade: " << average << '\n';
    std::cout << "Highest grade: " << highestGrade << '\n';
    std::cout << "Lowest grade: " << lowestGrade << '\n';
    std::cout << "Passing students: " << passingStudents << " out of " << numStudents << '\n';
    std::cout << "Pass rate: " << passRate << "%\n";
    
    // Overall class performance
    if (average >= 90) 
    {
        std::cout << "Outstanding class performance!\n";
    } 
    else if (average >= 80) 
    {
        std::cout << "Good class performance.\n";
    } 
    else if (average >= 70) 
    {
        std::cout << "Average class performance.\n";
    } 
    else 
    {
        std::cout << "Class needs improvement.\n";
    }
    
    return 0;
}
```

### 5.6 - Advanced I/O Techniques

#### Working with Different Data Types

```cpp
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

int main() 
{
    std::cout << "Advanced Input/Output Techniques\n";
    std::cout << "================================\n";
    
    // Safe input function for integers
    auto getInteger = [](const std::string& prompt) -> int 
    {
        int value;
        while (true) 
        {
            std::cout << prompt;
            if (std::cin >> value) 
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;
            } 
            else 
            {
                std::cout << "Invalid input! Please enter a whole number.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    };
    
    // Safe input function for doubles
    auto getDouble = [](const std::string& prompt) -> double 
    {
        double value;
        while (true) 
        {
            std::cout << prompt;
            if (std::cin >> value) 
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;
            } 
            else 
            {
                std::cout << "Invalid input! Please enter a number.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    };
    
    // Using the safe input functions
    int age = getInteger("Enter your age: ");
    double salary = getDouble("Enter your salary: ");
    
    std::cout << "You are " << age << " years old with a salary of $" 
              << std::fixed << std::setprecision(2) << salary << '\n';
    
    // String stream for parsing
    std::string dateInput;
    std::cout << "Enter a date (MM/DD/YYYY): ";
    std::getline(std::cin, dateInput);
    
    // Replace slashes with spaces for easier parsing
    for (char& c : dateInput) 
    {
        if (c == '/') c = ' ';
    }
    
    std::stringstream ss(dateInput);
    int month, day, year;
    if (ss >> month >> day >> year) 
    {
        std::cout << "Parsed date: Month=" << month 
                  << ", Day=" << day << ", Year=" << year << '\n';
        
        // Validate date
        bool validDate = true;
        if (month < 1 || month > 12) validDate = false;
        if (day < 1 || day > 31) validDate = false;
        if (year < 1900 || year > 2100) validDate = false;
        
        std::cout << "Date is " << (validDate ? "valid" : "invalid") << '\n';
    } 
    else 
    {
        std::cout << "Could not parse the date!\n";
    }
    
    return 0;
}
```

---

## Real-World Applications and Projects

### Project 1: Personal Budget Calculator

```cpp
#include <iostream>
#include <string>
#include <iomanip>

int main() 
{
    std::cout << "Personal Budget Calculator\n";
    std::cout << "=========================\n";
    
    // Income section
    std::string name;
    double monthlyIncome, rent, groceries, utilities, transportation, entertainment, other;
    
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    
    std::cout << "Enter your monthly income: $";
    std::cin >> monthlyIncome;
    
    // Expense categories
    std::cout << "\nEnter your monthly expenses:\n";
    std::cout << "Rent/Mortgage: $";
    std::cin >> rent;
    
    std::cout << "Groceries: $";
    std::cin >> groceries;
    
    std::cout << "Utilities: $";
    std::cin >> utilities;
    
    std::cout << "Transportation: $";
    std::cin >> transportation;
    
    std::cout << "Entertainment: $";
    std::cin >> entertainment;
    
    std::cout << "Other expenses: $";
    std::cin >> other;
    
    // Calculations
    double totalExpenses = rent + groceries + utilities + transportation + entertainment + other;
    double remainingMoney = monthlyIncome - totalExpenses;
    double savingsRate = (remainingMoney / monthlyIncome) * 100;
    
    // Budget report
    std::cout << "\n" << std::string(50, '=') << '\n';
    std::cout << "BUDGET REPORT FOR " << name << '\n';
    std::cout << std::string(50, '=') << '\n';
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::left << std::setw(20) << "Monthly Income:" << std::right << std::setw(10) << "$" << monthlyIncome << '\n';
    
    std::cout << "\nEXPENSES:\n";
    std::cout << std::left << std::setw(20) << "Rent/Mortgage:" << std::right << std::setw(10) << "$" << rent << '\n';
    std::cout << std::left << std::setw(20) << "Groceries:" << std::right << std::setw(10) << "$" << groceries << '\n';
    std::cout << std::left << std::setw(20) << "Utilities:" << std::right << std::setw(10) << "$" << utilities << '\n';
    std::cout << std::left << std::setw(20) << "Transportation:" << std::right << std::setw(10) << "$" << transportation << '\n';
    std::cout << std::left << std::setw(20) << "Entertainment:" << std::right << std::setw(10) << "$" << entertainment << '\n';
    std::cout << std::left << std::setw(20) << "Other:" << std::right << std::setw(10) << "$" << other << '\n';
    std::cout << std::string(30, '-') << '\n';
    std::cout << std::left << std::setw(20) << "Total Expenses:" << std::right << std::setw(10) << "$" << totalExpenses << '\n';
    
    std::cout << '\n';
    std::cout << std::left << std::setw(20) << "Remaining:" << std::right << std::setw(10) << "$" << remainingMoney << '\n';
    std::cout << std::left << std::setw(20) << "Savings Rate:" << std::right << std::setw(9) << savingsRate << "%\n";
    
    // Financial advice
    std::cout << "\nFINANCIAL ADVICE:\n";
    if (remainingMoney < 0) 
    {
        std::cout << "⚠️  WARNING: You're spending more than you earn!\n";
        std::cout << "   Consider reducing expenses by $" << -remainingMoney << '\n';
    } 
    else if (savingsRate < 10) 
    {
        std::cout << "💡 TIP: Try to save at least 10% of your income.\n";
        std::cout << "   You could save $" << (monthlyIncome * 0.10) - remainingMoney << " more.\n";
    } 
    else if (savingsRate >= 20) 
    {
        std::cout << "🎉 EXCELLENT: You're saving " << savingsRate << "% of your income!\n";
    } 
    else 
    {
        std::cout << "👍 GOOD: You're saving " << savingsRate << "% of your income.\n";
    }
    
    return 0;
}
```

### Project 2: Unit Conversion Tool

```cpp
#include <iostream>
#include <iomanip>

int main() 
{
    std::cout << "Universal Unit Conversion Tool\n";
    std::cout << "==============================\n";
    
    bool continueConverting = true;
    
    while (continueConverting) 
    {
        std::cout << "\nConversion Categories:\n";
        std::cout << "1. Length (meters, feet, inches)\n";
        std::cout << "2. Weight (kg, pounds, ounces)\n";
        std::cout << "3. Temperature (Celsius, Fahrenheit, Kelvin)\n";
        std::cout << "4. Currency (simple USD/EUR example)\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose category: ";
        
        int category;
        std::cin >> category;
        
        if (category == 5) 
        {
            continueConverting = false;
            continue;
        }
        
        double value;
        std::cout << "Enter value to convert: ";
        std::cin >> value;
        
        std::cout << std::fixed << std::setprecision(2);
        
        switch (category) 
        {
            case 1: // Length
                std::cout << "\nLength Conversions for " << value << ":\n";
                std::cout << "Meters: " << value << " m\n";
                std::cout << "Feet: " << (value * 3.28084) << " ft\n";
                std::cout << "Inches: " << (value * 39.3701) << " in\n";
                std::cout << "Centimeters: " << (value * 100) << " cm\n";
                std::cout << "Kilometers: " << (value / 1000) << " km\n";
                break;
                
            case 2: // Weight
                std::cout << "\nWeight Conversions for " << value << " kg:\n";
                std::cout << "Kilograms: " << value << " kg\n";
                std::cout << "Pounds: " << (value * 2.20462) << " lbs\n";
                std::cout << "Ounces: " << (value * 35.274) << " oz\n";
                std::cout << "Grams: " << (value * 1000) << " g\n";
                break;
                
            case 3: // Temperature
                std::cout << "\nTemperature Conversions for " << value << "°C:\n";
                std::cout << "Celsius: " << value << "°C\n";
                std::cout << "Fahrenheit: " << ((value * 9.0/5.0) + 32) << "°F\n";
                std::cout << "Kelvin: " << (value + 273.15) << "K\n";
                break;
                
            case 4: // Currency (example rates)
                std::cout << "\nCurrency Conversions for $" << value << " USD:\n";
                std::cout << "USD: $" << value << '\n';
                std::cout << "EUR: €" << (value * 0.85) << " (example rate)\n";
                std::cout << "GBP: £" << (value * 0.73) << " (example rate)\n";
                std::cout << "JPY: ¥" << (value * 110) << " (example rate)\n";
                break;
                
            default:
                std::cout << "Invalid category!\n";
        }
        
        char again;
        std::cout << "\nConvert another value? (y/n): ";
        std::cin >> again;
        if (again != 'y' && again != 'Y') 
        {
            continueConverting = false;
        }
    }
    
    std::cout << "Thank you for using the Unit Conversion Tool!\n";
    return 0;
}
```

---

## Best Practices and Common Patterns

### Do's ✅

1. **Always initialize variables**:
```cpp
int score = 0;          // ✅ Known starting value
bool isReady = false;   // ✅ Clear initial state
```

2. **Use meaningful variable names**:
```cpp
double studentGPA = 3.85;        // ✅ Self-documenting
int numberOfStudents = 25;       // ✅ Clear purpose
```

3. **Include proper headers**:
```cpp
#include <iostream>    // ✅ For input/output
#include <iomanip>     // ✅ For formatting
#include <string>      // ✅ For string operations
```

4. **Use const for unchanging values**:
```cpp
const double PI = 3.14159;           // ✅ Mathematical constant
const int MAX_STUDENTS = 100;       // ✅ System limit
```

5. **Validate user input**:
```cpp
if (std::cin.fail()) {              // ✅ Check for input errors
    std::cin.clear();               // ✅ Reset error state
}
```

### Don'ts ❌

1. **Don't use uninitialized variables**:
```cpp
int score;              // ❌ Contains garbage value
std::cout << score;     // ❌ Undefined behavior
```

2. **Don't use cryptic names**:
```cpp
int x, y, z;           // ❌ What do these represent?
double d1, d2;         // ❌ Meaningless names
```

3. **Don't forget input buffer issues**:
```cpp
std::cin >> number;
std::getline(std::cin, name);  // ❌ Will skip input!
```

4. **Don't ignore the return value of main**:
```cpp
int main() {
    // ... code ...
    // ❌ Missing return statement
}
```

### Modern C++ Features to Embrace

```cpp
// C++11: Auto keyword for type deduction
auto name = std::string("Alice");    // ✅ Compiler deduces type

// C++11: Uniform initialization
int score{100};                      // ✅ Brace initialization
std::string title{"C++ Programming"}; // ✅ Consistent syntax

// C++11: Range-based for loops (when applicable)
std::string text = "Hello";
for (char c : text) {               // ✅ Modern iteration
    std::cout << c << ' ';
}
```

---

## Common Beginner Challenges and Solutions

### Challenge 1: Input Buffer Problems

```cpp
#include <iostream>
#include <string>

int main() 
{
    std::cout << "Demonstrating Input Buffer Issues\n";
    std::cout << "=================================\n";
    
    int age;
    std::string name;
    
    // ❌ This pattern causes problems:
    std::cout << "Enter your age: ";
    std::cin >> age;
    
    std::cout << "Enter your name: ";
    // std::getline(std::cin, name);  // This would be skipped!
    
    // ✅ Solution: Clear the buffer
    std::cin.ignore();  // Consume the leftover newline
    std::getline(std::cin, name);
    
    std::cout << "Age: " << age << ", Name: " << name << '\n';
    
    return 0;
}
```

### Challenge 2: Numeric Limits and Overflow

```cpp
#include <iostream>
#include <limits>

int main() 
{
    std::cout << "Understanding Numeric Limits\n";
    std::cout << "============================\n";
    
    // Display limits for common types
    std::cout << "int range: " << std::numeric_limits<int>::min() 
              << " to " << std::numeric_limits<int>::max() << '\n';
    
    std::cout << "double range: " << std::numeric_limits<double>::min() 
              << " to " << std::numeric_limits<double>::max() << '\n';
    
    // Demonstrate overflow
    int maxInt = std::numeric_limits<int>::max();
    std::cout << "Maximum int: " << maxInt << '\n';
    std::cout << "Max int + 1: " << (maxInt + 1) << " (overflow!)\n";
    
    // Safe arithmetic
    if (maxInt > std::numeric_limits<int>::max() - 1) 
    {
        std::cout << "Cannot safely add 1 to maxInt\n";
    }
    
    return 0;
}
```

### Challenge 3: Floating-Point Precision

```cpp
#include <iostream>
#include <iomanip>

int main() 
{
    std::cout << "Floating-Point Precision Issues\n";
    std::cout << "===============================\n";
    
    double a = 0.1;
    double b = 0.2;
    double sum = a + b;
    
    std::cout << std::setprecision(17);
    std::cout << "0.1 + 0.2 = " << sum << '\n';
    std::cout << "Expected: 0.3\n";
    std::cout << "Equal to 0.3? " << (sum == 0.3 ? "Yes" : "No") << '\n';
    
    // Safe comparison for floating-point
    const double EPSILON = 1e-9;
    bool approximately_equal = std::abs(sum - 0.3) < EPSILON;
    std::cout << "Approximately equal? " << (approximately_equal ? "Yes" : "No") << '\n';
    
    return 0;
}
```

---

## Conclusion

Chapters 0-5 provide the essential foundation for C++ programming:

- **Chapter 0**: Understanding programming concepts and the development process
- **Chapter 1**: Program structure, statements, and proper documentation
- **Chapter 2**: Functions, file organization, and the preprocessor
- **Chapter 3**: Memory concepts and the sizeof operator
- **Chapter 4**: Variables, initialization, assignment, and scope
- **Chapter 5**: Input/output operations and user interaction

### Key Takeaways

**Programming Fundamentals**: Understanding how programs are structured and executed
**Data Management**: Working with variables, types, and memory efficiently
**User Interaction**: Creating programs that can communicate with users
**Best Practices**: Writing clean, maintainable, and robust code from the beginning
**Problem Solving**: Breaking down complex problems into manageable parts

### Skills You've Developed

After mastering these chapters, you can:
- Write complete C++ programs with proper structure
- Handle user input and provide formatted output
- Work with different data types appropriately
- Debug common beginner issues
- Apply best practices for code quality
- Create interactive console applications

These foundational skills prepare you for the more advanced concepts in operators, control flow, and functions that follow in Chapters 6-10. The emphasis on proper practices and common pitfalls ensures you develop good programming habits from the start.

**Next: Chapters 6-10 - Operators, Control Flow, and Functions**
        

# Chapters 6-10: Operators, Control Flow & Functions - Building Program Logic

## Building from Variables & I/O: Creating Interactive Programs

After mastering variables and basic I/O in earlier chapters, we now dive into the core logic-building tools of C++. These chapters teach you how to make decisions, repeat actions, and organize code into reusable functions - the essential building blocks of any meaningful program.

---

## Chapter 6: Operators - The Tools of Computation

### 6.1 - Arithmetic Operators

#### Basic Arithmetic Operations

```cpp
#include <iostream>

int main() 
{
    int a = 15, b = 4;
    
    std::cout << "a = " << a << ", b = " << b << '\n';
    std::cout << "Addition: " << a << " + " << b << " = " << (a + b) << '\n';      // 19
    std::cout << "Subtraction: " << a << " - " << b << " = " << (a - b) << '\n';   // 11
    std::cout << "Multiplication: " << a << " * " << b << " = " << (a * b) << '\n'; // 60
    std::cout << "Division: " << a << " / " << b << " = " << (a / b) << '\n';       // 3 (integer division!)
    std::cout << "Modulus: " << a << " % " << b << " = " << (a % b) << '\n';        // 3
    
    // Floating-point division
    double x = 15.0, y = 4.0;
    std::cout << "Float division: " << x << " / " << y << " = " << (x / y) << '\n'; // 3.75
    
    return 0;
}
```

#### Operator Precedence and Associativity

```cpp
#include <iostream>

int main() 
{
    // Understanding precedence
    int result1 = 2 + 3 * 4;        // 14, not 20 (multiplication first)
    int result2 = (2 + 3) * 4;      // 20 (parentheses override precedence)
    
    // Multiple operations of same precedence
    int result3 = 10 - 5 - 2;       // 3 (left-to-right associativity)
    int result4 = 2 * 3 * 4;        // 24 (left-to-right associativity)
    
    std::cout << "2 + 3 * 4 = " << result1 << '\n';
    std::cout << "(2 + 3) * 4 = " << result2 << '\n';
    std::cout << "10 - 5 - 2 = " << result3 << '\n';
    std::cout << "2 * 3 * 4 = " << result4 << '\n';
    
    return 0;
}
```

### 6.2 - Unary Operators

#### Increment and Decrement

```cpp
#include <iostream>

int main() 
{
    int x = 5;
    
    std::cout << "Initial x: " << x << '\n';          // 5
    
    // Post-increment: use current value, then increment
    std::cout << "x++: " << x++ << '\n';              // prints 5, x becomes 6
    std::cout << "After x++: " << x << '\n';          // 6
    
    // Pre-increment: increment first, then use new value
    std::cout << "++x: " << ++x << '\n';              // x becomes 7, prints 7
    std::cout << "After ++x: " << x << '\n';          // 7
    
    // Same logic for decrement
    std::cout << "x--: " << x-- << '\n';              // prints 7, x becomes 6
    std::cout << "--x: " << --x << '\n';              // x becomes 5, prints 5
    
    return 0;
}
```

#### Unary Plus and Minus

```cpp
#include <iostream>

int main() 
{
    int positive = 42;
    int negative = -positive;    // Unary minus
    int unchanged = +positive;   // Unary plus (rarely used)
    
    std::cout << "Original: " << positive << '\n';    // 42
    std::cout << "Negated: " << negative << '\n';     // -42
    std::cout << "Unchanged: " << unchanged << '\n';   // 42
    
    // Useful for clarity
    int temperature = -15;       // Negative temperature
    int balance = +1000;         // Positive balance (explicit)
    
    return 0;
}
```

### 6.3 - Assignment Operators

#### Compound Assignment Operators

```cpp
#include <iostream>

int main() 
{
    int score = 100;
    int bonus = 25;
    
    std::cout << "Initial score: " << score << '\n';
    
    // Compound assignment operators
    score += bonus;    // Equivalent to: score = score + bonus
    std::cout << "After += " << bonus << ": " << score << '\n';  // 125
    
    score -= 10;       // Equivalent to: score = score - 10
    std::cout << "After -= 10: " << score << '\n';               // 115
    
    score *= 2;        // Equivalent to: score = score * 2
    std::cout << "After *= 2: " << score << '\n';                // 230
    
    score /= 5;        // Equivalent to: score = score / 5
    std::cout << "After /= 5: " << score << '\n';                // 46
    
    score %= 7;        // Equivalent to: score = score % 7
    std::cout << "After %= 7: " << score << '\n';                // 4
    
    return 0;
}
```

### 6.4 - Comparison Operators

#### Relational Comparisons

```cpp
#include <iostream>

int main() 
{
    int age = 25;
    int votingAge = 18;
    int retirementAge = 65;
    
    // Basic comparisons
    std::cout << std::boolalpha;  // Print true/false instead of 1/0
    
    std::cout << "age == votingAge: " << (age == votingAge) << '\n';      // false
    std::cout << "age != votingAge: " << (age != votingAge) << '\n';      // true
    std::cout << "age >= votingAge: " << (age >= votingAge) << '\n';      // true
    std::cout << "age > votingAge: " << (age > votingAge) << '\n';        // true
    std::cout << "age < retirementAge: " << (age < retirementAge) << '\n'; // true
    std::cout << "age <= retirementAge: " << (age <= retirementAge) << '\n'; // true
    
    return 0;
}
```

#### Floating-Point Comparison Pitfalls

```cpp
#include <iostream>
#include <cmath>

int main() 
{
    double a = 0.1 + 0.2;
    double b = 0.3;
    
    std::cout << std::fixed;
    std::cout << "a = " << a << '\n';                    // 0.300000
    std::cout << "b = " << b << '\n';                    // 0.300000
    std::cout << "a == b: " << (a == b) << '\n';        // false! (floating-point precision)
    
    // Correct way to compare floating-point numbers
    const double epsilon = 1e-9;
    bool areEqual = std::abs(a - b) < epsilon;
    std::cout << "Are they approximately equal? " << areEqual << '\n'; // true
    
    return 0;
}
```

### 6.5 - Logical Operators

#### Boolean Logic

```cpp
#include <iostream>

int main() 
{
    bool hasTicket = true;
    bool hasID = true;
    bool isBanned = false;
    int age = 20;
    
    // Logical AND (&&) - all conditions must be true
    bool canEnterClub = hasTicket && hasID && !isBanned && (age >= 18);
    
    // Logical OR (||) - at least one condition must be true
    bool canGetDiscount = (age < 18) || (age >= 65);
    
    // Logical NOT (!) - negates boolean value
    bool cannotEnter = !canEnterClub;
    
    std::cout << std::boolalpha;
    std::cout << "Can enter club: " << canEnterClub << '\n';       // true
    std::cout << "Can get discount: " << canGetDiscount << '\n';   // false
    std::cout << "Cannot enter: " << cannotEnter << '\n';          // false
    
    return 0;
}
```

#### Short-Circuit Evaluation

```cpp
#include <iostream>

bool expensiveCheck() 
{
    std::cout << "Expensive check called!\n";
    return true;
}

int main() 
{
    bool fastCondition = false;
    
    // Short-circuit: expensiveCheck() is NOT called because fastCondition is false
    if (fastCondition && expensiveCheck()) 
    {
        std::cout << "Both conditions true\n";
    }
    
    fastCondition = true;
    
    // Now expensiveCheck() IS called because fastCondition is true
    if (fastCondition && expensiveCheck()) 
    {
        std::cout << "Both conditions true\n";
    }
    
    return 0;
}
```

---

## Chapter 7: Control Flow - Making Decisions

### 7.1 - Introduction to Control Flow

Control flow statements allow programs to make decisions and repeat actions based on conditions.

### 7.2 - If Statements and Blocks

#### Basic If Statements

```cpp
#include <iostream>

int main() 
{
    int temperature = 75;
    
    // Simple if statement
    if (temperature > 70) 
    {
        std::cout << "It's warm today!\n";
    }
    
    // If-else statement
    int score = 85;
    if (score >= 90) 
    {
        std::cout << "Grade: A\n";
    } 
    else 
    {
        std::cout << "Grade: Not an A\n";
    }
    
    // If-else chain
    if (score >= 90) 
    {
        std::cout << "Excellent!\n";
    } 
    else if (score >= 80) 
    {
        std::cout << "Good job!\n";
    } 
    else if (score >= 70) 
    {
        std::cout << "Passing grade.\n";
    } 
    else 
    {
        std::cout << "Need improvement.\n";
    }
    
    return 0;
}
```

#### Nested If Statements

```cpp
#include <iostream>

int main() 
{
    int age = 25;
    bool hasLicense = true;
    bool hasInsurance = true;
    
    // Nested conditions for car rental eligibility
    if (age >= 18) 
    {
        std::cout << "Age requirement met.\n";
        
        if (hasLicense) 
        {
            std::cout << "License requirement met.\n";
            
            if (hasInsurance) 
            {
                std::cout << "All requirements met! You can rent a car.\n";
            } 
            else 
            {
                std::cout << "Insurance required.\n";
            }
        } 
        else 
        {
            std::cout << "Valid license required.\n";
        }
    } 
    else 
    {
        std::cout << "Must be 18 or older.\n";
    }
    
    return 0;
}
```

### 7.3 - Switch Statements

#### Basic Switch Usage

```cpp
#include <iostream>

int main() 
{
    int dayOfWeek = 3;
    
    switch (dayOfWeek) 
    {
        case 1:
            std::cout << "Monday - Start of work week\n";
            break;
        case 2:
            std::cout << "Tuesday - Getting into the rhythm\n";
            break;
        case 3:
            std::cout << "Wednesday - Hump day!\n";
            break;
        case 4:
            std::cout << "Thursday - Almost there\n";
            break;
        case 5:
            std::cout << "Friday - TGIF!\n";
            break;
        case 6:
        case 7:
            std::cout << "Weekend - Relax time!\n";
            break;
        default:
            std::cout << "Invalid day number\n";
            break;
    }
    
    return 0;
}
```

#### Switch with Fallthrough

```cpp
#include <iostream>

int main() 
{
    char grade = 'B';
    
    std::cout << "Grade " << grade << ": ";
    
    switch (grade) 
    {
        case 'A':
            std::cout << "Excellent! ";
            [[fallthrough]];  // C++17: explicit fallthrough
        case 'B':
            std::cout << "Good work! ";
            [[fallthrough]];
        case 'C':
            std::cout << "Passing grade. ";
            break;
        case 'D':
            std::cout << "Below average. ";
            break;
        case 'F':
            std::cout << "Failing grade. ";
            break;
        default:
            std::cout << "Invalid grade. ";
            break;
    }
    
    std::cout << '\n';
    return 0;
}
```

### 7.4 - Goto Statements (Generally Avoided)

```cpp
#include <iostream>

// Example showing why goto is problematic (don't use in real code!)
int main() 
{
    int attempts = 0;
    
    retry:  // Label
    attempts++;
    
    std::cout << "Attempt " << attempts << '\n';
    
    if (attempts < 3) 
    {
        goto retry;  // Jump to label (creates spaghetti code!)
    }
    
    std::cout << "Done after " << attempts << " attempts\n";
    
    // Better approach would use a loop (covered in Chapter 8)
    
    return 0;
}
```

---

## Chapter 8: Loops - Repeating Actions

### 8.1 - Introduction to Loops

Loops allow us to execute code repeatedly based on conditions.

### 8.2 - While Loops

#### Basic While Loop

```cpp
#include <iostream>

int main() 
{
    // Countdown example
    int countdown = 10;
    
    while (countdown > 0) 
    {
        std::cout << countdown << "... ";
        countdown--;
    }
    std::cout << "Liftoff!\n";
    
    // Input validation example
    int number;
    std::cout << "\nEnter a positive number: ";
    std::cin >> number;
    
    while (number <= 0) 
    {
        std::cout << "Invalid! Please enter a positive number: ";
        std::cin >> number;
    }
    
    std::cout << "You entered: " << number << '\n';
    
    return 0;
}
```

#### Infinite Loops (Controlled)

```cpp
#include <iostream>

int main() 
{
    int userChoice = 0;
    
    while (true)  // Infinite loop
    {
        std::cout << "\nMenu:\n";
        std::cout << "1. Play game\n";
        std::cout << "2. View high scores\n";
        std::cout << "3. Exit\n";
        std::cout << "Choice: ";
        
        std::cin >> userChoice;
        
        if (userChoice == 1) 
        {
            std::cout << "Playing game...\n";
        } 
        else if (userChoice == 2) 
        {
            std::cout << "Showing high scores...\n";
        } 
        else if (userChoice == 3) 
        {
            std::cout << "Goodbye!\n";
            break;  // Exit the infinite loop
        } 
        else 
        {
            std::cout << "Invalid choice!\n";
        }
    }
    
    return 0;
}
```

### 8.3 - Do-While Loops

#### Guaranteed Execution

```cpp
#include <iostream>

int main() 
{
    char playAgain;
    
    do 
    {
        std::cout << "Playing the game...\n";
        std::cout << "Game over!\n";
        
        std::cout << "Play again? (y/n): ";
        std::cin >> playAgain;
        
    } while (playAgain == 'y' || playAgain == 'Y');
    
    std::cout << "Thanks for playing!\n";
    
    // Password verification example
    std::string password;
    const std::string correctPassword = "secret123";
    
    do 
    {
        std::cout << "Enter password: ";
        std::cin >> password;
        
        if (password != correctPassword) 
        {
            std::cout << "Incorrect password!\n";
        }
        
    } while (password != correctPassword);
    
    std::cout << "Access granted!\n";
    
    return 0;
}
```

### 8.4 - For Loops

#### Classic For Loop

```cpp
#include <iostream>

int main() 
{
    // Basic counting
    std::cout << "Counting up: ";
    for (int i = 1; i <= 10; ++i) 
    {
        std::cout << i << " ";
    }
    std::cout << '\n';
    
    // Counting down
    std::cout << "Counting down: ";
    for (int i = 10; i >= 1; --i) 
    {
        std::cout << i << " ";
    }
    std::cout << '\n';
    
    // Different increment
    std::cout << "Even numbers: ";
    for (int i = 2; i <= 20; i += 2) 
    {
        std::cout << i << " ";
    }
    std::cout << '\n';
    
    return 0;
}
```

#### Advanced For Loop Patterns

```cpp
#include <iostream>

int main() 
{
    // Multiple variables
    for (int i = 0, j = 10; i < j; ++i, --j) 
    {
        std::cout << "i=" << i << ", j=" << j << '\n';
    }
    
    // Nested loops (multiplication table)
    std::cout << "\nMultiplication Table:\n";
    for (int row = 1; row <= 5; ++row) 
    {
        for (int col = 1; col <= 5; ++col) 
        {
            std::cout << (row * col) << '\t';
        }
        std::cout << '\n';
    }
    
    return 0;
}
```

### 8.5 - Range-Based For Loops (Modern C++)

```cpp
#include <iostream>
#include <vector>
#include <string>

int main() 
{
    // With arrays
    int numbers[] = {1, 2, 3, 4, 5};
    
    std::cout << "Array elements: ";
    for (int num : numbers) 
    {
        std::cout << num << " ";
    }
    std::cout << '\n';
    
    // With vectors
    std::vector<std::string> names = {"Alice", "Bob", "Charlie", "Diana"};
    
    std::cout << "Names:\n";
    for (const auto& name : names)  // const auto& for efficiency
    {
        std::cout << "- " << name << '\n';
    }
    
    // Modifying elements (use reference)
    std::vector<int> scores = {80, 85, 90, 75, 88};
    
    std::cout << "Original scores: ";
    for (int score : scores) std::cout << score << " ";
    std::cout << '\n';
    
    // Add 5 points bonus to each score
    for (int& score : scores)  // Note the reference (&)
    {
        score += 5;
    }
    
    std::cout << "After bonus: ";
    for (int score : scores) std::cout << score << " ";
    std::cout << '\n';
    
    return 0;
}
```

### 8.6 - Loop Control: Break and Continue

#### Break Statement

```cpp
#include <iostream>

int main() 
{
    // Finding first even number
    std::cout << "Looking for first even number in sequence:\n";
    for (int i = 1; i <= 20; ++i) 
    {
        std::cout << "Checking " << i << "... ";
        
        if (i % 2 == 0) 
        {
            std::cout << "Found it! " << i << " is even.\n";
            break;  // Exit the loop
        }
        
        std::cout << "odd, continue searching.\n";
    }
    
    // Break in nested loops (only breaks inner loop)
    std::cout << "\nNested loop break example:\n";
    for (int i = 1; i <= 3; ++i) 
    {
        std::cout << "Outer loop i=" << i << '\n';
        
        for (int j = 1; j <= 5; ++j) 
        {
            if (j == 3) 
            {
                std::cout << "  Breaking inner loop at j=" << j << '\n';
                break;  // Only breaks inner loop
            }
            std::cout << "  Inner loop j=" << j << '\n';
        }
    }
    
    return 0;
}
```

#### Continue Statement

```cpp
#include <iostream>

int main() 
{
    // Print only odd numbers
    std::cout << "Odd numbers from 1 to 10: ";
    for (int i = 1; i <= 10; ++i) 
    {
        if (i % 2 == 0) 
        {
            continue;  // Skip rest of loop body for even numbers
        }
        
        std::cout << i << " ";
    }
    std::cout << '\n';
    
    // Skip negative numbers in calculation
    int sum = 0;
    int numbers[] = {5, -2, 8, -1, 3, -4, 7};
    
    for (int num : numbers) 
    {
        if (num < 0) 
        {
            std::cout << "Skipping negative number: " << num << '\n';
            continue;
        }
        
        sum += num;
        std::cout << "Adding " << num << ", sum now: " << sum << '\n';
    }
    
    std::cout << "Final sum of positive numbers: " << sum << '\n';
    
    return 0;
}
```

---

## Chapter 9: Functions - Organizing Code

### 9.1 - Introduction to Functions

Functions organize code into reusable, logical units.

### 9.2 - Function Basics

#### Simple Function Definition and Call

```cpp
#include <iostream>

// Function definition
void greetUser() 
{
    std::cout << "Welcome to our program!\n";
    std::cout << "We hope you enjoy using it.\n";
}

int main() 
{
    std::cout << "Program starting...\n";
    
    greetUser();  // Function call
    
    std::cout << "Program continuing...\n";
    
    greetUser();  // Can call multiple times
    
    return 0;
}
```

#### Functions with Parameters

```cpp
#include <iostream>

// Function with parameters
void greetUser(const std::string& name) 
{
    std::cout << "Hello, " << name << "!\n";
    std::cout << "Welcome to our program.\n";
}

void printRectangle(int width, int height) 
{
    for (int row = 0; row < height; ++row) 
    {
        for (int col = 0; col < width; ++col) 
        {
            std::cout << "* ";
        }
        std::cout << '\n';
    }
}

int main() 
{
    greetUser("Alice");
    greetUser("Bob");
    
    std::cout << "\nDrawing rectangles:\n";
    printRectangle(5, 3);
    
    std::cout << '\n';
    printRectangle(3, 4);
    
    return 0;
}
```

### 9.3 - Return Values

#### Functions That Return Values

```cpp
#include <iostream>
#include <cmath>

// Function returning a value
int add(int a, int b) 
{
    return a + b;
}

double calculateCircleArea(double radius) 
{
    return M_PI * radius * radius;
}

bool isEven(int number) 
{
    return (number % 2) == 0;
}

// Function with multiple return paths
std::string getGrade(int score) 
{
    if (score >= 90) return "A";
    if (score >= 80) return "B";
    if (score >= 70) return "C";
    if (score >= 60) return "D";
    return "F";
}

int main() 
{
    // Using return values
    int sum = add(15, 25);
    std::cout << "Sum: " << sum << '\n';
    
    double area = calculateCircleArea(5.0);
    std::cout << "Circle area: " << area << '\n';
    
    int testNumber = 42;
    if (isEven(testNumber)) 
    {
        std::cout << testNumber << " is even\n";
    } 
    else 
    {
        std::cout << testNumber << " is odd\n";
    }
    
    int studentScore = 87;
    std::cout << "Grade for " << studentScore << ": " << getGrade(studentScore) << '\n';
    
    return 0;
}
```

### 9.4 - Function Parameters and Arguments

#### Pass by Value vs Pass by Reference

```cpp
#include <iostream>

// Pass by value (makes a copy)
void modifyValue(int x) 
{
    x = x * 2;
    std::cout << "Inside function, x = " << x << '\n';
}

// Pass by reference (works with original variable)
void modifyReference(int& x) 
{
    x = x * 2;
    std::cout << "Inside function, x = " << x << '\n';
}

// Pass by const reference (efficient, safe)
void printValue(const int& x) 
{
    std::cout << "Value is: " << x << '\n';
    // x = 10;  // Error! Can't modify const reference
}

int main() 
{
    int number = 10;
    
    std::cout << "Original number: " << number << '\n';
    
    modifyValue(number);  // Pass by value
    std::cout << "After modifyValue: " << number << '\n';  // Unchanged
    
    modifyReference(number);  // Pass by reference
    std::cout << "After modifyReference: " << number << '\n';  // Changed!
    
    printValue(number);  // Efficient const reference
    
    return 0;
}
```

#### Default Parameters

```cpp
#include <iostream>

// Functions with default parameters
void printMessage(const std::string& message, int times = 1) 
{
    for (int i = 0; i < times; ++i) 
    {
        std::cout << message << '\n';
    }
}

double calculatePower(double base, double exponent = 2.0) 
{
    return std::pow(base, exponent);
}

void displayStudentInfo(const std::string& name, 
                       const std::string& major = "Undeclared", 
                       int year = 1) 
{
    std::cout << "Student: " << name << '\n';
    std::cout << "Major: " << major << '\n';
    std::cout << "Year: " << year << '\n';
    std::cout << "---\n";
}

int main() 
{
    // Using default parameters
    printMessage("Hello World");          // times = 1 (default)
    printMessage("Repeat this", 3);       // times = 3
    
    std::cout << "2^2 = " << calculatePower(2) << '\n';      // exponent = 2.0 (default)
    std::cout << "2^3 = " << calculatePower(2, 3) << '\n';   // exponent = 3
    
    displayStudentInfo("Alice");                                    // All defaults
    displayStudentInfo("Bob", "Computer Science");                  // year = 1 (default)
    displayStudentInfo("Charlie", "Mathematics", 3);               // No defaults
    
    return 0;
}
```

### 9.5 - Local Variables and Scope

#### Variable Scope and Lifetime

```cpp
#include <iostream>

int globalVariable = 100;  // Global scope

void demonstrateScope() 
{
    int localVar = 50;     // Local to this function
    
    std::cout << "Inside function:\n";
    std::cout << "  Local variable: " << localVar << '\n';
    std::cout << "  Global variable: " << globalVariable << '\n';
    
    // Block scope
    {
        int blockVar = 25;  // Only exists in this block
        localVar = 75;      // Can modify outer local variable
        
        std::cout << "  Inside block:\n";
        std::cout << "    Block variable: " << blockVar << '\n';
        std::cout << "    Modified local: " << localVar << '\n';
    }
    // blockVar no longer exists here
    
    std::cout << "  After block, local: " << localVar << '\n';
}

void anotherFunction() 
{
    // int x = localVar;  // Error! localVar not in scope
    int x = globalVariable;  // OK, global variables accessible everywhere
    
    std::cout << "Another function can access global: " << x << '\n';
}

int main() 
{
    std::cout << "In main, global variable: " << globalVariable << '\n';
    
    demonstrateScope();
    anotherFunction();
    
    return 0;
}
```

#### Variable Shadowing

```cpp
#include <iostream>

int value = 10;  // Global variable

void demonstrateShadowing() 
{
    int value = 20;  // Local variable shadows global
    
    std::cout << "Local value: " << value << '\n';          // 20
    std::cout << "Global value: " << ::value << '\n';       // 10 (scope resolution operator)
    
    {
        int value = 30;  // Block variable shadows both global and function-local
        std::cout << "Block value: " << value << '\n';      // 30
    }
    
    std::cout << "Back to local value: " << value << '\n';  // 20
}

int main() 
{
    std::cout << "Global value: " << value << '\n';         // 10
    demonstrateShadowing();
    std::cout << "Still global value: " << value << '\n';   // 10
    
    return 0;
}
```

### 9.6 - Function Overloading

#### Multiple Functions with Same Name

```cpp
#include <iostream>
#include <string>

// Overloaded functions - same name, different parameters
int add(int a, int b) 
{
    std::cout << "Adding integers: ";
    return a + b;
}

double add(double a, double b) 
{
    std::cout << "Adding doubles: ";
    return a + b;
}

std::string add(const std::string& a, const std::string& b) 
{
    std::cout << "Concatenating strings: ";
    return a + b;
}

// Overloaded print functions
void print(int value) 
{
    std::cout << "Integer: " << value << '\n';
}

void print(double value) 
{
    std::cout << "Double: " << value << '\n';
}

void print(const std::string& value) 
{
    std::cout << "String: " << value << '\n';
}

void print(bool value) 
{
    std::cout << "Boolean: " << (value ? "true" : "false") << '\n';
}

int main() 
{
    // Compiler chooses correct overload based on arguments
    std::cout << add(5, 10) << '\n';           // Calls int version
    std::cout << add(3.14, 2.86) << '\n';     // Calls double version
    std::cout << add(std::string("Hello "), std::string("World")) << '\n'; // Calls string version
    
    std::cout << '\n';
    
    // Compiler determines type and calls appropriate print function
    print(42);                    // int version
    print(3.14159);              // double version
    print("Hello World");        // string version
    print(true);                 // bool version
    
    return 0;
}
```

---

## Chapter 10: Advanced Functions - Professional Techniques

### 10.1 - Function Pointers

#### Basic Function Pointers

```cpp
#include <iostream>

// Functions to demonstrate function pointers
int add(int a, int b) 
{
    return a + b;
}

int multiply(int a, int b) 
{
    return a * b;
}

int subtract(int a, int b) 
{
    return a - b;
}

// Function that takes a function pointer as parameter
int calculate(int x, int y, int (*operation)(int, int)) 
{
    return operation(x, y);
}

int main() 
{
    // Declare function pointer
    int (*mathOperation)(int, int);
    
    // Assign function to pointer
    mathOperation = add;
    std::cout << "Addition: " << mathOperation(10, 5) << '\n';  // 15
    
    mathOperation = multiply;
    std::cout << "Multiplication: " << mathOperation(10, 5) << '\n';  // 50
    
    mathOperation = subtract;
    std::cout << "Subtraction: " << mathOperation(10, 5) << '\n';  // 5
    
    // Using function pointers with other functions
    std::cout << "Using calculate function:\n";
    std::cout << "Add: " << calculate(8, 3, add) << '\n';
    std::cout << "Multiply: " << calculate(8, 3, multiply) << '\n';
    std::cout << "Subtract: " << calculate(8, 3, subtract) << '\n';
    
    return 0;
}
```

#### Function Pointer Arrays (Simple Calculator)

```cpp
#include <iostream>

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return (b != 0) ? a / b : 0; }

int main() 
{
    // Array of function pointers
    int (*operations[])(int, int) = {add, subtract, multiply, divide};
    const char* operatorNames[] = {"+", "-", "*", "/"};
    
    int a = 12, b = 3;
    
    std::cout << "Calculator using function pointer array:\n";
    for (int i = 0; i < 4; ++i) 
    {
        int result = operations[i](a, b);
        std::cout << a << " " << operatorNames[i] << " " << b << " = " << result << '\n';
    }
    
    // Interactive calculator
    std::cout << "\nInteractive Calculator:\n";
    std::cout << "0: Add, 1: Subtract, 2: Multiply, 3: Divide\n";
    
    int x, y, choice;
    std::cout << "Enter two numbers: ";
    std::cin >> x >> y;
    std::cout << "Choose operation (0-3): ";
    std::cin >> choice;
    
    if (choice >= 0 && choice <= 3) 
    {
        int result = operations[choice](x, y);
        std::cout << "Result: " << x << " " << operatorNames[choice] << " " << y 
                  << " = " << result << '\n';
    } 
    else 
    {
        std::cout << "Invalid choice!\n";
    }
    
    return 0;
}
```

### 10.2 - std::function and Lambdas (Modern C++)

#### Introduction to std::function

```cpp
#include <iostream>
#include <functional>

// Regular functions
int add(int a, int b) 
{
    return a + b;
}

int multiply(int a, int b) 
{
    return a * b;
}

// Function that accepts std::function
void executeOperation(int x, int y, std::function<int(int, int)> op) 
{
    std::cout << "Result: " << op(x, y) << '\n';
}

int main() 
{
    // std::function can hold any callable
    std::function<int(int, int)> operation;
    
    // Assign regular function
    operation = add;
    executeOperation(5, 3, operation);  // 8
    
    operation = multiply;
    executeOperation(5, 3, operation);  // 15
    
    // Assign lambda function (C++11)
    operation = [](int a, int b) { return a - b; };
    executeOperation(5, 3, operation);  // 2
    
    return 0;
}
```

#### Lambda Functions

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() 
{
    // Basic lambda syntax: [capture](parameters) { body }
    auto simpleLambda = []() 
    {
        std::cout << "Hello from lambda!\n";
    };
    simpleLambda();
    
    // Lambda with parameters
    auto addLambda = [](int a, int b) 
    {
        return a + b;
    };
    std::cout << "Lambda addition: " << addLambda(10, 5) << '\n';
    
    // Lambda with capture
    int multiplier = 3;
    auto multiplyBy = [multiplier](int value) 
    {
        return value * multiplier;
    };
    std::cout << "Multiply by " << multiplier << ": " << multiplyBy(7) << '\n';
    
    // Using lambdas with STL algorithms
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Count even numbers
    int evenCount = std::count_if(numbers.begin(), numbers.end(), 
                                  [](int n) { return n % 2 == 0; });
    std::cout << "Even numbers count: " << evenCount << '\n';
    
    // Transform all numbers (multiply by 2)
    std::vector<int> doubled(numbers.size());
    std::transform(numbers.begin(), numbers.end(), doubled.begin(),
                   [](int n) { return n * 2; });
    
    std::cout << "Original: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << '\n';
    
    std::cout << "Doubled: ";
    for (int n : doubled) std::cout << n << " ";
    std::cout << '\n';
    
    return 0;
}
```

### 10.3 - Recursion

#### Basic Recursion Examples

```cpp
#include <iostream>

// Factorial calculation using recursion
int factorial(int n) 
{
    // Base case
    if (n <= 1) 
    {
        return 1;
    }
    
    // Recursive case
    return n * factorial(n - 1);
}

// Fibonacci sequence using recursion
int fibonacci(int n) 
{
    // Base cases
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Power calculation using recursion
double power(double base, int exponent) 
{
    // Base case
    if (exponent == 0) 
    {
        return 1.0;
    }
    
    // Handle negative exponents
    if (exponent < 0) 
    {
        return 1.0 / power(base, -exponent);
    }
    
    // Recursive case
    return base * power(base, exponent - 1);
}

int main() 
{
    // Test factorial
    std::cout << "Factorial examples:\n";
    for (int i = 1; i <= 6; ++i) 
    {
        std::cout << i << "! = " << factorial(i) << '\n';
    }
    
    // Test Fibonacci
    std::cout << "\nFibonacci sequence:\n";
    for (int i = 0; i <= 10; ++i) 
    {
        std::cout << "F(" << i << ") = " << fibonacci(i) << '\n';
    }
    
    // Test power function
    std::cout << "\nPower examples:\n";
    std::cout << "2^5 = " << power(2, 5) << '\n';
    std::cout << "3^4 = " << power(3, 4) << '\n';
    std::cout << "5^0 = " << power(5, 0) << '\n';
    std::cout << "2^(-3) = " << power(2, -3) << '\n';
    
    return 0;
}
```

#### More Complex Recursion: Tree Traversal Simulation

```cpp
#include <iostream>
#include <string>

// Simulate a simple directory structure traversal
void printIndentation(int depth) 
{
    for (int i = 0; i < depth; ++i) 
    {
        std::cout << "  ";
    }
}

void traverseDirectory(const std::string& name, int depth = 0) 
{
    printIndentation(depth);
    std::cout << name << "/\n";
    
    // Base case - simulate maximum depth
    if (depth >= 3) 
    {
        return;
    }
    
    // Simulate subdirectories (recursive calls)
    if (name == "root") 
    {
        traverseDirectory("home", depth + 1);
        traverseDirectory("etc", depth + 1);
        traverseDirectory("var", depth + 1);
    } 
    else if (name == "home") 
    {
        traverseDirectory("user1", depth + 1);
        traverseDirectory("user2", depth + 1);
    } 
    else if (name == "user1") 
    {
        printIndentation(depth + 1);
        std::cout << "documents.txt\n";
        printIndentation(depth + 1);
        std::cout << "photos.jpg\n";
    }
}

// Tower of Hanoi puzzle solution
void towerOfHanoi(int disks, char source, char destination, char auxiliary) 
{
    // Base case
    if (disks == 1) 
    {
        std::cout << "Move disk 1 from " << source << " to " << destination << '\n';
        return;
    }
    
    // Move n-1 disks from source to auxiliary
    towerOfHanoi(disks - 1, source, auxiliary, destination);
    
    // Move the bottom disk from source to destination
    std::cout << "Move disk " << disks << " from " << source << " to " << destination << '\n';
    
    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(disks - 1, auxiliary, destination, source);
}

int main() 
{
    std::cout << "Directory traversal simulation:\n";
    traverseDirectory("root");
    
    std::cout << "\nTower of Hanoi solution (3 disks):\n";
    towerOfHanoi(3, 'A', 'C', 'B');
    
    return 0;
}
```

### 10.4 - Advanced Function Techniques

#### Function Templates

```cpp
#include <iostream>
#include <string>

// Function template - works with any type
template<typename T>
T getMax(T a, T b) 
{
    return (a > b) ? a : b;
}

// Function template with multiple type parameters
template<typename T, typename U>
void printPair(T first, U second) 
{
    std::cout << "(" << first << ", " << second << ")\n";
}

// Template specialization for strings
template<>
std::string getMax<std::string>(std::string a, std::string b) 
{
    std::cout << "Using specialized string version\n";
    return (a.length() > b.length()) ? a : b;
}

int main() 
{
    // Template automatically deduces types
    std::cout << "Max of 10 and 20: " << getMax(10, 20) << '\n';           // int
    std::cout << "Max of 3.14 and 2.71: " << getMax(3.14, 2.71) << '\n';   // double
    std::cout << "Max of 'a' and 'z': " << getMax('a', 'z') << '\n';       // char
    
    // Using specialized template
    std::cout << "Max string: " << getMax(std::string("hello"), std::string("world")) << '\n';
    
    // Multiple template parameters
    printPair(10, "hello");        // int, string
    printPair(3.14, true);         // double, bool
    printPair("name", 42);         // string, int
    
    return 0;
}
```

#### Variadic Templates (C++11) - Advanced

```cpp
#include <iostream>

// Base case for recursion
void print() 
{
    std::cout << '\n';
}

// Variadic template function
template<typename T, typename... Args>
void print(T first, Args... args) 
{
    std::cout << first << " ";
    print(args...);  // Recursive call with remaining arguments
}

// Variadic template for sum calculation
template<typename T>
T sum(T value) 
{
    return value;
}

template<typename T, typename... Args>
T sum(T first, Args... args) 
{
    return first + sum(args...);
}

int main() 
{
    // Print function with variable arguments
    print("Hello", "World", 42, 3.14, true);
    print(1, 2, 3, 4, 5);
    print("Just one argument");
    
    // Sum function with variable arguments
    std::cout << "Sum of integers: " << sum(1, 2, 3, 4, 5) << '\n';
    std::cout << "Sum of doubles: " << sum(1.1, 2.2, 3.3) << '\n';
    
    return 0;
}
```

### 10.5 - Best Practices and Common Patterns

#### Input Validation Functions

```cpp
#include <iostream>
#include <limits>
#include <string>

// Robust input validation
int getValidInteger(const std::string& prompt, int min = INT_MIN, int max = INT_MAX) 
{
    int value;
    
    while (true) 
    {
        std::cout << prompt;
        std::cin >> value;
        
        // Check for input failure
        if (std::cin.fail()) 
        {
            std::cin.clear();  // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear buffer
            std::cout << "Invalid input! Please enter a number.\n";
            continue;
        }
        
        // Clear any remaining characters
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        // Check range
        if (value < min || value > max) 
        {
            std::cout << "Value must be between " << min << " and " << max << ".\n";
            continue;
        }
        
        return value;
    }
}

char getValidChoice(const std::string& prompt, const std::string& validChoices) 
{
    char choice;
    
    while (true) 
    {
        std::cout << prompt;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        // Convert to lowercase for comparison
        choice = std::tolower(choice);
        
        if (validChoices.find(choice) != std::string::npos) 
        {
            return choice;
        }
        
        std::cout << "Invalid choice! Valid options: " << validChoices << '\n';
    }
}

int main() 
{
    // Test input validation
    int age = getValidInteger("Enter your age (1-120): ", 1, 120);
    std::cout << "You entered: " << age << '\n';
    
    char choice = getValidChoice("Continue? (y/n): ", "yn");
    std::cout << "You chose: " << choice << '\n';
    
    if (choice == 'y') 
    {
        int score = getValidInteger("Enter test score (0-100): ", 0, 100);
        std::cout << "Your score: " << score << '\n';
    }
    
    return 0;
}
```

#### Error Handling Patterns

```cpp
#include <iostream>
#include <optional>  // C++17
#include <string>

// Function that might fail - returns optional
std::optional<double> safeDivide(double numerator, double denominator) 
{
    if (denominator == 0.0) 
    {
        return std::nullopt;  // Indicate failure
    }
    return numerator / denominator;
}

// Error handling with return codes
enum class MathError 
{
    None,
    DivisionByZero,
    NegativeSquareRoot,
    InvalidInput
};

MathError safeSquareRoot(double input, double& result) 
{
    if (input < 0) 
    {
        return MathError::NegativeSquareRoot;
    }
    
    result = std::sqrt(input);
    return MathError::None;
}

// Utility function for error messages
std::string errorToString(MathError error) 
{
    switch (error) 
    {
        case MathError::None: return "No error";
        case MathError::DivisionByZero: return "Division by zero";
        case MathError::NegativeSquareRoot: return "Negative square root";
        case MathError::InvalidInput: return "Invalid input";
        default: return "Unknown error";
    }
}

int main() 
{
    // Using optional return values
    auto result1 = safeDivide(10.0, 2.0);
    if (result1.has_value()) 
    {
        std::cout << "Division result: " << result1.value() << '\n';
    } 
    else 
    {
        std::cout << "Division failed!\n";
    }
    
    auto result2 = safeDivide(10.0, 0.0);
    if (!result2.has_value()) 
    {
        std::cout << "Cannot divide by zero!\n";
    }
    
    // Using error codes
    double sqrtResult;
    MathError error = safeSquareRoot(16.0, sqrtResult);
    
    if (error == MathError::None) 
    {
        std::cout << "Square root: " << sqrtResult << '\n';
    } 
    else 
    {
        std::cout << "Error: " << errorToString(error) << '\n';
    }
    
    // Test with negative number
    error = safeSquareRoot(-4.0, sqrtResult);
    if (error != MathError::None) 
    {
        std::cout << "Error: " << errorToString(error) << '\n';
    }
    
    return 0;
}
```

---

## Real-World Applications and Advanced Patterns

### Menu-Driven Program Architecture

```cpp
#include <iostream>
#include <functional>
#include <map>
#include <string>

class Calculator 
{
private:
    std::map<char, std::function<double(double, double)>> operations;
    
    void initializeOperations() 
    {
        operations['+'] = [](double a, double b) { return a + b; };
        operations['-'] = [](double a, double b) { return a - b; };
        operations['*'] = [](double a, double b) { return a * b; };
        operations['/'] = [](double a, double b) 
        {
            if (b == 0) throw std::runtime_error("Division by zero");
            return a / b;
        };
    }
    
public:
    Calculator() 
    {
        initializeOperations();
    }
    
    void showMenu() 
    {
        std::cout << "\n=== Calculator Menu ===\n";
        std::cout << "1. Perform calculation\n";
        std::cout << "2. List operations\n";
        std::cout << "3. Exit\n";
        std::cout << "Choice: ";
    }
    
    void listOperations() 
    {
        std::cout << "Available operations: ";
        for (const auto& op : operations) 
        {
            std::cout << op.first << " ";
        }
        std::cout << '\n';
    }
    
    void performCalculation() 
    {
        double a, b;
        char op;
        
        std::cout << "Enter first number: ";
        std::cin >> a;
        
        std::cout << "Enter operator: ";
        std::cin >> op;
        
        std::cout << "Enter second number: ";
        std::cin >> b;
        
        try 
        {
            if (operations.find(op) != operations.end()) 
            {
                double result = operations[op](a, b);
                std::cout << a << " " << op << " " << b << " = " << result << '\n';
            } 
            else 
            {
                std::cout << "Unknown operator: " << op << '\n';
            }
        } 
        catch (const std::exception& e) 
        {
            std::cout << "Error: " << e.what() << '\n';
        }
    }
    
    void run() 
    {
        int choice;
        
        while (true) 
        {
            showMenu();
            std::cin >> choice;
            
            switch (choice) 
            {
                case 1:
                    performCalculation();
                    break;
                case 2:
                    listOperations();
                    break;
                case 3:
                    std::cout << "Goodbye!\n";
                    return;
                default:
                    std::cout << "Invalid choice!\n";
                    break;
            }
        }
    }
};

int main() 
{
    Calculator calc;
    calc.run();
    
    return 0;
}
```

### Modern C++ Function Utilities

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>

// Higher-order functions demonstration
class FunctionUtils 
{
public:
    // Apply function to all elements
    template<typename Container, typename Function>
    static void forEach(Container& container, Function func) 
    {
        for (auto& element : container) 
        {
            func(element);
        }
    }
    
    // Filter elements based on predicate
    template<typename Container, typename Predicate>
    static Container filter(const Container& container, Predicate pred) 
    {
        Container result;
        std::copy_if(container.begin(), container.end(), 
                    std::back_inserter(result), pred);
        return result;
    }
    
    // Transform elements
    template<typename InputContainer, typename OutputContainer, typename Transform>
    static OutputContainer map(const InputContainer& input, Transform transform) 
    {
        OutputContainer result;
        std::transform(input.begin(), input.end(), 
                      std::back_inserter(result), transform);
        return result;
    }
    
    // Reduce/fold operation
    template<typename Container, typename T, typename BinaryOp>
    static T reduce(const Container& container, T init, BinaryOp op) 
    {
        return std::accumulate(container.begin(), container.end(), init, op);
    }
};

int main() 
{
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    std::cout << "Original numbers: ";
    FunctionUtils::forEach(numbers, [](int n) { std::cout << n << " "; });
    std::cout << '\n';
    
    // Filter even numbers
    auto evenNumbers = FunctionUtils::filter(numbers, 
        [](int n) { return n % 2 == 0; });
    
    std::cout << "Even numbers: ";
    FunctionUtils::forEach(evenNumbers, [](int n) { std::cout << n << " "; });
    std::cout << '\n';
    
    // Transform to squares
    std::vector<int> squares = FunctionUtils::map<std::vector<int>, std::vector<int>>(
        numbers, [](int n) { return n * n; });
    
    std::cout << "Squares: ";
    FunctionUtils::forEach(squares, [](int n) { std::cout << n << " "; });
    std::cout << '\n';
    
    // Reduce to sum
    int sum = FunctionUtils::reduce(numbers, 0, 
        [](int acc, int n) { return acc + n; });
    
    std::cout << "Sum: " << sum << '\n';
    
    // Reduce to product
    int product = FunctionUtils::reduce(numbers, 1, 
        [](int acc, int n) { return acc * n; });
    
    std::cout << "Product: " << product << '\n';
    
    return 0;
}
```

---

## Best Practices Summary

### Do's ✅

1. **Use meaningful function names**:
```cpp
bool isValidEmail(const std::string& email);  // ✅ Clear purpose
```

2. **Keep functions focused and small**:
```cpp
void validateInput();   // ✅ Single responsibility
void processData();     // ✅ Single responsibility
```

3. **Use const references for large objects**:
```cpp
void process(const std::vector<int>& data);  // ✅ Efficient
```

4. **Prefer return values over output parameters**:
```cpp
int calculateSum(const std::vector<int>& numbers);  // ✅ Clear interface
```

5. **Use function templates for generic algorithms**:
```cpp
template<typename T>
T findMax(const std::vector<T>& data);  // ✅ Reusable
```

### Don'ts ❌

1. **Don't use global variables when parameters suffice**:
```cpp
int globalCounter;  // ❌ Avoid global state
void increment() { globalCounter++; }  // ❌ Hidden dependency
```

2. **Don't make functions too long**:
```cpp
void doEverything() {  // ❌ Too many responsibilities
    // 100+ lines of code
}
```

3. **Don't ignore return values**:
```cpp
getString();  // ❌ Ignoring potential error or result
```

4. **Don't use raw function pointers when std::function is available**:
```cpp
int (*oldStyle)(int, int);  // ❌ C-style
std::function<int(int, int)> modernStyle;  // ✅ C++ style
```

### Modern C++ Features to Embrace

```cpp
// C++11: auto keyword
auto result = calculateValue();  // ✅ Type deduction

// C++11: Lambda functions
auto isEven = [](int n) { return n % 2 == 0; };  // ✅ Inline functions

// C++14: Generic lambdas
auto printer = [](const auto& value) { std::cout << value; };  // ✅ Generic

// C++17: std::optional for error handling
std::optional<int> safeParse(const std::string& str);  // ✅ Safe returns

// C++20: Concepts for template constraints
template<typename T>
requires std::integral<T>
T add(T a, T b) { return a + b; }  // ✅ Constrained templates
```

---

## Conclusion

Chapters 6-10 provide the essential building blocks for creating structured, efficient C++ programs:

- **Operators** - The tools for computation and comparison
- **Control Flow** - Decision-making with if/switch statements  
- **Loops** - Repeating actions efficiently
- **Functions** - Organizing code into reusable, logical units
- **Advanced Techniques** - Modern C++ features for professional development

These concepts enable you to:
- Write interactive programs that respond to user input
- Make complex decisions based on multiple conditions
- Process large amounts of data efficiently
- Create modular, maintainable code
- Handle errors gracefully
- Use modern C++ features for cleaner, safer code

**Next: Chapter 11-12 - Arrays, Vectors, and Memory Management**

# Chapter 11: Function Overloading and Templates

## Building from Constexpr: The Need for Generic Programming

In Chapter F, we learned about constexpr functions that can execute at compile-time. But what happens when we need the same functionality for different types? This is where function templates become essential, providing the missing piece for truly generic programming.

---

## 11.1 - Introduction to Function Overloading

### The Basic Problem

Consider this simple function:

```cpp
int add(int x, int y) 
{
    return x + y;
}
```

This works great for integers, but what about floating-point numbers? You'd need to create separate functions:

```cpp
int add(int x, int y) 
{
    return x + y;
}

double add(double x, double y) 
{
    return x + y;
}

float add(float x, float y) 
{
    return x + y;
}
```

### Function Overloading Rules

**Function overloading** allows multiple functions with the same name, provided they have different parameter types:

```cpp
#include <iostream>

// Overloaded functions for different types
void print(int value) 
{
    std::cout << "Printing int: " << value << '\n';
}

void print(double value) 
{
    std::cout << "Printing double: " << value << '\n';
}

void print(const std::string& value) 
{
    std::cout << "Printing string: " << value << '\n';
}

int main() 
{
    print(42);           // Calls print(int)
    print(3.14);         // Calls print(double)
    print("Hello");      // Calls print(const std::string&)
    return 0;
}
```

### Overloading Rules:
- ✅ **Different parameter types**
- ✅ **Different number of parameters**
- ✅ **Different parameter order** (if types differ)
- ❌ **Return type alone** (not sufficient for overloading)

---

## 11.2 - Function Overload Resolution

### How the Compiler Chooses

When you call an overloaded function, the compiler uses **overload resolution** to determine which function to call:

```cpp
void func(int x) { std::cout << "int version\n"; }
void func(double x) { std::cout << "double version\n"; }
void func(const std::string& x) { std::cout << "string version\n"; }

int main() 
{
    func(42);        // Exact match: calls func(int)
    func(3.14);      // Exact match: calls func(double)
    func(42.0f);     // Promotion: float→double, calls func(double)
    func("Hello");   // Conversion: const char*→std::string, calls func(const std::string&)
    return 0;
}
```

### Resolution Priority:
1. **Exact match** (including const/reference conversions)
2. **Promotions** (int→long, float→double)
3. **Standard conversions** (int→double, derived→base)
4. **User-defined conversions**
5. **Ellipsis matches**

---

## 11.6 - Function Templates: The Generic Solution

### The Problem with Overloading

Writing multiple overloads is a maintenance nightmare:

```cpp
// Repetitive and error-prone!
int max(int x, int y) { return (x < y) ? y : x; }
double max(double x, double y) { return (x < y) ? y : x; }
float max(float x, float y) { return (x < y) ? y : x; }
long max(long x, long y) { return (x < y) ? y : x; }
// ... and so on for every type!
```

### Enter Function Templates

A **function template** is a blueprint that generates functions for different types:

```cpp
template <typename T>
T max(T x, T y) 
{
    return (x < y) ? y : x;
}

int main() 
{
    std::cout << max<int>(5, 3) << '\n';      // Generates max<int>
    std::cout << max<double>(2.7, 4.1) << '\n'; // Generates max<double>
    std::cout << max<char>('a', 'z') << '\n';    // Generates max<char>
    return 0;
}
```

### Template Syntax Breakdown

```cpp
template <typename T>  // Template parameter declaration
T max(T x, T y)       // Function template definition
{
    return (x < y) ? y : x;
}
```

- `template` - Keyword indicating this is a template
- `<typename T>` - Template parameter list (T is a placeholder type)
- `T` - Can be replaced with any actual type
- `typename` - Preferred over `class` (both work the same)

---

## 11.7 - Function Template Instantiation

### How Templates Work

Templates don't generate code until they're used. When you call a template function, the compiler performs **instantiation**:

```cpp
template <typename T>
T square(T x) 
{
    return x * x;
}

int main() 
{
    auto result1 = square<int>(5);    // Instantiates square<int>
    auto result2 = square<double>(3.14); // Instantiates square<double>
    return 0;
}
```

The compiler essentially generates these functions:

```cpp
// Generated by the compiler
int square<int>(int x) 
{
    return x * x;
}

double square<double>(double x) 
{
    return x * x;
}
```

### Template Argument Deduction

You usually don't need to specify the template type explicitly:

```cpp
template <typename T>
T add(T x, T y) 
{
    return x + y;
}

int main() 
{
    // All equivalent calls:
    auto result1 = add<int>(5, 3);    // Explicit template argument
    auto result2 = add<>(5, 3);       // Empty angle brackets
    auto result3 = add(5, 3);         // Template argument deduction (preferred)
    
    return 0;
}
```

### Template Argument Deduction Rules

The compiler deduces template arguments from function arguments:

```cpp
template <typename T>
void print(T value) 
{
    std::cout << value << '\n';
}

int main() 
{
    print(42);        // T deduced as int
    print(3.14);      // T deduced as double
    print("Hello");   // T deduced as const char*
    print('A');       // T deduced as char
    return 0;
}
```

---

## 11.8 - Function Templates with Multiple Template Types

### The Limitation of Single Type Templates

```cpp
template <typename T>
T max(T x, T y)  // Both parameters must be the same type!
{
    return (x < y) ? y : x;
}

int main() 
{
    // max(5, 3.14); // ❌ ERROR: Can't deduce T (int vs double)
    return 0;
}
```

### Solution: Multiple Template Parameters

```cpp
template <typename T, typename U>
auto max(T x, U y) -> decltype(x < y ? y : x)  // C++11 trailing return type
{
    return (x < y) ? y : x;
}

// Or in C++14+, simply:
template <typename T, typename U>
auto max(T x, U y) 
{
    return (x < y) ? y : x;
}

int main() 
{
    std::cout << max(5, 3.14) << '\n';    // T=int, U=double, returns double
    std::cout << max(2.5, 1) << '\n';     // T=double, U=int, returns double
    return 0;
}
```

### Advanced Template Techniques

#### Template Specialization for Type Safety

```cpp
#include <iostream>
#include <string>

template <typename T>
T addOne(T x) 
{
    return x + 1;
}

// Specialized version for strings - delete to prevent compilation
template <>
std::string addOne<std::string>(std::string x) = delete;

int main() 
{
    std::cout << addOne(5) << '\n';       // ✅ Works: returns 6
    std::cout << addOne(3.14) << '\n';    // ✅ Works: returns 4.14
    // addOne(std::string("Hello"));      // ❌ Compile error: function deleted
    return 0;
}
```

---

## Advanced Template Features

### Constexpr Function Templates

Combining templates with constexpr for compile-time generic programming:

```cpp
template <typename T>
constexpr T factorial(T n) 
{
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main() 
{
    constexpr int fact5 = factorial(5);        // Computed at compile-time
    constexpr long fact10 = factorial(10L);    // Different type, still compile-time
    
    std::cout << "5! = " << fact5 << '\n';
    std::cout << "10! = " << fact10 << '\n';
    return 0;
}
```

### Template with Non-Template Parameters

```cpp
template <typename T>
void repeat(T value, int times = 1) 
{
    for (int i = 0; i < times; ++i) 
    {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}

int main() 
{
    repeat("Hello", 3);    // Template: T=const char*, Non-template: times=3
    repeat(42, 2);         // Template: T=int, Non-template: times=2
    repeat(3.14);          // Template: T=double, Non-template: times=1 (default)
    return 0;
}
```

### Template Parameter Naming Conventions

```cpp
// Simple, obvious usage - single letters
template <typename T>
T simple(T value) { return value; }

template <typename T, typename U, typename V>
auto complex(T a, U b, V c) { return a + b + c; }

// Complex usage - descriptive names
template <typename Container, typename Predicate>
void processIf(Container& container, Predicate pred) 
{
    // Implementation...
}

// Standard library style
template <typename InputIt, typename OutputIt, typename Comparator>
OutputIt customSort(InputIt first, InputIt last, OutputIt result, Comparator comp)
{
    // Implementation...
}
```

---

## Real-World Applications

### Generic Algorithms

```cpp
template <typename T>
void bubbleSort(T arr[], int size) 
{
    for (int i = 0; i < size - 1; ++i) 
    {
        for (int j = 0; j < size - i - 1; ++j) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() 
{
    int intArr[] = {64, 34, 25, 12, 22, 11, 90};
    double doubleArr[] = {3.1, 2.5, 1.8, 4.2};
    
    bubbleSort(intArr, 7);        // Works with int
    bubbleSort(doubleArr, 4);     // Works with double
    
    return 0;
}
```

### Type-Safe Containers

```cpp
template <typename T>
class SimpleVector 
{
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    explicit SimpleVector(size_t initialCapacity = 10) 
        : data(new T[initialCapacity]), size(0), capacity(initialCapacity) {}
    
    ~SimpleVector() { delete[] data; }
    
    void push_back(const T& item) 
    {
        if (size >= capacity) resize();
        data[size++] = item;
    }
    
    T& operator[](size_t index) { return data[index]; }
    const T& operator[](size_t index) const { return data[index]; }
    
    size_t getSize() const { return size; }

private:
    void resize() 
    {
        capacity *= 2;
        T* newData = new T[capacity];
        for (size_t i = 0; i < size; ++i) 
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
};

int main() 
{
    SimpleVector<int> intVec;
    SimpleVector<std::string> stringVec;
    
    intVec.push_back(1);
    intVec.push_back(2);
    
    stringVec.push_back("Hello");
    stringVec.push_back("World");
    
    return 0;
}
```

---

## Best Practices and Common Pitfalls

### Do's:
✅ **Use template argument deduction** when possible  
✅ **Start with regular functions, convert to templates when needed**  
✅ **Use meaningful names for non-trivial template parameters**  
✅ **Combine with constexpr for compile-time computation**  
✅ **Write comprehensive tests for different types**  

### Don'ts:
❌ **Don't overuse templates for simple, type-specific functions**  
❌ **Don't ignore compiler error messages** (though they're complex)  
❌ **Don't assume all types will work** without testing  
❌ **Don't create overly complex template hierarchies**  

### Common Pitfalls:

#### 1. Template Bloat
```cpp
// This creates separate functions for every type used
template <typename T>
void heavyFunction(T value) 
{
    // Lots of code here...
    // Each instantiation duplicates all this code
}
```

#### 2. Cryptic Error Messages
```cpp
template <typename T>
T badFunction(T x) 
{
    return x.nonexistentMethod(); // Will generate confusing errors
}
```

#### 3. Static Variable Surprises
```cpp
template <typename T>
void counter(T) 
{
    static int count = 0;    // Separate counter for each type!
    std::cout << ++count << '\n';
}

int main() 
{
    counter(1);      // Prints 1
    counter(2);      // Prints 2 (same int counter)
    counter(3.14);   // Prints 1 (new double counter!)
    return 0;
}
```

---

## The Power of Generic Programming

Function templates represent a paradigm shift from type-specific programming to **generic programming**, where we focus on algorithms and logic rather than specific types. This approach:

- **Reduces code duplication**
- **Improves maintainability**
- **Enhances type safety**
- **Enables powerful abstractions**
- **Facilitates code reuse**

When combined with constexpr functions from Chapter F, templates enable both **compile-time computation** and **generic programming**, forming the foundation of modern C++'s powerful template system that we'll see extensively in the Standard Template Library (STL).

Next, we'll explore how templates extend to classes and more advanced template metaprogramming techniques!

# Chapter 12: Compound Data Types - Pointers & References

## Building from Templates: Why Compound Types Matter

In Chapter 11, we learned how templates let us write generic code. But templates often work with **compound data types** - types that are built from other types. Understanding pointers and references is crucial for mastering templates, STL containers, and modern C++ programming.

---

## 12.1 - Introduction to Compound Data Types

### What Are Compound Data Types?

**Compound data types** are types that are built from fundamental types or other compound types:

```cpp
// Fundamental types
int x = 5;
double y = 3.14;
char c = 'A';

// Compound types
int* ptr;           // Pointer to int
int& ref = x;       // Reference to int
int arr[10];        // Array of ints
std::string text;   // Class type (compound)
```

### Why Compound Types Are Essential

```cpp
// Without compound types, this is impossible:
template <typename T>
void processLargeObject(T obj)    // ❌ Expensive copy!
{
    // Process obj...
}

// With compound types, we can do this:
template <typename T>
void processLargeObject(const T& obj)    // ✅ Efficient reference!
{
    // Process obj without copying...
}
```

---

## 12.2 - Value Categories: Lvalues and Rvalues

### The Foundation of Modern C++

Understanding **value categories** is essential for mastering references, move semantics, and template programming.

### What Are Value Categories?

Every expression in C++ has two properties:
1. **Type** - what kind of data (int, double, etc.)
2. **Value Category** - whether it evaluates to an object or a value

```cpp
int x = 5;          // x has type 'int' and is an lvalue
int y = x + 1;      // x is lvalue, x+1 is rvalue, y is lvalue
```

### Lvalues: "Locator Values"

An lvalue (pronounced "ell-value", short for "left value" or "locator value") is an expression that evaluates to an identifiable object or function:

```cpp
int main() 
{
    int x = 5;           // x is an lvalue (has identity, persists)
    int arr[5];          // arr is an lvalue
    const int c = 10;    // c is a non-modifiable lvalue
    
    // Lvalue expressions:
    x;                   // ✅ Variable
    arr[0];              // ✅ Array element
    ++x;                 // ✅ Pre-increment returns lvalue
    (x + y);             // ❌ This is actually an rvalue!
    
    return 0;
}
```

### Rvalues: "Right Values"

An rvalue is an expression that is not an lvalue. Rvalue expressions evaluate to a value:

```cpp
int getValue() { return 42; }

int main() 
{
    int x = 5;
    
    // Rvalue expressions:
    42;                  // ✅ Literal
    x + 1;               // ✅ Arithmetic result
    getValue();          // ✅ Function return value
    x++;                 // ✅ Post-increment returns rvalue
    static_cast<int>(3.14); // ✅ Cast result
    
    return 0;
}
```

### Visual Test: Determining Value Categories

Here's a practical way to test value categories:

```cpp
#include <iostream>
#include <string>

// T& is an lvalue reference - preferred for lvalues
template <typename T>
constexpr bool is_lvalue(T&) { return true; }

// T&& is an rvalue reference - preferred for rvalues  
template <typename T>
constexpr bool is_lvalue(T&&) { return false; }

#define TEST_CATEGORY(expr) \
    std::cout << #expr << " is " << (is_lvalue(expr) ? "lvalue" : "rvalue") << '\n';

int getNumber() { return 42; }

int main() 
{
    int x = 5;
    
    TEST_CATEGORY(x);                    // lvalue
    TEST_CATEGORY(42);                   // rvalue
    TEST_CATEGORY(x + 1);                // rvalue  
    TEST_CATEGORY(++x);                  // lvalue
    TEST_CATEGORY(x++);                  // rvalue
    TEST_CATEGORY(getNumber());          // rvalue
    TEST_CATEGORY("Hello");              // lvalue (special case!)
    TEST_CATEGORY(std::string("Hello")); // rvalue
    
    return 0;
}
```

### Key Insight: Assignment Rules

Assignment requires the left operand to be a modifiable lvalue expression and the right operand to be an rvalue expression:

```cpp
int main() 
{
    int x = 5, y = 10;
    
    x = y;              // ✅ lvalue = rvalue (y converts to rvalue)
    x = 42;             // ✅ lvalue = rvalue
    x = x + 1;          // ✅ lvalue = rvalue
    
    // 42 = x;          // ❌ rvalue = lvalue (illegal!)
    // x + 1 = y;       // ❌ rvalue = rvalue (illegal!)
    
    return 0;
}
```

---

## 12.3 - Lvalue References

### What Are References?

A **reference** acts as an alias for an existing object - it's essentially another name for the same memory location:

```cpp
int main() 
{
    int x = 5;           // Original variable
    int& ref = x;        // ref is now an alias for x
    
    std::cout << x << '\n';      // Prints: 5
    std::cout << ref << '\n';    // Prints: 5 (same object)
    
    ref = 10;                    // Changes x through ref
    std::cout << x << '\n';      // Prints: 10
    
    x = 20;                      // Changes ref through x  
    std::cout << ref << '\n';    // Prints: 20
    
    return 0;
}
```

### Reference Rules and Limitations

```cpp
int main() 
{
    int x = 5, y = 10;
    
    // ✅ Valid reference declarations
    int& ref1 = x;           // Must initialize when declared
    int& ref2 = y;           // Each reference needs separate declaration
    
    // ❌ Invalid reference operations
    // int& ref3;            // Error: references must be initialized
    // ref1 = ref2;          // This assigns y's value to x (doesn't rebind ref1!)
    // int& ref4 = 42;       // Error: can't bind to rvalue
    
    return 0;
}
```

### References vs Pointers: First Look

```cpp
int main() 
{
    int x = 5, y = 10;
    
    // References
    int& ref = x;        // Must initialize, becomes alias
    ref = 20;            // Changes x to 20
    // ref = &y;         // ❌ Can't rebind reference
    
    // Pointers (preview)
    int* ptr = &x;       // Stores address of x
    *ptr = 30;           // Changes x to 30
    ptr = &y;            // ✅ Can point to different objects
    
    return 0;
}
```

---

## 12.4 - Lvalue References to Const

### The Power of Const References

Lvalue references to const can bind to modifiable lvalues, non-modifiable lvalues, and rvalues:

```cpp
#include <iostream>

void printValue(const int& value)    // Can accept any int expression
{
    std::cout << "Value: " << value << '\n';
}

int getValue() { return 42; }

int main() 
{
    int x = 5;
    const int c = 10;
    
    // const references can bind to anything!
    printValue(x);           // ✅ Modifiable lvalue
    printValue(c);           // ✅ Non-modifiable lvalue  
    printValue(42);          // ✅ Rvalue literal
    printValue(x + 1);       // ✅ Rvalue expression
    printValue(getValue());  // ✅ Rvalue from function
    
    return 0;
}
```

### Lifetime Extension Magic

When a const reference is directly bound to a temporary, the lifetime of that temporary is extended to match the lifetime of the reference:

```cpp
#include <iostream>
#include <string>

int main() 
{
    // Without lifetime extension:
    // auto temp = std::string("Hello") + " World";
    // const std::string& ref = temp;  // Normal reference to existing object
    
    // With lifetime extension:
    const std::string& ref = std::string("Hello") + " World";  // Temporary extended!
    
    std::cout << ref << '\n';  // ✅ Safe to use - temporary still alive
    
    return 0;
}
```

---

## 12.7 - Introduction to Pointers

### Understanding Memory Addresses

When the code generated for this definition is executed, a piece of memory from RAM will be assigned to this object:

```cpp
#include <iostream>

int main() 
{
    int x = 5;           // Assume assigned to address 1000
    char c = 'A';        // Assume assigned to address 1004
    double d = 3.14;     // Assume assigned to address 1008
    
    std::cout << "x value: " << x << ", address: " << &x << '\n';
    std::cout << "c value: " << c << ", address: " << (void*)&c << '\n';  
    std::cout << "d value: " << d << ", address: " << &d << '\n';
    
    return 0;
}
```

### The Address-of Operator (&)

The address-of operator (&) returns the memory address of its operand:

```cpp
#include <iostream>

int main() 
{
    int x = 42;
    double arr[3] = {1.1, 2.2, 3.3};
    
    std::cout << "Address of x: " << &x << '\n';
    std::cout << "Address of arr[0]: " << &arr[0] << '\n';
    std::cout << "Address of arr[1]: " << &arr[1] << '\n';
    std::cout << "Address of arr[2]: " << &arr[2] << '\n';
    
    // Notice how array elements are contiguous in memory!
    return 0;
}
```

### The Dereference Operator (*)

The dereference operator (*) returns the value at a given memory address as an lvalue:

```cpp
#include <iostream>

int main() 
{
    int x = 100;
    
    std::cout << "Direct access: " << x << '\n';           // 100
    std::cout << "Address: " << &x << '\n';                // e.g., 0x7fff5fbff6ac
    std::cout << "Indirect access: " << *(&x) << '\n';     // 100
    
    // Address-of and dereference are opposites
    // &x gets the address, *(&x) gets the value back
    
    return 0;
}
```

---

## 12.8 - Pointer Fundamentals

### Declaring and Initializing Pointers

A pointer is an object that holds a memory address (typically of another variable) as its value:

```cpp
#include <iostream>

int main() 
{
    int x = 5, y = 10;
    
    // Pointer declarations and initialization
    int* ptr1;           // ❌ Uninitialized (wild pointer)
    int* ptr2{};         // ✅ Null pointer
    int* ptr3 = &x;      // ✅ Points to x
    int* ptr4{&y};       // ✅ Points to y (preferred syntax)
    
    std::cout << "x = " << x << ", *ptr3 = " << *ptr3 << '\n';  // Both print 5
    std::cout << "y = " << y << ", *ptr4 = " << *ptr4 << '\n';  // Both print 10
    
    return 0;
}
```

### Pointer Assignment: Two Ways

We can use assignment with pointers in two different ways: To change what the pointer is pointing at (by assigning the pointer a new address) To change the value being pointed at (by assigning the dereferenced pointer a new value):

```cpp
#include <iostream>

int main() 
{
    int x = 5, y = 10, z = 15;
    int* ptr = &x;
    
    std::cout << "Initially: *ptr = " << *ptr << '\n';  // 5
    
    // Method 1: Change what pointer points to
    ptr = &y;
    std::cout << "After ptr = &y: *ptr = " << *ptr << '\n';  // 10
    
    // Method 2: Change the value being pointed at
    *ptr = 99;
    std::cout << "After *ptr = 99: y = " << y << '\n';  // 99 (y changed!)
    
    return 0;
}
```

### Pointers vs References Comparison

Pointers and lvalue references behave similarly, but with key differences:

```cpp
#include <iostream>

int main() 
{
    int x = 5, y = 10;
    
    // References
    int& ref = x;        // Must initialize, becomes permanent alias
    ref = 20;            // Changes x to 20
    ref = y;             // ❌ This assigns y's VALUE to x, doesn't rebind!
    
    // Pointers  
    int* ptr = &x;       // Initialize with address
    *ptr = 30;           // Changes x to 30
    ptr = &y;            // ✅ Now points to y instead
    *ptr = 40;           // Changes y to 40
    
    std::cout << "x = " << x << ", y = " << y << '\n';  // x = 30, y = 40
    
    return 0;
}
```

### Key Differences Summary

| Feature | References | Pointers |
|---------|------------|----------|
| **Initialization** | Required | Optional (but should) |
| **Rebinding** | ❌ Cannot | ✅ Can |
| **Null State** | ❌ Must bind to object | ✅ Can be null |
| **Arithmetic** | ❌ Not allowed | ✅ Supported |
| **Memory Overhead** | None (alias) | Yes (stores address) |
| **Syntax** | Implicit | Explicit (* and &) |
| **Safety** | Safer | More dangerous |

---

## Advanced Applications

### Template Functions with References and Pointers

Combining our knowledge with templates from Chapter 11:

```cpp
#include <iostream>
#include <string>

// Template function using const reference (efficient for large objects)
template <typename T>
void printTwice(const T& value) 
{
    std::cout << value << '\n';
    std::cout << value << '\n';
}

// Template function using pointers (can handle optional parameters)
template <typename T>
void printIfNotNull(const T* ptr) 
{
    if (ptr != nullptr) 
    {
        std::cout << *ptr << '\n';
    } 
    else 
    {
        std::cout << "null pointer!\n";
    }
}

int main() 
{
    std::string bigString = "This is a potentially large string object";
    int number = 42;
    
    // Efficient - no copying of large string
    printTwice(bigString);
    printTwice(number);
    
    // Safe pointer handling
    int* validPtr = &number;
    int* nullPtr = nullptr;
    
    printIfNotNull(validPtr);    // Prints: 42
    printIfNotNull(nullPtr);     // Prints: null pointer!
    
    return 0;
}
```

### Smart Pointer Preview

Modern C++ provides safer alternatives to raw pointers:

```cpp
#include <iostream>
#include <memory>
#include <string>

int main() 
{
    // Raw pointer (dangerous)
    int* rawPtr = new int(42);
    std::cout << *rawPtr << '\n';
    delete rawPtr;  // Must remember to delete!
    
    // Smart pointer (safe) - C++14
    auto smartPtr = std::make_unique<int>(42);
    std::cout << *smartPtr << '\n';
    // Automatic cleanup - no delete needed!
    
    // Smart pointers work great with templates
    auto smartString = std::make_unique<std::string>("Hello, Smart Pointers!");
    std::cout << *smartString << '\n';
    
    return 0;
}
```

### Reference Wrappers for Container Storage

References can't be stored in containers, but we can use `std::reference_wrapper`:

```cpp
#include <iostream>
#include <vector>
#include <functional>

int main() 
{
    int a = 1, b = 2, c = 3;
    
    // Can't do: std::vector<int&> refs;  // ❌ Error!
    
    // Solution: use reference_wrapper
    std::vector<std::reference_wrapper<int>> refs = {a, b, c};
    
    // Modify through references
    for (auto& ref : refs) 
    {
        ref.get() *= 2;  // Double each value
    }
    
    std::cout << "a = " << a << ", b = " << b << ", c = " << c << '\n';
    // Prints: a = 2, b = 4, c = 6
    
    return 0;
}
```

---

## Best Practices and Common Pitfalls

### Do's ✅

1. **Always initialize pointers**:
```cpp
int* ptr = nullptr;     // ✅ Safe default
int* ptr = &variable;   // ✅ Point to valid object
```

2. **Use const references for function parameters**:
```cpp
template <typename T>
void process(const T& obj) {  // ✅ Efficient, safe
    // Read-only access to obj
}
```

3. **Prefer references when you don't need rebinding**:
```cpp
void increment(int& value) {  // ✅ Clear intent
    ++value;
}
```

4. **Check pointers before dereferencing**:
```cpp
if (ptr != nullptr) {   // ✅ Safe
    std::cout << *ptr;
}
```

### Don'ts ❌

1. **Don't use uninitialized pointers**:
```cpp
int* ptr;          // ❌ Wild pointer
std::cout << *ptr; // ❌ Undefined behavior
```

2. **Don't dereference dangling pointers**:
```cpp
int* ptr = nullptr;
{
    int x = 5;
    ptr = &x;
}  // x destroyed here
std::cout << *ptr;  // ❌ Undefined behavior
```

3. **Don't confuse assignment vs rebinding**:
```cpp
int x = 5, y = 10;
int& ref = x;
ref = y;        // ❌ This assigns y's VALUE to x, doesn't rebind!
```

### Memory Management Best Practices

```cpp
#include <memory>

// ❌ Manual memory management (error-prone)
void badExample() 
{
    int* ptr = new int(42);
    // ... do work ...
    delete ptr;  // Easy to forget or miss on exception!
}

// ✅ RAII with smart pointers
void goodExample() 
{
    auto ptr = std::make_unique<int>(42);
    // ... do work ...
    // Automatic cleanup, exception-safe
}

// ✅ Stack allocation when possible
void bestExample() 
{
    int value = 42;  // No dynamic allocation needed
    // ... do work ...
    // Automatic cleanup
}
```

---

## Real-World Applications

### Implementing a Generic Swap Function

```cpp
template <typename T>
void swap(T& a, T& b) 
{
    T temp = a;  // Copy a
    a = b;       // Copy b to a
    b = temp;    // Copy temp to b
}

// More efficient for large objects (uses pointers internally)
template <typename T>
void swapPtr(T* a, T* b) 
{
    if (a && b) {  // Safety check
        T temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main() 
{
    int x = 10, y = 20;
    std::cout << "Before: x=" << x << ", y=" << y << '\n';
    
    swap(x, y);
    std::cout << "After: x=" << x << ", y=" << y << '\n';
    
    return 0;
}
```

### Building Linked Data Structures

```cpp
#include <iostream>
#include <memory>

template <typename T>
struct Node 
{
    T data;
    std::unique_ptr<Node<T>> next;
    
    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList 
{
private:
    std::unique_ptr<Node<T>> head;
    
public:
    void push_front(T value) 
    {
        auto newNode = std::make_unique<Node<T>>(value);
        newNode->next = std::move(head);
        head = std::move(newNode);
    }
    
    void print() const 
    {
        Node<T>* current = head.get();  // Raw pointer for traversal
        while (current != nullptr) 
        {
            std::cout << current->data << " -> ";
            current = current->next.get();
        }
        std::cout << "null\n";
    }
};

int main() 
{
    LinkedList<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    list.print();  // Prints: 1 -> 2 -> 3 -> null
    
    return 0;
}
```

---

## Conclusion

Understanding pointers and references is foundational to mastering:

- **Template programming** (efficient parameter passing)
- **STL containers** (iterators are sophisticated pointers)
- **Object relationships** (composition, aggregation)
- **Memory management** (smart pointers, RAII)
- **Performance optimization** (avoiding unnecessary copies)

The concepts in this chapter directly enable the advanced C++ features we'll explore next, particularly STL containers, algorithms, and modern memory management techniques. The distinction between lvalues and rvalues becomes even more important when we discuss move semantics in later chapters.

Next up: **Chapter 13 - Enumerations and Structs**, which will show how to create our own compound data types!

# Chapter 13: Enumerations and Structs - Building User-Defined Types

## Building from Pointers & References: Creating Your Own Types

In Chapter 12, we mastered compound data types that work with existing types. Now we'll learn to create our own **user-defined types** using enumerations and structs. These are the building blocks for object-oriented programming and essential for creating meaningful, type-safe code.

---

## 13.1 - Introduction to Program-Defined (User-Defined) Types

### The Need for Custom Types

Consider representing different states in a game:

```cpp
// Using magic numbers (bad approach)
int gameState = 0;    // What does 0 mean?
int playerState = 2;  // What does 2 mean?

if (gameState == 1) { /* do something */ }  // Magic number - unclear!
```

### What Are Program-Defined Types?

**Program-defined types** (also called user-defined types) are custom types that we create for use in our own programs:

```cpp
// Better approach with user-defined types
enum class GameState 
{
    menu,
    playing,
    paused,
    gameOver
};

struct Player 
{
    std::string name;
    int health;
    int score;
};

GameState currentState = GameState::playing;  // Clear and type-safe!
Player hero { "Link", 100, 0 };
```

### Categories of Program-Defined Types

1. **Enumerated types** (unscoped and scoped enumerations)
2. **Class types** (including structs, classes, and unions)

Both must be **defined before use** and require a **type definition**.

---

## 13.2 - Unscoped Enumerations

### Basic Unscoped Enumerations

An enumeration (enum) defines a set of named integral constants:

```cpp
#include <iostream>

// Define an enumeration for colors
enum Color 
{
    red,      // assigned value 0
    green,    // assigned value 1  
    blue,     // assigned value 2
    yellow    // assigned value 3
};

int main() 
{
    Color paint = red;        // paint now holds the value corresponding to red
    Color house = green;      // house now holds the value corresponding to green
    Color apple = red;        // apple now holds the value corresponding to red
    
    std::cout << "Paint color: " << paint << '\n';  // prints 0
    std::cout << "House color: " << house << '\n';  // prints 1
    
    return 0;
}
```

### Explicit Value Assignment

You can explicitly assign values to enumerators:

```cpp
enum Status 
{
    ready = 10,      // explicitly assigned 10
    waiting,         // assigned 11 (10 + 1)
    processing = 25, // explicitly assigned 25  
    complete         // assigned 26 (25 + 1)
};

enum Priority 
{
    low = 1,
    medium = 5,
    high = 10,
    critical = 20
};

int main() 
{
    Status currentStatus = processing;
    Priority taskPriority = high;
    
    std::cout << "Status: " << currentStatus << '\n';    // prints 25
    std::cout << "Priority: " << taskPriority << '\n';   // prints 10
    
    return 0;
}
```

### Problems with Unscoped Enumerations

#### 1. Namespace Pollution

```cpp
enum Animal 
{
    cat,
    dog,
    bird
};

enum Transport 
{
    car,
    // cat,   // ❌ Error: 'cat' already declared!
    plane
};

int main() 
{
    // Enumerators are in global scope
    Animal pet = cat;       // ✅ Works
    Transport vehicle = car; // ✅ Works
    
    return 0;
}
```

#### 2. Unwanted Implicit Conversions

```cpp
enum Color { red, blue };
enum Fruit { banana, apple };

int main() 
{
    Color color = red;      // red = 0
    Fruit fruit = banana;   // banana = 0
    
    if (color == fruit)     // ❌ This compiles but makes no sense!
    {
        std::cout << "Color and fruit are equal!\n"; // This prints!
    }
    
    // Even worse:
    Color paint = red;
    int number = paint + 5;  // ❌ Unwanted implicit conversion
    
    return 0;
}
```

---

## 13.6 - Scoped Enumerations (enum class)

### The Solution: Scoped Enumerations

**Scoped enumerations** (enum class) solve the problems of unscoped enumerations:

```cpp
#include <iostream>

enum class Color 
{
    red,      // Color::red
    green,    // Color::green
    blue      // Color::blue
};

enum class Fruit 
{
    apple,    // Fruit::apple
    banana,   // Fruit::banana  
    orange    // Fruit::orange
};

int main() 
{
    Color paint = Color::red;       // ✅ Must use scope resolution
    Fruit snack = Fruit::apple;     // ✅ Must use scope resolution
    
    // These no longer compile (good!):
    // if (paint == snack) {}       // ❌ Error: can't compare different enum types
    // int value = paint;           // ❌ Error: no implicit conversion to int
    
    // This works (same type comparison):
    if (paint == Color::red) 
    {
        std::cout << "Paint is red!\n";
    }
    
    return 0;
}
```

### Explicit Conversions When Needed

Sometimes you need the underlying integer value:

```cpp
#include <iostream>
#include <utility>  // for std::to_underlying (C++23)

enum class ErrorCode 
{
    none = 0,
    fileNotFound = 404,
    serverError = 500,
    timeout = 408
};

void logError(ErrorCode code) 
{
    // Method 1: static_cast (all C++ versions)
    std::cout << "Error code: " << static_cast<int>(code) << '\n';
    
    // Method 2: std::to_underlying (C++23 - preferred)
    // std::cout << "Error code: " << std::to_underlying(code) << '\n';
}

int main() 
{
    ErrorCode error = ErrorCode::fileNotFound;
    logError(error);  // prints: Error code: 404
    
    return 0;
}
```

### Modern C++20: using enum Statements

Reduce repetition in switch statements:

```cpp
#include <iostream>
#include <string_view>

enum class Direction 
{
    north,
    south,
    east,
    west
};

std::string_view getDirectionName(Direction dir) 
{
    using enum Direction;  // C++20: Import all enumerators
    
    switch (dir) 
    {
        case north: return "North";  // No need for Direction::north
        case south: return "South";
        case east:  return "East";
        case west:  return "West";
        default:    return "Unknown";
    }
}

int main() 
{
    Direction playerDirection = Direction::north;
    std::cout << "Moving " << getDirectionName(playerDirection) << '\n';
    
    return 0;
}
```

---

## 13.7 - Introduction to Structs

### The Problem: Related Data Scattered

Imagine tracking employee information with separate variables:

```cpp
// Problematic approach
std::string employeeName;
std::string employeeTitle;
int employeeAge;
int employeeId;
double employeeWage;

// Hard to manage, pass to functions, or scale to multiple employees!
```

### The Solution: Structs

A **struct** bundles related variables together into a single type:

```cpp
#include <iostream>
#include <string>

// Define the Employee struct type
struct Employee 
{
    int id{};           // Data member (value-initialized)
    std::string name;   // Data member
    std::string title;  // Data member
    int age{};         // Data member  
    double wage{};     // Data member
};

int main() 
{
    // Create Employee objects
    Employee joe{};     // All members value-initialized
    Employee sarah{};   // Separate Employee object
    
    // Access members using the dot operator
    joe.id = 101;
    joe.name = "Joe Smith";
    joe.title = "Developer";
    joe.age = 32;
    joe.wage = 75000.0;
    
    sarah.id = 102;
    sarah.name = "Sarah Johnson";
    sarah.title = "Manager";
    sarah.age = 28;
    sarah.wage = 85000.0;
    
    // Use the data
    std::cout << joe.name << " (ID: " << joe.id << ") earns $" << joe.wage << '\n';
    std::cout << sarah.name << " (ID: " << sarah.id << ") earns $" << sarah.wage << '\n';
    
    if (sarah.wage > joe.wage) 
    {
        std::cout << sarah.name << " earns more than " << joe.name << '\n';
    }
    
    return 0;
}
```

---

## 13.8 - Struct Aggregate Initialization

### List Initialization of Structs

You can initialize struct members directly using brace initialization:

```cpp
#include <iostream>
#include <string>

struct Point3D 
{
    double x{};
    double y{};
    double z{};
};

struct RGB 
{
    int red{};
    int green{};  
    int blue{};
};

int main() 
{
    // Aggregate initialization
    Point3D origin{};              // All members = 0.0
    Point3D position{1.5, 2.7, 3.2}; // x=1.5, y=2.7, z=3.2
    
    RGB white{255, 255, 255};      // red=255, green=255, blue=255
    RGB red{255, 0, 0};            // red=255, green=0, blue=0
    RGB partialColor{100};         // red=100, green=0, blue=0
    
    std::cout << "Position: (" << position.x << ", " << position.y << ", " << position.z << ")\n";
    std::cout << "Red color: RGB(" << red.red << ", " << red.green << ", " << red.blue << ")\n";
    
    return 0;
}
```

### Designated Initializers (C++20)

Make initialization more explicit and readable:

```cpp
#include <iostream>
#include <string>

struct Car 
{
    std::string brand;
    std::string model;
    int year{};
    double price{};
    bool isElectric{};
};

int main() 
{
    // C++20 designated initializers
    Car tesla {
        .brand = "Tesla",
        .model = "Model 3",
        .year = 2023,
        .price = 35000.0,
        .isElectric = true
    };
    
    Car honda {
        .brand = "Honda",
        .model = "Civic",
        .year = 2022,
        .price = 23000.0
        // isElectric defaults to false
    };
    
    std::cout << tesla.brand << " " << tesla.model << " (" << tesla.year << ")\n";
    std::cout << "Electric: " << (tesla.isElectric ? "Yes" : "No") << "\n";
    
    return 0;
}
```

---

## 13.9 - Default Member Initialization

### Setting Default Values in the Struct Definition

You can provide default values for struct members:

```cpp
#include <iostream>
#include <string>

struct GameCharacter 
{
    std::string name = "Unknown";    // Default value
    int health = 100;               // Default value
    int mana = 50;                  // Default value
    int level = 1;                  // Default value
    bool isAlive = true;            // Default value
};

int main() 
{
    // Use defaults
    GameCharacter npc{};
    std::cout << "NPC: " << npc.name << ", Health: " << npc.health << '\n';
    
    // Override some defaults
    GameCharacter hero{"Link", 120, 75, 5};  // name, health, mana, level
    std::cout << "Hero: " << hero.name << ", Level: " << hero.level << '\n';
    
    // Override specific members (C++20 designated initializers)
    GameCharacter boss{
        .name = "Ganondorf",
        .health = 500,
        .level = 50
        // mana, isAlive use defaults
    };
    
    std::cout << "Boss: " << boss.name << ", Health: " << boss.health 
              << ", Mana: " << boss.mana << '\n';
    
    return 0;
}
```

---

## 13.10 - Passing and Returning Structs

### Efficient Function Parameters

Use const references to avoid copying large structs:

```cpp
#include <iostream>
#include <string>

struct Student 
{
    std::string name;
    int id{};
    double gpa{};
    std::string major;
};

// ❌ Inefficient: copies the entire struct
void displayStudentCopy(Student s) 
{
    std::cout << s.name << " (ID: " << s.id << ", GPA: " << s.gpa << ")\n";
}

// ✅ Efficient: passes by const reference
void displayStudent(const Student& s) 
{
    std::cout << s.name << " (ID: " << s.id << ", GPA: " << s.gpa << ")\n";
}

// ✅ Modify struct through non-const reference
void updateGPA(Student& s, double newGPA) 
{
    s.gpa = newGPA;
}

// ✅ Return struct by value (modern compilers optimize this)
Student createStudent(const std::string& name, int id, double gpa, const std::string& major) 
{
    return Student{name, id, gpa, major};
}

int main() 
{
    Student alice = createStudent("Alice Johnson", 12345, 3.85, "Computer Science");
    
    displayStudent(alice);        // Efficient const reference
    
    updateGPA(alice, 3.92);       // Modify through reference
    displayStudent(alice);        // Show updated GPA
    
    return 0;
}
```

### Returning Multiple Values with Structs

```cpp
#include <iostream>
#include <cmath>

struct Coordinates 
{
    double x;
    double y;
};

struct PolarCoordinates 
{
    double radius;
    double angle;  // in radians
};

// Convert Cartesian to Polar coordinates
PolarCoordinates toPolar(const Coordinates& cartesian) 
{
    double radius = std::sqrt(cartesian.x * cartesian.x + cartesian.y * cartesian.y);
    double angle = std::atan2(cartesian.y, cartesian.x);
    
    return PolarCoordinates{radius, angle};
}

// Convert Polar to Cartesian coordinates
Coordinates toCartesian(const PolarCoordinates& polar) 
{
    double x = polar.radius * std::cos(polar.angle);
    double y = polar.radius * std::sin(polar.angle);
    
    return Coordinates{x, y};
}

int main() 
{
    Coordinates point{3.0, 4.0};
    std::cout << "Cartesian: (" << point.x << ", " << point.y << ")\n";
    
    PolarCoordinates polar = toPolar(point);
    std::cout << "Polar: radius=" << polar.radius << ", angle=" << polar.angle << " rad\n";
    
    Coordinates converted = toCartesian(polar);
    std::cout << "Back to Cartesian: (" << converted.x << ", " << converted.y << ")\n";
    
    return 0;
}
```

---

## Advanced Applications

### Template Structs

Combine structs with templates for generic programming:

```cpp
#include <iostream>
#include <string>

template <typename T>
struct Pair 
{
    T first;
    T second;
    
    // Member functions
    T sum() const { return first + second; }
    T max() const { return (first > second) ? first : second; }
    void swap() { std::swap(first, second); }
};

// Template specialization for string concatenation
template <>
std::string Pair<std::string>::sum() const 
{
    return first + " " + second;
}

int main() 
{
    Pair<int> numbers{10, 20};
    std::cout << "Sum: " << numbers.sum() << '\n';        // 30
    std::cout << "Max: " << numbers.max() << '\n';        // 20
    
    Pair<double> decimals{3.14, 2.71};
    std::cout << "Sum: " << decimals.sum() << '\n';       // 5.85
    
    Pair<std::string> words{"Hello", "World"};
    std::cout << "Combined: " << words.sum() << '\n';     // Hello World
    
    return 0;
}
```

### Nested Structs and Complex Data

```cpp
#include <iostream>
#include <string>
#include <vector>

struct Address 
{
    std::string street;
    std::string city;
    std::string state;
    std::string zipCode;
};

struct Person 
{
    std::string firstName;
    std::string lastName;
    Address address;           // Nested struct
    std::vector<std::string> phoneNumbers;
    
    // Member function
    std::string fullName() const 
    {
        return firstName + " " + lastName;
    }
    
    void displayInfo() const 
    {
        std::cout << "Name: " << fullName() << '\n';
        std::cout << "Address: " << address.street << ", " 
                  << address.city << ", " << address.state << " " << address.zipCode << '\n';
        std::cout << "Phone numbers: ";
        for (const auto& phone : phoneNumbers) 
        {
            std::cout << phone << " ";
        }
        std::cout << '\n';
    }
};

int main() 
{
    Person john {
        .firstName = "John",
        .lastName = "Doe", 
        .address = {
            .street = "123 Main St",
            .city = "Springfield",
            .state = "IL",
            .zipCode = "62701"
        },
        .phoneNumbers = {"555-1234", "555-5678"}
    };
    
    john.displayInfo();
    
    return 0;
}
```

### Data Validation and Invariants

```cpp
#include <iostream>
#include <string>
#include <stdexcept>

struct Temperature 
{
    enum class Scale { Celsius, Fahrenheit, Kelvin };
    
    double value{};
    Scale scale = Scale::Celsius;
    
    // Validation function
    bool isValid() const 
    {
        switch (scale) 
        {
            case Scale::Celsius:    return value >= -273.15;
            case Scale::Fahrenheit: return value >= -459.67;
            case Scale::Kelvin:     return value >= 0.0;
        }
        return false;
    }
    
    // Conversion functions
    Temperature toCelsius() const 
    {
        if (!isValid()) throw std::invalid_argument("Invalid temperature");
        
        switch (scale) 
        {
            case Scale::Celsius:    return *this;
            case Scale::Fahrenheit: return {(value - 32) * 5.0/9.0, Scale::Celsius};
            case Scale::Kelvin:     return {value - 273.15, Scale::Celsius};
        }
        return {};
    }
    
    void display() const 
    {
        char symbol = (scale == Scale::Celsius) ? 'C' : 
                     (scale == Scale::Fahrenheit) ? 'F' : 'K';
        std::cout << value << "°" << symbol;
    }
};

int main() 
{
    Temperature room{22.5, Temperature::Scale::Celsius};
    Temperature freezing{32.0, Temperature::Scale::Fahrenheit};
    
    std::cout << "Room temperature: ";
    room.display();
    std::cout << '\n';
    
    std::cout << "Freezing point in Fahrenheit: ";
    freezing.display();
    std::cout << " = ";
    freezing.toCelsius().display();
    std::cout << '\n';
    
    return 0;
}
```

---

## Best Practices and Modern Usage

### Do's ✅

1. **Use enum class over plain enum**:
```cpp
enum class Status { ready, processing, complete };  // ✅ Type-safe
```

2. **Initialize struct members**:
```cpp
struct Point { double x{}, y{}, z{}; };  // ✅ Default values
```

3. **Use const references for function parameters**:
```cpp
void process(const LargeStruct& data) { /* ... */ }  // ✅ Efficient
```

4. **Group related data logically**:
```cpp
struct PlayerStats { int health, mana, experience; };  // ✅ Cohesive
```

### Don'ts ❌

1. **Don't use magic numbers**:
```cpp
int gameState = 2;  // ❌ What is 2?
```

2. **Don't pass large structs by value**:
```cpp
void process(LargeStruct data) { /* ... */ }  // ❌ Expensive copy
```

3. **Don't compare different enum types**:
```cpp
if (color == fruit) { /* ... */ }  // ❌ Meaningless comparison
```

### Modern C++ Features

```cpp
// C++17: Structured bindings
struct Point { double x, y; };
Point p{3.0, 4.0};
auto [x, y] = p;  // ✅ Decompose struct

// C++20: Designated initializers
Car tesla{.brand = "Tesla", .year = 2023};  // ✅ Clear intent

// C++20: using enum
using enum Color;
if (paint == red) { /* ... */ }  // ✅ Less verbose
```

---

## Real-World Applications

### Game Development

```cpp
enum class EntityType { Player, Enemy, Projectile, Powerup };

struct GameObject 
{
    EntityType type;
    double x{}, y{};
    double velocityX{}, velocityY{};
    int health = 100;
    bool isActive = true;
    
    void update(double deltaTime) 
    {
        x += velocityX * deltaTime;
        y += velocityY * deltaTime;
    }
};
```

### Configuration Management

```cpp
struct ServerConfig 
{
    std::string host = "localhost";
    int port = 8080;
    int maxConnections = 100;
    bool enableLogging = true;
    double timeoutSeconds = 30.0;
};
```

### Data Analysis

```cpp
struct DataPoint 
{
    double timestamp;
    double value;
    std::string category;
    bool isValid = true;
};

struct Statistics 
{
    double mean{}, median{}, stdDev{};
    double min{}, max{};
    size_t count{};
};
```

---

## Conclusion

Enumerations and structs are fundamental building blocks that enable:

- **Type Safety** - Prevent meaningless operations and catch errors at compile time
- **Code Organization** - Group related data and concepts together
- **Self-Documenting Code** - Names convey meaning better than magic numbers
- **Scalability** - Easy to extend and modify as requirements change
- **Template Compatibility** - Work seamlessly with generic programming

These user-defined types form the foundation for object-oriented programming (classes) and are essential for building robust, maintainable C++ applications. Next, we'll explore how structs evolve into full classes with encapsulation and member functions!

**Next: Chapter 14-15 - Object-Oriented Programming (Classes and Encapsulation)**

# Chapter 14: Introduction to Object-Oriented Programming - From Structs to Classes

## Building from Structs: Creating Intelligent Objects

In Chapter 13, we learned to bundle related data using structs. Now we'll transform these passive data containers into active, intelligent objects that can manage their own behavior. This is the foundation of **Object-Oriented Programming (OOP)**.

---

## 14.1 - Introduction to Object-Oriented Programming

### The Evolution from Procedural to Object-Oriented

Consider managing a bank account with traditional procedural programming:

```cpp
// Procedural approach - data and functions are separate
struct BankAccount {
    double balance;
    std::string accountNumber;
};

// Functions operate on the data externally
double getBalance(const BankAccount& account) {
    return account.balance;
}

bool withdraw(BankAccount& account, double amount) {
    if (amount <= account.balance) {
        account.balance -= amount;
        return true;
    }
    return false;
}

void deposit(BankAccount& account, double amount) {
    account.balance += amount;
}
```

**Problems with this approach:**
- Data and related functions are scattered
- No protection against invalid operations
- Anyone can directly modify `balance`
- Functions must be remembered and called correctly

### Object-Oriented Solution

```cpp
#include <iostream>
#include <string>

class BankAccount {
private:
    double m_balance;
    std::string m_accountNumber;

public:
    // Constructor
    BankAccount(const std::string& accountNumber, double initialBalance = 0.0)
        : m_accountNumber{accountNumber}, m_balance{initialBalance} {}
    
    // Member functions (methods) that operate on the object's data
    double getBalance() const { return m_balance; }
    
    bool withdraw(double amount) {
        if (amount > 0 && amount <= m_balance) {
            m_balance -= amount;
            return true;
        }
        return false;
    }
    
    void deposit(double amount) {
        if (amount > 0) {
            m_balance += amount;
        }
    }
    
    void displayInfo() const {
        std::cout << "Account: " << m_accountNumber 
                  << ", Balance: $" << m_balance << '\n';
    }
};

int main() {
    BankAccount savings{"SAV-001", 1000.0};
    
    savings.displayInfo();           // Account: SAV-001, Balance: $1000
    savings.deposit(250.0);          // Method call on the object
    savings.withdraw(100.0);         // Object manages its own state
    savings.displayInfo();           // Account: SAV-001, Balance: $1150
    
    // savings.m_balance = -500;     // ❌ Error: private member not accessible
    
    return 0;
}
```

### Core OOP Principles

1. **Encapsulation** - Bundle data and functions together, control access
2. **Data Hiding** - Keep internal details private, expose only necessary interface
3. **Abstraction** - Provide simple interface while hiding complexity
4. **Inheritance** - Create new classes based on existing ones (Chapter 17-18)
5. **Polymorphism** - Objects of different types respond to same interface (Chapter 18)

---

## 14.2 - Classes and Class Members

### From struct to class

In C++, `struct` and `class` are nearly identical - the only difference is default access:

```cpp
// struct: members are public by default
struct Point2D {
    double x, y;  // public by default
    void display() { std::cout << "(" << x << ", " << y << ")\n"; }
};

// class: members are private by default  
class Point3D {
    double x, y, z;  // private by default
    
public:  // Must explicitly specify public
    void setCoordinates(double newX, double newY, double newZ) {
        x = newX; y = newY; z = newZ;
    }
    
    void display() const {
        std::cout << "(" << x << ", " << y << ", " << z << ")\n";
    }
};
```

### Class Member Types

```cpp
#include <iostream>
#include <string>

class Student {
private:
    // Data members (member variables)
    std::string m_name;
    int m_id;
    double m_gpa;
    static int s_totalStudents;  // Static member - shared by all instances

public:
    // Member functions (methods)
    Student(const std::string& name, int id, double gpa = 0.0);  // Constructor
    ~Student();  // Destructor
    
    // Accessor functions (getters)
    const std::string& getName() const { return m_name; }
    int getId() const { return m_id; }
    double getGpa() const { return m_gpa; }
    
    // Mutator functions (setters)
    void setName(const std::string& name) { m_name = name; }
    void setGpa(double gpa) { 
        if (gpa >= 0.0 && gpa <= 4.0) {
            m_gpa = gpa; 
        }
    }
    
    // Utility functions
    void displayInfo() const;
    bool isHonorStudent() const { return m_gpa >= 3.5; }
    
    // Static member function
    static int getTotalStudents() { return s_totalStudents; }
};

// Static member definition (outside class)
int Student::s_totalStudents = 0;

// Constructor implementation
Student::Student(const std::string& name, int id, double gpa)
    : m_name{name}, m_id{id}, m_gpa{gpa} {
    ++s_totalStudents;
    std::cout << "Student " << m_name << " created\n";
}

// Destructor implementation  
Student::~Student() {
    --s_totalStudents;
    std::cout << "Student " << m_name << " destroyed\n";
}

// Member function implementation
void Student::displayInfo() const {
    std::cout << "Name: " << m_name << ", ID: " << m_id 
              << ", GPA: " << m_gpa << '\n';
}

int main() {
    std::cout << "Total students: " << Student::getTotalStudents() << '\n';
    
    Student alice{"Alice Johnson", 12345, 3.85};
    Student bob{"Bob Smith", 54321, 2.95};
    
    std::cout << "Total students: " << Student::getTotalStudents() << '\n';
    
    alice.displayInfo();
    std::cout << alice.getName() << " is " 
              << (alice.isHonorStudent() ? "" : "not ") 
              << "an honor student\n";
    
    return 0;
}
```

---

## 14.3 - Public vs Private Access Specifiers

### Access Control in Action

```cpp
#include <iostream>
#include <string>

class SecureVault {
private:
    std::string m_contents;
    std::string m_passcode;
    bool m_isLocked;
    int m_failedAttempts;
    static constexpr int MAX_ATTEMPTS = 3;

public:
    SecureVault(const std::string& passcode) 
        : m_passcode{passcode}, m_isLocked{true}, m_failedAttempts{0} {}
    
    bool unlock(const std::string& attempt) {
        if (m_failedAttempts >= MAX_ATTEMPTS) {
            std::cout << "Vault permanently locked due to too many failed attempts!\n";
            return false;
        }
        
        if (attempt == m_passcode) {
            m_isLocked = false;
            m_failedAttempts = 0;  // Reset on successful unlock
            std::cout << "Vault unlocked!\n";
            return true;
        } else {
            ++m_failedAttempts;
            std::cout << "Wrong passcode! Attempts remaining: " 
                      << (MAX_ATTEMPTS - m_failedAttempts) << '\n';
            return false;
        }
    }
    
    void lock() {
        m_isLocked = true;
        std::cout << "Vault locked\n";
    }
    
    bool storeItem(const std::string& item) {
        if (m_isLocked) {
            std::cout << "Cannot store item: vault is locked\n";
            return false;
        }
        m_contents = item;
        std::cout << "Item stored successfully\n";
        return true;
    }
    
    std::string retrieveContents() {
        if (m_isLocked) {
            std::cout << "Cannot retrieve: vault is locked\n";
            return "";
        }
        return m_contents;
    }
    
    bool isLocked() const { return m_isLocked; }
};

int main() {
    SecureVault myVault{"secret123"};
    
    // myVault.m_passcode = "hacked";  // ❌ Error: private member
    
    myVault.storeItem("Gold coins");     // Cannot store: vault is locked
    
    myVault.unlock("wrong");             // Wrong passcode! Attempts remaining: 2
    myVault.unlock("alsowrong");         // Wrong passcode! Attempts remaining: 1
    myVault.unlock("secret123");         // Vault unlocked!
    
    myVault.storeItem("Gold coins");     // Item stored successfully
    std::cout << "Retrieved: " << myVault.retrieveContents() << '\n';
    
    myVault.lock();
    
    return 0;
}
```

### Benefits of Encapsulation

1. **Data Integrity** - Invalid states prevented by controlled access
2. **Security** - Sensitive data hidden from outside access
3. **Maintainability** - Internal implementation can change without affecting users
4. **Debugging** - Easier to track down issues when data access is controlled

---

## 14.4 - Access Functions and Encapsulation

### Well-Designed Accessor Pattern

```cpp
#include <iostream>
#include <string>
#include <stdexcept>

class Temperature {
private:
    double m_celsius;
    
    // Private helper functions
    bool isValidCelsius(double temp) const {
        return temp >= -273.15;  // Absolute zero
    }

public:
    // Constructor with validation
    Temperature(double celsius = 0.0) {
        if (!isValidCelsius(celsius)) {
            throw std::invalid_argument("Temperature cannot be below absolute zero");
        }
        m_celsius = celsius;
    }
    
    // Read-only accessors (getters)
    double celsius() const { return m_celsius; }
    double fahrenheit() const { return (m_celsius * 9.0/5.0) + 32.0; }
    double kelvin() const { return m_celsius + 273.15; }
    
    // Mutator with validation (setter)
    void setCelsius(double temp) {
        if (!isValidCelsius(temp)) {
            throw std::invalid_argument("Invalid temperature");
        }
        m_celsius = temp;
    }
    
    void setFahrenheit(double temp) {
        double celsiusEquivalent = (temp - 32.0) * 5.0/9.0;
        setCelsius(celsiusEquivalent);  // Reuse validation
    }
    
    void setKelvin(double temp) {
        setCelsius(temp - 273.15);  // Reuse validation
    }
    
    // Utility functions
    bool isFreezing() const { return m_celsius <= 0.0; }
    bool isBoiling() const { return m_celsius >= 100.0; }
    
    std::string getState() const {
        if (m_celsius < 0.0) return "Solid (Ice)";
        if (m_celsius < 100.0) return "Liquid (Water)";
        return "Gas (Steam)";
    }
    
    void display() const {
        std::cout << "Temperature: " << m_celsius << "°C (" 
                  << fahrenheit() << "°F, " << kelvin() << "K)\n"
                  << "State: " << getState() << '\n';
    }
};

int main() {
    try {
        Temperature room{22.5};
        room.display();
        
        Temperature hot;
        hot.setFahrenheit(212.0);  // Boiling point
        hot.display();
        
        // Temperature invalid{-300.0};  // ❌ Throws exception
        
        room.setCelsius(0.0);
        std::cout << "Is freezing: " << (room.isFreezing() ? "Yes" : "No") << '\n';
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    
    return 0;
}
```

### Member Functions vs Free Functions

```cpp
#include <iostream>
#include <cmath>

class Circle {
private:
    double m_radius;

public:
    Circle(double radius) : m_radius{radius} {
        if (radius <= 0) {
            throw std::invalid_argument("Radius must be positive");
        }
    }
    
    // Accessor
    double radius() const { return m_radius; }
    
    // Mutator  
    void setRadius(double radius) {
        if (radius <= 0) {
            throw std::invalid_argument("Radius must be positive");
        }
        m_radius = radius;
    }
    
    // Member functions - operate on this object's data
    double area() const { return 3.14159 * m_radius * m_radius; }
    double circumference() const { return 2 * 3.14159 * m_radius; }
    
    void scale(double factor) {
        if (factor <= 0) return;
        m_radius *= factor;
    }
    
    void display() const {
        std::cout << "Circle with radius " << m_radius 
                  << " (area: " << area() << ")\n";
    }
};

// Free functions - don't need access to private members
bool areEqual(const Circle& c1, const Circle& c2) {
    return std::abs(c1.radius() - c2.radius()) < 0.001;
}

Circle createUnitCircle() {
    return Circle{1.0};
}

double distanceBetweenCenters(const Circle& c1, const Circle& c2) {
    // This would need coordinate data if we had it
    return 0.0;  // Simplified example
}

int main() {
    Circle small{2.0};
    Circle large{5.0};
    
    small.display();
    large.display();
    
    small.scale(2.0);  // Member function modifies the object
    std::cout << "After scaling: ";
    small.display();
    
    std::cout << "Circles equal: " << (areEqual(small, large) ? "Yes" : "No") << '\n';
    
    Circle unit = createUnitCircle();  // Free function creates object
    unit.display();
    
    return 0;
}
```

---

## 14.5 - Constructors

### Default Constructor vs Parameterized Constructor

```cpp
#include <iostream>
#include <string>

class Player {
private:
    std::string m_name;
    int m_health;
    int m_level;
    double m_experience;

public:
    // Default constructor
    Player() {
        m_name = "Unknown";
        m_health = 100;
        m_level = 1;
        m_experience = 0.0;
        std::cout << "Default player created\n";
    }
    
    // Parameterized constructor
    Player(const std::string& name, int health = 100) {
        m_name = name;
        m_health = health;
        m_level = 1;
        m_experience = 0.0;
        std::cout << "Player " << m_name << " created\n";
    }
    
    // Another parameterized constructor
    Player(const std::string& name, int health, int level, double exp) {
        m_name = name;
        m_health = health;
        m_level = level;
        m_experience = exp;
        std::cout << "Experienced player " << m_name << " created\n";
    }
    
    void displayStats() const {
        std::cout << "Player: " << m_name << " (Level " << m_level 
                  << ", Health: " << m_health << ", XP: " << m_experience << ")\n";
    }
};

int main() {
    Player newbie;                              // Default constructor
    Player hero{"Link", 120};                   // Parameterized constructor  
    Player veteran{"Zelda", 150, 10, 9999.0};  // Full parameterized constructor
    
    newbie.displayStats();
    hero.displayStats();
    veteran.displayStats();
    
    return 0;
}
```

### Member Initializer Lists (Preferred Method)

```cpp
#include <iostream>
#include <string>

class Book {
private:
    const std::string m_title;      // const member - must be initialized
    const std::string m_author;     // const member - must be initialized  
    int m_pages;
    double m_price;

public:
    // ❌ This won't compile - can't assign to const members in constructor body
    /*
    Book(const std::string& title, const std::string& author, int pages, double price) {
        m_title = title;    // Error: const member
        m_author = author;  // Error: const member
        m_pages = pages;
        m_price = price;
    }
    */
    
    // ✅ Member initializer list - preferred method
    Book(const std::string& title, const std::string& author, int pages = 0, double price = 0.0)
        : m_title{title}, m_author{author}, m_pages{pages}, m_price{price} {
        // Constructor body can contain additional logic
        std::cout << "Book \"" << m_title << "\" by " << m_author << " created\n";
    }
    
    // Accessors
    const std::string& title() const { return m_title; }
    const std::string& author() const { return m_author; }
    int pages() const { return m_pages; }
    double price() const { return m_price; }
    
    // Mutators (only for non-const members)
    void setPages(int pages) { 
        if (pages >= 0) m_pages = pages; 
    }
    void setPrice(double price) { 
        if (price >= 0.0) m_price = price; 
    }
    
    void displayInfo() const {
        std::cout << "\"" << m_title << "\" by " << m_author 
                  << " (" << m_pages << " pages, $" << m_price << ")\n";
    }
};

int main() {
    Book novel{"The Great Gatsby", "F. Scott Fitzgerald", 180, 12.99};
    Book reference{"C++ Reference", "Unknown Author"};  // Uses defaults
    
    novel.displayInfo();
    reference.displayInfo();
    
    reference.setPages(500);
    reference.setPrice(49.99);
    reference.displayInfo();
    
    return 0;
}
```

### Constructor Delegation (C++11)

```cpp
#include <iostream>
#include <string>

class Rectangle {
private:
    double m_width;
    double m_height;

public:
    // Primary constructor
    Rectangle(double width, double height) : m_width{width}, m_height{height} {
        if (width <= 0 || height <= 0) {
            throw std::invalid_argument("Dimensions must be positive");
        }
        std::cout << "Rectangle created: " << m_width << "x" << m_height << '\n';
    }
    
    // Delegating constructors - call the primary constructor
    Rectangle() : Rectangle(1.0, 1.0) {  // Default to unit square
        std::cout << "Default rectangle created\n";
    }
    
    Rectangle(double side) : Rectangle(side, side) {  // Square constructor
        std::cout << "Square created\n";
    }
    
    double area() const { return m_width * m_height; }
    double perimeter() const { return 2 * (m_width + m_height); }
    
    void display() const {
        std::cout << "Rectangle: " << m_width << "x" << m_height 
                  << " (area: " << area() << ")\n";
    }
};

int main() {
    try {
        Rectangle unit;           // Default constructor -> delegates to Rectangle(1.0, 1.0)
        Rectangle square{5.0};    // Square constructor -> delegates to Rectangle(5.0, 5.0)
        Rectangle rect{3.0, 4.0}; // Direct constructor call
        
        unit.display();
        square.display();
        rect.display();
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    
    return 0;
}
```

---

## 14.6 - Destructors

### Automatic Resource Management

```cpp
#include <iostream>
#include <string>

class FileHandler {
private:
    std::string m_filename;
    bool m_isOpen;

public:
    // Constructor
    FileHandler(const std::string& filename) : m_filename{filename}, m_isOpen{false} {
        std::cout << "FileHandler created for: " << m_filename << '\n';
        // In real implementation, would open file here
        m_isOpen = true;
        std::cout << "File opened: " << m_filename << '\n';
    }
    
    // Destructor - called automatically when object goes out of scope
    ~FileHandler() {
        std::cout << "FileHandler destructor called for: " << m_filename << '\n';
        if (m_isOpen) {
            // In real implementation, would close file here
            std::cout << "File closed: " << m_filename << '\n';
            m_isOpen = false;
        }
        std::cout << "FileHandler destroyed\n";
    }
    
    void writeData(const std::string& data) {
        if (m_isOpen) {
            std::cout << "Writing to " << m_filename << ": " << data << '\n';
        }
    }
    
    bool isOpen() const { return m_isOpen; }
};

void processFiles() {
    std::cout << "=== Entering processFiles() ===\n";
    
    FileHandler config{"config.txt"};      // Constructor called
    FileHandler log{"application.log"};    // Constructor called
    
    config.writeData("server_port=8080");
    log.writeData("Application started");
    
    std::cout << "=== Leaving processFiles() ===\n";
    // Destructors called automatically as objects go out of scope
    // Order: log destroyed first (LIFO), then config
}

int main() {
    std::cout << "=== Main function start ===\n";
    
    processFiles();  // Objects created and destroyed within this function
    
    std::cout << "=== Back in main ===\n";
    
    {
        std::cout << "--- Entering block scope ---\n";
        FileHandler temp{"temp.dat"};
        temp.writeData("temporary data");
        std::cout << "--- Leaving block scope ---\n";
        // temp destructor called here
    }
    
    std::cout << "=== Main function end ===\n";
    
    return 0;
}
```

### RAII (Resource Acquisition Is Initialization)

```cpp
#include <iostream>
#include <memory>

class DatabaseConnection {
private:
    std::string m_connectionString;
    bool m_connected;

public:
    DatabaseConnection(const std::string& connStr) 
        : m_connectionString{connStr}, m_connected{false} {
        // Acquire resource in constructor
        std::cout << "Connecting to database: " << m_connectionString << '\n';
        m_connected = true;
        std::cout << "Database connection established\n";
    }
    
    ~DatabaseConnection() {
        // Release resource in destructor
        if (m_connected) {
            std::cout << "Closing database connection: " << m_connectionString << '\n';
            m_connected = false;
        }
    }
    
    // Delete copy constructor and copy assignment to prevent copying
    DatabaseConnection(const DatabaseConnection&) = delete;
    DatabaseConnection& operator=(const DatabaseConnection&) = delete;
    
    void executeQuery(const std::string& query) {
        if (m_connected) {
            std::cout << "Executing query: " << query << '\n';
        } else {
            std::cout << "Error: Not connected to database\n";
        }
    }
    
    bool isConnected() const { return m_connected; }
};

class DataProcessor {
private:
    DatabaseConnection m_dbConn;

public:
    DataProcessor(const std::string& dbConnStr) : m_dbConn{dbConnStr} {
        std::cout << "DataProcessor initialized\n";
    }
    
    ~DataProcessor() {
        std::cout << "DataProcessor shutting down\n";
        // m_dbConn destructor called automatically
    }
    
    void processUserData(int userId) {
        m_dbConn.executeQuery("SELECT * FROM users WHERE id = " + std::to_string(userId));
        // Process data...
        m_dbConn.executeQuery("UPDATE users SET last_access = NOW() WHERE id = " + std::to_string(userId));
    }
};

int main() {
    std::cout << "=== Application Start ===\n";
    
    try {
        DataProcessor processor{"postgresql://localhost:5432/mydb"};
        processor.processUserData(12345);
        
        std::cout << "=== Processing Complete ===\n";
        
        // When processor goes out of scope:
        // 1. DataProcessor destructor called
        // 2. DatabaseConnection destructor called automatically
        // 3. All resources properly cleaned up
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    
    std::cout << "=== Application End ===\n";
    
    return 0;
}
```

---

## 14.7 - The Hidden "this" Pointer

### Understanding Object Identity

```cpp
#include <iostream>
#include <string>

class Counter {
private:
    int m_value;
    std::string m_name;

public:
    Counter(const std::string& name, int initial = 0) 
        : m_name{name}, m_value{initial} {}
    
    // Method that doesn't use 'this' explicitly
    void increment() {
        ++m_value;  // Equivalent to: ++(this->m_value);
        std::cout << m_name << " incremented to " << m_value << '\n';
    }
    
    // Method that explicitly uses 'this'
    Counter& add(int amount) {
        this->m_value += amount;  // Explicit use of 'this'
        return *this;             // Return reference to current object
    }
    
    // Method chaining using 'this'
    Counter& multiply(int factor) {
        m_value *= factor;
        return *this;  // Enable chaining: counter.multiply(2).add(5)
    }
    
    // Compare with another Counter
    bool isGreaterThan(const Counter& other) const {
        return this->m_value > other.m_value;
        // Could also write: return m_value > other.m_value;
    }
    
    // Self-assignment check (useful in copy assignment operator)
    Counter& copyFrom(const Counter& other) {
        if (this == &other) {  // Check for self-assignment
            std::cout << "Self-assignment detected, no operation performed\n";
            return *this;
        }
        
        this->m_value = other.m_value;
        std::cout << m_name << " copied value from " << other.m_name << '\n';
        return *this;
    }
    
    int getValue() const { return m_value; }
    const std::string& getName() const { return m_name; }
    
    void display() const {
        std::cout << m_name << ": " << m_value << " (object at " << this << ")\n";
    }
};

int main() {
    Counter alpha{"Alpha", 10};
    Counter beta{"Beta", 5};
    
    std::cout << "Initial state:\n";
    alpha.display();  // Shows object address
    beta.display();   // Different object address
    
    // Method chaining using returned *this
    alpha.add(5).multiply(2).add(3);  // 10 + 5 = 15, 15 * 2 = 30, 30 + 3 = 33
    std::cout << "After chaining: " << alpha.getValue() << '\n';
    
    // Comparison using 'this'
    if (alpha.isGreaterThan(beta)) {
        std::cout << alpha.getName() << " is greater than " << beta.getName() << '\n';
    }
    
    // Self-assignment
    alpha.copyFrom(alpha);  // Detects self-assignment
    
    // Copy from other
    beta.copyFrom(alpha);
    
    alpha.display();
    beta.display();
    
    return 0;
}
```

### When to Use 'this' Explicitly

```cpp
#include <iostream>
#include <string>

class Person {
private:
    std::string m_name;
    int m_age;

public:
    Person(const std::string& name, int age) : m_name{name}, m_age{age} {}
    
    // Case 1: Parameter name conflicts with member name
    void setName(const std::string& name) {
        this->m_name = name;  // 'this->' needed to distinguish from parameter
        // Without 'this->': name = name; would assign parameter to itself!
    }
    
    void setAge(int age) {
        this->m_age = age;    // 'this->' needed to distinguish from parameter
    }
    
    // Case 2: Method chaining
    Person& changeName(const std::string& name) {
        m_name = name;        // 'this->' not needed here (no naming conflict)
        return *this;         // 'this' needed to return current object
    }
    
    Person& changeAge(int age) {
        this->m_age = age;    // 'this->' used for consistency
        return *this;
    }
    
    // Case 3: Self-comparison or operations
    bool isSamePersonAs(const Person& other) const {
        return this == &other;  // Comparing object addresses
    }
    
    bool isOlderThan(const Person& other) const {
        return m_age > other.m_age;  // 'this->' not needed - no ambiguity
        // Could write: return this->m_age > other.m_age;
    }
    
    void display() const {
        std::cout << "Name: " << m_name << ", Age: " << m_age << '\n';
    }
};

int main() {
    Person john{"John", 25};
    Person jane{"Jane", 30};
    
    john.display();
    
    // Method chaining
    john.changeName("Johnny").changeAge(26);
    john.display();
    
    // Self-comparison
    std::cout << "john same as john: " << (john.isSamePersonAs(john) ? "Yes" : "No") << '\n';
    std::cout << "john same as jane: " << (john.isSamePersonAs(jane) ? "Yes" : "No") << '\n';
    
    return 0;
}
```

---

## 14.8 - Class Code and Header Files

### Separating Interface from Implementation

**Rectangle.h** (Header file - Interface)
```cpp
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

class Rectangle {
private:
    double m_width;
    double m_height;

public:
    // Constructor declarations
    Rectangle(double width, double height);
    Rectangle();  // Default constructor
    
    // Accessor declarations
    double getWidth() const;
    double getHeight() const;
    double area() const;
    double perimeter() const;
    
    // Mutator declarations
    void setWidth(double width);
    void setHeight(double height);
    void scale(double factor);
    
    // Utility function declarations
    void display() const;
    bool isSquare() const;
};

#endif
```

**Rectangle.cpp** (Implementation file)
```cpp
#include "Rectangle.h"
#include <stdexcept>

// Constructor definitions
Rectangle::Rectangle(double width, double height) : m_width{width}, m_height{height} {
    if (width <= 0 || height <= 0) {
        throw std::invalid_argument("Dimensions must be positive");
    }
}

Rectangle::Rectangle() : Rectangle(1.0, 1.0) {
    // Delegates to parameterized constructor
}

// Accessor definitions
double Rectangle::getWidth() const {
    return m_width;
}

double Rectangle::getHeight() const {
    return m_height;
}

double Rectangle::area() const {
    return m_width * m_height;
}

double Rectangle::perimeter() const {
    return 2.0 * (m_width + m_height);
}

// Mutator definitions
void Rectangle::setWidth(double width) {
    if (width <= 0) {
        throw std::invalid_argument("Width must be positive");
    }
    m_width = width;
}

void Rectangle::setHeight(double height) {
    if (height <= 0) {
        throw std::invalid_argument("Height must be positive");
    }
    m_height = height;
}

void Rectangle::scale(double factor) {
    if (factor <= 0) {
        throw std::invalid_argument("Scale factor must be positive");
    }
    m_width *= factor;
    m_height *= factor;
}

// Utility function definitions
void Rectangle::display() const {
    std::cout << "Rectangle: " << m_width << "x" << m_height 
              << " (area: " << area() << ", perimeter: " << perimeter() << ")\n";
}

bool Rectangle::isSquare() const {
    const double EPSILON = 0.0001;
    return std::abs(m_width - m_height) < EPSILON;
}
```

**main.cpp** (Using the class)
```cpp
#include "Rectangle.h"
#include <iostream>
#include <stdexcept>

int main() {
    try {
        Rectangle rect1{5.0, 3.0};
        Rectangle rect2;  // Default constructor
        
        rect1.display();
        rect2.display();
        
        rect1.scale(1.5);
        rect1.display();
        
        rect2.setWidth(4.0);
        rect2.setHeight(4.0);
        
        std::cout << "rect2 is square: " << (rect2.isSquare() ? "Yes" : "No") << '\n';
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    
    return 0;
}
```

### Inline Functions in Headers

```cpp
// Timer.h
#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <iostream>

class Timer {
private:
    std::chrono::steady_clock::time_point m_startTime;
    bool m_running;

public:
    Timer() : m_running{false} {}
    
    // Simple functions can be defined inline in header
    void start() {
        m_startTime = std::chrono::steady_clock::now();
        m_running = true;
    }
    
    void stop() {
        m_running = false;
    }
    
    bool isRunning() const { return m_running; }
    
    // More complex function - declare here, define in .cpp
    double getElapsedSeconds() const;
    void displayElapsed() const;
};

// Inline function definition (alternative to defining in class body)
inline void Timer::displayElapsed() const {
    std::cout << "Elapsed time: " << getElapsedSeconds() << " seconds\n";
}

#endif
```

**Timer.cpp**
```cpp
#include "Timer.h"

double Timer::getElapsedSeconds() const {
    if (!m_running) {
        return 0.0;
    }
    
    auto currentTime = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
        currentTime - m_startTime);
    
    return elapsed.count() / 1000.0;
}
```

---

## Real-World Applications

### Game Entity System

```cpp
// GameEntity.h
#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include <string>

class GameEntity {
private:
    static int s_nextId;
    
    int m_id;
    std::string m_name;
    double m_x, m_y;
    int m_health;
    int m_maxHealth;
    bool m_isActive;

public:
    // Constructors
    GameEntity(const std::string& name, double x = 0.0, double y = 0.0, int maxHealth = 100);
    ~GameEntity();
    
    // Accessors
    int getId() const { return m_id; }
    const std::string& getName() const { return m_name; }
    double getX() const { return m_x; }
    double getY() const { return m_y; }
    int getHealth() const { return m_health; }
    int getMaxHealth() const { return m_maxHealth; }
    bool isActive() const { return m_isActive; }
    bool isAlive() const { return m_health > 0; }
    
    // Mutators
    void setPosition(double x, double y);
    void move(double deltaX, double deltaY);
    void takeDamage(int damage);
    void heal(int amount);
    void setActive(bool active) { m_isActive = active; }
    
    // Utility functions
    double distanceTo(const GameEntity& other) const;
    void displayStatus() const;
    
    // Static function
    static int getTotalEntities() { return s_nextId - 1; }
};

#endif
```

### Bank Account with Transaction History

```cpp
// BankAccount.h
#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>
#include <vector>

struct Transaction {
    enum Type { Deposit, Withdrawal, Transfer };
    Type type;
    double amount;
    std::string description;
    std::string timestamp;
};

class BankAccount {
private:
    std::string m_accountNumber;
    std::string m_ownerName;
    double m_balance;
    std::vector<Transaction> m_transactions;
    static double s_interestRate;

public:
    BankAccount(const std::string& accountNumber, const std::string& ownerName, 
                double initialDeposit = 0.0);
    
    // Account operations
    bool deposit(double amount, const std::string& description = "Deposit");
    bool withdraw(double amount, const std::string& description = "Withdrawal");
    bool transferTo(BankAccount& recipient, double amount, 
                   const std::string& description = "Transfer");
    
    // Interest calculation
    void applyInterest();
    static void setInterestRate(double rate) { s_interestRate = rate; }
    static double getInterestRate() { return s_interestRate; }
    
    // Account information
    double getBalance() const { return m_balance; }
    const std::string& getAccountNumber() const { return m_accountNumber; }
    const std::string& getOwnerName() const { return m_ownerName; }
    
    // Transaction history
    void displayTransactionHistory() const;
    void displayAccountSummary() const;
    
private:
    void addTransaction(Transaction::Type type, double amount, const std::string& description);
    std::string getCurrentTimestamp() const;
};

#endif
```

---

## Best Practices and Modern Usage

### Do's ✅

1. **Use member initializer lists**:
```cpp
class Point {
    double m_x, m_y;
public:
    Point(double x, double y) : m_x{x}, m_y{y} {}  // ✅ Efficient initialization
};
```

2. **Make single-argument constructors explicit**:
```cpp
class Temperature {
public:
    explicit Temperature(double celsius) : m_celsius{celsius} {}  // ✅ Prevents implicit conversion
};
```

3. **Use const for read-only member functions**:
```cpp
class Circle {
public:
    double area() const { return 3.14159 * m_radius * m_radius; }  // ✅ const-correct
};
```

4. **Follow RAII principle**:
```cpp
class FileHandler {
public:
    FileHandler(const std::string& filename) { /* acquire resource */ }
    ~FileHandler() { /* release resource */ }  // ✅ Automatic cleanup
};
```

### Don'ts ❌

1. **Don't make everything public**:
```cpp
class BadClass {
public:
    int importantData;  // ❌ Should be private with accessors
};
```

2. **Don't forget const-correctness**:
```cpp
class Circle {
public:
    double area() { return 3.14159 * m_radius * m_radius; }  // ❌ Should be const
};
```

3. **Don't use assignment in constructor body for const members**:
```cpp
class Book {
    const std::string m_title;
public:
    Book(const std::string& title) {
        m_title = title;  // ❌ Error: can't assign to const
    }
};
```

### Modern C++ Features

```cpp
// C++11: Default and delete
class NonCopyable {
public:
    NonCopyable() = default;                           // ✅ Explicitly defaulted
    NonCopyable(const NonCopyable&) = delete;         // ✅ Explicitly deleted
    NonCopyable& operator=(const NonCopyable&) = delete;
};

// C++11: Delegating constructors
class Rectangle {
public:
    Rectangle(double w, double h) : m_width{w}, m_height{h} {}
    Rectangle() : Rectangle(1.0, 1.0) {}              // ✅ Delegates to main constructor
};

// C++14: Auto return type deduction
class Calculator {
public:
    auto add(double a, double b) const { return a + b; }  // ✅ Auto deduced as double
};
```

---

## Conclusion

Object-Oriented Programming with classes provides:

- **Encapsulation** - Bundle data and behavior together
- **Data Protection** - Control access through public/private
- **Automatic Resource Management** - RAII with constructors/destructors
- **Code Reusability** - Objects can be used in multiple contexts
- **Maintainability** - Changes to internal implementation don't affect users
- **Type Safety** - Custom types prevent misuse

Classes transform passive data structures into intelligent objects that can manage their own state and behavior. This foundation enables advanced OOP concepts like inheritance and polymorphism covered in later chapters.

**Next: Chapter 15 - More on Classes (Operator Overloading, Friend Functions, Static Members)**

# Chapter 15: More on Classes - Advanced Class Features

## Building on Class Fundamentals: Advanced Features for Professional Programming

In Chapter 14, we learned the basics of classes and encapsulation. Now we'll explore advanced features that make classes more powerful and flexible: operator overloading, friend functions, static members, and more sophisticated class design patterns.

---

## 15.1 - The Hidden "this" Pointer and const Member Functions

### Understanding Object Context in Member Functions

Every non-static member function receives an implicit `this` pointer:

```cpp
#include <iostream>

class Counter {
private:
    int m_value;

public:
    Counter(int value = 0) : m_value{value} {}
    
    // These two functions are equivalent:
    void increment1() {
        m_value++;        // Implicit: this->m_value++
    }
    
    void increment2() {
        this->m_value++;  // Explicit use of this pointer
    }
    
    // const member function - this becomes const Counter* const this
    int getValue() const {
        return m_value;   // Can't modify m_value through const this
        // m_value++;     // ❌ Error: cannot modify in const function
    }
    
    // Method chaining using this
    Counter& add(int amount) {
        m_value += amount;
        return *this;     // Return reference to current object
    }
    
    // Self-comparison
    bool equals(const Counter& other) const {
        return this->m_value == other.m_value;
    }
    
    void displayAddress() const {
        std::cout << "Object at address: " << this << ", value: " << m_value << '\n';
    }
};

int main() {
    Counter a{10};
    Counter b{20};
    
    a.displayAddress();  // Different addresses
    b.displayAddress();
    
    // Method chaining
    a.add(5).add(3);     // Chained calls: 10 + 5 + 3 = 18
    std::cout << "a after chaining: " << a.getValue() << '\n';
    
    // const object can only call const member functions
    const Counter c{100};
    std::cout << "const counter: " << c.getValue() << '\n';  // ✅ const function
    // c.increment1();   // ❌ Error: non-const function on const object
    
    return 0;
}
```

### Const-Correctness in Practice

```cpp
#include <iostream>
#include <string>
#include <vector>

class Student {
private:
    std::string m_name;
    std::vector<int> m_grades;
    mutable int m_accessCount;  // mutable allows modification in const functions

public:
    Student(const std::string& name) : m_name{name}, m_accessCount{0} {}
    
    // const member functions - promise not to modify object state
    const std::string& getName() const {
        ++m_accessCount;  // ✅ mutable member can be modified
        return m_name;
    }
    
    double getAverageGrade() const {
        if (m_grades.empty()) return 0.0;
        
        int sum = 0;
        for (int grade : m_grades) {
            sum += grade;
        }
        return static_cast<double>(sum) / m_grades.size();
    }
    
    size_t getGradeCount() const { return m_grades.size(); }
    
    int getAccessCount() const { return m_accessCount; }
    
    // non-const member functions - can modify object state
    void addGrade(int grade) {
        if (grade >= 0 && grade <= 100) {
            m_grades.push_back(grade);
        }
    }
    
    void setName(const std::string& name) {
        m_name = name;
    }
    
    // const and non-const overloads
    const std::vector<int>& getGrades() const {
        std::cout << "const version called\n";
        return m_grades;
    }
    
    std::vector<int>& getGrades() {
        std::cout << "non-const version called\n";
        return m_grades;
    }
};

void processStudent(const Student& student) {  // const reference parameter
    std::cout << "Processing student: " << student.getName() << '\n';
    std::cout << "Average grade: " << student.getAverageGrade() << '\n';
    // student.addGrade(95);  // ❌ Error: const object, non-const function
}

int main() {
    Student alice{"Alice"};
    alice.addGrade(85);
    alice.addGrade(92);
    alice.addGrade(78);
    
    processStudent(alice);  // Calls const member functions
    
    // Demonstrate const vs non-const overloads
    const Student& constRef = alice;
    constRef.getGrades();   // Calls const version
    alice.getGrades();      // Calls non-const version
    
    std::cout << "Access count: " << alice.getAccessCount() << '\n';
    
    return 0;
}
```

---

## 15.2 - Classes and Header Files Organization

### Professional Project Structure

**Math/Vector2D.h** (Interface)
```cpp
#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

namespace Math {

class Vector2D {
private:
    double m_x, m_y;

public:
    // Constructors
    Vector2D(double x = 0.0, double y = 0.0);
    Vector2D(const Vector2D& other);  // Copy constructor
    
    // Destructor
    ~Vector2D() = default;
    
    // Assignment operator
    Vector2D& operator=(const Vector2D& other);
    
    // Accessors
    double getX() const { return m_x; }
    double getY() const { return m_y; }
    double magnitude() const;
    double magnitudeSquared() const;
    
    // Mutators
    void setX(double x) { m_x = x; }
    void setY(double y) { m_y = y; }
    void set(double x, double y);
    void normalize();
    
    // Vector operations
    Vector2D& add(const Vector2D& other);
    Vector2D& subtract(const Vector2D& other);
    Vector2D& multiply(double scalar);
    double dotProduct(const Vector2D& other) const;
    
    // Utility functions
    void print() const;
    bool isZero() const;
    
    // Static utility functions
    static double distance(const Vector2D& a, const Vector2D& b);
    static Vector2D lerp(const Vector2D& a, const Vector2D& b, double t);
    
    // Friend functions (declared here, defined outside)
    friend Vector2D operator+(const Vector2D& left, const Vector2D& right);
    friend Vector2D operator-(const Vector2D& left, const Vector2D& right);
    friend Vector2D operator*(const Vector2D& vec, double scalar);
    friend Vector2D operator*(double scalar, const Vector2D& vec);
    friend std::ostream& operator<<(std::ostream& out, const Vector2D& vec);
};

// Free function declarations
Vector2D operator+(const Vector2D& left, const Vector2D& right);
Vector2D operator-(const Vector2D& left, const Vector2D& right);
Vector2D operator*(const Vector2D& vec, double scalar);
Vector2D operator*(double scalar, const Vector2D& vec);
std::ostream& operator<<(std::ostream& out, const Vector2D& vec);

} // namespace Math

#endif
```

**Math/Vector2D.cpp** (Implementation)
```cpp
#include "Vector2D.h"
#include <cmath>
#include <iostream>

namespace Math {

// Constructor implementations
Vector2D::Vector2D(double x, double y) : m_x{x}, m_y{y} {}

Vector2D::Vector2D(const Vector2D& other) : m_x{other.m_x}, m_y{other.m_y} {}

// Assignment operator
Vector2D& Vector2D::operator=(const Vector2D& other) {
    if (this != &other) {  // Self-assignment check
        m_x = other.m_x;
        m_y = other.m_y;
    }
    return *this;
}

// Magnitude calculations
double Vector2D::magnitude() const {
    return std::sqrt(m_x * m_x + m_y * m_y);
}

double Vector2D::magnitudeSquared() const {
    return m_x * m_x + m_y * m_y;  // Avoid expensive sqrt when possible
}

// Mutator implementations
void Vector2D::set(double x, double y) {
    m_x = x;
    m_y = y;
}

void Vector2D::normalize() {
    double mag = magnitude();
    if (mag > 0.0) {
        m_x /= mag;
        m_y /= mag;
    }
}

// Vector operation implementations
Vector2D& Vector2D::add(const Vector2D& other) {
    m_x += other.m_x;
    m_y += other.m_y;
    return *this;
}

Vector2D& Vector2D::subtract(const Vector2D& other) {
    m_x -= other.m_x;
    m_y -= other.m_y;
    return *this;
}

Vector2D& Vector2D::multiply(double scalar) {
    m_x *= scalar;
    m_y *= scalar;
    return *this;
}

double Vector2D::dotProduct(const Vector2D& other) const {
    return m_x * other.m_x + m_y * other.m_y;
}

// Utility function implementations
void Vector2D::print() const {
    std::cout << "(" << m_x << ", " << m_y << ")";
}

bool Vector2D::isZero() const {
    const double EPSILON = 0.0001;
    return std::abs(m_x) < EPSILON && std::abs(m_y) < EPSILON;
}

// Static function implementations
double Vector2D::distance(const Vector2D& a, const Vector2D& b) {
    double dx = a.m_x - b.m_x;
    double dy = a.m_y - b.m_y;
    return std::sqrt(dx * dx + dy * dy);
}

Vector2D Vector2D::lerp(const Vector2D& a, const Vector2D& b, double t) {
    return Vector2D{
        a.m_x + t * (b.m_x - a.m_x),
        a.m_y + t * (b.m_y - a.m_y)
    };
}

// Friend function implementations
Vector2D operator+(const Vector2D& left, const Vector2D& right) {
    return Vector2D{left.m_x + right.m_x, left.m_y + right.m_y};
}

Vector2D operator-(const Vector2D& left, const Vector2D& right) {
    return Vector2D{left.m_x - right.m_x, left.m_y - right.m_y};
}

Vector2D operator*(const Vector2D& vec, double scalar) {
    return Vector2D{vec.m_x * scalar, vec.m_y * scalar};
}

Vector2D operator*(double scalar, const Vector2D& vec) {
    return vec * scalar;  // Reuse the above operator
}

std::ostream& operator<<(std::ostream& out, const Vector2D& vec) {
    out << "(" << vec.m_x << ", " << vec.m_y << ")";
    return out;
}

} // namespace Math
```

**main.cpp** (Usage)
```cpp
#include "Math/Vector2D.h"
#include <iostream>

int main() {
    using namespace Math;
    
    Vector2D a{3.0, 4.0};
    Vector2D b{1.0, 2.0};
    
    std::cout << "Vector a: " << a << '\n';
    std::cout << "Vector b: " << b << '\n';
    std::cout << "Magnitude of a: " << a.magnitude() << '\n';
    
    // Using operators
    Vector2D c = a + b;
    std::cout << "a + b = " << c << '\n';
    
    Vector2D d = a * 2.0;
    std::cout << "a * 2 = " << d << '\n';
    
    // Using member functions
    Vector2D e = a;
    e.normalize();
    std::cout << "Normalized a: " << e << '\n';
    
    // Static functions
    std::cout << "Distance between a and b: " << Vector2D::distance(a, b) << '\n';
    
    return 0;
}
```

---

## 15.3 - Nested Types and Nested Classes

### Nested Enumerations and Type Aliases

```cpp
#include <iostream>
#include <string>
#include <vector>

class NetworkConnection {
public:
    // Nested enumeration - scoped to the class
    enum class Protocol { TCP, UDP, HTTP, HTTPS };
    enum class Status { Disconnected, Connecting, Connected, Error };
    
    // Nested type alias
    using Port = unsigned short;
    using Address = std::string;
    
private:
    Address m_serverAddress;
    Port m_port;
    Protocol m_protocol;
    Status m_status;

public:
    NetworkConnection(const Address& address, Port port, Protocol protocol)
        : m_serverAddress{address}, m_port{port}, m_protocol{protocol}, m_status{Status::Disconnected} {}
    
    bool connect() {
        m_status = Status::Connecting;
        std::cout << "Connecting to " << m_serverAddress << ":" << m_port;
        std::cout << " using " << protocolToString(m_protocol) << '\n';
        
        // Simulate connection logic
        m_status = Status::Connected;
        return true;
    }
    
    void disconnect() {
        if (m_status == Status::Connected) {
            m_status = Status::Disconnected;
            std::cout << "Disconnected from server\n";
        }
    }
    
    Status getStatus() const { return m_status; }
    Protocol getProtocol() const { return m_protocol; }
    
private:
    std::string protocolToString(Protocol protocol) const {
        switch (protocol) {
            case Protocol::TCP:   return "TCP";
            case Protocol::UDP:   return "UDP";
            case Protocol::HTTP:  return "HTTP";
            case Protocol::HTTPS: return "HTTPS";
            default: return "Unknown";
        }
    }
};

int main() {
    // Use nested types with scope resolution
    NetworkConnection conn{"192.168.1.1", 8080, NetworkConnection::Protocol::HTTP};
    
    conn.connect();
    
    if (conn.getStatus() == NetworkConnection::Status::Connected) {
        std::cout << "Connection successful!\n";
    }
    
    conn.disconnect();
    
    return 0;
}
```

### Nested Classes for Helper Objects

```cpp
#include <iostream>
#include <vector>
#include <string>

class Database {
private:
    // Nested class for internal use
    class Connection {
    private:
        std::string m_connectionString;
        bool m_isOpen;
        
    public:
        Connection(const std::string& connStr) : m_connectionString{connStr}, m_isOpen{false} {}
        
        bool open() {
            std::cout << "Opening database connection: " << m_connectionString << '\n';
            m_isOpen = true;
            return true;
        }
        
        void close() {
            if (m_isOpen) {
                std::cout << "Closing database connection\n";
                m_isOpen = false;
            }
        }
        
        bool execute(const std::string& query) {
            if (!m_isOpen) return false;
            std::cout << "Executing: " << query << '\n';
            return true;
        }
        
        bool isOpen() const { return m_isOpen; }
    };
    
    Connection m_connection;
    std::string m_databaseName;

public:
    Database(const std::string& dbName, const std::string& connStr)
        : m_databaseName{dbName}, m_connection{connStr} {}
    
    ~Database() {
        m_connection.close();
    }
    
    bool connect() {
        return m_connection.open();
    }
    
    bool executeQuery(const std::string& query) {
        return m_connection.execute(query);
    }
    
    bool isConnected() const {
        return m_connection.isOpen();
    }
    
    const std::string& getName() const { return m_databaseName; }
};

int main() {
    Database userDB{"UserDatabase", "postgresql://localhost:5432/users"};
    
    if (userDB.connect()) {
        userDB.executeQuery("SELECT * FROM users");
        userDB.executeQuery("UPDATE users SET last_login = NOW() WHERE id = 1");
    }
    
    // Connection automatically closed by destructor
    
    return 0;
}
```

---

## 15.4 - Timing Your Code

### Performance Measurement Class

```cpp
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <string>

class Timer {
private:
    std::chrono::steady_clock::time_point m_startTime;
    std::chrono::steady_clock::time_point m_endTime;
    bool m_running;

public:
    Timer() : m_running{false} {}
    
    void start() {
        m_startTime = std::chrono::steady_clock::now();
        m_running = true;
    }
    
    void stop() {
        if (m_running) {
            m_endTime = std::chrono::steady_clock::now();
            m_running = false;
        }
    }
    
    double getElapsedMilliseconds() const {
        if (m_running) {
            auto currentTime = std::chrono::steady_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(
                currentTime - m_startTime);
            return elapsed.count() / 1000.0;
        } else {
            auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(
                m_endTime - m_startTime);
            return elapsed.count() / 1000.0;
        }
    }
    
    double getElapsedSeconds() const {
        return getElapsedMilliseconds() / 1000.0;
    }
    
    bool isRunning() const { return m_running; }
};

// RAII Timer for automatic measurement
class ScopedTimer {
private:
    Timer m_timer;
    std::string m_label;

public:
    ScopedTimer(const std::string& label) : m_label{label} {
        std::cout << "Starting: " << m_label << '\n';
        m_timer.start();
    }
    
    ~ScopedTimer() {
        m_timer.stop();
        std::cout << "Completed: " << m_label 
                  << " (" << m_timer.getElapsedMilliseconds() << " ms)\n";
    }
};

// Performance testing functions
void slowFunction() {
    std::vector<int> data(1000000);
    for (int i = 0; i < 1000000; ++i) {
        data[i] = i * i;
    }
    std::sort(data.begin(), data.end());
}

void fastFunction() {
    std::vector<int> data;
    data.reserve(1000000);  // Pre-allocate memory
    for (int i = 0; i < 1000000; ++i) {
        data.push_back(i * i);
    }
}

int main() {
    // Manual timing
    Timer manualTimer;
    
    manualTimer.start();
    slowFunction();
    manualTimer.stop();
    
    std::cout << "Manual timing - Slow function: " 
              << manualTimer.getElapsedMilliseconds() << " ms\n";
    
    // RAII automatic timing
    {
        ScopedTimer autoTimer{"Fast function execution"};
        fastFunction();
        // Timer automatically stops and reports when going out of scope
    }
    
    // Multiple measurements
    std::vector<double> measurements;
    for (int i = 0; i < 5; ++i) {
        Timer timer;
        timer.start();
        fastFunction();
        timer.stop();
        measurements.push_back(timer.getElapsedMilliseconds());
    }
    
    double average = 0.0;
    for (double time : measurements) {
        average += time;
    }
    average /= measurements.size();
    
    std::cout << "Average time over 5 runs: " << average << " ms\n";
    
    return 0;
}
```

---

## 15.5 - Static Member Variables

### Shared Data Among All Instances

```cpp
#include <iostream>
#include <string>
#include <vector>

class Employee {
private:
    static int s_nextEmployeeId;        // Shared by all instances
    static double s_minimumWage;        // Company-wide policy
    static std::string s_companyName;   // Company information
    
    int m_employeeId;                   // Instance-specific data
    std::string m_name;
    double m_salary;
    
public:
    Employee(const std::string& name, double salary)
        : m_employeeId{s_nextEmployeeId++}, m_name{name}, m_salary{salary} {
        if (salary < s_minimumWage) {
            m_salary = s_minimumWage;
            std::cout << "Salary adjusted to minimum wage for " << m_name << '\n';
        }
    }
    
    // Static member functions - can only access static members
    static void setCompanyName(const std::string& name) {
        s_companyName = name;
    }
    
    static const std::string& getCompanyName() {
        return s_companyName;
    }
    
    static void setMinimumWage(double wage) {
        if (wage > 0) {
            s_minimumWage = wage;
            std::cout << "Minimum wage updated to $" << wage << '\n';
        }
    }
    
    static double getMinimumWage() {
        return s_minimumWage;
    }
    
    static int getNextEmployeeId() {
        return s_nextEmployeeId;
    }
    
    static int getTotalEmployees() {
        return s_nextEmployeeId - 1;
    }
    
    // Instance member functions
    int getEmployeeId() const { return m_employeeId; }
    const std::string& getName() const { return m_name; }
    double getSalary() const { return m_salary; }
    
    void setSalary(double salary) {
        if (salary >= s_minimumWage) {
            m_salary = salary;
        } else {
            std::cout << "Cannot set salary below minimum wage\n";
        }
    }
    
    void displayInfo() const {
        std::cout << "Employee #" << m_employeeId << ": " << m_name 
                  << " at " << s_companyName << " earns $" << m_salary << '\n';
    }
};

// Static member variable definitions (required outside class)
int Employee::s_nextEmployeeId = 1000;         // Start employee IDs at 1000
double Employee::s_minimumWage = 15.0;         // $15/hour minimum
std::string Employee::s_companyName = "TechCorp";

int main() {
    std::cout << "Company: " << Employee::getCompanyName() << '\n';
    std::cout << "Current minimum wage: $" << Employee::getMinimumWage() << '\n';
    std::cout << "Total employees: " << Employee::getTotalEmployees() << '\n';
    
    // Create employees
    Employee alice{"Alice Johnson", 25.0};
    Employee bob{"Bob Smith", 10.0};    // Below minimum, will be adjusted
    Employee charlie{"Charlie Brown", 30.0};
    
    alice.displayInfo();
    bob.displayInfo();
    charlie.displayInfo();
    
    std::cout << "Total employees after creation: " << Employee::getTotalEmployees() << '\n';
    
    // Update company-wide policies
    Employee::setMinimumWage(18.0);
    Employee::setCompanyName("TechCorp Solutions");
    
    // Try to set salary below new minimum
    bob.setSalary(16.0);  // Will be rejected
    bob.setSalary(20.0);  // Will be accepted
    
    bob.displayInfo();
    
    return 0;
}
```

### Static Members for Configuration and Tracking

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

class GameEntity {
private:
    static int s_nextId;
    static std::vector<GameEntity*> s_allEntities;  // Track all instances
    static bool s_debugMode;
    static int s_maxEntities;
    
    int m_id;
    std::string m_name;
    double m_x, m_y;
    bool m_active;
    
public:
    GameEntity(const std::string& name, double x = 0.0, double y = 0.0)
        : m_id{s_nextId++}, m_name{name}, m_x{x}, m_y{y}, m_active{true} {
        
        if (s_allEntities.size() >= static_cast<size_t>(s_maxEntities)) {
            throw std::runtime_error("Maximum number of entities exceeded");
        }
        
        s_allEntities.push_back(this);
        
        if (s_debugMode) {
            std::cout << "Entity created: " << m_name << " (ID: " << m_id << ")\n";
        }
    }
    
    ~GameEntity() {
        // Remove from static tracking vector
        auto it = std::find(s_allEntities.begin(), s_allEntities.end(), this);
        if (it != s_allEntities.end()) {
            s_allEntities.erase(it);
        }
        
        if (s_debugMode) {
            std::cout << "Entity destroyed: " << m_name << " (ID: " << m_id << ")\n";
        }
    }
    
    // Static configuration functions
    static void setDebugMode(bool enabled) { s_debugMode = enabled; }
    static bool isDebugMode() { return s_debugMode; }
    static void setMaxEntities(int max) { s_maxEntities = max; }
    static int getMaxEntities() { return s_maxEntities; }
    
    // Static entity management
    static size_t getEntityCount() { return s_allEntities.size(); }
    
    static void printAllEntities() {
        std::cout << "=== All Entities (" << s_allEntities.size() << ") ===\n";
        for (const GameEntity* entity : s_allEntities) {
            entity->printInfo();
        }
    }
    
    static GameEntity* findEntityById(int id) {
        for (GameEntity* entity : s_allEntities) {
            if (entity->m_id == id) {
                return entity;
            }
        }
        return nullptr;
    }
    
    static void updateAllEntities() {
        for (GameEntity* entity : s_allEntities) {
            if (entity->m_active) {
                entity->update();
            }
        }
    }
    
    // Instance methods
    int getId() const { return m_id; }
    const std::string& getName() const { return m_name; }
    void setPosition(double x, double y) { m_x = x; m_y = y; }
    void setActive(bool active) { m_active = active; }
    bool isActive() const { return m_active; }
    
    void printInfo() const {
        std::cout << "  " << m_name << " (ID: " << m_id << ") at (" 
                  << m_x << ", " << m_y << ") " 
                  << (m_active ? "[Active]" : "[Inactive]") << '\n';
    }
    
private:
    void update() {
        // Simple movement simulation
        m_x += 1.0;
        if (s_debugMode) {
            std::cout << m_name << " moved to (" << m_x << ", " << m_y << ")\n";
        }
    }
};

// Static member definitions
int GameEntity::s_nextId = 1;
std::vector<GameEntity*> GameEntity::s_allEntities;
bool GameEntity::s_debugMode = false;
int GameEntity::s_maxEntities = 100;

int main() {
    // Configure system
    GameEntity::setDebugMode(true);
    GameEntity::setMaxEntities(5);
    
    std::cout << "Max entities: " << GameEntity::getMaxEntities() << '\n';
    std::cout << "Current count: " << GameEntity::getEntityCount() << '\n';
    
    // Create entities
    GameEntity player{"Player", 0.0, 0.0};
    GameEntity enemy1{"Enemy1", 10.0, 5.0};
    GameEntity enemy2{"Enemy2", -5.0, 8.0};
    
    GameEntity::printAllEntities();
    
    // Find specific entity
    GameEntity* found = GameEntity::findEntityById(2);
    if (found) {
        std::cout << "Found entity: " << found->getName() << '\n';
        found->setActive(false);
    }
    
    // Update all entities
    std::cout << "\n=== Updating all entities ===\n";
    GameEntity::updateAllEntities();
    
    GameEntity::printAllEntities();
    
    return 0;
    // All entities destroyed automatically, removed from static vector
}
```

---

## 15.6 - Static Member Functions

### Static Functions for Utility and Factory Patterns

```cpp
#include <iostream>
#include <string>
#include <cmath>
#include <random>

class MathUtils {
public:
    // Static utility functions - no instance required
    static double degreesToRadians(double degrees) {
        return degrees * M_PI / 180.0;
    }
    
    static double radiansToDegrees(double radians) {
        return radians * 180.0 / M_PI;
    }
    
    static bool isPrime(int number) {
        if (number <= 1) return false;
        if (number <= 3) return true;
        if (number % 2 == 0 || number % 3 == 0) return false;
        
        for (int i = 5; i * i <= number; i += 6) {
            if (number % i == 0 || number % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
    
    static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    static double distance(double x1, double y1, double x2, double y2) {
        double dx = x2 - x1;
        double dy = y2 - y1;
        return std::sqrt(dx * dx + dy * dy);
    }
};

class Color {
private:
    int m_red, m_green, m_blue;
    
    // Private constructor - force use of factory methods
    Color(int red, int green, int blue) 
        : m_red{clamp(red)}, m_green{clamp(green)}, m_blue{clamp(blue)} {}

public:
    // Static factory methods
    static Color fromRGB(int red, int green, int blue) {
        return Color{red, green, blue};
    }
    
    static Color fromHex(const std::string& hexColor) {
        // Simplified hex parsing (assumes #RRGGBB format)
        if (hexColor.length() == 7 && hexColor[0] == '#') {
            int red = std::stoi(hexColor.substr(1, 2), nullptr, 16);
            int green = std::stoi(hexColor.substr(3, 2), nullptr, 16);
            int blue = std::stoi(hexColor.substr(5, 2), nullptr, 16);
            return Color{red, green, blue};
        }
        return Color{0, 0, 0}; // Default to black for invalid input
    }
    
    static Color random() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> dis(0, 255);
        
        return Color{dis(gen), dis(gen), dis(gen)};
    }
    
    // Predefined color constants (static factory methods)
    static Color red() { return Color{255, 0, 0}; }
    static Color green() { return Color{0, 255, 0}; }
    static Color blue() { return Color{0, 0, 255}; }
    static Color white() { return Color{255, 255, 255}; }
    static Color black() { return Color{0, 0, 0}; }
    
    // Instance methods
    int getRed() const { return m_red; }
    int getGreen() const { return m_green; }
    int getBlue() const { return m_blue; }
    
    void display() const {
        std::cout << "RGB(" << m_red << ", " << m_green << ", " << m_blue << ")";
    }
    
    std::string toHex() const {
        char buffer[8];
        std::sprintf(buffer, "#%02X%02X%02X", m_red, m_green, m_blue);
        return std::string(buffer);
    }
    
private:
    static int clamp(int value) {
        return (value < 0) ? 0 : (value > 255) ? 255 : value;
    }
};

// Singleton pattern using static members
class Logger {
private:
    static Logger* s_instance;
    std::string m_logLevel;
    bool m_enabled;
    
    // Private constructor prevents direct instantiation
    Logger() : m_logLevel{"INFO"}, m_enabled{true} {}

public:
    // Static method to get singleton instance
    static Logger& getInstance() {
        if (s_instance == nullptr) {
            s_instance = new Logger();
        }
        return *s_instance;
    }
    
    // Delete copy constructor and assignment operator
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    
    static void setLogLevel(const std::string& level) {
        getInstance().m_logLevel = level;
    }
    
    static void enable() { getInstance().m_enabled = true; }
    static void disable() { getInstance().m_enabled = false; }
    
    static void log(const std::string& message) {
        Logger& logger = getInstance();
        if (logger.m_enabled) {
            std::cout << "[" << logger.m_logLevel << "] " << message << '\n';
        }
    }
    
    static void info(const std::string& message) {
        log("INFO: " + message);
    }
    
    static void error(const std::string& message) {
        log("ERROR: " + message);
    }
    
    // Cleanup (optional - for demonstration)
    static void cleanup() {
        delete s_instance;
        s_instance = nullptr;
    }
};

// Static member definition
Logger* Logger::s_instance = nullptr;

int main() {
    // Using static utility functions
    std::cout << "45 degrees = " << MathUtils::degreesToRadians(45.0) << " radians\n";
    std::cout << "Is 17 prime? " << (MathUtils::isPrime(17) ? "Yes" : "No") << '\n';
    std::cout << "GCD(48, 18) = " << MathUtils::gcd(48, 18) << '\n';
    std::cout << "Distance: " << MathUtils::distance(0, 0, 3, 4) << '\n';
    
    // Using static factory methods
    Color red = Color::red();
    Color fromHex = Color::fromHex("#FF5733");
    Color random = Color::random();
    
    std::cout << "\nColors:\n";
    std::cout << "Red: "; red.display(); std::cout << " -> " << red.toHex() << '\n';
    std::cout << "From hex: "; fromHex.display(); std::cout << " -> " << fromHex.toHex() << '\n';
    std::cout << "Random: "; random.display(); std::cout << " -> " << random.toHex() << '\n';
    
    // Using singleton logger
    Logger::info("Application started");
    Logger::setLogLevel("DEBUG");
    Logger::log("This is a debug message");
    Logger::error("This is an error message");
    
    Logger::disable();
    Logger::info("This won't be printed");
    
    Logger::enable();
    Logger::info("Logging re-enabled");
    
    Logger::cleanup();  // Optional cleanup
    
    return 0;
}
```

---

## 15.7 - Friend Functions and Friend Classes

### Friend Functions for Enhanced Operator Overloading

```cpp
#include <iostream>
#include <string>

class Fraction {
private:
    int m_numerator;
    int m_denominator;
    
    // Helper function to simplify fractions
    void simplify() {
        int gcd = calculateGCD(std::abs(m_numerator), std::abs(m_denominator));
        m_numerator /= gcd;
        m_denominator /= gcd;
        
        // Keep denominator positive
        if (m_denominator < 0) {
            m_numerator = -m_numerator;
            m_denominator = -m_denominator;
        }
    }
    
    static int calculateGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    Fraction(int numerator = 0, int denominator = 1) 
        : m_numerator{numerator}, m_denominator{denominator} {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        simplify();
    }
    
    // Member function operators (for assignment-style operations)
    Fraction& operator+=(const Fraction& other) {
        m_numerator = m_numerator * other.m_denominator + other.m_numerator * m_denominator;
        m_denominator = m_denominator * other.m_denominator;
        simplify();
        return *this;
    }
    
    Fraction& operator-=(const Fraction& other) {
        m_numerator = m_numerator * other.m_denominator - other.m_numerator * m_denominator;
        m_denominator = m_denominator * other.m_denominator;
        simplify();
        return *this;
    }
    
    // Friend functions for binary operators (need access to private members)
    friend Fraction operator+(const Fraction& left, const Fraction& right);
    friend Fraction operator-(const Fraction& left, const Fraction& right);
    friend Fraction operator*(const Fraction& left, const Fraction& right);
    friend Fraction operator/(const Fraction& left, const Fraction& right);
    
    // Friend functions for comparison operators
    friend bool operator==(const Fraction& left, const Fraction& right);
    friend bool operator!=(const Fraction& left, const Fraction& right);
    friend bool operator<(const Fraction& left, const Fraction& right);
    friend bool operator>(const Fraction& left, const Fraction& right);
    
    // Friend function for stream insertion
    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& in, Fraction& fraction);
    
    // Accessor methods
    int getNumerator() const { return m_numerator; }
    int getDenominator() const { return m_denominator; }
    
    double toDouble() const {
        return static_cast<double>(m_numerator) / m_denominator;
    }
};

// Friend function implementations (have access to private members)
Fraction operator+(const Fraction& left, const Fraction& right) {
    return Fraction{
        left.m_numerator * right.m_denominator + right.m_numerator * left.m_denominator,
        left.m_denominator * right.m_denominator
    };
}

Fraction operator-(const Fraction& left, const Fraction& right) {
    return Fraction{
        left.m_numerator * right.m_denominator - right.m_numerator * left.m_denominator,
        left.m_denominator * right.m_denominator
    };
}

Fraction operator*(const Fraction& left, const Fraction& right) {
    return Fraction{
        left.m_numerator * right.m_numerator,
        left.m_denominator * right.m_denominator
    };
}

Fraction operator/(const Fraction& left, const Fraction& right) {
    return Fraction{
        left.m_numerator * right.m_denominator,
        left.m_denominator * right.m_numerator
    };
}

bool operator==(const Fraction& left, const Fraction& right) {
    return left.m_numerator == right.m_numerator && 
           left.m_denominator == right.m_denominator;
}

bool operator!=(const Fraction& left, const Fraction& right) {
    return !(left == right);
}

bool operator<(const Fraction& left, const Fraction& right) {
    return left.m_numerator * right.m_denominator < 
           right.m_numerator * left.m_denominator;
}

bool operator>(const Fraction& left, const Fraction& right) {
    return right < left;
}

std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
    if (fraction.m_denominator == 1) {
        out << fraction.m_numerator;
    } else {
        out << fraction.m_numerator << "/" << fraction.m_denominator;
    }
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& fraction) {
    int numerator, denominator = 1;
    char slash;
    
    in >> numerator;
    if (in.peek() == '/') {
        in >> slash >> denominator;
    }
    
    fraction = Fraction{numerator, denominator};
    return in;
}

int main() {
    try {
        Fraction a{3, 4};
        Fraction b{1, 2};
        
        std::cout << "a = " << a << '\n';
        std::cout << "b = " << b << '\n';
        
        // Using friend operators
        Fraction sum = a + b;
        Fraction difference = a - b;
        Fraction product = a * b;
        Fraction quotient = a / b;
        
        std::cout << "a + b = " << sum << '\n';
        std::cout << "a - b = " << difference << '\n';
        std::cout << "a * b = " << product << '\n';
        std::cout << "a / b = " << quotient << '\n';
        
        // Comparisons
        std::cout << "a == b: " << (a == b ? "true" : "false") << '\n';
        std::cout << "a > b: " << (a > b ? "true" : "false") << '\n';
        
        // Assignment operators
        Fraction c{1, 3};
        c += a;
        std::cout << "After c += a: c = " << c << '\n';
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    
    return 0;
}
    

# Chapters 16-18: Comprehensive Object-Oriented Programming Guide

## From Basic Classes to Advanced OOP: Inheritance, Virtual Functions, and Polymorphism

Building on the foundation from Chapters 14-15, we now explore the advanced pillars of Object-Oriented Programming: **Inheritance** (Chapter 16), **Virtual Functions** (Chapter 17), and **Polymorphism** (Chapter 18). These concepts enable code reuse, extensibility, and elegant design patterns essential for large-scale software development.

---

## Chapter 16: Inheritance - Building Class Hierarchies

### 16.1 - Introduction to Inheritance

Inheritance allows us to create new classes based on existing classes, promoting code reuse and establishing "is-a" relationships.

```cpp
#include <iostream>
#include <string>

// Base class (parent class)
class Animal {
protected:  // Accessible to derived classes, but not to external code
    std::string m_name;
    int m_age;

public:
    Animal(const std::string& name, int age) : m_name{name}, m_age{age} {
        std::cout << "Animal constructor: " << m_name << '\n';
    }
    
    ~Animal() {
        std::cout << "Animal destructor: " << m_name << '\n';
    }
    
    void eat() const {
        std::cout << m_name << " is eating\n";
    }
    
    void sleep() const {
        std::cout << m_name << " is sleeping\n";
    }
    
    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }
    
    void displayInfo() const {
        std::cout << "Animal: " << m_name << ", Age: " << m_age << '\n';
    }
};

// Derived class (child class) - inherits from Animal
class Dog : public Animal {  // "public inheritance" - is-a relationship
private:
    std::string m_breed;

public:
    Dog(const std::string& name, int age, const std::string& breed)
        : Animal{name, age}, m_breed{breed} {  // Call base class constructor
        std::cout << "Dog constructor: " << m_name << '\n';
    }
    
    ~Dog() {
        std::cout << "Dog destructor: " << m_name << '\n';
    }
    
    // Additional methods specific to Dog
    void bark() const {
        std::cout << m_name << " barks: Woof! Woof!\n";
    }
    
    void wagTail() const {
        std::cout << m_name << " wags tail happily\n";
    }
    
    const std::string& getBreed() const { return m_breed; }
    
    // Override base class method with additional information
    void displayInfo() const {
        std::cout << "Dog: " << m_name << " (" << m_breed << "), Age: " << m_age << '\n';
    }
};

class Cat : public Animal {
private:
    bool m_isIndoor;

public:
    Cat(const std::string& name, int age, bool isIndoor = true)
        : Animal{name, age}, m_isIndoor{isIndoor} {
        std::cout << "Cat constructor: " << m_name << '\n';
    }
    
    ~Cat() {
        std::cout << "Cat destructor: " << m_name << '\n';
    }
    
    void meow() const {
        std::cout << m_name << " meows: Meow! Meow!\n";
    }
    
    void purr() const {
        std::cout << m_name << " purrs contentedly\n";
    }
    
    bool isIndoor() const { return m_isIndoor; }
    
    void displayInfo() const {
        std::cout << "Cat: " << m_name << ", Age: " << m_age 
                  << " (" << (m_isIndoor ? "Indoor" : "Outdoor") << ")\n";
    }
};

int main() {
    std::cout << "=== Creating Animals ===\n";
    
    Dog buddy{"Buddy", 3, "Golden Retriever"};
    Cat whiskers{"Whiskers", 2, true};
    
    std::cout << "\n=== Using inherited methods ===\n";
    buddy.eat();        // Inherited from Animal
    buddy.sleep();      // Inherited from Animal
    buddy.bark();       // Dog-specific method
    buddy.wagTail();    // Dog-specific method
    
    whiskers.eat();     // Inherited from Animal
    whiskers.sleep();   // Inherited from Animal
    whiskers.meow();    // Cat-specific method
    whiskers.purr();    // Cat-specific method
    
    std::cout << "\n=== Display information ===\n";
    buddy.displayInfo();    // Dog's version
    whiskers.displayInfo(); // Cat's version
    
    std::cout << "\n=== Destructors called automatically ===\n";
    return 0;
    // Destructors called in reverse order: derived, then base
}
```

### 16.2 - Order of Construction and Destruction

Understanding the construction/destruction order is crucial for proper resource management:

```cpp
#include <iostream>
#include <string>

class Component {
private:
    std::string m_name;

public:
    Component(const std::string& name) : m_name{name} {
        std::cout << "  Component '" << m_name << "' constructed\n";
    }
    
    ~Component() {
        std::cout << "  Component '" << m_name << "' destroyed\n";
    }
    
    const std::string& getName() const { return m_name; }
};

class Vehicle {
protected:
    std::string m_model;
    Component m_engine;   // Member object constructed first

public:
    Vehicle(const std::string& model) : m_model{model}, m_engine{"Engine"} {
        std::cout << "Vehicle '" << m_model << "' constructed\n";
    }
    
    ~Vehicle() {
        std::cout << "Vehicle '" << m_model << "' destroyed\n";
    }
    
    void start() const {
        std::cout << m_model << " engine starting...\n";
    }
};

class Car : public Vehicle {
private:
    Component m_radio;    // Derived class members constructed after base
    int m_doors;

public:
    Car(const std::string& model, int doors) 
        : Vehicle{model}, m_radio{"Radio"}, m_doors{doors} {
        std::cout << "Car with " << m_doors << " doors constructed\n";
    }
    
    ~Car() {
        std::cout << "Car destroyed\n";
        // Destruction order: derived members, then base class
    }
    
    void playMusic() const {
        std::cout << "Playing music on " << m_radio.getName() << '\n';
    }
};

int main() {
    std::cout << "=== Construction Order ===\n";
    {
        Car sedan{"Toyota Camry", 4};
        std::cout << "\n=== Using the car ===\n";
        sedan.start();      // Inherited method
        sedan.playMusic();  // Derived method
        std::cout << "\n=== Destruction Order ===\n";
    } // Car destructor called here
    
    return 0;
}
```

### 16.3 - Inheritance and Access Specifiers

```cpp
#include <iostream>
#include <string>

class BaseClass {
public:
    int m_publicMember = 1;

protected:
    int m_protectedMember = 2;

private:
    int m_privateMember = 3;

public:
    void publicFunction() {
        std::cout << "Base public function\n";
        // Can access all members within the class
        std::cout << "Public: " << m_publicMember << '\n';
        std::cout << "Protected: " << m_protectedMember << '\n';
        std::cout << "Private: " << m_privateMember << '\n';
    }

protected:
    void protectedFunction() {
        std::cout << "Base protected function\n";
    }

private:
    void privateFunction() {
        std::cout << "Base private function\n";
    }
};

// Public inheritance: maintains access levels
class PublicDerived : public BaseClass {
public:
    void testAccess() {
        std::cout << "=== Public Inheritance Access ===\n";
        
        // ✅ Can access public members
        m_publicMember = 10;
        publicFunction();
        
        // ✅ Can access protected members
        m_protectedMember = 20;
        protectedFunction();
        
        // ❌ Cannot access private members
        // m_privateMember = 30;     // Error
        // privateFunction();        // Error
        
        std::cout << "Public: " << m_publicMember << '\n';
        std::cout << "Protected: " << m_protectedMember << '\n';
    }
};

// Protected inheritance: public becomes protected
class ProtectedDerived : protected BaseClass {
public:
    void testAccess() {
        std::cout << "=== Protected Inheritance Access ===\n";
        
        // ✅ Can access public members (now protected in derived)
        m_publicMember = 100;
        publicFunction();
        
        // ✅ Can access protected members
        m_protectedMember = 200;
        protectedFunction();
        
        std::cout << "Public (now protected): " << m_publicMember << '\n';
        std::cout << "Protected: " << m_protectedMember << '\n';
    }
};

// Private inheritance: public and protected become private
class PrivateDerived : private BaseClass {
public:
    void testAccess() {
        std::cout << "=== Private Inheritance Access ===\n";
        
        // ✅ Can access public members (now private in derived)
        m_publicMember = 1000;
        publicFunction();
        
        // ✅ Can access protected members (now private in derived)
        m_protectedMember = 2000;
        protectedFunction();
        
        std::cout << "Public (now private): " << m_publicMember << '\n';
        std::cout << "Protected (now private): " << m_protectedMember << '\n';
    }
    
    // Expose base functionality through wrapper
    void callBasePublicFunction() {
        publicFunction();  // Can access internally
    }
};

int main() {
    PublicDerived pubDerived;
    pubDerived.testAccess();
    pubDerived.publicFunction();  // ✅ Still public
    // pubDerived.protectedFunction();  // ❌ Error: protected
    
    std::cout << '\n';
    
    ProtectedDerived protDerived;
    protDerived.testAccess();
    // protDerived.publicFunction();  // ❌ Error: now protected
    
    std::cout << '\n';
    
    PrivateDerived privDerived;
    privDerived.testAccess();
    // privDerived.publicFunction();  // ❌ Error: now private
    privDerived.callBasePublicFunction();  // ✅ Wrapped access
    
    return 0;
}
```

### 16.4 - Adding New Functionality in Derived Classes

```cpp
#include <iostream>
#include <string>
#include <vector>

// Base class for all employees
class Employee {
protected:
    std::string m_name;
    int m_employeeId;
    double m_baseSalary;

public:
    Employee(const std::string& name, int id, double baseSalary)
        : m_name{name}, m_employeeId{id}, m_baseSalary{baseSalary} {}
    
    virtual ~Employee() = default;  // Virtual destructor for proper cleanup
    
    const std::string& getName() const { return m_name; }
    int getId() const { return m_employeeId; }
    double getBaseSalary() const { return m_baseSalary; }
    
    virtual double calculatePay() const {
        return m_baseSalary;
    }
    
    virtual void displayInfo() const {
        std::cout << "Employee: " << m_name << " (ID: " << m_employeeId 
                  << ", Base: $" << m_baseSalary << ")\n";
    }
};

// Developer with additional programming skills
class Developer : public Employee {
private:
    std::vector<std::string> m_programmingLanguages;
    int m_yearsExperience;
    double m_bonusRate;

public:
    Developer(const std::string& name, int id, double baseSalary, 
              int yearsExp, double bonusRate = 0.1)
        : Employee{name, id, baseSalary}, m_yearsExperience{yearsExp}, 
          m_bonusRate{bonusRate} {}
    
    // Add new functionality
    void addProgrammingLanguage(const std::string& language) {
        m_programmingLanguages.push_back(language);
    }
    
    const std::vector<std::string>& getProgrammingLanguages() const {
        return m_programmingLanguages;
    }
    
    int getYearsExperience() const { return m_yearsExperience; }
    
    // Override base class methods with enhanced functionality
    double calculatePay() const override {
        double experienceBonus = m_yearsExperience * 1000.0;
        double languageBonus = m_programmingLanguages.size() * 500.0;
        return m_baseSalary + experienceBonus + languageBonus;
    }
    
    void displayInfo() const override {
        std::cout << "Developer: " << m_name << " (ID: " << m_employeeId << ")\n";
        std::cout << "  Base Salary: $" << m_baseSalary << '\n';
        std::cout << "  Experience: " << m_yearsExperience << " years\n";
        std::cout << "  Languages: ";
        for (size_t i = 0; i < m_programmingLanguages.size(); ++i) {
            std::cout << m_programmingLanguages[i];
            if (i < m_programmingLanguages.size() - 1) std::cout << ", ";
        }
        std::cout << "\n  Total Pay: $" << calculatePay() << '\n';
    }
    
    // New methods specific to developers
    void codeReview() const {
        std::cout << m_name << " is conducting a code review\n";
    }
    
    void debugCode() const {
        std::cout << m_name << " is debugging code\n";
    }
};

// Manager with team management capabilities
class Manager : public Employee {
private:
    std::vector<Employee*> m_team;
    double m_teamBonusRate;

public:
    Manager(const std::string& name, int id, double baseSalary, double teamBonusRate = 0.05)
        : Employee{name, id, baseSalary}, m_teamBonusRate{teamBonusRate} {}
    
    // Team management functionality
    void addTeamMember(Employee* employee) {
        m_team.push_back(employee);
    }
    
    void removeTeamMember(int employeeId) {
        m_team.erase(
            std::remove_if(m_team.begin(), m_team.end(),
                [employeeId](Employee* emp) { return emp->getId() == employeeId; }),
            m_team.end()
        );
    }
    
    size_t getTeamSize() const { return m_team.size(); }
    
    const std::vector<Employee*>& getTeam() const { return m_team; }
    
    // Override with team-based bonus calculation
    double calculatePay() const override {
        double teamBonus = m_team.size() * 2000.0 * m_teamBonusRate;
        return m_baseSalary + teamBonus;
    }
    
    void displayInfo() const override {
        std::cout << "Manager: " << m_name << " (ID: " << m_employeeId << ")\n";
        std::cout << "  Base Salary: $" << m_baseSalary << '\n';
        std::cout << "  Team Size: " << m_team.size() << " members\n";
        std::cout << "  Total Pay: $" << calculatePay() << '\n';
    }
    
    // Manager-specific methods
    void conductMeeting() const {
        std::cout << m_name << " is conducting a team meeting with " 
                  << m_team.size() << " members\n";
    }
    
    void reviewPerformance(Employee* employee) const {
        std::cout << m_name << " is reviewing performance of " 
                  << employee->getName() << '\n';
    }
    
    void displayTeam() const {
        std::cout << "Team managed by " << m_name << ":\n";
        for (const Employee* emp : m_team) {
            std::cout << "  - " << emp->getName() << " (ID: " << emp->getId() << ")\n";
        }
    }
};

int main() {
    // Create different types of employees
    Developer alice{"Alice Johnson", 1001, 75000, 5, 0.15};
    alice.addProgrammingLanguage("C++");
    alice.addProgrammingLanguage("Python");
    alice.addProgrammingLanguage("JavaScript");
    
    Developer bob{"Bob Smith", 1002, 70000, 3};
    bob.addProgrammingLanguage("Java");
    bob.addProgrammingLanguage("C#");
    
    Manager charlie{"Charlie Brown", 2001, 90000, 0.08};
    
    // Build team relationship
    charlie.addTeamMember(&alice);
    charlie.addTeamMember(&bob);
    
    std::cout << "=== Employee Information ===\n";
    alice.displayInfo();
    std::cout << '\n';
    bob.displayInfo();
    std::cout << '\n';
    charlie.displayInfo();
    
    std::cout << "\n=== Demonstrating additional functionality ===\n";
    alice.codeReview();
    alice.debugCode();
    
    charlie.conductMeeting();
    charlie.reviewPerformance(&alice);
    charlie.displayTeam();
    
    return 0;
}
```

---

## Chapter 17: Virtual Functions and Polymorphism

### 17.1 - Pointers and References to the Base Class

```cpp
#include <iostream>
#include <vector>
#include <memory>

class Shape {
protected:
    std::string m_name;
    std::string m_color;

public:
    Shape(const std::string& name, const std::string& color)
        : m_name{name}, m_color{color} {}
    
    virtual ~Shape() = default;  // Virtual destructor
    
    // Non-virtual functions - early binding (compile-time)
    const std::string& getName() const { return m_name; }
    const std::string& getColor() const { return m_color; }
    
    void setColor(const std::string& color) { m_color = color; }
    
    // Virtual functions - late binding (runtime)
    virtual double getArea() const = 0;        // Pure virtual - abstract
    virtual double getPerimeter() const = 0;   // Pure virtual - abstract
    
    virtual void draw() const {
        std::cout << "Drawing a " << m_color << " " << m_name << '\n';
    }
    
    virtual void displayInfo() const {
        std::cout << m_name << " (" << m_color << ") - Area: " << getArea() 
                  << ", Perimeter: " << getPerimeter() << '\n';
    }
};

class Circle : public Shape {
private:
    double m_radius;

public:
    Circle(double radius, const std::string& color = "red")
        : Shape{"Circle", color}, m_radius{radius} {}
    
    double getRadius() const { return m_radius; }
    void setRadius(double radius) { m_radius = radius; }
    
    // Override virtual functions
    double getArea() const override {
        return 3.14159 * m_radius * m_radius;
    }
    
    double getPerimeter() const override {
        return 2 * 3.14159 * m_radius;
    }
    
    void draw() const override {
        std::cout << "Drawing a " << m_color << " circle with radius " << m_radius << '\n';
    }
};

class Rectangle : public Shape {
private:
    double m_width, m_height;

public:
    Rectangle(double width, double height, const std::string& color = "blue")
        : Shape{"Rectangle", color}, m_width{width}, m_height{height} {}
    
    double getWidth() const { return m_width; }
    double getHeight() const { return m_height; }
    
    double getArea() const override {
        return m_width * m_height;
    }
    
    double getPerimeter() const override {
        return 2 * (m_width + m_height);
    }
    
    void draw() const override {
        std::cout << "Drawing a " << m_color << " rectangle " 
                  << m_width << "x" << m_height << '\n';
    }
};

class Triangle : public Shape {
private:
    double m_base, m_height, m_side1, m_side2;

public:
    Triangle(double base, double height, double side1, double side2, 
             const std::string& color = "green")
        : Shape{"Triangle", color}, m_base{base}, m_height{height}, 
          m_side1{side1}, m_side2{side2} {}
    
    double getArea() const override {
        return 0.5 * m_base * m_height;
    }
    
    double getPerimeter() const override {
        return m_base + m_side1 + m_side2;
    }
    
    void draw() const override {
        std::cout << "Drawing a " << m_color << " triangle with base " 
                  << m_base << " and height " << m_height << '\n';
    }
};

// Function that works with any Shape through polymorphism
void processShape(const Shape& shape) {
    shape.displayInfo();  // Calls appropriate derived version
    shape.draw();         // Calls appropriate derived version
}

void processShapePointer(const Shape* shape) {
    if (shape) {
        shape->displayInfo();  // Polymorphic call
        shape->draw();         // Polymorphic call
    }
}

int main() {
    // Create different shapes
    Circle circle{5.0, "red"};
    Rectangle rect{4.0, 6.0, "blue"};
    Triangle triangle{3.0, 4.0, 5.0, 5.0, "green"};
    
    std::cout << "=== Direct object usage ===\n";
    circle.displayInfo();
    rect.displayInfo();
    triangle.displayInfo();
    
    std::cout << "\n=== Polymorphism with references ===\n";
    processShape(circle);    // Shape& refers to Circle
    processShape(rect);      // Shape& refers to Rectangle
    processShape(triangle);  // Shape& refers to Triangle
    
    std::cout << "\n=== Polymorphism with pointers ===\n";
    Shape* shapes[] = {&circle, &rect, &triangle};
    
    for (int i = 0; i < 3; ++i) {
        std::cout << "Shape " << (i + 1) << ": ";
        processShapePointer(shapes[i]);
        std::cout << '\n';
    }
    
    std::cout << "\n=== Dynamic polymorphism with smart pointers ===\n";
    std::vector<std::unique_ptr<Shape>> shapeCollection;
    shapeCollection.push_back(std::make_unique<Circle>(3.0, "yellow"));
    shapeCollection.push_back(std::make_unique<Rectangle>(2.0, 8.0, "purple"));
    shapeCollection.push_back(std::make_unique<Triangle>(6.0, 8.0, 10.0, 10.0, "orange"));
    
    double totalArea = 0.0;
    for (const auto& shape : shapeCollection) {
        shape->displayInfo();
        totalArea += shape->getArea();  // Polymorphic call to correct getArea()
    }
    
    std::cout << "Total area of all shapes: " << totalArea << '\n';
    
    return 0;
}
```

### 17.2 - Virtual Functions and Polymorphism

```cpp
#include <iostream>
#include <vector>
#include <memory>
#include <string>

// Abstract base class for all game entities
class GameEntity {
protected:
    std::string m_name;
    double m_x, m_y;
    int m_health;
    bool m_isActive;

public:
    GameEntity(const std::string& name, double x = 0.0, double y = 0.0, int health = 100)
        : m_name{name}, m_x{x}, m_y{y}, m_health{health}, m_isActive{true} {}
    
    virtual ~GameEntity() = default;
    
    // Non-virtual interface
    const std::string& getName() const { return m_name; }
    double getX() const { return m_x; }
    double getY() const { return m_y; }
    int getHealth() const { return m_health; }
    bool isActive() const { return m_isActive; }
    bool isAlive() const { return m_health > 0; }
    
    void setPosition(double x, double y) { m_x = x; m_y = y; }
    void setActive(bool active) { m_isActive = active; }
    
    // Virtual interface - polymorphic behavior
    virtual void update(double deltaTime) = 0;  // Pure virtual
    virtual void render() const = 0;            // Pure virtual
    virtual void takeDamage(int damage) {       // Virtual with default implementation
        m_health -= damage;
        if (m_health <= 0) {
            m_health = 0;
            m_isActive = false;
            onDeath();
        }
    }
    
    virtual void onDeath() {
        std::cout << m_name << " has died!\n";
    }
    
    virtual void displayStats() const {
        std::cout << m_name << " at (" << m_x << ", " << m_y 
                  << ") Health: " << m_health << '\n';
    }
};

class Player : public GameEntity {
private:
    int m_score;
    double m_speed;
    int m_ammo;

public:
    Player(const std::string& name, double x = 0.0, double y = 0.0)
        : GameEntity{name, x, y, 100}, m_score{0}, m_speed{5.0}, m_ammo{30} {}
    
    int getScore() const { return m_score; }
    int getAmmo() const { return m_ammo; }
    
    void addScore(int points) { m_score += points; }
    
    void reload() { 
        m_ammo = 30; 
        std::cout << m_name << " reloaded! Ammo: " << m_ammo << '\n';
    }
    
    bool shoot() {
        if (m_ammo > 0) {
            --m_ammo;
            std::cout << m_name << " shoots! Ammo remaining: " << m_ammo << '\n';
            return true;
        }
        std::cout << m_name << " is out of ammo!\n";
        return false;
    }
    
    // Override virtual functions
    void update(double deltaTime) override {
        // Player movement logic (simplified)
        // In real game, would handle input here
        std::cout << m_name << " player update (deltaTime: " << deltaTime << ")\n";
    }
    
    void render() const override {
        std::cout << "Rendering player " << m_name << " at (" << m_x << ", " << m_y << ")\n";
    }
    
    void takeDamage(int damage) override {
        std::cout << m_name << " takes " << damage << " damage!\n";
        GameEntity::takeDamage(damage);  // Call base implementation
    }
    
    void onDeath() override {
        std::cout << "GAME OVER! " << m_name << " died with score: " << m_score << '\n';
    }
    
    void displayStats() const override {
        GameEntity::displayStats();
        std::cout << "  Score: " << m_score << ", Ammo: " << m_ammo << '\n';
    }
};

class Enemy : public GameEntity {
private:
    double m_speed;
    int m_damage;
    double m_attackRange;
    GameEntity* m_target;

public:
    Enemy(const std::string& name, double x, double y, int health = 50, 
          int damage = 10, double attackRange = 2.0)
        : GameEntity{name, x, y, health}, m_speed{2.0}, m_damage{damage}, 
          m_attackRange{attackRange}, m_target{nullptr} {}
    
    void setTarget(GameEntity* target) { m_target = target; }
    int getDamage() const { return m_damage; }
    
    double distanceToTarget() const {
        if (!m_target) return std::numeric_limits<double>::max();
        double dx = m_target->getX() - m_x;
        double dy = m_target->getY() - m_y;
        return std::sqrt(dx * dx + dy * dy);
    }
    
    bool canAttackTarget() const {
        return m_target && m_target->isAlive() && distanceToTarget() <= m_attackRange;
    }
    
    void update(double deltaTime) override {
        if (!m_target || !m_target->isAlive()) {
            std::cout << m_name << " has no target\n";
            return;
        }
        
        double distance = distanceToTarget();
        
        if (distance <= m_attackRange) {
            // Attack target
            std::cout << m_name << " attacks " << m_target->getName() << "!\n";
            m_target->takeDamage(m_damage);
        } else {
            // Move towards target (simplified)
            double dx = m_target->getX() - m_x;
            double dy = m_target->getY() - m_y;
            double length = std::sqrt(dx * dx + dy * dy);
            
            if (length > 0) {
                dx /= length;  // Normalize
                dy /= length;
                
                m_x += dx * m_speed * deltaTime;
                m_y += dy * m_speed * deltaTime;
                
                std::cout << m_name << " moves toward " << m_target->getName() 
                          << " to (" << m_x << ", " << m_y << ")\n";
            }
        }
    }
    
    void render() const override {
        std::cout << "Rendering enemy " << m_name << " at (" << m_x << ", " << m_y << ")\n";
    }
    
    void onDeath() override {
        std::cout << m_name << " enemy defeated!\n";
        if (m_target) {
            // Give points to player if target is player
            Player* player = dynamic_cast<Player*>(m_target);
            if (player) {
                player->addScore(100);
                std::cout << "Player gained 100 points!\n";
            }
        }
    }
};

class PowerUp : public GameEntity {
private:
    std::string m_powerType;
    int m_value;

public:
    PowerUp(const std::string& powerType, double x, double y, int value = 50)
        : GameEntity{"PowerUp", x, y, 1}, m_powerType{powerType}, m_value{value} {}
    
    const std::string& getPowerType() const { return m_powerType; }
    int getValue() const { return m_value; }
    
    void applyTo(Player* player) {
        if (m_powerType == "Health") {
            // Heal player (would need to add healing method to GameEntity)
            std::cout << "Health powerup applied to " << player->getName() << "!\n";
        } else if (m_powerType == "Ammo") {
            player->reload();
            std::cout << "Ammo powerup applied to " << player->getName() << "!\n";
        } else if (m_powerType == "Score") {
            player->addScore(m_value);
            std::cout << "Score powerup +" << m_value << " applied to " 
                      << player->getName() << "!\n";
        }
        m_isActive = false;  // Consumed
    }
    
    void update(double deltaTime) override {
        // Simple floating animation
        static double time = 0;
        time += deltaTime;
        std::cout << m_powerType << " powerup floating (time: " << time << ")\n";
    }
    
    void render() const override {
        std::cout << "Rendering " << m_powerType << " powerup at (" 
                  << m_x << ", " << m_y << ")\n";
    }
};

// Game engine that manages entities polymorphically
class GameEngine {
private:
    std::vector<std::unique_ptr<GameEntity>> m_entities;

public:
    void addEntity(std::unique_ptr<GameEntity> entity) {
        m_entities.push_back(std::move(entity));
    }
    
    void update(double deltaTime) {
        std::cout << "=== Game Update (deltaTime: " << deltaTime << ") ===\n";
        
        // Update all entities polymorphically
        for (auto& entity : m_entities) {
            if (entity->isActive()) {
                entity->update(deltaTime);
            }
        }
        
        // Remove inactive entities
        m_entities.erase(
            std::remove_if(m_entities.begin(), m_entities.end(),
                [](const std::unique_ptr<GameEntity>& entity) {
                    return !entity->isActive();
                }),
            m_entities.end()
        );
    }
    
    void render() {
        std::cout << "=== Game Render ===\n";
        for (const auto& entity : m_entities) {
            if (entity->isActive()) {
                entity->render();
            }
        }
    }
    
    void displayAll

# Chapters 19-23: Templates, Operator Overloading & Advanced C++ Features

## Building Advanced C++ Applications: Generic Programming and Custom Operators

Having mastered the fundamentals of C++ and object-oriented programming, we now venture into advanced territories that make C++ truly powerful: **templates** for generic programming, **operator overloading** for intuitive class interfaces, and advanced **object-oriented techniques**. These features enable you to write flexible, reusable, and elegant code that forms the backbone of professional C++ applications.

---

## Chapter 19: Function Templates and Generic Programming

### 19.1 - Introduction to Function Templates

#### The Problem: Code Duplication

Consider these similar functions for finding the maximum of two values:

```cpp
// Separate functions for each type - lots of duplication!
int max(int a, int b) 
{
    return (a > b) ? a : b;
}

double max(double a, double b) 
{
    return (a > b) ? a : b;
}

std::string max(const std::string& a, const std::string& b) 
{
    return (a > b) ? a : b;
}
// ... and so on for every type we want to support
```

#### The Solution: Function Templates

**Function templates** allow you to write one function that works with multiple types:

```cpp
#include <iostream>
#include <string>

// Template function - works with any type T
template <typename T>
T max(const T& a, const T& b) 
{
    return (a > b) ? a : b;
}

int main() 
{
    // Compiler automatically deduces types
    std::cout << "Max of 5, 7: " << max(5, 7) << '\n';           // T = int
    std::cout << "Max of 3.14, 2.71: " << max(3.14, 2.71) << '\n'; // T = double
    std::cout << "Max of 'hello', 'world': " << max(std::string("hello"), std::string("world")) << '\n';
    
    return 0;
}
```

### 19.2 - Template Parameter Syntax

#### Basic Template Syntax

```cpp
// Single template parameter
template <typename T>
T add(const T& a, const T& b) 
{
    return a + b;
}

// Multiple template parameters
template <typename T, typename U>
auto multiply(const T& a, const U& b) -> decltype(a * b) 
{
    return a * b;
}

// Alternative syntax (equivalent to typename)
template <class T>
T square(const T& value) 
{
    return value * value;
}
```

#### Template with Non-Type Parameters

```cpp
#include <iostream>
#include <array>

// Template with value parameter
template <typename T, size_t N>
void printArray(const std::array<T, N>& arr) 
{
    std::cout << "Array of " << N << " elements: ";
    for (const auto& element : arr) 
    {
        std::cout << element << " ";
    }
    std::cout << '\n';
}

int main() 
{
    std::array<int, 5> numbers{1, 2, 3, 4, 5};
    std::array<std::string, 3> words{"hello", "world", "template"};
    
    printArray(numbers);  // T=int, N=5
    printArray(words);    // T=std::string, N=3
    
    return 0;
}
```

### 19.3 - Template Specialization

#### Explicit Template Specialization

Sometimes you need special behavior for specific types:

```cpp
#include <iostream>
#include <cstring>

// General template
template <typename T>
bool isEqual(const T& a, const T& b) 
{
    return a == b;
}

// Explicit specialization for C-style strings
template <>
bool isEqual<const char*>(const char* const& a, const char* const& b) 
{
    return std::strcmp(a, b) == 0;  // Use strcmp for C-strings
}

int main() 
{
    // Uses general template
    std::cout << "5 == 5: " << isEqual(5, 5) << '\n';
    std::cout << "'hello' == 'hello': " << isEqual(std::string("hello"), std::string("hello")) << '\n';
    
    // Uses specialized version
    const char* str1 = "hello";
    const char* str2 = "hello";
    std::cout << "C-strings equal: " << isEqual(str1, str2) << '\n';
    
    return 0;
}
```

### 19.4 - Advanced Template Concepts

#### SFINAE (Substitution Failure Is Not An Error)

```cpp
#include <iostream>
#include <type_traits>
#include <vector>

// Only enabled for integral types
template <typename T>
typename std::enable_if_t<std::is_integral_v<T>, void>
processNumber(T value) 
{
    std::cout << "Processing integer: " << value << '\n';
}

// Only enabled for floating-point types
template <typename T>
typename std::enable_if_t<std::is_floating_point_v<T>, void>
processNumber(T value) 
{
    std::cout << "Processing float: " << value << " (rounded: " << static_cast<int>(value) << ")\n";
}

// Constexpr if (C++17) - cleaner alternative
template <typename T>
void processValue(T value) 
{
    if constexpr (std::is_integral_v<T>) 
    {
        std::cout << "Integer value: " << value << '\n';
    }
    else if constexpr (std::is_floating_point_v<T>) 
    {
        std::cout << "Floating-point value: " << value << '\n';
    }
    else 
    {
        std::cout << "Other type value: " << value << '\n';
    }
}

int main() 
{
    processNumber(42);      // Calls integral version
    processNumber(3.14);    // Calls floating-point version
    
    processValue(100);      // Integer branch
    processValue(2.71);     // Floating-point branch
    processValue("hello");  // Other type branch
    
    return 0;
}
```

---

## Chapter 20: Class Templates and Generic Classes

### 20.1 - Introduction to Class Templates

#### Template Classes for Generic Containers

```cpp
#include <iostream>
#include <stdexcept>

template <typename T>
class SimpleVector 
{
private:
    T* data;
    size_t size;
    size_t capacity;
    
    void resize() 
    {
        capacity *= 2;
        T* newData = new T[capacity];
        for (size_t i = 0; i < size; ++i) 
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    
public:
    explicit SimpleVector(size_t initialCapacity = 4) 
        : data(new T[initialCapacity]), size(0), capacity(initialCapacity) 
    {
    }
    
    ~SimpleVector() 
    {
        delete[] data;
    }
    
    // Copy constructor
    SimpleVector(const SimpleVector& other) 
        : data(new T[other.capacity]), size(other.size), capacity(other.capacity) 
    {
        for (size_t i = 0; i < size; ++i) 
        {
            data[i] = other.data[i];
        }
    }
    
    // Assignment operator
    SimpleVector& operator=(const SimpleVector& other) 
    {
        if (this != &other) 
        {
            delete[] data;
            data = new T[other.capacity];
            size = other.size;
            capacity = other.capacity;
            for (size_t i = 0; i < size; ++i) 
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    
    void push_back(const T& value) 
    {
        if (size == capacity) 
        {
            resize();
        }
        data[size++] = value;
    }
    
    T& operator[](size_t index) 
    {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }
    
    const T& operator[](size_t index) const 
    {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }
    
    size_t getSize() const { return size; }
    bool isEmpty() const { return size == 0; }
};

int main() 
{
    // Vector of integers
    SimpleVector<int> intVec;
    intVec.push_back(1);
    intVec.push_back(2);
    intVec.push_back(3);
    
    std::cout << "Integer vector: ";
    for (size_t i = 0; i < intVec.getSize(); ++i) 
    {
        std::cout << intVec[i] << " ";
    }
    std::cout << '\n';
    
    // Vector of strings
    SimpleVector<std::string> stringVec;
    stringVec.push_back("Hello");
    stringVec.push_back("Template");
    stringVec.push_back("World");
    
    std::cout << "String vector: ";
    for (size_t i = 0; i < stringVec.getSize(); ++i) 
    {
        std::cout << stringVec[i] << " ";
    }
    std::cout << '\n';
    
    return 0;
}
```

### 20.2 - Template Class Specialization

#### Full and Partial Specialization

```cpp
#include <iostream>
#include <cstring>

// Primary template
template <typename T>
class Storage 
{
private:
    T value;
    
public:
    Storage(const T& v) : value(v) {}
    
    void print() const 
    {
        std::cout << "Generic storage: " << value << '\n';
    }
    
    T getValue() const { return value; }
};

// Explicit specialization for bool
template <>
class Storage<bool> 
{
private:
    bool value;
    
public:
    Storage(bool v) : value(v) {}
    
    void print() const 
    {
        std::cout << "Boolean storage: " << (value ? "true" : "false") << '\n';
    }
    
    bool getValue() const { return value; }
};

// Explicit specialization for C-string
template <>
class Storage<const char*> 
{
private:
    char* value;
    
public:
    Storage(const char* v) : value(new char[std::strlen(v) + 1]) 
    {
        std::strcpy(value, v);
    }
    
    ~Storage() 
    {
        delete[] value;
    }
    
    // Copy constructor
    Storage(const Storage& other) : value(new char[std::strlen(other.value) + 1]) 
    {
        std::strcpy(value, other.value);
    }
    
    void print() const 
    {
        std::cout << "C-string storage: " << value << '\n';
    }
    
    const char* getValue() const { return value; }
};

int main() 
{
    Storage<int> intStorage(42);
    Storage<bool> boolStorage(true);
    Storage<const char*> stringStorage("Hello Templates!");
    
    intStorage.print();     // Uses generic version
    boolStorage.print();    // Uses bool specialization
    stringStorage.print();  // Uses C-string specialization
    
    return 0;
}
```

---

## Chapter 21: Operator Overloading

### 21.1 - Introduction to Operator Overloading

#### Making Custom Types Behave Like Built-in Types

```cpp
#include <iostream>

class Fraction 
{
private:
    int numerator;
    int denominator;
    
    // Helper function to find GCD
    int gcd(int a, int b) const 
    {
        return (b == 0) ? a : gcd(b, a % b);
    }
    
    // Helper function to reduce fraction
    void reduce() 
    {
        int common = gcd(abs(numerator), abs(denominator));
        numerator /= common;
        denominator /= common;
        
        // Keep denominator positive
        if (denominator < 0) 
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
    
public:
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) 
    {
        if (denominator == 0) 
        {
            throw std::runtime_error("Denominator cannot be zero");
        }
        reduce();
    }
    
    // Arithmetic operators
    Fraction operator+(const Fraction& other) const 
    {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
                       denominator * other.denominator);
    }
    
    Fraction operator-(const Fraction& other) const 
    {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
                       denominator * other.denominator);
    }
    
    Fraction operator*(const Fraction& other) const 
    {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }
    
    Fraction operator/(const Fraction& other) const 
    {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }
    
    // Comparison operators
    bool operator==(const Fraction& other) const 
    {
        return (numerator == other.numerator) && (denominator == other.denominator);
    }
    
    bool operator!=(const Fraction& other) const 
    {
        return !(*this == other);
    }
    
    bool operator<(const Fraction& other) const 
    {
        return (numerator * other.denominator) < (other.numerator * denominator);
    }
    
    // Unary operators
    Fraction operator-() const 
    {
        return Fraction(-numerator, denominator);
    }
    
    // Compound assignment operators
    Fraction& operator+=(const Fraction& other) 
    {
        *this = *this + other;
        return *this;
    }
    
    // Stream operators (as friend functions)
    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& in, Fraction& fraction);
};

// Stream output operator
std::ostream& operator<<(std::ostream& out, const Fraction& fraction) 
{
    if (fraction.denominator == 1) 
    {
        out << fraction.numerator;
    }
    else 
    {
        out << fraction.numerator << '/' << fraction.denominator;
    }
    return out;
}

// Stream input operator
std::istream& operator>>(std::istream& in, Fraction& fraction) 
{
    int num, den = 1;
    in >> num;
    
    if (in.peek() == '/') 
    {
        in.ignore();  // Skip the '/'
        in >> den;
    }
    
    fraction = Fraction(num, den);
    return in;
}

int main() 
{
    Fraction f1(1, 2);    // 1/2
    Fraction f2(3, 4);    // 3/4
    Fraction f3(2, 3);    // 2/3
    
    std::cout << "f1 = " << f1 << '\n';
    std::cout << "f2 = " << f2 << '\n';
    std::cout << "f3 = " << f3 << '\n';
    
    // Arithmetic operations
    std::cout << "f1 + f2 = " << (f1 + f2) << '\n';    // 10/8 = 5/4
    std::cout << "f2 - f1 = " << (f2 - f1) << '\n';    // 2/8 = 1/4
    std::cout << "f1 * f3 = " << (f1 * f3) << '\n';    // 2/6 = 1/3
    std::cout << "f2 / f3 = " << (f2 / f3) << '\n';    // 9/8
    
    // Comparison operations
    std::cout << "f1 == f2: " << (f1 == f2) << '\n';
    std::cout << "f1 < f2: " << (f1 < f2) << '\n';
    
    // Compound assignment
    f1 += f2;
    std::cout << "f1 after += f2: " << f1 << '\n';
    
    return 0;
}
```

### 21.2 - Overloading Specific Operators

#### Subscript and Function Call Operators

```cpp
#include <iostream>
#include <stdexcept>

template <typename T, size_t Rows, size_t Cols>
class Matrix 
{
private:
    T data[Rows][Cols];
    
public:
    Matrix() 
    {
        for (size_t i = 0; i < Rows; ++i) 
        {
            for (size_t j = 0; j < Cols; ++j) 
            {
                data[i][j] = T{};
            }
        }
    }
    
    // Subscript operator for 2D access: matrix[row][col]
    T* operator[](size_t row) 
    {
        if (row >= Rows) throw std::out_of_range("Row index out of range");
        return data[row];
    }
    
    const T* operator[](size_t row) const 
    {
        if (row >= Rows) throw std::out_of_range("Row index out of range");
        return data[row];
    }
    
    // Function call operator for 2D access: matrix(row, col)
    T& operator()(size_t row, size_t col) 
    {
        if (row >= Rows || col >= Cols) 
            throw std::out_of_range("Index out of range");
        return data[row][col];
    }
    
    const T& operator()(size_t row, size_t col) const 
    {
        if (row >= Rows || col >= Cols) 
            throw std::out_of_range("Index out of range");
        return data[row][col];
    }
    
    // Matrix addition
    Matrix operator+(const Matrix& other) const 
    {
        Matrix result;
        for (size_t i = 0; i < Rows; ++i) 
        {
            for (size_t j = 0; j < Cols; ++j) 
            {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    
    void print() const 
    {
        for (size_t i = 0; i < Rows; ++i) 
        {
            for (size_t j = 0; j < Cols; ++j) 
            {
                std::cout << data[i][j] << " ";
            }
            std::cout << '\n';
        }
    }
    
    constexpr size_t rows() const { return Rows; }
    constexpr size_t cols() const { return Cols; }
};

int main() 
{
    Matrix<int, 3, 3> mat1;
    Matrix<int, 3, 3> mat2;
    
    // Using subscript operator
    mat1[0][0] = 1; mat1[0][1] = 2; mat1[0][2] = 3;
    mat1[1][0] = 4; mat1[1][1] = 5; mat1[1][2] = 6;
    mat1[2][0] = 7; mat1[2][1] = 8; mat1[2][2] = 9;
    
    // Using function call operator
    mat2(0, 0) = 9; mat2(0, 1) = 8; mat2(0, 2) = 7;
    mat2(1, 0) = 6; mat2(1, 1) = 5; mat2(1, 2) = 4;
    mat2(2, 0) = 3; mat2(2, 1) = 2; mat2(2, 2) = 1;
    
    std::cout << "Matrix 1:\n";
    mat1.print();
    
    std::cout << "Matrix 2:\n";
    mat2.print();
    
    std::cout << "Matrix 1 + Matrix 2:\n";
    Matrix<int, 3, 3> sum = mat1 + mat2;
    sum.print();
    
    return 0;
}
```

#### Increment and Decrement Operators

```cpp
#include <iostream>

class Counter 
{
private:
    int value;
    
public:
    explicit Counter(int v = 0) : value(v) {}
    
    // Prefix increment: ++counter
    Counter& operator++() 
    {
        ++value;
        return *this;
    }
    
    // Postfix increment: counter++
    Counter operator++(int) 
    {
        Counter temp(*this);  // Save current state
        ++value;              // Increment
        return temp;          // Return old state
    }
    
    // Prefix decrement: --counter
    Counter& operator--() 
    {
        --value;
        return *this;
    }
    
    // Postfix decrement: counter--
    Counter operator--(int) 
    {
        Counter temp(*this);
        --value;
        return temp;
    }
    
    int getValue() const { return value; }
    
    friend std::ostream& operator<<(std::ostream& out, const Counter& counter) 
    {
        out << counter.value;
        return out;
    }
};

int main() 
{
    Counter c(5);
    
    std::cout << "Initial value: " << c << '\n';
    
    // Prefix operations
    std::cout << "++c: " << ++c << '\n';        // c becomes 6, prints 6
    std::cout << "c after ++: " << c << '\n';   // prints 6
    
    std::cout << "c++: " << c++ << '\n';        // prints 6, c becomes 7
    std::cout << "c after ++: " << c << '\n';   // prints 7
    
    // Prefix operations
    std::cout << "--c: " << --c << '\n';        // c becomes 6, prints 6
    std::cout << "c after --: " << c << '\n';   // prints 6
    
    std::cout << "c--: " << c-- << '\n';        // prints 6, c becomes 5
    std::cout << "c after --: " << c << '\n';   // prints 5
    
    return 0;
}
```

### 21.3 - Type Conversion Operators

#### Converting Between Custom Types

```cpp
#include <iostream>
#include <string>

class Temperature 
{
private:
    double celsius;
    
public:
    explicit Temperature(double c = 0.0) : celsius(c) {}
    
    // Conversion to double (returns Celsius)
    operator double() const 
    {
        return celsius;
    }
    
    // Conversion to int (returns rounded Celsius)
    operator int() const 
    {
        return static_cast<int>(celsius + 0.5);
    }
    
    // Explicit conversion to Fahrenheit
    double toFahrenheit() const 
    {
        return celsius * 9.0 / 5.0 + 32.0;
    }
    
    double getCelsius() const { return celsius; }
    
    friend std::ostream& operator<<(std::ostream& out, const Temperature& temp) 
    {
        out << temp.celsius << "°C";
        return out;
    }
};

class Distance 
{
private:
    double meters;
    
public:
    explicit Distance(double m = 0.0) : meters(m) {}
    
    // Constructor for conversion from feet
    Distance(double feet, bool fromFeet) : meters(fromFeet ? feet * 0.3048 : feet) {}
    
    // Implicit conversion to double (returns meters)
    operator double() const 
    {
        return meters;
    }
    
    // Explicit conversion to feet
    explicit operator double() const 
    {
        return meters / 0.3048;
    }
    
    double toFeet() const 
    {
        return meters / 0.3048;
    }
    
    friend std::ostream& operator<<(std::ostream& out, const Distance& dist) 
    {
        out << dist.meters << "m";
        return out;
    }
};

int main() 
{
    Temperature temp(25.7);
    std::cout << "Temperature: " << temp << '\n';
    std::cout << "As double: " << static_cast<double>(temp) << '\n';
    std::cout << "As int: " << static_cast<int>(temp) << '\n';
    std::cout << "In Fahrenheit: " << temp.toFahrenheit() << "°F\n";
    
    Distance dist(100.0);  // 100 meters
    std::cout << "Distance: " << dist << '\n';
    std::cout << "In feet: " << dist.toFeet() << " ft\n";
    
    // Implicit conversion in arithmetic
    double totalMeters = dist + 50.5;  // dist converts to double
    std::cout << "Total meters: " << totalMeters << '\n';
    
    return 0;
}
```

---

## Chapter 22: Smart Pointers and Resource Management

### 22.1 - Introduction to Smart Pointers

#### The Problem: Manual Memory Management

```cpp
#include <iostream>

// Problematic approach - manual memory management
class ResourceLeaker 
{
public:
    void doSomething() 
    {
        int* ptr = new int(42);  // Allocate memory
        
        // If an exception occurs here, memory leaks!
        if (someCondition()) 
        {
            throw std::runtime_error("Something went wrong");
        }
        
        delete ptr;  // This might never execute!
    }
    
private:
    bool someCondition() { return true; }  // Simulate condition
};
```

#### The Solution: Smart Pointers

```cpp
#include <iostream>
#include <memory>
#include <vector>

class Resource 
{
private:
    int id;
    
public:
    explicit Resource(int identifier) : id(identifier) 
    {
        std::cout << "Resource " << id << " created\n";
    }
    
    ~Resource() 
    {
        std::cout << "Resource " << id << " destroyed\n";
    }
    
    void doWork() 
    {
        std::cout << "Resource " << id << " is working\n";
    }
    
    int getId() const { return id; }
};

// Modern approach with smart pointers
class ResourceManager 
{
public:
    void demonstrateUniquePtr() 
    {
        std::cout << "=== unique_ptr Demo ===\n";
        
        // Automatic memory management
        std::unique_ptr<Resource> ptr = std::make_unique<Resource>(1);
        ptr->doWork();
        
        // Transfer ownership
        std::unique_ptr<Resource> ptr2 = std::move(ptr);
        // ptr is now nullptr, ptr2 owns the resource
        
        if (ptr == nullptr) 
        {
            std::cout << "ptr is now null\n";
        }
        
        ptr2->doWork();
        
        // Resource automatically destroyed when ptr2 goes out of scope
    }
    
    void demonstrateSharedPtr() 
    {
        std::cout << "\n=== shared_ptr Demo ===\n";
        
        std::shared_ptr<Resource> ptr1 = std::make_shared<Resource>(2);
        std::cout << "Reference count: " << ptr1.use_count() << '\n';
        
        {
            std::shared_ptr<Resource> ptr2 = ptr1;  // Share ownership
            std::cout << "Reference count: " << ptr1.use_count() << '\n';
            
            std::shared_ptr<Resource> ptr3 = ptr1;  // Another shared owner
            std::cout << "Reference count: " << ptr1.use_count() << '\n';
            
            ptr2->doWork();
            ptr3->doWork();
            
        }  // ptr2 and ptr3 destroyed here
        
        std::cout << "Reference count: " << ptr1.use_count() << '\n';
        ptr1->doWork();
        
        // Resource destroyed when ptr1 goes out of scope
    }
    
    void demonstrateWeakPtr() 
    {
        std::cout << "\n=== weak_ptr Demo ===\n";
        
        std::shared_ptr<Resource> shared = std::make_shared<Resource>(3);
        std::weak_ptr<Resource> weak = shared;  // Doesn't increase ref count
        
        std::cout << "Shared ref count: " << shared.use_count() << '\n';
        std::cout << "Weak expired? " << weak.expired() << '\n';
        
        // Use weak_ptr safely
        if (auto locked = weak.lock()) 
        {
            locked->doWork();
            std::cout << "Successfully accessed resource through weak_ptr\n";
        }
        
        shared.reset();  // Release the shared_ptr
        
        std::cout << "After reset - Weak expired? " << weak.expired() << '\n';
        
        // Attempting to lock now returns nullptr
        if (auto locked = weak.lock()) 
        {
            locked->doWork();  // Won't execute
        }
        else 
        {
            std::cout << "weak_ptr is expired, cannot access resource\n";
        }
    }
};

int main() 
{
    ResourceManager manager;
    
    manager.demonstrateUniquePtr();
    manager.demonstrateSharedPtr();
    manager.demonstrateWeakPtr();
    
    return 0;
}
```

### 22.2 - Custom Deleters and Advanced Smart Pointer Usage

#### Custom Deleters for Special Resources

```cpp
#include <iostream>
#include <memory>
#include <cstdio>

// Custom deleter for FILE*
struct FileDeleter 
{
    void operator()(FILE* file) const 
    {
        if (file) 
        {
            std::cout << "Closing file\n";
            std::fclose(file);
        }
    }
};

// Custom deleter for arrays
template <typename T>
struct ArrayDeleter 
{
    void operator()(T* ptr) const 
    {
        std::cout << "Deleting array\n";
        delete[] ptr;
    }
};

class SmartResourceManager 
{
public:
    void demonstrateCustomDeleters() 
    {
        std::cout << "=== Custom Deleters Demo ===\n";
        
        // Smart pointer with custom deleter for FILE*
        std::unique_ptr<FILE, FileDeleter> file(std::fopen("temp.txt", "w"));
        
        if (file) 
        {
            std::fprintf(file.get(), "Hello from smart pointer!\n");
            // File automatically closed when unique_ptr is destroyed
        }
        
        // Smart pointer with lambda deleter
        auto arrayPtr = std::unique_ptr<int[], ArrayDeleter<int>>(new int[10]);
        
        // Initialize array
        for (int i = 0; i < 10; ++i) 
        {
            arrayPtr[i] = i * i;
        }
        
        std::cout << "Array values: ";
        for (int i = 0; i < 10; ++i) 
        {
            std::cout << arrayPtr[i] << " ";
        }
        std::cout << '\n';
        
        // Lambda deleter example
        auto customPtr = std::unique_ptr<Resource, std::function<void(Resource*)>>(
            new Resource(99),
            [](Resource* r) 
            {
                std::cout << "Custom lambda deleter called\n";
                delete r;
            }
        );
        
        customPtr->doWork();
    }
    
    void demonstrateSharedPtrWithCustomDeleter() 
    {
        std::cout << "\n=== shared_ptr with Custom Deleter ===\n";
        
        // shared_ptr with custom deleter
        std::shared_ptr<Resource> resource(new Resource(100), 
            [](Resource* r) 
            {
                std::cout << "Custom deleter for shared_ptr\n";
                delete r;
            });
        
        // Multiple shared_ptr instances can share the same custom deleter
        std::shared_ptr<Resource> resource2 = resource;
        
        std::cout << "Reference count: " << resource.use_count() << '\n';
        
        resource->doWork();
        resource2->doWork();
    }
};
```

### 22.3 - RAII and Exception Safety

#### Resource Acquisition Is Initialization

```cpp
#include <iostream>
#include <memory>
#include <fstream>
#include <mutex>
#include <thread>
#include <vector>

// RAII wrapper for mutex locking
class LockGuard 
{
private:
    std::mutex& mtx;
    
public:
    explicit LockGuard(std::mutex& m) : mtx(m) 
    {
        mtx.lock();
        std::cout << "Mutex locked\n";
    }
    
    ~LockGuard() 
    {
        mtx.unlock();
        std::cout << "Mutex unlocked\n";
    }
    
    // Non-copyable
    LockGuard(const LockGuard&) = delete;
    LockGuard& operator=(const LockGuard&) = delete;
};

// Exception-safe resource management
class DatabaseConnection 
{
private:
    bool connected;
    std::string connectionString;
    
public:
    explicit DatabaseConnection(const std::string& connStr) 
        : connected(false), connectionString(connStr) 
    {
        // Simulate connection
        std::cout << "Connecting to database: " << connectionString << '\n';
        connected = true;
    }
    
    ~DatabaseConnection() 
    {
        if (connected) 
        {
            std::cout << "Disconnecting from database\n";
            connected = false;
        }
    }
    
    void query(const std::string& sql) 
    {
        if (!connected) throw std::runtime_error("Not connected");
        std::cout << "Executing query: " << sql << '\n';
    }
    
    // Non-copyable
    DatabaseConnection(const DatabaseConnection&) = delete;
    DatabaseConnection& operator=(const DatabaseConnection&) = delete;
    
    // Movable
    DatabaseConnection(DatabaseConnection&& other) noexcept 
        : connected(other.connected), connectionString(std::move(other.connectionString)) 
    {
        other.connected = false;
    }
};

class ExceptionSafeOperations 
{
private:
    std::mutex dataMutex;
    std::vector<int> data;
    
public:
    void riskyOperation() 
    {
        std::cout << "\n=== Exception Safety Demo ===\n";
        
        try 
        {
            // RAII ensures cleanup even if exceptions occur
            auto dbConn = std::make_unique<DatabaseConnection>("postgresql://localhost:5432/mydb");
            LockGuard lock(dataMutex);  // Automatic unlocking
            
            dbConn->query("SELECT * FROM users");
            
            // Simulate exception
            if (true) 
            {
                throw std::runtime_error("Database error occurred");
            }
            
            dbConn->query("UPDATE users SET active = true");
            
        }
        catch (const std::exception& e) 
        {
            std::cout << "Exception caught: " << e.what() << '\n';
            std::cout << "Resources automatically cleaned up!\n";
        }
        // mutex automatically unlocked, database connection closed
    }
    
    void strongExceptionSafety() 
    {
        std::cout << "\n=== Strong Exception Safety ===\n";
        
        std::vector<int> backup = data;  // Save current state
        
        try 
        {
            // Perform operations that might throw
            data.push_back(1);
            data.push_back(2);
            
            // Simulate failure
            throw std::runtime_error("Operation failed");
            
            data.push_back(3);  // This won't execute
        }
        catch (const std::exception& e) 
        {
            // Restore to previous state (strong exception safety)
            data = backup;
            std::cout << "Exception: " << e.what() << '\n';
            std::cout << "Data restored to previous state\n";
        }
    }
};
```

---

## Chapter 23: Move Semantics and Perfect Forwarding

### 23.1 - Introduction to Move Semantics

#### The Problem: Expensive Copying

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <utility>

class ExpensiveResource 
{
private:
    std::vector<int> data;
    std::string name;
    
public:
    // Constructor
    ExpensiveResource(const std::string& n, size_t size) : name(n), data(size) 
    {
        std::cout << "Creating " << name << " with " << size << " elements\n";
        
        // Fill with some data
        for (size_t i = 0; i < size; ++i) 
        {
            data[i] = static_cast<int>(i);
        }
    }
    
    // Copy constructor (expensive)
    ExpensiveResource(const ExpensiveResource& other) 
        : name(other.name + "_copy"), data(other.data) 
    {
        std::cout << "EXPENSIVE COPY: Copying " << other.name << " to " << name << '\n';
    }
    
    // Move constructor (cheap)
    ExpensiveResource(ExpensiveResource&& other) noexcept 
        : name(std::move(other.name)), data(std::move(other.data)) 
    {
        std::cout << "EFFICIENT MOVE: Moving " << name << '\n';
        other.name = "moved_from";
    }
    
    // Copy assignment operator
    ExpensiveResource& operator=(const ExpensiveResource& other) 
    {
        if (this != &other) 
        {
            name = other.name + "_assigned";
            data = other.data;
            std::cout << "EXPENSIVE COPY ASSIGNMENT\n";
        }
        return *this;
    }
    
    // Move assignment operator
    ExpensiveResource& operator=(ExpensiveResource&& other) noexcept 
    {
        if (this != &other) 
        {
            name = std::move(other.name);
            data = std::move(other.data);
            other.name = "moved_from";
            std::cout << "EFFICIENT MOVE ASSIGNMENT\n";
        }
        return *this;
    }
    
    // Destructor
    ~ExpensiveResource() 
    {
        std::cout << "Destroying " << name << '\n';
    }
    
    const std::string& getName() const { return name; }
    size_t size() const { return data.size(); }
};

// Function that returns by value
ExpensiveResource createResource(const std::string& name, size_t size) 
{
    return ExpensiveResource(name, size);  // Move semantics kicks in
}

void demonstrateMoveSemantics() 
{
    std::cout << "=== Move Semantics Demo ===\n";
    
    // Direct construction
    ExpensiveResource res1("Resource1", 1000);
    
    // Move construction (efficient)
    ExpensiveResource res2 = std::move(res1);
    std::cout << "res1 name after move: " << res1.getName() << '\n';
    std::cout << "res2 name: " << res2.getName() << '\n';
    
    // Function return value (automatic move)
    ExpensiveResource res3 = createResource("Resource3", 2000);
    
    // Move assignment
    res1 = std::move(res3);
    std::cout << "res1 name after move assignment: " << res1.getName() << '\n';
    
    // Copy vs Move in containers
    std::vector<ExpensiveResource> resources;
    resources.reserve(3);  // Avoid reallocations
    
    std::cout << "\n--- Adding to vector ---\n";
    resources.push_back(createResource("VecResource1", 500));  // Move
    resources.emplace_back("VecResource2", 750);               // Direct construction
    
    ExpensiveResource temp("Temp", 300);
    resources.push_back(temp);              // Copy (temp is lvalue)
    resources.push_back(std::move(temp));   // Move
}
```

### 23.2 - Perfect Forwarding and Universal References

#### Forwarding Arguments Efficiently

```cpp
#include <iostream>
#include <memory>
#include <utility>

class Widget 
{
private:
    std::string name;
    int value;
    
public:
    Widget(const std::string& n, int v) : name(n), value(v) 
    {
        std::cout << "Widget constructed: " << name << " = " << value << '\n';
    }
    
    Widget(std::string&& n, int v) : name(std::move(n)), value(v) 
    {
        std::cout << "Widget move-constructed: " << name << " = " << value << '\n';
    }
    
    const std::string& getName() const { return name; }
    int getValue() const { return value; }
};

// Perfect forwarding factory function
template <typename T, typename... Args>
std::unique_ptr<T> makeUnique(Args&&... args) 
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

// Universal reference function
template <typename T>
void processValue(T&& value) 
{
    using ValueType = std::remove_reference_t<T>;
    
    if constexpr (std::is_lvalue_reference_v<T>) 
    {
        std::cout << "Received lvalue reference\n";
    }
    else 
    {
        std::cout << "Received rvalue reference\n";
    }
    
    // Forward the value maintaining its value category
    forwardToProcessor(std::forward<T>(value));
}

template <typename T>
void forwardToProcessor(T&& value) 
{
    std::cout << "Processing: " << value << '\n';
}

// Variadic template with perfect forwarding
template <typename Func, typename... Args>
auto measureTime(Func&& func, Args&&... args) -> decltype(func(std::forward<Args>(args)...)) 
{
    auto start = std::chrono::high_resolution_clock::now();
    
    // Perfect forwarding of all arguments
    auto result = func(std::forward<Args>(args)...);
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << "Execution time: " << duration.count() << " microseconds\n";
    
    return result;
}

void demonstratePerfectForwarding() 
{
    std::cout << "\n=== Perfect Forwarding Demo ===\n";
    
    // Perfect forwarding with makeUnique
    std::string name = "Widget1";
    auto widget1 = makeUnique<Widget>(name, 42);           // Copy string
    auto widget2 = makeUnique<Widget>(std::string("Widget2"), 84);  // Move string
    auto widget3 = makeUnique<Widget>("Widget3", 126);     // Direct construction
    
    // Universal references
    int x = 10;
    processValue(x);              // Lvalue reference
    processValue(20);             // Rvalue reference
    processValue(std::move(x));   // Rvalue reference
    
    // Perfect forwarding with function measurement
    auto expensiveFunction = [](const std::string& s, int multiplier) 
    {
        std::string result;
        for (int i = 0; i < multiplier; ++i) 
        {
            result += s;
        }
        return result;
    };
    
    std::string text = "Hello ";
    auto result = measureTime(expensiveFunction, text, 1000);
    std::cout << "Result length: " << result.length() << '\n';
}
```

### 23.3 - Move-Aware Classes and Optimization

#### Implementing Efficient Move Operations

```cpp
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

template <typename T>
class MoveOptimizedVector 
{
private:
    std::unique_ptr<T[]> data;
    size_t size_;
    size_t capacity_;
    
    void reallocate(size_t newCapacity) 
    {
        auto newData = std::make_unique<T[]>(newCapacity);
        
        // Move elements if T has noexcept move constructor
        if constexpr (std::is_nothrow_move_constructible_v<T>) 
        {
            for (size_t i = 0; i < size_; ++i) 
            {
                new (&newData[i]) T(std::move(data[i]));
            }
        }
        else 
        {
            // Copy if move might throw
            for (size_t i = 0; i < size_; ++i) 
            {
                new (&newData[i]) T(data[i]);
            }
        }
        
        data = std::move(newData);
        capacity_ = newCapacity;
    }
    
public:
    MoveOptimizedVector() : data(nullptr), size_(0), capacity_(0) {}
    
    explicit MoveOptimizedVector(size_t initialCapacity) 
        : data(std::make_unique<T[]>(initialCapacity)), size_(0), capacity_(initialCapacity) {}
    
    // Copy constructor
    MoveOptimizedVector(const MoveOptimizedVector& other) 
        : data(std::make_unique<T[]>(other.capacity_)), size_(other.size_), capacity_(other.capacity_) 
    {
        for (size_t i = 0; i < size_; ++i) 
        {
            new (&data[i]) T(other.data[i]);
        }
        std::cout << "Vector copied\n";
    }
    
    // Move constructor
    MoveOptimizedVector(MoveOptimizedVector&& other) noexcept 
        : data(std::move(other.data)), size_(other.size_), capacity_(other.capacity_) 
    {
        other.size_ = 0;
        other.capacity_ = 0;
        std::cout << "Vector moved\n";
    }
    
    // Copy assignment
    MoveOptimizedVector& operator=(const MoveOptimizedVector& other) 
    {
        if (this != &other) 
        {
            data = std::make_unique<T[]>(other.capacity_);
            size_ = other.size_;
            capacity_ = other.capacity_;
            
            for (size_t i = 0; i < size_; ++i) 
            {
                new (&data[i]) T(other.data[i]);
            }
            std::cout << "Vector copy-assigned\n";
        }
        return *this;
    }
    
    // Move assignment
    MoveOptimizedVector& operator=(MoveOptimizedVector&& other) noexcept 
    {
        if (this != &other) 
        {
            data = std::move(other.data);
            size_ = other.size_;
            capacity_ = other.capacity_;
            
            other.size_ = 0;
            other.capacity_ = 0;
            std::cout << "Vector move-assigned\n";
        }
        return *this;
    }
    
    void push_back(const T& value) 
    {
        if (size_ == capacity_) 
        {
            reallocate(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        new (&data[size_++]) T(value);
    }
    
    void push_back(T&& value) 
    {
        if (size_ == capacity_) 
        {
            reallocate(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        new (&data[size_++]) T(std::move(value));
    }
    
    template <typename... Args>
    void emplace_back(Args&&... args) 
    {
        if (size_ == capacity_) 
        {
            reallocate(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        new (&data[size_++]) T(std::forward<Args>(args)...);
    }
    
    T& operator[](size_t index) { return data[index]; }
    const T& operator[](size_t index) const { return data[index]; }
    
    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
    bool empty() const { return size_ == 0; }
};

// Test class to demonstrate move optimizations
class MoveTestClass 
{
private:
    std::string data;
    
public:
    MoveTestClass(const std::string& s) : data(s) 
    {
        std::cout << "MoveTestClass constructed: " << data << '\n';
    }
    
    MoveTestClass(const MoveTestClass& other) : data(other.data) 
    {
        std::cout << "MoveTestClass copied: " << data << '\n';
    }
    
    MoveTestClass(MoveTestClass&& other) noexcept : data(std::move(other.data)) 
    {
        std::cout << "MoveTestClass moved: " << data << '\n';
    }
    
    ~MoveTestClass() 
    {
        std::cout << "MoveTestClass destroyed: " << data << '\n';
    }
    
    const std::string& getData() const { return data; }
};

void demonstrateMoveOptimizations() 
{
    std::cout << "\n=== Move Optimizations Demo ===\n";
    
    MoveOptimizedVector<MoveTestClass> vec;
    
    std::cout << "--- Adding elements ---\n";
    vec.emplace_back("Element1");                    // Direct construction
    
    MoveTestClass temp("Element2");
    vec.push_back(temp);                            // Copy
    vec.push_back(std::move(temp));                 // Move
    
    std::cout << "\n--- Moving entire vector ---\n";
    MoveOptimizedVector<MoveTestClass> vec2 = std::move(vec);  // Efficient move
    
    std::cout << "\n--- Vector operations complete ---\n";
}

int main() 
{
    demonstrateMoveSemantics();
    demonstratePerfectForwarding();
    demonstrateMoveOptimizations();
    
    return 0;
}
```

---

## Advanced Applications and Best Practices

### Template Metaprogramming

```cpp
#include <iostream>
#include <type_traits>

// Compile-time factorial
template <int N>
struct Factorial 
{
    static constexpr int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> 
{
    static constexpr int value = 1;
};

// SFINAE-based type traits
template <typename T, typename = void>
struct has_size_method : std::false_type {};

template <typename T>
struct has_size_method<T, std::void_t<decltype(std::declval<T>().size())>> : std::true_type {};

// Template specialization based on type traits
template <typename Container>
auto getSize(const Container& c) -> std::enable_if_t<has_size_method<Container>::value, size_t> 
{
    return c.size();
}

template <typename Container>
auto getSize(const Container& c) -> std::enable_if_t<!has_size_method<Container>::value, size_t> 
{
    return std::distance(std::begin(c), std::end(c));
}

// Concepts (C++20)
template <typename T>
concept Printable = requires(T t) 
{
    std::cout << t;
};

template <Printable T>
void safePrint(const T& value) 
{
    std::cout << "Printing: " << value << '\n';
}
```

### Modern C++ Features Integration

```cpp
// C++17: Structured bindings with custom types
struct Point3D 
{
    double x, y, z;
    
    // Enable structured bindings
    template <size_t I>
    auto get() const 
    {
        if constexpr (I == 0) return x;
        else if constexpr (I == 1) return y;
        else if constexpr (I == 2) return z;
    }
};

// Specialize std::tuple_size and std::tuple_element
namespace std 
{
    template <>
    struct tuple_size<Point3D> : std::integral_constant<size_t, 3> {};
    
    template <size_t I>
    struct tuple_element<I, Point3D> 
    {
        using type = double;
    };
}

// C++20: Abbreviated function templates
void processAny(auto&& value) 
{
    std::cout << "Processing: " << value << '\n';
}

// C++20: Requires clauses
template <typename T>
requires std::integral<T> || std::floating_point<T>
T multiply(T a, T b) 
{
    return a * b;
}
```

---

## Real-World Applications

### Generic Data Structures

```cpp
template <typename Key, typename Value>
class SimpleHashMap 
{
private:
    struct Entry 
    {
        Key key;
        Value value;
        bool occupied = false;
        
        Entry() = default;
        Entry(const Key& k, const Value& v) : key(k), value(v), occupied(true) {}
    };
    
    std::vector<Entry> buckets;
    size_t bucket_count;
    size_t size_;
    
    size_t hash(const Key& key) const 
    {
        return std::hash<Key>{}(key) % bucket_count;
    }
    
public:
    explicit SimpleHashMap(size_t initial_size = 16) 
        : buckets(initial_size), bucket_count(initial_size), size_(0) {}
    
    void insert(const Key& key, const Value& value) 
    {
        size_t index = hash(key);
        size_t original_index = index;
        
        do 
        {
            if (!buckets[index].occupied) 
            {
                buckets[index] = Entry(key, value);
                ++size_;
                return;
            }
            if (buckets[index].key == key) 
            {
                buckets[index].value = value;
                return;
            }
            index = (index + 1) % bucket_count;
        } 
        while (index != original_index);
        
        throw std::runtime_error("HashMap is full");
    }
    
    Value* find(const Key& key) 
    {
        size_t index = hash(key);
        size_t original_index = index;
        
        do 
        {
            if (!buckets[index].occupied) 
            {
                return nullptr;
            }
            if (buckets[index].key == key) 
            {
                return &buckets[index].value;
            }
            index = (index + 1) % bucket_count;
        } 
        while (index != original_index);
        
        return nullptr;
    }
    
    size_t size() const { return size_; }
};
```

### Thread-Safe Smart Pointers

```cpp
#include <atomic>
#include <memory>

template <typename T>
class AtomicSharedPtr 
{
private:
    mutable std::atomic<std::shared_ptr<T>*> ptr;
    
public:
    AtomicSharedPtr() : ptr(new std::shared_ptr<T>()) {}
    
    explicit AtomicSharedPtr(std::shared_ptr<T> p) 
        : ptr(new std::shared_ptr<T>(std::move(p))) {}
    
    ~AtomicSharedPtr() 
    {
        delete ptr.load();
    }
    
    std::shared_ptr<T> load() const 
    {
        return *ptr.load();
    }
    
    void store(std::shared_ptr<T> p) 
    {
        auto old_ptr = ptr.exchange(new std::shared_ptr<T>(std::move(p)));
        delete old_ptr;
    }
    
    std::shared_ptr<T> exchange(std::shared_ptr<T> p) 
    {
        auto new_ptr = new std::shared_ptr<T>(std::move(p));
        auto old_ptr = ptr.exchange(new_ptr);
        auto result = *old_ptr;
        delete old_ptr;
        return result;
    }
};
```

---

## Best Practices and Guidelines

### Template Design Principles

1. **Prefer function templates over overloads**:
```cpp
// ✅ Good: Single template handles all types
template <typename T>
T max(const T& a, const T& b) { return (a > b) ? a : b; }

// ❌ Avoid: Multiple overloads for similar logic
int max(int a, int b);
double max(double a, double b);
// ... many more overloads
```

2. **Use SFINAE and concepts for type constraints**:
```cpp
// C++20 concepts (preferred)
template <std::integral T>
void processInteger(T value) { /* ... */ }

// Pre-C++20 SFINAE
template <typename T>
std::enable_if_t<std::is_integral_v<T>, void>
processInteger(T value) { /* ... */ }
```

3. **Perfect forwarding for function wrappers**:
```cpp
template <typename Func, typename... Args>
auto wrapper(Func&& f, Args&&... args) -> decltype(f(std::forward<Args>(args)...)) 
{
    // Do something before/after
    return f(std::forward<Args>(args)...);
}
```

### Move Semantics Guidelines

1. **Always mark move operations noexcept when possible**:
```cpp
class MyClass 
{
public:
    MyClass(MyClass&& other) noexcept { /* ... */ }
    MyClass& operator=(MyClass&& other) noexcept { /* ... */ }
};
```

2. **Use std::move for rvalue references, std::forward for universal references**:
```cpp
template <typename T>
void func(T&& param) 
{
    other_func(std::forward<T>(param));  // ✅ Universal reference
}

void func(MyClass&& obj) 
{
    other_func(std::move(obj));  // ✅ Rvalue reference
}
```

3. **Prefer emplace over push for containers**:
```cpp
std::vector<std::string> vec;
vec.emplace_back("Hello");        // ✅ Direct construction
vec.push_back(std::string("Hi")); // ❌ Temporary object created
```

### Smart Pointer Best Practices

1. **Use make_unique and make_shared**:
```cpp
auto ptr = std::make_unique<MyClass>(args);     // ✅ Exception safe
auto ptr = std::unique_ptr<MyClass>(new MyClass(args)); // ❌ Not exception safe
```

2. **Prefer unique_ptr over shared_ptr when ownership is clear**:
```cpp
std::unique_ptr<Resource> createResource(); // ✅ Clear ownership transfer
std::shared_ptr<Resource> createResource(); // ❌ Unclear why sharing is needed
```

3. **Use weak_ptr to break circular references**:
```cpp
struct Parent 
{
    std::vector<std::shared_ptr<Child>> children;
};

struct Child 
{
    std::weak_ptr<Parent> parent;  // ✅ Breaks circular reference
};
```

---

## Performance Considerations and Optimization

### Template Instantiation Control

```cpp
// Explicit instantiation to control code bloat
template class SimpleVector<int>;
template class SimpleVector<std::string>;

// Extern template to avoid duplicate instantiations
extern template class std::vector<MyClass>;

// Template specialization for performance-critical types
template <>
class SimpleVector<bool> 
{
    // Specialized implementation for space efficiency
    std::vector<uint8_t> data;
    size_t bit_size;
    
public:
    class BitReference 
    {
        uint8_t& byte;
        uint8_t mask;
        
    public:
        BitReference(uint8_t& b, uint8_t m) : byte(b), mask(m) {}
        
        BitReference& operator=(bool value) 
        {
            if (value) byte |= mask;
            else byte &= ~mask;
            return *this;
        }
        
        operator bool() const 
        {
            return (byte & mask) != 0;
        }
    };
    
    BitReference operator[](size_t index) 
    {
        size_t byte_index = index / 8;
        uint8_t bit_index = index % 8;
        return BitReference(data[byte_index], 1 << bit_index);
    }
    
    bool operator[](size_t index) const 
    {
        size_t byte_index = index / 8;
        uint8_t bit_index = index % 8;
        return (data[byte_index] & (1 << bit_index)) != 0;
    }
};
```

### Move Semantics Performance

```cpp
#include <chrono>
#include <iostream>
#include <vector>

class PerformanceTest 
{
public:
    static void compareCopyVsMove() 
    {
        std::cout << "\n=== Copy vs Move Performance ===\n";
        
        const size_t iterations = 1000000;
        std::vector<std::string> source;
        source.reserve(iterations);
        
        // Prepare source data
        for (size_t i = 0; i < iterations; ++i) 
        {
            source.emplace_back("This is a test string " + std::to_string(i));
        }
        
        // Test copy performance
        auto start = std::chrono::high_resolution_clock::now();
        std::vector<std::string> copy_dest;
        copy_dest.reserve(iterations);
        
        for (const auto& str : source) 
        {
            copy_dest.push_back(str);  // Copy
        }
        
        auto copy_time = std::chrono::high_resolution_clock::now() - start;
        
        // Test move performance
        start = std::chrono::high_resolution_clock::now();
        std::vector<std::string> move_dest;
        move_dest.reserve(iterations);
        
        for (auto& str : source) 
        {
            move_dest.push_back(std::move(str));  // Move
        }
        
        auto move_time = std::chrono::high_resolution_clock::now() - start;
        
        std::cout << "Copy time: " << std::chrono::duration_cast<std::chrono::milliseconds>(copy_time).count() << "ms\n";
        std::cout << "Move time: " << std::chrono::duration_cast<std::chrono::milliseconds>(move_time).count() << "ms\n";
        
        auto speedup = static_cast<double>(copy_time.count()) / move_time.count();
        std::cout << "Speedup: " << speedup << "x faster\n";
    }
    
    static void testRVO() 
    {
        std::cout << "\n=== Return Value Optimization ===\n";
        
        auto createLargeString = [](size_t size) 
        {
            std::string result;
            result.reserve(size);
            for (size_t i = 0; i < size; ++i) 
            {
                result += 'A' + (i % 26);
            }
            return result;  // RVO applies here
        };
        
        auto start = std::chrono::high_resolution_clock::now();
        
        for (int i = 0; i < 10000; ++i) 
        {
            auto str = createLargeString(1000);  // No copy/move thanks to RVO
            // Use str to prevent optimization away
            volatile auto len = str.length();
            (void)len;
        }
        
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        
        std::cout << "RVO test completed in: " << duration.count() << "ms\n";
    }
};
```

---

## Advanced Template Patterns

### CRTP (Curiously Recurring Template Pattern)

```cpp
#include <iostream>

// Base template using CRTP
template <typename Derived>
class Printable 
{
public:
    void print() const 
    {
        static_cast<const Derived*>(this)->printImpl();
    }
    
    void printTwice() const 
    {
        print();
        print();
    }
};

// Derived classes implement printImpl
class Document : public Printable<Document> 
{
private:
    std::string title;
    std::string content;
    
public:
    Document(const std::string& t, const std::string& c) : title(t), content(c) {}
    
    void printImpl() const 
    {
        std::cout << "Document: " << title << "\nContent: " << content << '\n';
    }
};

class Image : public Printable<Image> 
{
private:
    std::string filename;
    int width, height;
    
public:
    Image(const std::string& f, int w, int h) : filename(f), width(w), height(h) {}
    
    void printImpl() const 
    {
        std::cout << "Image: " << filename << " (" << width << "x" << height << ")\n";
    }
};

// CRTP for compile-time polymorphism
template <typename T>
class Comparable 
{
public:
    bool operator<(const T& other) const 
    {
        return static_cast<const T*>(this)->compare(other) < 0;
    }
    
    bool operator>(const T& other) const 
    {
        return static_cast<const T*>(this)->compare(other) > 0;
    }
    
    bool operator==(const T& other) const 
    {
        return static_cast<const T*>(this)->compare(other) == 0;
    }
    
    bool operator!=(const T& other) const 
    {
        return !(*this == other);
    }
};

class Version : public Comparable<Version> 
{
private:
    int major, minor, patch;
    
public:
    Version(int maj, int min, int p) : major(maj), minor(min), patch(p) {}
    
    int compare(const Version& other) const 
    {
        if (major != other.major) return major - other.major;
        if (minor != other.minor) return minor - other.minor;
        return patch - other.patch;
    }
    
    friend std::ostream& operator<<(std::ostream& out, const Version& v) 
    {
        return out << v.major << '.' << v.minor << '.' << v.patch;
    }
};

void demonstrateCRTP() 
{
    std::cout << "\n=== CRTP Demo ===\n";
    
    Document doc("My Document", "This is the content");
    Image img("photo.jpg", 1920, 1080);
    
    doc.print();
    std::cout << '\n';
    img.printTwice();
    
    Version v1(2, 1, 0);
    Version v2(2, 0, 5);
    
    std::cout << v1 << " > " << v2 << ": " << (v1 > v2) << '\n';
    std::cout << v1 << " == " << v2 << ": " << (v1 == v2) << '\n';
}
```

### Policy-Based Design

```cpp
#include <iostream>
#include <memory>

// Storage policies
template <typename T>
class HeapStorage 
{
private:
    std::unique_ptr<T> data;
    
public:
    HeapStorage() : data(std::make_unique<T>()) {}
    explicit HeapStorage(const T& value) : data(std::make_unique<T>(value)) {}
    
    T& get() { return *data; }
    const T& get() const { return *data; }
    
    static constexpr const char* name() { return "HeapStorage"; }
};

template <typename T>
class StackStorage 
{
private:
    T data{};
    
public:
    StackStorage() = default;
    explicit StackStorage(const T& value) : data(value) {}
    
    T& get() { return data; }
    const T& get() const { return data; }
    
    static constexpr const char* name() { return "StackStorage"; }
};

// Threading policies
class SingleThreaded 
{
public:
    void lock() const {}
    void unlock() const {}
    static constexpr const char* name() { return "SingleThreaded"; }
};

class MultiThreaded 
{
private:
    mutable std::mutex mtx;
    
public:
    void lock() const { mtx.lock(); }
    void unlock() const { mtx.unlock(); }
    static constexpr const char* name() { return "MultiThreaded"; }
};

// Policy-based smart holder
template <typename T, 
          template<typename> class StoragePolicy = HeapStorage,
          class ThreadingPolicy = SingleThreaded>
class SmartHolder : private StoragePolicy<T>, private ThreadingPolicy 
{
public:
    SmartHolder() = default;
    explicit SmartHolder(const T& value) : StoragePolicy<T>(value) {}
    
    T& operator*() 
    {
        std::lock_guard<ThreadingPolicy> lock(*this);
        return this->StoragePolicy<T>::get();
    }
    
    const T& operator*() const 
    {
        std::lock_guard<ThreadingPolicy> lock(*this);
        return this->StoragePolicy<T>::get();
    }
    
    T* operator->() 
    {
        std::lock_guard<ThreadingPolicy> lock(*this);
        return &this->StoragePolicy<T>::get();
    }
    
    const T* operator->() const 
    {
        std::lock_guard<ThreadingPolicy> lock(*this);
        return &this->StoragePolicy<T>::get();
    }
    
    void info() const 
    {
        std::cout << "SmartHolder using " << StoragePolicy<T>::name() 
                  << " and " << ThreadingPolicy::name() << '\n';
    }
    
private:
    // RAII lock guard
    template <typename Policy>
    struct lock_guard 
    {
        const Policy& policy;
        lock_guard(const Policy& p) : policy(p) { policy.lock(); }
        ~lock_guard() { policy.unlock(); }
    };
};

void demonstratePolicyDesign() 
{
    std::cout << "\n=== Policy-Based Design Demo ===\n";
    
    // Different combinations of policies
    SmartHolder<std::string, HeapStorage> heapHolder("Heap stored");
    SmartHolder<std::string, StackStorage> stackHolder("Stack stored");
    SmartHolder<std::string, HeapStorage, MultiThreaded> threadSafeHolder("Thread safe");
    
    heapHolder.info();
    stackHolder.info();
    threadSafeHolder.info();
    
    std::cout << "Heap holder: " << *heapHolder << '\n';
    std::cout << "Stack holder: " << *stackHolder << '\n';
    std::cout << "Thread-safe holder: " << *threadSafeHolder << '\n';
}
```

---

## Error Handling and Debugging

### Template Error Diagnostics

```cpp
#include <type_traits>
#include <string>

// Better error messages with static_assert
template <typename T>
class NumericContainer 
{
    static_assert(std::is_arithmetic_v<T>, 
                  "NumericContainer requires arithmetic types (int, float, double, etc.)");
    
private:
    T value{};
    
public:
    explicit NumericContainer(T v) : value(v) {}
    
    T getValue() const { return value; }
    
    // Operations only available for numeric types
    NumericContainer operator+(const NumericContainer& other) const 
    {
        return NumericContainer(value + other.value);
    }
    
    NumericContainer operator*(const NumericContainer& other) const 
    {
        return NumericContainer(value * other.value);
    }
};

// Concept-based constraints (C++20)
template <typename T>
concept Numeric = std::is_arithmetic_v<T>;

template <Numeric T>
class BetterNumericContainer 
{
private:
    T value{};
    
public:
    explicit BetterNumericContainer(T v) : value(v) {}
    T getValue() const { return value; }
};

// SFINAE-friendly detection
template <typename T, typename = void>
struct has_begin : std::false_type {};

template <typename T>
struct has_begin<T, std::void_t<decltype(std::begin(std::declval<T>()))>> : std::true_type {};

template <typename Container>
auto safeIterate(Container&& container) 
    -> std::enable_if_t<has_begin<Container>::value, void> 
{
    std::cout << "Iterating over container:\n";
    for (const auto& item : container) 
    {
        std::cout << item << " ";
    }
    std::cout << '\n';
}

template <typename T>
auto safeIterate(T&& item) 
    -> std::enable_if_t<!has_begin<T>::value, void> 
{
    std::cout << "Single item: " << item << '\n';
}

void demonstrateErrorHandling() 
{
    std::cout << "\n=== Template Error Handling ===\n";
    
    // These work fine
    NumericContainer<int> intContainer(42);
    NumericContainer<double> doubleContainer(3.14);
    
    std::cout << "Int container: " << intContainer.getValue() << '\n';
    std::cout << "Double container: " << doubleContainer.getValue() << '\n';
    
    auto sum = intContainer + NumericContainer<int>(8);
    std::cout << "Sum: " << sum.getValue() << '\n';
    
    // This would cause a compile-time error:
    // NumericContainer<std::string> stringContainer("hello"); // Error!
    
    // SFINAE-based safe iteration
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::string str = "hello";
    
    safeIterate(vec);   // Uses container version
    safeIterate(42);    // Uses single item version
}
```

### Memory Management Debugging

```cpp
#include <iostream>
#include <memory>
#include <vector>

// Debug allocator for tracking allocations
template <typename T>
class DebuggingAllocator 
{
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    
    template <typename U>
    struct rebind { using other = DebuggingAllocator<U>; };
    
    DebuggingAllocator() = default;
    
    template <typename U>
    DebuggingAllocator(const DebuggingAllocator<U>&) {}
    
    pointer allocate(size_type n) 
    {
        std::cout << "Allocating " << n << " objects of size " << sizeof(T) << '\n';
        return static_cast<pointer>(::operator new(n * sizeof(T)));
    }
    
    void deallocate(pointer p, size_type n) 
    {
        std::cout << "Deallocating " << n << " objects of size " << sizeof(T) << '\n';
        ::operator delete(p);
    }
    
    template <typename U, typename... Args>
    void construct(U* p, Args&&... args) 
    {
        std::cout << "Constructing object at " << p << '\n';
        new(p) U(std::forward<Args>(args)...);
    }
    
    template <typename U>
    void destroy(U* p) 
    {
        std::cout << "Destroying object at " << p << '\n';
        p->~U();
    }
};

template <typename T, typename U>
bool operator==(const DebuggingAllocator<T>&, const DebuggingAllocator<U>&) 
{
    return true;
}

template <typename T, typename U>
bool operator!=(const DebuggingAllocator<T>&, const DebuggingAllocator<U>&) 
{
    return false;
}

// Memory leak detector for smart pointers
class MemoryTracker 
{
private:
    static inline std::atomic<size_t> allocation_count{0};
    static inline std::atomic<size_t> deallocation_count{0};
    
public:
    static void track_allocation() 
    {
        allocation_count++;
        std::cout << "Allocation #" << allocation_count.load() << '\n';
    }
    
    static void track_deallocation() 
    {
        deallocation_count++;
        std::cout << "Deallocation #" << deallocation_count.load() << '\n';
    }
    
    static void report() 
    {
        std::cout << "=== Memory Report ===\n";
        std::cout << "Allocations: " << allocation_count.load() << '\n';
        std::cout << "Deallocations: " << deallocation_count.load() << '\n';
        std::cout << "Potential leaks: " << (allocation_count.load() - deallocation_count.load()) << '\n';
    }
};

template <typename T>
class TrackedResource 
{
private:
    T* data;
    
public:
    explicit TrackedResource(const T& value) : data(new T(value)) 
    {
        MemoryTracker::track_allocation();
    }
    
    ~TrackedResource() 
    {
        delete data;
        MemoryTracker::track_deallocation();
    }
    
    // Non-copyable, movable
    TrackedResource(const TrackedResource&) = delete;
    TrackedResource& operator=(const TrackedResource&) = delete;
    
    TrackedResource(TrackedResource&& other) noexcept : data(other.data) 
    {
        other.data = nullptr;
    }
    
    TrackedResource& operator=(TrackedResource&& other) noexcept 
    {
        if (this != &other) 
        {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }
    
    T& get() { return *data; }
    const T& get() const { return *data; }
};

void demonstrateDebugging() 
{
    std::cout << "\n=== Memory Debugging Demo ===\n";
    
    // Debug allocator usage
    std::vector<int, DebuggingAllocator<int>> debugVec;
    debugVec.push_back(1);
    debugVec.push_back(2);
    debugVec.push_back(3);
    
    std::cout << "\n--- Memory tracking ---\n";
    {
        TrackedResource<std::string> resource1("Resource 1");
        TrackedResource<std::string> resource2("Resource 2");
        
        std::cout << "Resource 1: " << resource1.get() << '\n';
        std::cout << "Resource 2: " << resource2.get() << '\n';
        
        // Move resource2
        TrackedResource<std::string> resource3 = std::move(resource2);
        std::cout << "Resource 3 (moved): " << resource3.get() << '\n';
    }
    
    MemoryTracker::report();
}
```

---

## Complete Example: Generic JSON-like Data Structure

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <variant>
#include <memory>

// Modern C++ JSON-like variant type
class JsonValue 
{
public:
    using JsonObject = std::map<std::string, JsonValue>;
    using JsonArray = std::vector<JsonValue>;
    using ValueType = std::variant<std::nullptr_t, bool, int, double, std::string, JsonArray, JsonObject>;
    
private:
    ValueType value;
    
public:
    // Constructors for different types
    JsonValue() : value(nullptr) {}
    JsonValue(std::nullptr_t) : value(nullptr) {}
    JsonValue(bool b) : value(b) {}
    JsonValue(int i) : value(i) {}
    JsonValue(double d) : value(d) {}
    JsonValue(const char* s) : value(std::string(s)) {}
    JsonValue(const std::string& s) : value(s) {}
    JsonValue(std::string&& s) : value(std::move(s)) {}
    JsonValue(const JsonArray& arr) : value(arr) {}
    JsonValue(JsonArray&& arr) : value(std::move(arr)) {}
    JsonValue(const JsonObject& obj) : value(obj) {}
    JsonValue(JsonObject&& obj) : value(std::move(obj)) {}
    
    // Type checking
    bool isNull() const { return std::holds_alternative<std::nullptr_t>(value); }
    bool isBool() const { return std::holds_alternative<bool>(value); }
    bool isInt() const { return std::holds_alternative<int>(value); }
    bool isDouble() const { return std::holds_alternative<double>(value); }
    bool isString() const { return std::holds_alternative<std::string>(value); }
    bool isArray() const { return std::holds_alternative<JsonArray>(value); }
    bool isObject() const { return std::holds_alternative<JsonObject>(value); }
    
    // Value getters with type safety
    template <typename T>
    T get() const 
    {
        if constexpr (std::is_same_v<T, bool>) 
        {
            return std::get<bool>(value);
        }
        else if constexpr (std::is_same_v<T, int>) 
        {
            return std::get<int>(value);
        }
        else if constexpr (std::is_same_v<T, double>) 
        {
            return std::get<double>(value);
        }
        else if constexpr (std::is_same_v<T, std::string>) 
        {
            return std::get<std::string>(value);
        }
        else if constexpr (std::is_same_v<T, JsonArray>) 
        {
            return std::get<JsonArray>(value);
        }
        else if constexpr (std::is_same_v<T, JsonObject>) 
        {
            return std::get<JsonObject>(value);
        }
        else 
        {
            static_assert(sizeof(T) == 0, "Unsupported type for JsonValue::get()");
        }
    }
    
    // Array access
    JsonValue& operator[](size_t index) 
    {
        return std::get<JsonArray>(value)[index];
    }
    
    const JsonValue& operator[](size_t index) const 
    {
        return std::get<JsonArray>(value)[index];
    }
    
    // Object access
    JsonValue& operator[](const std::string& key) 
    {
        return std::get<JsonObject>(value)[key];
    }
    
    const JsonValue& operator[](const std::string& key) const 
    {
        return std::get<JsonObject>(value).at(key);
    }
    
    // Pretty printing with visitor pattern
    class PrintVisitor 
    {
    private:
        mutable int indent_level = 0;
        
        void print_indent() const 
        {
            for (int i = 0; i < indent_level; ++i) std::cout << "  ";
        }
        
    public:
        void operator()(std::nullptr_t) const 
        {
            std::cout << "null";
        }
        
        void operator()(bool b) const 
        {
            std::cout << (b ? "true" : "false");
        }
        
        void operator()(int i) const 
        {
            std::cout << i;
        }
        
        void operator()(double d) const 
        {
            std::cout << d;
        }
        
        void operator()(const std::string& s) const 
        {
            std::cout << '"' << s << '"';
        }
        
        void operator()(const JsonArray& arr) const 
        {
            std::cout << "[\n";
            ++indent_level;
            
            for (size_t i = 0; i < arr.size(); ++i) 
            {
                print_indent();
                std::visit(*this, arr[i].value);
                if (i < arr.size() - 1) std::cout << ",";
                std::cout << "\n";
            }
            
            --indent_level;
            print_indent();
            std::cout << "]";
        }
        
        void operator()(const JsonObject& obj) const 
        {
            std::cout << "{\n";
            ++indent_level;
            
            size_t count = 0;
            for (const auto& [key, val] : obj) 
            {
                print_indent();
                std::cout << '"' << key << "\": ";
                std::visit(*this, val.value);
                if (++count < obj.size()) std::cout << ",";
                std::cout << "\n";
            }
            
            --indent_level;
            print_indent();
            std::cout << "}";
        }
    };
    
    void print() const 
    {
        std::visit(PrintVisitor{}, value);
        std::cout << std::endl;
    }
    
    friend std::ostream& operator<<(std::ostream& out, const JsonValue& json) 
    {
        std::visit(PrintVisitor{}, json.value);
        return out;
    }
};

void demonstrateJsonExample() 
{
    std::cout << "\n=== JSON-like Data Structure Demo ===\n";
    
    // Create complex JSON structure
    JsonValue json = JsonValue::JsonObject{
        {"name", "John Doe"},
        {"age", 30},
        {"height", 175.5},
        {"married", true},
        {"children", JsonValue::JsonArray{
            "Alice", "Bob"
        }},
        {"address", JsonValue::JsonObject{
            {"street", "123 Main St"},
            {"city", "Springfield"},
            {"zipcode", 12345}
        }},
        {"hobbies", JsonValue::JsonArray{
            "reading", "swimming", "coding"
        }}
    };
    
    std::cout << "Complete JSON structure:\n";
    json.print();
    
    // Access specific values
    std::cout << "\nName: " << json["name"].get<std::string>() << '\n';
    std::cout << "Age: " << json["age"].get<int>() << '\n';
    std::cout << "First child: " << json["children"][0].get<std::string>() << '\n';
    std::cout << "City: " << json["address"]["city"].get<std::string>() << '\n';
    
    // Modify values
    json["age"] = 31;
    json["married"] = false;
    
    std::cout << "\nAfter modifications:\n";
    std::cout << "Age: " << json["age"].get<int>() << '\n';
    std::cout << "Married: " << json["married"].get<bool>() << '\n';
}

int main() 
{
    demonstrateCRTP();
    demonstratePolicyDesign();
    demonstrateErrorHandling();
    demonstrateDebugging();
    demonstrateJsonExample();
    
    PerformanceTest::compareCopyVsMove();
    PerformanceTest::testRVO();
    
    return 0;
}
```

---

## Summary and Conclusions

### Key Takeaways from Chapters 19-23

1. **Templates enable generic programming** - Write code once, use with multiple types
2. **Operator overloading makes custom types intuitive** - Allow natural syntax for user-defined types  
3. **Smart pointers provide automatic resource management** - Eliminate manual memory management errors
4. **Move semantics optimize performance** - Avoid expensive copies when objects are temporary
5. **Perfect forwarding preserves value categories** - Essential for efficient generic functions

### Modern C++ Evolution

These advanced features represent C++'s evolution toward:
- **Zero-cost abstractions** - High-level features with minimal runtime overhead
- **Type safety** - Catch errors at compile time rather than runtime
- **Resource safety** - Automatic cleanup prevents leaks and dangling pointers
- **Performance** - Move semantics and template optimization rival hand-optimized C code
- **Expressiveness** - Write code that clearly expresses intent

### Next Steps

With mastery of these advanced concepts, you're ready to:
- **Build production-quality libraries** using templates and smart pointers
- **Optimize performance-critical code** with move semantics and perfect forwarding
- **Design elegant APIs** using operator overloading and CRTP patterns
- **Contribute to open-source projects** that use modern C++ extensively
- **Explore specialized domains** like game development, systems programming, or high-frequency trading

The journey from basic C++ to these advanced features represents a significant leap in capability. You now possess the tools to write efficient, safe, and expressive C++ code that leverages the full power of the language!

**Next: Advanced topics like concurrency, networking, or domain-specific applications**

# Chapters 24-28: Advanced C++ - Modern Language Features and Best Practices

## Building on Fundamentals: Advanced C++ Programming

Having mastered classes, inheritance, and basic templates, we now explore the sophisticated features that make modern C++ a powerful and expressive language. These chapters cover advanced topics that professional C++ developers use daily to write efficient, maintainable, and robust code.

---

## 24.1 - Smart Pointers: Automatic Memory Management

### The Problem with Raw Pointers

Raw pointers create numerous pitfalls:

```cpp
// Problematic raw pointer usage
void problematicCode() {
    int* data = new int[1000];  // Manual allocation
    
    // ... complex logic that might throw exceptions
    
    if (someCondition) {
        return;  // ❌ Memory leak! Forgot to delete[]
    }
    
    delete[] data;  // ❌ Only reached if no early return
}

void dangerousSharing() {
    int* ptr = new int(42);
    
    processData(ptr);    // Who owns ptr now?
    delete ptr;          // ❌ Double delete if processData also deletes?
    
    *ptr = 100;          // ❌ Use after free!
}
```

### Smart Pointers: The Modern Solution

Smart pointers automatically manage memory and provide clear ownership semantics:

```cpp
#include <memory>
#include <iostream>
#include <vector>

class Resource {
public:
    Resource(int value) : data_(value) {
        std::cout << "Resource " << data_ << " created\n";
    }
    
    ~Resource() {
        std::cout << "Resource " << data_ << " destroyed\n";
    }
    
    void use() const {
        std::cout << "Using resource " << data_ << "\n";
    }
    
private:
    int data_;
};

void demonstrateSmartPointers() {
    // unique_ptr: Exclusive ownership
    std::unique_ptr<Resource> unique = std::make_unique<Resource>(1);
    unique->use();
    // Automatically deleted when unique goes out of scope
    
    // shared_ptr: Shared ownership
    std::shared_ptr<Resource> shared1 = std::make_shared<Resource>(2);
    {
        std::shared_ptr<Resource> shared2 = shared1;  // Reference count: 2
        shared2->use();
    }  // shared2 destroyed, reference count: 1
    shared1->use();  // Resource still alive
    // Resource deleted when shared1 goes out of scope
}
```

### unique_ptr: Exclusive Ownership

```cpp
#include <memory>
#include <vector>
#include <algorithm>

class Database {
public:
    void connect() { std::cout << "Connected to database\n"; }
    void disconnect() { std::cout << "Disconnected from database\n"; }
    ~Database() { disconnect(); }
};

class DataManager {
private:
    std::unique_ptr<Database> db_;
    
public:
    DataManager() : db_(std::make_unique<Database>()) {
        db_->connect();
    }
    
    // Move-only semantics (no copying)
    DataManager(const DataManager&) = delete;
    DataManager& operator=(const DataManager&) = delete;
    
    DataManager(DataManager&& other) noexcept : db_(std::move(other.db_)) {}
    DataManager& operator=(DataManager&& other) noexcept {
        if (this != &other) {
            db_ = std::move(other.db_);
        }
        return *this;
    }
    
    // Transfer ownership
    std::unique_ptr<Database> releaseDatabase() {
        return std::move(db_);
    }
};

// Factory function returning unique ownership
std::unique_ptr<Resource> createResource(int value) {
    return std::make_unique<Resource>(value);
}

void uniquePtrExamples() {
    // Array management
    std::unique_ptr<int[]> numbers = std::make_unique<int[]>(100);
    
    // Container of unique_ptrs
    std::vector<std::unique_ptr<Resource>> resources;
    resources.push_back(createResource(10));
    resources.push_back(createResource(20));
    
    // Move semantics in algorithms
    std::sort(resources.begin(), resources.end(),
        [](const std::unique_ptr<Resource>& a, const std::unique_ptr<Resource>& b) {
            return a.get() < b.get();  // Sort by pointer address
        });
}
```

### shared_ptr: Shared Ownership

```cpp
#include <memory>
#include <vector>
#include <thread>

class Logger {
public:
    void log(const std::string& message) {
        std::cout << "[LOG] " << message << std::endl;
    }
    
    ~Logger() {
        std::cout << "Logger destroyed\n";
    }
};

class Service {
private:
    std::shared_ptr<Logger> logger_;
    std::string name_;
    
public:
    Service(const std::string& name, std::shared_ptr<Logger> logger) 
        : name_(name), logger_(std::move(logger)) {}
    
    void doWork() {
        logger_->log(name_ + " is working");
    }
};

void sharedPtrExamples() {
    // Shared logger across multiple services
    auto logger = std::make_shared<Logger>();
    
    std::vector<std::unique_ptr<Service>> services;
    services.push_back(std::make_unique<Service>("Service1", logger));
    services.push_back(std::make_unique<Service>("Service2", logger));
    services.push_back(std::make_unique<Service>("Service3", logger));
    
    // All services share the same logger
    for (auto& service : services) {
        service->doWork();
    }
    
    std::cout << "Logger use count: " << logger.use_count() << "\n";
    
    // Logger automatically destroyed when last shared_ptr is destroyed
}

// Thread-safe shared ownership
void threadSafeSharing() {
    auto resource = std::make_shared<Resource>(100);
    
    std::vector<std::thread> threads;
    
    for (int i = 0; i < 4; ++i) {
        threads.emplace_back([resource]() {  // Capture by value (copies shared_ptr)
            resource->use();  // Thread-safe reference counting
        });
    }
    
    for (auto& t : threads) {
        t.join();
    }
}
```

### weak_ptr: Breaking Circular References

```cpp
#include <memory>
#include <iostream>

class Child;

class Parent {
public:
    std::shared_ptr<Child> child_;
    
    Parent() { std::cout << "Parent created\n"; }
    ~Parent() { std::cout << "Parent destroyed\n"; }
    
    void setChild(std::shared_ptr<Child> child) {
        child_ = child;
    }
};

class Child {
public:
    std::weak_ptr<Parent> parent_;  // ✅ weak_ptr breaks the cycle
    
    Child() { std::cout << "Child created\n"; }
    ~Child() { std::cout << "Child destroyed\n"; }
    
    void setParent(std::shared_ptr<Parent> parent) {
        parent_ = parent;
    }
    
    void doSomethingWithParent() {
        if (auto parent = parent_.lock()) {  // Safe access
            std::cout << "Child accessing parent\n";
        } else {
            std::cout << "Parent no longer exists\n";
        }
    }
};

void demonstrateWeakPtr() {
    auto parent = std::make_shared<Parent>();
    auto child = std::make_shared<Child>();
    
    parent->setChild(child);
    child->setParent(parent);  // No circular reference due to weak_ptr
    
    child->doSomethingWithParent();
    
    // Both objects properly destroyed when shared_ptrs go out of scope
}
```

---

## 24.2 - Move Semantics and Perfect Forwarding

### Understanding Value Categories

```cpp
#include <iostream>
#include <string>
#include <utility>

void demonstrateValueCategories() {
    std::string str = "Hello";
    
    // lvalues (have names, can appear on left of assignment)
    std::string& lref = str;        // lvalue reference
    const std::string& clref = str; // const lvalue reference
    
    // rvalues (temporary objects, literals)
    std::string&& rref = std::move(str);  // rvalue reference
    std::string&& rref2 = "World";        // rvalue reference to temporary
    
    // Functions can be overloaded based on value category
    auto result1 = processString(str);           // Calls lvalue version
    auto result2 = processString(std::move(str)); // Calls rvalue version
    auto result3 = processString("literal");      // Calls rvalue version
}

// Overloaded functions for different value categories
std::string processString(const std::string& s) {  // lvalue version
    std::cout << "Processing lvalue: " << s << "\n";
    return s;  // Copy
}

std::string processString(std::string&& s) {  // rvalue version
    std::cout << "Processing rvalue: " << s << "\n";
    return std::move(s);  // Move
}
```

### Move Constructor and Move Assignment

```cpp
#include <vector>
#include <memory>
#include <algorithm>

class MovableResource {
private:
    std::unique_ptr<int[]> data_;
    size_t size_;
    
public:
    // Constructor
    explicit MovableResource(size_t size) 
        : data_(std::make_unique<int[]>(size)), size_(size) {
        std::cout << "Constructor: allocated " << size_ << " elements\n";
        
        // Initialize with some values
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = static_cast<int>(i);
        }
    }
    
    // Copy constructor (expensive)
    MovableResource(const MovableResource& other) 
        : data_(std::make_unique<int[]>(other.size_)), size_(other.size_) {
        std::cout << "Copy constructor: copying " << size_ << " elements\n";
        std::copy(other.data_.get(), other.data_.get() + size_, data_.get());
    }
    
    // Move constructor (cheap)
    MovableResource(MovableResource&& other) noexcept 
        : data_(std::move(other.data_)), size_(other.size_) {
        std::cout << "Move constructor: transferred " << size_ << " elements\n";
        other.size_ = 0;  // Reset moved-from object
    }
    
    // Copy assignment operator
    MovableResource& operator=(const MovableResource& other) {
        if (this != &other) {
            std::cout << "Copy assignment: copying " << other.size_ << " elements\n";
            data_ = std::make_unique<int[]>(other.size_);
            size_ = other.size_;
            std::copy(other.data_.get(), other.data_.get() + size_, data_.get());
        }
        return *this;
    }
    
    // Move assignment operator
    MovableResource& operator=(MovableResource&& other) noexcept {
        if (this != &other) {
            std::cout << "Move assignment: transferred " << other.size_ << " elements\n";
            data_ = std::move(other.data_);
            size_ = other.size_;
            other.size_ = 0;
        }
        return *this;
    }
    
    size_t size() const { return size_; }
    int& operator[](size_t index) { return data_[index]; }
    const int& operator[](size_t index) const { return data_[index]; }
};

void demonstrateMoveSemantics() {
    std::vector<MovableResource> resources;
    
    // Move construction
    resources.push_back(MovableResource(1000));  // Temporary object moved
    
    MovableResource large(2000);
    resources.push_back(std::move(large));       // Explicit move
    
    // Move in algorithms
    std::vector<MovableResource> moved_resources;
    moved_resources.reserve(resources.size());
    
    std::move(resources.begin(), resources.end(), 
              std::back_inserter(moved_resources));
}
```

### Perfect Forwarding with std::forward

```cpp
#include <iostream>
#include <memory>
#include <utility>

class Widget {
public:
    Widget() { std::cout << "Widget default constructor\n"; }
    Widget(const Widget&) { std::cout << "Widget copy constructor\n"; }
    Widget(Widget&&) noexcept { std::cout << "Widget move constructor\n"; }
    
    explicit Widget(int value) { 
        std::cout << "Widget constructor with value: " << value << "\n"; 
    }
    
    Widget(const std::string& name, int value) {
        std::cout << "Widget constructor: " << name << ", " << value << "\n";
    }
};

// Factory function with perfect forwarding
template<typename T, typename... Args>
std::unique_ptr<T> make_unique_perfect(Args&&... args) {
    return std::make_unique<T>(std::forward<Args>(args)...);
}

// Wrapper that forwards arguments perfectly
template<typename F, typename... Args>
decltype(auto) call_with_timing(F&& func, Args&&... args) {
    auto start = std::chrono::high_resolution_clock::now();
    
    // Perfect forwarding preserves value categories
    decltype(auto) result = std::forward<F>(func)(std::forward<Args>(args)...);
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Function took " << duration.count() << " microseconds\n";
    
    return result;
}

void demonstratePerfectForwarding() {
    // Perfect forwarding in factory functions
    auto widget1 = make_unique_perfect<Widget>();                    // Default construction
    auto widget2 = make_unique_perfect<Widget>(42);                  // Value construction
    auto widget3 = make_unique_perfect<Widget>("Test", 100);         // Multi-argument
    
    // Perfect forwarding with function wrappers
    Widget w;
    auto result = call_with_timing([](const Widget& w) { return w; }, w);         // lvalue
    auto result2 = call_with_timing([](Widget w) { return w; }, std::move(w));    // rvalue
}
```

---

## 25.1 - Lambda Expressions and Functional Programming

### Basic Lambda Syntax

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void basicLambdas() {
    // Basic lambda syntax: [capture](parameters) -> return_type { body }
    
    // Simple lambda
    auto greet = []() {
        std::cout << "Hello, World!\n";
    };
    greet();
    
    // Lambda with parameters
    auto add = [](int a, int b) {
        return a + b;
    };
    std::cout << "3 + 4 = " << add(3, 4) << "\n";
    
    // Lambda with explicit return type
    auto divide = [](double a, double b) -> double {
        if (b != 0.0) {
            return a / b;
        }
        throw std::invalid_argument("Division by zero");
    };
    
    // Generic lambda (C++14)
    auto generic_add = [](auto a, auto b) {
        return a + b;
    };
    
    std::cout << generic_add(1, 2) << "\n";      // int + int
    std::cout << generic_add(1.5, 2.5) << "\n"; // double + double
    std::cout << generic_add(std::string("Hello"), std::string(" World")) << "\n"; // string + string
}
```

### Capture Mechanisms

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

void demonstrateCaptures() {
    int x = 10;
    int y = 20;
    
    // Capture by value
    auto lambda1 = [x, y](int z) {
        return x + y + z;  // x and y are copied
    };
    
    // Capture by reference
    auto lambda2 = [&x, &y](int z) {
        x += z;  // Modifies original x
        return x + y;
    };
    
    // Capture all by value
    auto lambda3 = [=](int z) {
        return x + y + z;  // All variables copied
    };
    
    // Capture all by reference
    auto lambda4 = [&](int z) {
        x += z;  // All variables by reference
        return x + y;
    };
    
    // Mixed capture
    auto lambda5 = [=, &x](int z) {
        x += z;      // x by reference
        return x + y + z;  // y by value
    };
    
    // Init capture (C++14)
    auto lambda6 = [captured_value = x * 2](int z) {
        return captured_value + z;
    };
    
    // Move capture
    auto resource = std::make_unique<int>(42);
    auto lambda7 = [moved_resource = std::move(resource)](int multiplier) {
        return *moved_resource * multiplier;
    };
    
    std::cout << lambda1(5) << "\n";  // 35
    std::cout << lambda6(8) << "\n";  // 28 (x*2 + 8)
    std::cout << lambda7(3) << "\n";  // 126 (42 * 3)
}
```

### Lambdas with STL Algorithms

```cpp
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <map>

struct Product {
    std::string name;
    double price;
    int quantity;
    
    double totalValue() const { return price * quantity; }
};

void lambdasWithSTL() {
    std::vector<Product> inventory = {
        {"Laptop", 999.99, 10},
        {"Mouse", 25.50, 50},
        {"Keyboard", 75.00, 30},
        {"Monitor", 299.99, 15},
        {"Speaker", 150.00, 25}
    };
    
    // Find expensive items
    auto expensive_threshold = 100.0;
    auto expensive_count = std::count_if(inventory.begin(), inventory.end(),
        [expensive_threshold](const Product& p) {
            return p.price > expensive_threshold;
        });
    
    std::cout << "Products over $" << expensive_threshold << ": " << expensive_count << "\n";
    
    // Sort by total value (price * quantity)
    std::sort(inventory.begin(), inventory.end(),
        [](const Product& a, const Product& b) {
            return a.totalValue() > b.totalValue();  // Descending order
        });
    
    std::cout << "Most valuable inventory item: " << inventory[0].name 
              << " ($" << inventory[0].totalValue() << ")\n";
    
    // Transform to create a summary
    std::vector<std::string> summaries;
    std::transform(inventory.begin(), inventory.end(), std::back_inserter(summaries),
        [](const Product& p) {
            return p.name + ": $" + std::to_string(p.totalValue());
        });
    
    // Calculate total inventory value
    auto total_value = std::accumulate(inventory.begin(), inventory.end(), 0.0,
        [](double sum, const Product& p) {
            return sum + p.totalValue();
        });
    
    std::cout << "Total inventory value: $" << total_value << "\n";
    
    // Group products by price range
    std::map<std::string, std::vector<Product>> price_groups;
    std::for_each(inventory.begin(), inventory.end(),
        [&price_groups](const Product& p) {
            std::string category;
            if (p.price < 50.0) category = "Budget";
            else if (p.price < 200.0) category = "Mid-range";
            else category = "Premium";
            
            price_groups[category].push_back(p);
        });
    
    for (const auto& [category, products] : price_groups) {
        std::cout << category << " products: " << products.size() << "\n";
    }
}
```

### Advanced Lambda Features

```cpp
#include <iostream>
#include <functional>
#include <vector>
#include <memory>

// Recursive lambda (C++14 with auto)
void recursiveLambda() {
    std::function<int(int)> factorial = [&factorial](int n) -> int {
        return (n <= 1) ? 1 : n * factorial(n - 1);
    };
    
    std::cout << "5! = " << factorial(5) << "\n";
    
    // Y combinator style recursive lambda
    auto make_recursive = [](auto f) {
        return [f](auto&&... args) {
            return f(f, std::forward<decltype(args)>(args)...);
        };
    };
    
    auto fib = make_recursive([](auto f, int n) -> int {
        return (n <= 1) ? n : f(f, n-1) + f(f, n-2);
    });
    
    std::cout << "fib(10) = " << fib(10) << "\n";
}

// Lambda as template parameter
template<typename Container, typename Predicate>
auto filter(const Container& container, Predicate pred) {
    Container result;
    std::copy_if(container.begin(), container.end(), std::back_inserter(result), pred);
    return result;
}

// Higher-order functions
template<typename F>
auto curry(F&& f) {
    return [f = std::forward<F>(f)](auto&& arg1) {
        return [f, arg1 = std::forward<decltype(arg1)>(arg1)](auto&& arg2) {
            return f(arg1, std::forward<decltype(arg2)>(arg2));
        };
    };
}

void advancedLambdaFeatures() {
    // Lambda templates (C++20)
    auto generic_lambda = []<typename T>(T&& value) {
        std::cout << "Processing: " << value << " of type " << typeid(T).name() << "\n";
        return std::forward<T>(value);
    };
    
    generic_lambda(42);
    generic_lambda("Hello");
    
    // Using lambdas with custom algorithms
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto evens = filter(numbers, [](int n) { return n % 2 == 0; });
    
    std::cout << "Even numbers: ";
    for (int n : evens) {
        std::cout << n << " ";
    }
    std::cout << "\n";
    
    // Currying example
    auto add = [](int a, int b) { return a + b; };
    auto curried_add = curry(add);
    auto add_five = curried_add(5);
    
    std::cout << "5 + 3 = " << add_five(3) << "\n";
}

// Lambda in class context
class EventHandler {
private:
    std::vector<std::function<void()>> handlers_;
    
public:
    void addHandler(std::function<void()> handler) {
        handlers_.push_back(handler);
    }
    
    void processEvents() {
        for (auto& handler : handlers_) {
            handler();
        }
    }
};

void lambdaInClassContext() {
    EventHandler eventSystem;
    
    std::string message = "Event processed";
    int counter = 0;
    
    // Lambda capturing class context
    eventSystem.addHandler([&message, &counter]() {
        std::cout << message << " #" << ++counter << "\n";
    });
    
    eventSystem.addHandler([]() {
        std::cout << "Another event handler\n";
    });
    
    eventSystem.processEvents();
    eventSystem.processEvents();
}
```

---

## 26.1 - Advanced Template Programming

### Variadic Templates

```cpp
#include <iostream>
#include <string>
#include <sstream>
#include <type_traits>

// Basic variadic template
template<typename... Args>
void print(Args&&... args) {
    ((std::cout << args << " "), ...);  // C++17 fold expression
    std::cout << "\n";
}

// Recursive variadic template (pre-C++17 style)
template<typename First>
void print_recursive(First&& first) {
    std::cout << first << "\n";
}

template<typename First, typename... Rest>
void print_recursive(First&& first, Rest&&... rest) {
    std::cout << first << " ";
    print_recursive(rest...);
}

// Perfect forwarding with variadic templates
template<typename T, typename... Args>
std::unique_ptr<T> make_unique_variadic(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

class ComplexObject {
public:
    ComplexObject(const std::string& name, int value, double rate) 
        : name_(name), value_(value), rate_(rate) {
        std::cout << "ComplexObject created: " << name_ << "\n";
    }
    
private:
    std::string name_;
    int value_;
    double rate_;
};

// Variadic template for string formatting
template<typename... Args>
std::string format_string(const std::string& format, Args&&... args) {
    std::ostringstream oss;
    format_impl(oss, format, std::forward<Args>(args)...);
    return oss.str();
}

template<typename T>
void format_impl(std::ostringstream& oss, const std::string& format, T&& value) {
    size_t pos = format.find("{}");
    if (pos != std::string::npos) {
        oss << format.substr(0, pos) << value << format.substr(pos + 2);
    } else {
        oss << format;
    }
}

template<typename T, typename... Args>
void format_impl(std::ostringstream& oss, const std::string& format, T&& value, Args&&... args) {
    size_t pos = format.find("{}");
    if (pos != std::string::npos) {
        oss << format.substr(0, pos) << value;
        format_impl(oss, format.substr(pos + 2), std::forward<Args>(args)...);
    } else {
        oss << format;
    }
}

void demonstrateVariadicTemplates() {
    // Basic usage
    print("Hello", "World", 42, 3.14, true);
    print_recursive("Recursive:", 1, 2, 3);
    
    // Perfect forwarding
    auto obj = make_unique_variadic<ComplexObject>("Test", 100, 2.5);
    
    // String formatting
    std::string result = format_string("Value: {}, Rate: {}, Active: {}", 42, 3.14, true);
    std::cout << result << "\n";
}
```

### SFINAE and Template Metaprogramming

```cpp
#include <iostream>
#include <type_traits>
#include <vector>
#include <string>

// SFINAE (Substitution Failure Is Not An Error) examples

// Enable function only for integral types
template<typename T>
std::enable_if_t<std::is_integral_v<T>, void>
process_integral(T value) {
    std::cout << "Processing integral value: " << value << "\n";
}

// Enable function only for floating point types
template<typename T>
std::enable_if_t<std::is_floating_point_v<T>, void>
process_floating_point(T value) {
    std::cout << "Processing floating point value: " << value << "\n";
}

// Detect if a type has a specific member function
template<typename T, typename = void>
struct has_size : std::false_type {};

template<typename T>
struct has_size<T, std::void_t<decltype(std::declval<T>().size())>> : std::true_type {};

template<typename T>
constexpr bool has_size_v = has_size<T>::value;

// Function overloading based on type traits
template<typename Container>
std::enable_if_t<has_size_v<Container>, size_t>
get_size(const Container& container) {
    return container.size();
}

template<typename T>
std::enable_if_t<!has_size_v<T>, size_t>
get_size(const T&) {
    return 1;  // Assume single element for non-containers
}

// if constexpr (C++17) - compile-time conditional
template<typename T>
void process_value(T value) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << "Integral: " << value << " (squared: " << value * value << ")\n";
    } else if constexpr (std::is_floating_point_v<T>) {
        std::cout << "Float: " << value << " (sqrt: " << std::sqrt(value) << ")\n";
    } else if constexpr (std::is_same_v<T, std::string>) {
        std::cout << "String: '" << value << "' (length: " << value.length() << ")\n";
    } else {
        std::cout << "Other type\n";
    }
}

void demonstrateSFINAE() {
    // Type-based function selection
    process_integral(42);
    process_floating_point(3.14);
    
    // Member detection
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::string str = "hello";
    int single_value = 42;
    
    std::cout << "Vector size: " << get_size(vec) << "\n";
    std::cout << "String size: " << get_size(str) << "\n";
    std::cout << "Int 'size': " << get_size(single_value) << "\n";
    
    // if constexpr usage
    process_value(42);
    process_value(3.14);
    process_value(std::string("Hello"));
}
```

### Template Specialization and Concepts (C++20)

```cpp
#include <iostream>
#include <vector>
#include <concepts>
#include <type_traits>

// Template specialization
template<typename T>
class Container {
public

# Advanced Functions: Constexpr and Consteval (Chapter F)

## F.1 - Constexpr Functions

### Introduction to Constexpr Functions

A constexpr function is a function that is allowed to be called in a constant expression. This is a powerful feature that bridges the gap between compile-time and runtime programming.

### The Problem: Functions in Constant Expressions

Consider this scenario where we want to calculate a circle's circumference at compile-time:

```cpp
#include <iostream>

// This works fine
int main()
{
    constexpr double radius { 3.0 };
    constexpr double pi { 3.14159265359 };
    constexpr double circumference { 2.0 * radius * pi };
    std::cout << "Our circle has circumference " << circumference << "\n";
    return 0;
}
```

But if we try to refactor into a function:

```cpp
#include <iostream>

double calcCircumference(double radius)
{
    constexpr double pi { 3.14159265359 };
    return 2.0 * pi * radius;
}

int main()
{
    constexpr double circumference { calcCircumference(3.0) }; // ❌ COMPILE ERROR
    std::cout << "Our circle has circumference " << circumference << "\n";
    return 0;
}
```

**Problem**: Regular functions cannot be called in constant expressions because the compiler cannot guarantee they can be evaluated at compile-time.

### The Solution: Constexpr Functions

To make a function a constexpr function, we simply use the constexpr keyword in front of the function's return type.

```cpp
#include <iostream>

constexpr double calcCircumference(double radius) // ✅ Now a constexpr function
{
    constexpr double pi { 3.14159265359 };
    return 2.0 * pi * radius;
}

int main()
{
    constexpr double circumference { calcCircumference(3.0) }; // ✅ Now compiles
    std::cout << "Our circle has circumference " << circumference << "\n";
    return 0;
}
```

### How Constexpr Functions Work

#### Compile-Time Evaluation
When a function call is evaluated at compile-time, the compiler will calculate the return value of the function call at compile-time, and then replace the function call with the return value.

The compiler essentially transforms:
```cpp
constexpr double circumference { calcCircumference(3.0) };
```

Into:
```cpp
constexpr double circumference { 18.8496 }; // Calculated at compile-time
```

#### Requirements for Compile-Time Evaluation

To evaluate at compile-time, two other things must also be true:
- The call to the constexpr function must have arguments that are known at compile time (e.g. are constant expressions).
- All statements and expressions within the constexpr function must be evaluatable at compile-time.

### Dual Nature: Compile-Time and Runtime

One of the most powerful aspects of constexpr functions is their flexibility:

```cpp
#include <iostream>

constexpr int greater(int x, int y)
{
    return (x > y ? x : y);
}

int main()
{
    // Compile-time evaluation
    constexpr int result1 { greater(5, 3) }; // Evaluated at compile-time
    
    // Runtime evaluation  
    int x{ 5 }; // not constexpr
    int y{ 6 }; // not constexpr
    std::cout << greater(x, y) << " is greater!\n"; // ✅ Evaluated at runtime
    
    return 0;
}
```

When a constexpr function evaluates at runtime, it evaluates just like a normal (non-constexpr) function would. In other words, the constexpr has no effect in this case.

## F.2 - Constexpr Functions (Part 2) - Advanced Rules

### Function Parameter Rules

**Important**: Function parameters are NOT constexpr by default:

```cpp
constexpr int square(int x)  // x is NOT constexpr
{
    // x is treated as a runtime variable within the function
    return x * x;
}

int main()
{
    constexpr int result { square(5) }; // ✅ Works: argument 5 is compile-time constant
    return 0;
}
```

### Local Variables in Constexpr Functions

You can use non-constexpr local variables:

```cpp
constexpr int doSomething(int x, int y)
{
    int temp = x + y;      // ✅ Non-constexpr local variable allowed
    temp *= 2;             // ✅ Can modify local variables
    return temp;
}
```

### Complex Constexpr Functions

```cpp
constexpr int factorial(int n)
{
    if (n <= 1) return 1;
    
    int result = 1;
    for (int i = 2; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}

int main()
{
    constexpr int fact5 { factorial(5) }; // ✅ Computed at compile-time: 120
    return 0;
}
```

## F.3 - Constexpr Functions (Part 3) and Consteval

### The Limitation of Constexpr

While constexpr functions *can* be evaluated at compile-time, they're not *required* to be. This can lead to unexpected runtime evaluation:

```cpp
constexpr int slowComputation(int n)
{
    // Imagine this is expensive
    int result = 0;
    for (int i = 0; i < n; ++i) {
        result += i * i;
    }
    return result;
}

int main()
{
    // We WANT this computed at compile-time, but it might not be!
    int value { slowComputation(1000) }; // Might be runtime evaluation
    return 0;
}
```

### Enter Consteval: Guaranteed Compile-Time

**C++20** introduced `consteval` - functions that **must** be evaluated at compile-time:

```cpp
consteval int mandatoryCompileTime(int x)
{
    return x * x + 10;
}

int main()
{
    constexpr int result1 { mandatoryCompileTime(5) }; // ✅ Compile-time
    
    int runtime_val = 5;
    // int result2 { mandatoryCompileTime(runtime_val) }; // ❌ COMPILE ERROR!
    
    return 0;
}
```

### Consteval vs Constexpr Comparison

| Feature | constexpr | consteval |
|---------|-----------|-----------|
| Can be evaluated at compile-time | ✅ Yes | ✅ Yes |
| Can be evaluated at runtime | ✅ Yes | ❌ No |
| Guaranteed compile-time evaluation | ❌ No | ✅ Yes |
| Introduced | C++11 | C++20 |

## F.4 - Constexpr Functions (Part 4) - Best Practices

### Guidelines for Constexpr Functions

1. **Avoid calling non-constexpr functions**:
```cpp
#include <cmath>

constexpr double badExample(double x)
{
    return std::sqrt(x); // ❌ std::sqrt is not constexpr in many implementations
}

// Better approach
constexpr double goodExample(double x)
{
    // Implement your own compile-time safe version
    return x * x; // Simple example
}
```

2. **Keep functions simple and focused**:
```cpp
constexpr bool isPrime(int n)
{
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0) return false;
    }
    return true;
}
```

3. **Use for mathematical computations**:
```cpp
constexpr double pow(double base, int exponent)
{
    if (exponent == 0) return 1.0;
    if (exponent < 0) return 1.0 / pow(base, -exponent);
    
    double result = 1.0;
    for (int i = 0; i < exponent; ++i)
    {
        result *= base;
    }
    return result;
}

int main()
{
    constexpr double result { pow(2.0, 10) }; // 1024.0 computed at compile-time
    return 0;
}
```

## Advanced Use Cases

### Template Metaprogramming

```cpp
template<int N>
constexpr int fibonacci()
{
    if constexpr (N <= 1)
        return N;
    else
        return fibonacci<N-1>() + fibonacci<N-2>();
}

int main()
{
    constexpr int fib10 { fibonacci<10>() }; // Computed at compile-time
    return 0;
}
```

### Constexpr Arrays and Strings

```cpp
constexpr std::array<int, 5> makeArray()
{
    std::array<int, 5> arr{};
    for (int i = 0; i < 5; ++i)
    {
        arr[i] = i * i;
    }
    return arr;
}

int main()
{
    constexpr auto squares { makeArray() }; // {0, 1, 4, 9, 16} at compile-time
    return 0;
}
```

## Key Benefits

1. **Performance**: Computation moved from runtime to compile-time
2. **Optimization**: Compiler can make better optimization decisions
3. **Template Requirements**: Many template contexts require constant expressions
4. **Static Assertions**: Enable compile-time checking and validation
5. **Embedded Systems**: Reduce runtime computation overhead

## Common Pitfalls

1. **Assuming constexpr means compile-time**: It doesn't guarantee it
2. **Complex logic**: Too complex functions may not be evaluable at compile-time
3. **Platform dependencies**: Some standard library functions aren't constexpr on all platforms
4. **Debugging difficulty**: Compile-time evaluation can make debugging harder

## Modern C++ Best Practices

- Use `consteval` when you absolutely need compile-time evaluation
- Use `constexpr` for functions that benefit from both compile-time and runtime flexibility
- Prefer constexpr for mathematical computations, array initialization, and template parameters
- Keep constexpr functions simple and well-tested
- Document when functions are intended for compile-time use

This powerful feature set represents one of the most significant advances in modern C++, enabling efficient compile-time programming and optimization opportunities that were previously impossible.