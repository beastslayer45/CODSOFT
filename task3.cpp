#include <iostream>
using namespace std;

char board[9];
char currentPlayer;

// Function to initialize the board
void initializeBoard() {
    for (int i = 0; i < 9; i++) {
        board[i] = ' ';
    }
}

// Function to display the board
void displayBoard() {
    cout << "\n";
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
    cout << "\n";
}

// Function to check win condition
bool checkWin() {
    int winConditions[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8}, // rows
        {0,3,6}, {1,4,7}, {2,5,8}, // columns
        {0,4,8}, {2,4,6}           // diagonals
    };

    for (int i = 0; i < 8; i++) {
        if (board[winConditions[i][0]] == currentPlayer &&
            board[winConditions[i][1]] == currentPlayer &&
            board[winConditions[i][2]] == currentPlayer) {
            return true;
        }
    }
    return false;
}

// Function to check draw condition
bool checkDraw() {
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ')
            return false;
    }
    return true;
}

// Function to switch player
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    char choice;

    do {
        initializeBoard();
        currentPlayer = 'X';

        while (true) {
            displayBoard();
            int move;

            cout << "Player " << currentPlayer
                 << ", enter your move (1-9): ";
            cin >> move;
            move--; // Convert to index

            if (move < 0 || move > 8 || board[move] != ' ') {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            board[move] = currentPlayer;

            if (checkWin()) {
                displayBoard();
                cout << "?? Player " << currentPlayer << " wins!\n";
                break;
            }

            if (checkDraw()) {
                displayBoard();
                cout << "?? It's a draw!\n";
                break;
            }

            switchPlayer();
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Thanks for playing! ??\n";
    return 0;
}
