// Simple, obvious usage - single letters
template <typename T>
T simple(T value) { return value; }

template <typename T, typename U, typename V>
auto complex(T a, U b, V c) { return a + b + c; }

// Complex usage - descriptive names
template <typename Container, typename Predicate>
void processIf(Container& container, Predicate pred) 
{
    // Implementation...
}

// Standard library style
template <typename InputIt, typename OutputIt, typename Comparator>
OutputIt customSort(InputIt first, InputIt last, OutputIt result, Comparator comp)
{
    // Implementation...
}
