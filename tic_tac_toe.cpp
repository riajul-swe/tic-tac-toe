#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'},
                     {'4', '5', '6'},
                     {'7', '8', '9'} };

char currentMarker;
int currentPlayer;

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool placeMarker(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}

int checkWinner() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return currentPlayer;
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return currentPlayer;
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return currentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return currentPlayer;

    return 0; // No winner yet
}

void swapPlayerAndMarker() {
    if (currentMarker == 'X') {
        currentMarker = 'O';
        currentPlayer = 2;
    } else {
        currentMarker = 'X';
        currentPlayer = 1;
    }
}

void playGame() {
    cout << "Player 1, choose your marker (X or O): ";
    cin >> currentMarker;

    currentPlayer = 1;

    displayBoard();

    int winner = 0;
    for (int i = 0; i < 9; i++) { // Maximum 9 moves
        cout << "Player " << currentPlayer << "'s turn. Enter your position (1-9): ";
        int position;
        cin >> position;

        if (position < 1 || position > 9) {
            cout << "Invalid position! Try again.\n";
            i--;
            continue;
        }

        if (!placeMarker(position)) {
            cout << "Position already taken! Try again.\n";
            i--;
            continue;
        }

        displayBoard();

        winner = checkWinner();
        if (winner != 0) {
            cout << "Player " << winner << " wins!\n";
            break;
        }

        swapPlayerAndMarker();
    }

    if (winner == 0) {
        cout << "It's a draw!\n";
    }
}

int main() {
    cout << "Welcome to Tic Tac Toe!\n";
    playGame();
    return 0;
}
