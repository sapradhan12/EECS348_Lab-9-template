#include "matrix.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Demo: create a 3x3 matrix from hardcoded data.
    vector<vector<int>> data = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Matrix<int> m(data);
    cout << "Original Matrix:" << endl;
    m.print();

    // Demonstrate set_value and get_value.
    m.set_value(0, 0, 10);
    cout << "After setting element (0,0) to 10:" << endl;
    m.print();

    // Demonstrate addition.
    Matrix<int> m2(data);
    Matrix<int> added = m + m2;
    cout << "Matrix after addition:" << endl;
    added.print();

    // Demonstrate multiplication.
    Matrix<int> multiplied = m * m2;
    cout << "Matrix after multiplication:" << endl;
    multiplied.print();

    // Demonstrate swapping rows (using polymorphism via the MatrixBase pointer).
    MatrixBase<int>* basePtr = &m;
    cout << "Matrix before swapping rows 0 and 2:" << endl;
    m.print();
    basePtr->swap_rows(0, 2);
    cout << "Matrix after swapping rows 0 and 2:" << endl;
    m.print();

    return 0;
}
