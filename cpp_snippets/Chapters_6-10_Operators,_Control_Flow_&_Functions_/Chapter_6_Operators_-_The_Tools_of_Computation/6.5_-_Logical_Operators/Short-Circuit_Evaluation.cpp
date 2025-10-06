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
