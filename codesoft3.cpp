#include <iostream>
using namespace std;

char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
char currentPlayer = 'X';

// Display the game board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "-----------\n";
    }
    cout << "\n";
}

// Get player move and validate
int getMove() {
    int move;
    cout << "Player " << currentPlayer << ", enter move (1-9): ";
    cin >> move;
    
    // Validate input
    if (cin.fail() || move < 1 || move > 9) {
        cout << "Invalid input! Try again.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return getMove();
    }
    
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    
    // Check if position is empty
    if (board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Position taken! Try again.\n";
        return getMove();
    }
    
    return move;
}

// Update board with player's move
void updateBoard(int move) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    board[row][col] = currentPlayer;
}

// Check for win (rows, columns, diagonals)
bool checkWin() {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
    }
    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

// Check for draw (board full)
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}

// Switch players
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Main game loop
void playGame() {
    cout << "=== TIC-TAC-TOE ===\n";
    displayBoard();
    
    while (true) {
        int move = getMove();
        updateBoard(move);
        displayBoard();
        
        if (checkWin()) {
            cout << "Player " << currentPlayer << " WINS!\n";
            break;
        }
        if (checkDraw()) {
            cout << "It's a DRAW!\n";
            break;
        }
        
        switchPlayer();
    }
}

int main() {
    char playAgain;
    
    do {
        // Reset board
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = '1' + (i * 3 + j + 1);
            }
        }
        currentPlayer = 'X';
        
        playGame();
        
        cout << "Play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    
    cout << "Thanks for playing!\n";
    return 0;
}
