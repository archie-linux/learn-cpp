template <typename T>
void bubbleSort(T arr[], int size) 
{
    for (int i = 0; i < size - 1; ++i) 
    {
        for (int j = 0; j < size - i - 1; ++j) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() 
{
    int intArr[] = {64, 34, 25, 12, 22, 11, 90};
    double doubleArr[] = {3.1, 2.5, 1.8, 4.2};
    
    bubbleSort(intArr, 7);        // Works with int
    bubbleSort(doubleArr, 4);     // Works with double
    
    return 0;
}
