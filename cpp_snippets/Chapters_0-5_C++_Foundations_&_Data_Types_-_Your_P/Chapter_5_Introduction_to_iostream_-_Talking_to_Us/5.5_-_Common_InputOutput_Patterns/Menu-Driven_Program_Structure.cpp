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
