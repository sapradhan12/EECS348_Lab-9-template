#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::out_of_range;
using std::setw;

//abstract base class
template<typename T>
class MatrixBase {
public:
    virtual void swap_rows(int row1, int row2) = 0;
    virtual void swap_cols(int col1, int col2) = 0;
    virtual void print() const = 0;
    virtual ~MatrixBase() {}
};

//templated Matrix class
template<typename T>
class Matrix : public MatrixBase<T> {
private:
    vector<vector<T>> data;
public:
    Matrix() {}
    Matrix(const vector<vector<T>> &d) : data(d) {
        if (!data.empty()) {
            size_t n = data.size();
            for (const auto &row : data) {
                if (row.size() != n)
                    throw std::invalid_argument("Matrix must be square.");
            }
        }
    }

    //get the size of the matrix
    int get_size() const {
        return data.size();
    }

    //get a value with bounds checking
    T get_value(int i, int j) const {
        if (i < 0 || i >= get_size() || j < 0 || j >= get_size())
            throw out_of_range("Index out of bounds");
        return data[i][j];
    }

    //set a value with bounds checking
    void set_value(int i, int j, T value) {
        if (i < 0 || i >= get_size() || j < 0 || j >= get_size())
            throw out_of_range("Index out of bounds");
        data[i][j] = value;
    }

    //overload the addition operator
    Matrix<T> operator+(const Matrix<T>& other) const {
        int n = get_size();
        if (n != other.get_size())
            throw std::invalid_argument("Matrix sizes do not match for addition");
        vector<vector<T>> result(n, vector<T>(n, 0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                result[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return Matrix<T>(result);
    }

    //overload the multiplication operator
    Matrix<T> operator*(const Matrix<T>& other) const {
        int n = get_size();
        if (n != other.get_size())
            throw std::invalid_argument("Matrix sizes do not match for multiplication");
        vector<vector<T>> result(n, vector<T>(n, 0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                for (int k = 0; k < n; k++){
                    result[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return Matrix<T>(result);
    }

    //swap two rows
    void swap_rows(int row1, int row2) override {
        int n = get_size();
        if (row1 < 0 || row1 >= n || row2 < 0 || row2 >= n)
            throw out_of_range("Row index out of bounds");
        std::swap(data[row1], data[row2]);
    }

    //swap two columns
    void swap_cols(int col1, int col2) override {
        int n = get_size();
        if (col1 < 0 || col1 >= n || col2 < 0 || col2 >= n)
            throw out_of_range("Column index out of bounds");
        for (int i = 0; i < n; i++) {
            std::swap(data[i][col1], data[i][col2]);
        }
    }

    //sum of the main diagonal
    T sum_diagonal_major() const {
        int n = get_size();
        T sum = 0;
        for (int i = 0; i < n; i++){
            sum += data[i][i];
        }
        return sum;
    }

    //sum of the secondary diagonal
    T sum_diagonal_minor() const {
        int n = get_size();
        T sum = 0;
        for (int i = 0; i < n; i++){
            sum += data[i][n - i - 1];
        }
        return sum;
    }

    //print the matrix
    void print() const override {
        int n = get_size();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout << setw(4) << data[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
};

#endif
