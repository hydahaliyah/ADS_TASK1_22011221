#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    if (rows <= 0 || cols <= 0 || rows > 10 || cols > 10) {
        cout << "Invalid dimensions. Rows and columns must be between 1 and 10." << endl;
        return 1;
    }

    int mat[10][10];
    int rotated[10][10];

    cout << "\nEnter the matrix elements (1 2 3):" << endl;
    for (int i = 0; i < rows; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }

    cout << "\nYour matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            rotated[cols - 1 - j][i] = mat[i][j];
        }
    }

    cout << "\nRotated 90° Counterclockwise:" << endl;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << rotated[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}