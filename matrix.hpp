#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <stdexcept>
using namespace std;

// The header declares a templated Matrix class interface.
// (No definitions or inline implementations appear here.)
template<typename T>
class Matrix {
public:
    // Constructor from a 2D vector.
    Matrix(const vector<vector<T>> &data);
    
    // Returns the matrix dimension (assumed square).
    int get_size() const;
    
    // Returns the element at the given row and column (with bounds checking).
    T get_value(int row, int col) const;
    
    // Sets the element at (row, col) to value (with bounds checking).
    void set_value(int row, int col, T value);
    
    // Operator overloading for matrix addition.
    Matrix<T> operator+(const Matrix<T>& other) const;
    
    // Operator overloading for matrix multiplication.
    Matrix<T> operator*(const Matrix<T>& other) const;
    
    // Returns the sum of the major (main) diagonal.
    int sum_diagonal_major() const;
    
    // Returns the sum of the minor (secondary) diagonal.
    int sum_diagonal_minor() const;
    
    // Swaps two rows. (This member function is virtual to demonstrate polymorphism.)
    virtual void swap_rows(int row1, int row2);
    
    // Swaps two columns.
    void swap_cols(int col1, int col2);
    
    // A simple print function to display the matrix.
    void print() const;
    
private:
    vector<vector<T>> data;
};

#endif // MATRIX_HPP
