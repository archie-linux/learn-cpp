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
