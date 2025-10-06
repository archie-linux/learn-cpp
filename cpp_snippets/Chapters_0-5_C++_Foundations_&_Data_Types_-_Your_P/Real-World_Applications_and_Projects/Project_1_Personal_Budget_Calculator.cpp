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
