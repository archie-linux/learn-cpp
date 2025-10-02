#include <iostream>
#include <stdexcept>

template <typename T, size_t Rows, size_t Cols>
class Matrix 
{
private:
    T data[Rows][Cols];
    
public:
    Matrix() 
    {
        for (size_t i = 0; i < Rows; ++i) 
        {
            for (size_t j = 0; j < Cols; ++j) 
            {
                data[i][j] = T{};
            }
        }
    }
    
    // Subscript operator for 2D access: matrix[row][col]
    T* operator[](size_t row) 
    {
        if (row >= Rows) throw std::out_of_range("Row index out of range");
        return data[row];
    }
    
    const T* operator[](size_t row) const 
    {
        if (row >= Rows) throw std::out_of_range("Row index out of range");
        return data[row];
    }
    
    // Function call operator for 2D access: matrix(row, col)
    T& operator()(size_t row, size_t col) 
    {
        if (row >= Rows || col >= Cols) 
            throw std::out_of_range("Index out of range");
        return data[row][col];
    }
    
    const T& operator()(size_t row, size_t col) const 
    {
        if (row >= Rows || col >= Cols) 
            throw std::out_of_range("Index out of range");
        return data[row][col];
    }
    
    // Matrix addition
    Matrix operator+(const Matrix& other) const 
    {
        Matrix result;
        for (size_t i = 0; i < Rows; ++i) 
        {
            for (size_t j = 0; j < Cols; ++j) 
            {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    
    void print() const 
    {
        for (size_t i = 0; i < Rows; ++i) 
        {
            for (size_t j = 0; j < Cols; ++j) 
            {
                std::cout << data[i][j] << " ";
            }
            std::cout << '\n';
        }
    }
    
    constexpr size_t rows() const { return Rows; }
    constexpr size_t cols() const { return Cols; }
};

int main() 
{
    Matrix<int, 3, 3> mat1;
    Matrix<int, 3, 3> mat2;
    
    // Using subscript operator
    mat1[0][0] = 1; mat1[0][1] = 2; mat1[0][2] = 3;
    mat1[1][0] = 4; mat1[1][1] = 5; mat1[1][2] = 6;
    mat1[2][0] = 7; mat1[2][1] = 8; mat1[2][2] = 9;
    
    // Using function call operator
    mat2(0, 0) = 9; mat2(0, 1) = 8; mat2(0, 2) = 7;
    mat2(1, 0) = 6; mat2(1, 1) = 5; mat2(1, 2) = 4;
    mat2(2, 0) = 3; mat2(2, 1) = 2; mat2(2, 2) = 1;
    
    std::cout << "Matrix 1:\n";
    mat1.print();
    
    std::cout << "Matrix 2:\n";
    mat2.print();
    
    std::cout << "Matrix 1 + Matrix 2:\n";
    Matrix<int, 3, 3> sum = mat1 + mat2;
    sum.print();
    
    return 0;
}
