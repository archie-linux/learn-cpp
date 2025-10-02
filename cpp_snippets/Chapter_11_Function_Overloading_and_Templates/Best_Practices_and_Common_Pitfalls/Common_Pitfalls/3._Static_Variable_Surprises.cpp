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
