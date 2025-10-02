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
