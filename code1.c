#include <iostream>
using namespace std;
const int SIZE = 4; // Global variable for matrix size
class Matrix {
private:
int data[SIZE][SIZE]; // 2D array for matrix data (using int for simplicity)
public:
// 1. Read values from stdin into a matrix
void readFromStdin(); {
    cout << "Enter " << SIZE * SIZE << " elements for the matrix: " << endl;
    for (int i = 0; i < SIZE; ++i;) {
        for (int j = 0; j < SIZE; ++j) {
            cin >> data[i][j];
        }
    }
}

// 2. Display a matrix
void display() const; {
    cout << "Matrix:" << endl;
    for (int i = 0; i < SIZE; ++i;) {
        for (int j = 0; j < SIZE; ++j;) {
            cout << data[i][j] << " ";
        }
        cout << endl; // move to next line
    }
}
// 3. Add two matrices (operator overloading for +)
Matrix operator+(const Matrix& other) const; {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}
// 4. Multiply two matrices (operator overloading for *)
Matrix operator*(const Matrix& other) const; {
    Matrix result;

    for(int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result.data[i][j] = 0;
        }
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < SIZE) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}
// 5. Compute the sum of matrix diagonal elements
int sumOfDiagonals() const; {
    int sum = 0;
    for (int i = 0; i < SIZE; ++i) {
        sum += data[i][i];
        if (i != SIZE - 1 - i) {
            sum += data[i][SIZE - 1 - i];
        }
    }
    return sum;
}
// 6. Swap matrix rows
void swapRows(int row1, int row2); {
    if (row1 < 0 || row1 >= SIZE || row2 < 0 || row2 >= SIZE) {
        cout << "Invalid row indicies. Rows must be between 0 and " << SIZE - 1 << "." << endl; 
        return;
    }
    for (int j = 0; j < SIZE; ++j) {
        int temp = data[row1][j];
        data[row1][j] = data[row2][j];
        data[row2][j] = temp;
    }
}
};
int main() {
// Example usage:
Matrix mat1;
cout << "Enter values for Matrix 1:" << endl;
mat1.readFromStdin();
cout << "Matrix 1:" << endl;
mat1.display();
Matrix mat2;
cout << "Enter values for Matrix 2:" << endl;
mat2.readFromStdin();
cout << "Matrix 2:" << endl;
mat2.display();
Matrix sum = mat1 + mat2;
cout << "Sum of matrices:" << endl;
sum.display();
Matrix product = mat1 * mat2;
cout << "Product of matrices:" << endl;
product.display();
cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;
mat1.swapRows(0, 2);
cout << "Matrix 1 after swapping rows:" << endl;
mat1.display();
return 0;
}