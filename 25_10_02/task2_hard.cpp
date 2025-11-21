#include <iostream>
using namespace std;


bool checkWin(char board[], char player) {
    for (int i = 0; i < 9; i += 3) {
        if (board[i] == player && board[i+1] == player && board[i+2] == player) return true;
    }
   
    for (int j = 0; j < 3; j++) {
        if (board[j] == player && board[j+3] == player && board[j+6] == player) return true;
    }
    
    if (board[0] == player && board[4] == player && board[8] == player) return true;
    if (board[2] == player && board[4] == player && board[6] == player) return true;
    
    return false;
}

bool isValidTicTacToe(char board[], bool &xWins, bool &oWins) {
    int countX = 0;
    int countO = 0;
    
    for (int i = 0; i < 9; i++) {
        if (board[i] == 'X'){ 
            countX++;
        }
        else if (board[i] == 'O'){
            countO++;
        }
    }

    if (!(countX == countO || countX == countO + 1)) {
        return false;
    }

    xWins = checkWin(board, 'X');
    oWins = checkWin(board, 'O');
    
    if (xWins && oWins) {
        return false;
    }
    
    if (xWins && countX != countO + 1) {
        return false;
    }
    
    if (oWins && countX != countO) {
        return false;
    }
    return true;
}

int main() {
    char board[9];
    bool xWins;
    bool oWins;
    cout << "Enter Tic-Tac-Toe board (use capital X, O, or - for empty): " << endl;
    for (int i = 0; i < 9; i++) {
        cout << "Position " << i+1 << ": ";
        cin >> board[i];
    }
    
    cout << "\nYour Tic-Tac-Toe board:" << endl;
    for (int i = 0; i < 9; i++) {
        cout << board[i] << " ";
        if ((i+1)%3 == 0){
            cout << endl;
        }
    }
    
    if (isValidTicTacToe(board, xWins, oWins)) {
        cout << "\nValid board position!" << endl;
        if (xWins == true){
            cout << "X wins" << endl;
        } else if (oWins == true){
            cout << "O wins!" << endl;
        } else {
            cout << "Game is in progress or it's a draw!" << endl;
        }
    } else {
        cout << "\nInvalid board position!" << endl;
    }
    return 0;
}