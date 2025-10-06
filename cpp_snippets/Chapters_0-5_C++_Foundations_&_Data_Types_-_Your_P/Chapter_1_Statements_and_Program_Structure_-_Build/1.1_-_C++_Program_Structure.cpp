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
