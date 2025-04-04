#include "matrix.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <algorithm>
using namespace std;

// *** All definitions for the Matrix<T> template are in this file. ***

// Constructor: ensures the matrix is square.
template<typename T>
Matrix<T>::Matrix(const vector<vector<T>> &data_input) : data(data_input) {
    if (!data.empty()) {
        size_t n = data.size();
        for (const auto &row : data) {
            if (row.size() != n)
                throw std::invalid_argument("Matrix must be square.");
        }
    }
}

template<typename T>
int Matrix<T>::get_size() const {
    return data.size();
}

template<typename T>
T Matrix<T>::get_value(int row, int col) const {
    if (row < 0 || row >= get_size() || col < 0 || col >= get_size())
        throw std::out_of_range("Index out of bounds");
    return data[row][col];
}

template<typename T>
void Matrix<T>::set_value(int row, int col, T value) {
    if (row < 0 || row >= get_size() || col < 0 || col >= get_size())
        throw std::out_of_range("Index out of bounds");
    data[row][col] = value;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
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

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const {
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

template<typename T>
int Matrix<T>::sum_diagonal_major() const {
    int n = get_size();
    T sum = 0;
    for (int i = 0; i < n; i++){
        sum += data[i][i];
    }
    return sum;
}

template<typename T>
int Matrix<T>::sum_diagonal_minor() const {
    int n = get_size();
    T sum = 0;
    for (int i = 0; i < n; i++){
        sum += data[i][n - i - 1];
    }
    return sum;
}

// swap_rows is declared virtual to demonstrate polymorphism.
template<typename T>
void Matrix<T>::swap_rows(int row1, int row2) {
    int n = get_size();
    if (row1 < 0 || row1 >= n || row2 < 0 || row2 >= n)
        throw std::out_of_range("Row index out of bounds");
    swap(data[row1], data[row2]);
}

template<typename T>
void Matrix<T>::swap_cols(int col1, int col2) {
    int n = get_size();
    if (col1 < 0 || col1 >= n || col2 < 0 || col2 >= n)
        throw std::out_of_range("Column index out of bounds");
    for (int i = 0; i < n; i++) {
        swap(data[i][col1], data[i][col2]);
    }
}

template<typename T>
void Matrix<T>::print() const {
    int n = get_size();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << setw(4) << data[i][j];
        }
        cout << endl;
    }
    cout << endl;
}