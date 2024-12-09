/*
#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

class TicTacToe {
private:
    // Add private members if needed

public:
    TicTacToe() {
        // Initialize random seed
        srand(time(0));
    }

    int checkWinner(vector<int>& board) {
        // Player
        if (board[0] == 1 && board[1] == 1 && board[2] == 1) return 1; // ---
        else if (board[3] == 1 && board[4] == 1 && board[5] == 1) return 1; // ---
        else if (board[6] == 1 && board[7] == 1 && board[8] == 1) return 1; // ---
        else if (board[0] == 1 && board[4] == 1 && board[8] == 1) return 1; // - -
        else if (board[2] == 1 && board[4] == 1 && board[6] == 1) return 1; //  -
        else if (board[1] == 1 && board[4] == 1 && board[7] == 1) return 1; // - -

        // Computer
        else if (board[0] == 2 && board[1] == 2 && board[2] == 2) return 2; // ---
        else if (board[3] == 2 && board[4] == 2 && board[5] == 2) return 2; // ---
        else if (board[6] == 2 && board[7] == 2 && board[8] == 2) return 2; // ---
        else if (board[0] == 2 && board[4] == 2 && board[8] == 2) return 2; // - -
        else if (board[2] == 2 && board[4] == 2 && board[6] == 2) return 2; //  -
        else if (board[1] == 2 && board[4] == 2 && board[7] == 2) return 2; // - -

        // Check for draw
        bool isDraw = true;
        for (int i = 0; i < board.size(); ++i) {
            if (board[i] == 0) { // Assuming 0 means the position is empty
                isDraw = false;
                break;
            }
        }
        if (isDraw) return 3; // Assuming 3 indicates a draw
        
        return 0; // Assuming 0 means no winner yet
    }

    void makeMove(int player, vector<int>& board, int position, int moveValue) {
        if (player == 1) {
            board[position] = moveValue;
        } else {
            // Random move for the computer
            int pos;
            do {
                pos = rand() % 9; // Random position from 0 to 8
            } while (board[pos] != 0); // Assuming 0 means empty
            board[pos] = moveValue;
        }
    }

    void visualizeBoard(vector<int>& board) {
        for(int i=0; i<9 ; i++) {
            if(i==2 || i == 5) {
                cout << board[i] << endl;
                cout << "-----" << endl;
            } else if(i==8) {
                cout << board[i] << endl;
                break;
            } else {
                cout << board[i] << "|";
            }
        }
    }
};

int main() {
    TicTacToe game;
    vector<int> board(9, 0); // Initialize a board with 9 positions set to 0

    int currentPlayer = 1; // Start with player 1
    int winner = 0;

    while (winner == 0) {
        game.visualizeBoard(board);
        int position;
        cout << "Player " << currentPlayer << ", enter your move (0-8): ";
        cin >> position;

        if (position < 0 || position > 8 || board[position] != 0) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        game.makeMove(currentPlayer, board, position, currentPlayer);
        winner = game.checkWinner(board);

        if (winner == 0) {
            currentPlayer = (currentPlayer == 1) ? 2 : 1; // Switch player
        }
    }

    game.visualizeBoard(board);

    if (winner == 1) {
        cout << "Player 1 wins!" << endl;
    } else if (winner == 2) {
        cout << "Player 2 wins!" << endl;
    } else if (winner == 3) {
        cout << "It's a draw!" << endl;
    }

    return 0;
}
*/

#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

class TicTacToe {
private:
    // Add private members if needed

public:
    TicTacToe() {
        // Initialize random seed
        srand(time(0));
    }

    int checkWinner(vector<char>& board) {
        // Player
        if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X') return 1; // ---
        else if (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') return 1; // ---
        else if (board[6] == 'X' && board[7] == 'X' && board[8] == 'X') return 1; // ---
        else if (board[0] == 'X' && board[4] == 'X' && board[8] == 'X') return 1; // - -
        else if (board[2] == 'X' && board[4] == 'X' && board[6] == 'X') return 1; //  -
        else if (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') return 1; // - -

        // Computer
        else if (board[0] == 'O' && board[1] == 'O' && board[2] == 'O') return 2; // ---
        else if (board[3] == 'O' && board[4] == 'O' && board[5] == 'O') return 2; // ---
        else if (board[6] == 'O' && board[7] == 'O' && board[8] == 'O') return 2; // ---
        else if (board[0] == 'O' && board[4] == 'O' && board[8] == 'O') return 2; // - -
        else if (board[2] == 'O' && board[4] == 'O' && board[6] == 'O') return 2; //  -
        else if (board[1] == 'O' && board[4] == 'O' && board[7] == 'O') return 2; // - -

        // Check for draw
        bool isDraw = true;
        for (int i = 0; i < board.size(); ++i) {
            if (board[i] == ' ') { // Assuming ' ' means the position is empty
                isDraw = false;
                break;
            }
        }
        if (isDraw) return 3; // Assuming 3 indicates a draw
        
        return 0; // Assuming 0 means no winner yet
    }

    void makeMove(int player, vector<char>& board, int position) {
        if (player == 1) {
            cout << endl << "Player Move: " << endl;
            board[position] = 'X';
        } else {
            // Random move for the computer
            cout << endl << "Computer Move:" << endl;
            int pos;
            do {
                pos = rand() % 9; // Random position from 0 to 8
            } while (board[pos] != ' '); // Assuming ' ' means empty
            board[pos] = 'O';
        }
    }

    void visualizeBoard(vector<char>& board) {
        for(int i=0; i<9 ; i++) {
            if(i==2 || i == 5) {
                cout << board[i] << endl;
                cout << "-----" << endl;
            } else if(i==8) {
                cout << board[i] << endl;
                break;
            } else {
                cout << board[i] << "|";
            }
        }
    }
};

int main() {
    TicTacToe game;
    vector<char> board(9, ' '); // Initialize a board with 9 positions set to ' '

    int currentPlayer = 1; // Start with player 1
    int winner = 0;

    while (winner == 0) {
        game.visualizeBoard(board);
        int position;
        if (currentPlayer == 1) {
            cout << "Player " << currentPlayer << ", enter your move (0-8): ";
            cin >> position;

            if (position < 0 || position > 8 || board[position] != ' ') {
                cout << "Invalid move. Try again." << endl;
                continue;
            }
        }

        game.makeMove(currentPlayer, board, position);
        winner = game.checkWinner(board);

        if (winner == 0) {
            currentPlayer = (currentPlayer == 1) ? 2 : 1; // Switch player
        }
    }

    game.visualizeBoard(board);

    if (winner == 1) {
        cout << "Player 1 wins!" << endl;
    } else if (winner == 2) {
        cout << "Player 2 wins!" << endl;
    } else if (winner == 3) {
        cout << "It's a draw!" << endl;
    }

    return 0;
}
