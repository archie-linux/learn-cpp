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
