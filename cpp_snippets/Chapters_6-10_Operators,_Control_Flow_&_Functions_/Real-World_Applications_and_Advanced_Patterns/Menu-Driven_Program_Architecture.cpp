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
