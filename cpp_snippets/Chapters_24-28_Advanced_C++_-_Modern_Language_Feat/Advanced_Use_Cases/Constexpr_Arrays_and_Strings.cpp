constexpr std::array<int, 5> makeArray()
{
    std::array<int, 5> arr{};
    for (int i = 0; i < 5; ++i)
    {
        arr[i] = i * i;
    }
    return arr;
}

int main()
{
    constexpr auto squares { makeArray() }; // {0, 1, 4, 9, 16} at compile-time
    return 0;
}
