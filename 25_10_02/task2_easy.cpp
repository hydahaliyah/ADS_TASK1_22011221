#include <iostream>
#include <algorithm>

using namespace std;

int findMaxOnesRow(int mat[][10], int rows, int cols) {
    if (rows <= 0 || cols <= 0) {
        return -1;
    }

    int i = 0;
    int j = cols - 1;
    int maxRowIndex = -1;

    while (i < rows && j >= 0) {
        if (mat[i][j] == 1) {
            maxRowIndex = i;
            j--;
        } else {
            i++;
        }
    }

    return maxRowIndex;
}

int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    if (rows > 10 || cols > 10 || rows <= 0 || cols <= 0) {
        return 1;
    }

    int mat[10][10];
    
    cout << "Enter the binary matrix (row by row):\n";
    for (int i = 0; i < rows; i++) {
        cout << "Enter Row " << i + 1 << ": ";
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }

    cout << "\nYour matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    int maxRowIndex = findMaxOnesRow(mat, rows, cols);

    if (maxRowIndex == -1) {
        cout << "None of the rows has a '1' or the matrix is empty." << endl;
    } else {
        int maxRow = maxRowIndex + 1;
        int maxOnes = cols; 
        for(int j=0; j<cols; ++j){
            if(mat[maxRowIndex][j] == 0) maxOnes--;
            else break;
        }

        cout << "Row " << maxRow << " has the maximum number of ones." << endl;
        cout << "Number of ones: " << maxOnes << endl;
    }

    return 0;
}