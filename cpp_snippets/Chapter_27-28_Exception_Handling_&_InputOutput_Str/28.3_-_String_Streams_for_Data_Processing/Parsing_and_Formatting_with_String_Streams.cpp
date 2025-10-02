#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdexcept>

class DataParser 
{
public:
    // ✅ Parse CSV-like data
    static std::vector<std::vector<std::string>> parseCSV(const std::string& csvData, char delimiter = ',') 
    {
        std::vector<std::vector<std::string>> result;
        std::istringstream dataStream(csvData);
        std::string line;
        
        while (std::getline(dataStream, line)) 
        {
            std::vector<std::string> row;
            std::istringstream lineStream(line);
            std::string field;
            
            while (std::getline(lineStream, field, delimiter)) 
            {
                // Trim whitespace
                field.erase(0, field.find_first_not_of(" \t"));
                field.erase(field.find_last_not_of(" \t") + 1);
                row.push_back(field);
            }
            
            if (!row.empty()) 
            {
                result.push_back(row);
            }
        }
        
        return result;
    }
    
    // ✅ Convert structured data to CSV
    static std::string toCSV(const std::vector<std::vector<std::string>>& data, char delimiter = ',') 
    {
        std::ostringstream csvStream;
        
        for (size_t i = 0; i < data.size(); ++i) 
        {
            const auto& row = data[i];
            
            for (size_t j = 0; j < row.size(); ++j) 
            {
                csvStream << row[j];
                if (j < row.size() - 1) 
                {
                    csvStream << delimiter;
                }
            }
            
            if (i < data.size() - 1) 
            {
                csvStream << "\n";
            }
        }
        
        return csvStream.str();
    }
    
    // ✅ Parse numbers with error handling
    static std::vector<double> parseNumbers(const std::string& input) 
    {
        std::vector<double> numbers;
        std::istringstream stream(input);
        std::string token;
        
        while (stream >> token) 
        {
            try 
            {
                double value = std::stod(token);
                numbers.push_back(value);
            }
            catch (const std::invalid_argument&) 
            {
                std::cout << "Warning: Skipping invalid number: '" << token << "'\n";
            }
            catch (const std::out_of_range&) 
            {
                std::cout << "Warning: Number out of range: '" << token << "'\n";
            }
        }
        
        return numbers;
    }
    
    // ✅ Advanced parsing with multiple data types
    struct PersonRecord 
    {
        std::string name;
        int age;
        double salary;
        bool isActive;
        
        void display() const 
        {
            std::cout << "Name: " << name 
                      << ", Age: " << age 
                      << ", Salary: $" << std::fixed << std::setprecision(2) << salary 
                      << ", Active: " << (isActive ? "Yes" : "No") << "\n";
        }
    };
    
    static std::vector<PersonRecord> parsePersonRecords(const std::string& data) 
    {
        std::vector<PersonRecord> records;
        std::istringstream dataStream(data);
        std::string line;
        
        while (std::getline(dataStream, line)) 
        {
            if (line.empty()) continue;
            
            std::istringstream lineStream(line);
            PersonRecord person;
            
            // Parse name (may contain spaces)
            if (!std::getline(lineStream, person.name, ',')) 
            {
                continue;  // Skip invalid line
            }
            
            // Trim whitespace from name
            person.name.erase(0, person.name.find_first_not_of(" \t"));
            person.name.erase(person.name.find_last_not_of(" \t") + 1);
            
            // Parse age
            std::string ageStr;
            if (!std::getline(lineStream, ageStr, ',')) 
            {
                continue;
            }
            
            try 
            {
                person.age = std::stoi(ageStr);
            }
            catch (...) 
            {
                std::cout << "Warning: Invalid age for " << person.name << "\n";
                continue;
            }
            
            // Parse salary
            std::string salaryStr;
            if (!std::getline(lineStream, salaryStr, ',')) 
            {
                continue;
            }
            
            try 
            {
                person.salary = std::stod(salaryStr);
            }
            catch (...) 
            {
                std::cout << "Warning: Invalid salary for " << person.name << "\n";
                continue;
            }
            
            // Parse active status
            std::string activeStr;
            if (!std::getline(lineStream, activeStr)) 
            {
                continue;
            }
            
            // Trim and convert to lowercase for comparison
            activeStr.erase(0, activeStr.find_first_not_of(" \t"));
            activeStr.erase(activeStr.find_last_not_of(" \t") + 1);
            std::transform(activeStr.begin(), activeStr.end(), activeStr.begin(), ::tolower);
            
            person.isActive = (activeStr == "true" || activeStr == "yes" || activeStr == "1");
            
            records.push_back(person);
        }
        
        return records;
    }
};

class ReportGenerator 
{
public:
    // ✅ Generate formatted report
    static std::string generateSalesReport(const std::vector<std::pair<std::string, double>>& salesData) 
    {
        std::ostringstream report;
        
        report << "SALES REPORT\n";
        report << std::string(50, '=') << "\n\n";
        
        report << std::left << std::setw(30) << "Product" 
               << std::right << std::setw(15) << "Sales ($)" << "\n";
        report << std::string(50, '-') << "\n";
        
        double totalSales = 0.0;
        
        for (const auto& [product, sales] : salesData) 
        {
            report << std::left << std::setw(30) << product 
                   << std::right << std::setw(15) << std::fixed << std::setprecision(2) << sales << "\n";
            totalSales += sales;
        }
        
        report << std::string(50, '-') << "\n";
        report << std::left << std::setw(30) << "TOTAL" 
               << std::right << std::setw(15) << std::fixed << std::setprecision(2) << totalSales << "\n";
        report << std::string(50, '=') << "\n";
        
        return report.str();
    }
    
    // ✅ Generate HTML report
    static std::string generateHTMLTable(const std::vector<DataParser::PersonRecord>& records) 
    {
        std::ostringstream html;
        
        html << "<!DOCTYPE html>\n";
        html << "<html>\n<head>\n<title>Employee Records</title>\n</head>\n<body>\n";
        html << "<h1>Employee Records</h1>\n";
        html << "<table border='1' style='border-collapse: collapse;'>\n";
        html << "<tr><th>Name</th><th>Age</th><th>Salary</th><th>Status</th></tr>\n";
        
        for (const auto& person : records) 
        {
            html << "<tr>";
            html << "<td>" << person.name << "</td>";
            html << "<td>" << person.age << "</td>";
            html << "<td>$" << std::fixed << std::setprecision(2) << person.salary << "</td>";
            html << "<td>" << (person.isActive ? "Active" : "Inactive") << "</td>";
            html << "</tr>\n";
        }
        
        html << "</table>\n</body>\n</html>";
        
        return html.str();
    }
};

void demonstrateStringStreams() 
{
    std::cout << "=== String Streams Demonstration ===\n";
    
    // CSV parsing demonstration
    std::cout << "\n--- CSV Parsing ---\n";
    std::string csvData = 
        "Name,Age,Department\n"
        "John Doe,30,Engineering\n"
        "Jane Smith,25,Marketing\n"
        "Bob Johnson,35,Sales\n";
    
    auto parsedData = DataParser::parseCSV(csvData);
    
    std::cout << "Parsed CSV data:\n";
    for (const auto& row : parsedData) 
    {
        for (size_t i = 0; i < row.size(); ++i) 
        {
            std::cout << row[i];
            if (i < row.size() - 1) std::cout << " | ";
        }
        std::cout << "\n";
    }
    
    // Numbers parsing
    std::cout << "\n--- Number Parsing ---\n";
    std::string numberData = "3.14 42 invalid 2.71 overflow 99.9";
    auto numbers = DataParser::parseNumbers(numberData);
    
    std::cout << "Parsed numbers: ";
    for (double num : numbers) 
    {
        std::cout << num << " ";
    }
    std::cout << "\n";
    
    // Complex record parsing
    std::cout << "\n--- Person Record Parsing ---\n";
    std::string personData = 
        "Alice Johnson, 28, 65000.50, true\n"
        "Bob Smith, 35, 75000.75, false\n"
        "Carol Davis, 42, 85000.25, yes\n"
        "David Wilson, 29, invalid_salary, true\n"
        "Eve Brown, 31, 72000.00, 1\n";
    
    auto persons = DataParser::parsePersonRecords(personData);
    
    std::cout << "Parsed person records:\n";
    for (const auto& person : persons) 
    {
        person.display();
    }
    
    // Report generation
    std::cout << "\n--- Sales Report Generation ---\n";
    std::vector<std::pair<std::string, double>> salesData = {
        {"Widget A", 15420.50},
        {"Widget B", 23150.75},
        {"Widget C", 8900.25},
        {"Widget D", 31250.00}
    };
    
    std::string report = ReportGenerator::generateSalesReport(salesData);
    std::cout << report << "\n";
    
    // HTML generation
    std::cout << "\n--- HTML Report Generation ---\n";
    std::string htmlReport = ReportGenerator::generateHTMLTable(persons);
    std::cout << "Generated HTML (first 200 chars):\n";
    std::cout << htmlReport.substr(0, 200) << "...\n";
}
