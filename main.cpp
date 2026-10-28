
#include <iostream>
#include <array>
#include <limits>
#include <string>

using namespace std;

class TicTacToe {
private:
    array<char, 9> board;
    char currentPlayer;
    bool gameOver;

    void resetBoard() {
        board.fill(' ');
        currentPlayer = 'X';
        gameOver = false;
    }

    void displayBoard() const {
        cout << "\n";
        cout << "       TIC-TAC-TOE\n\n";

        for (int row = 0; row < 3; ++row) {
            cout << "       ";

            for (int col = 0; col < 3; ++col) {
                int index = row * 3 + col;

                if (board[index] == ' ')
                    cout << index + 1;
                else
                    cout << board[index];

                if (col < 2)
                    cout << " | ";
            }

            cout << '\n';

            if (row < 2)
                cout << "      ---+---+---\n";
        }

        cout << '\n';
    }

    bool checkWin() const {
        const int winningLines[8][3] = {
            {0, 1, 2},
            {3, 4, 5},
            {6, 7, 8},
            {0, 3, 6},
            {1, 4, 7},
            {2, 5, 8},
            {0, 4, 8},
            {2, 4, 6}
        };

        for (const auto& line : winningLines) {
            if (board[line[0]] != ' ' &&
                board[line[0]] == board[line[1]] &&
                board[line[1]] == board[line[2]]) {
                return true;
            }
        }

        return false;
    }

    bool checkDraw() const {
        for (char cell : board) {
            if (cell == ' ')
                return false;
        }

        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void playTurn() {
        int position;

        while (true) {
            cout << "Player " << currentPlayer
                 << ", choose a position (1-9): ";

            if (!(cin >> position)) {
                cout << "Invalid input. Enter a number from 1 to 9.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (position < 1 || position > 9) {
                cout << "Position must be between 1 and 9.\n";
                continue;
            }

            if (board[position - 1] != ' ') {
                cout << "That position is already occupied. Try again.\n";
                continue;
            }

            break;
        }

        board[position - 1] = currentPlayer;
    }

public:
    TicTacToe() {
        resetBoard();
    }

    void play() {
        bool replay = true;

        while (replay) {
            resetBoard();

            while (!gameOver) {
                displayBoard();
                playTurn();

                if (checkWin()) {
                    displayBoard();
                    cout << "Congratulations! Player "
                         << currentPlayer << " wins!\n";
                    gameOver = true;
                } else if (checkDraw()) {
                    displayBoard();
                    cout << "It's a draw! Nobody wins this round.\n";
                    gameOver = true;
                } else {
                    switchPlayer();
                }
            }

            char answer;

            while (true) {
                cout << "\nWould you like to play again? (y/n): ";

                if (!(cin >> answer)) {
                    cout << "Invalid input. Please try again.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (answer == 'y' || answer == 'Y') {
                    replay = true;
                    break;
                }

                if (answer == 'n' || answer == 'N') {
                    replay = false;
                    break;
                }

                cout << "Please enter y or n.\n";
            }
        }

        cout << "\nThanks for playing Tic-Tac-Toe!\n";
    }
};

int main() {
    cout << "================================\n";
    cout << "       MINI GAME PROJECT\n";
    cout << "          TIC-TAC-TOE\n";
    cout << "================================\n";
    cout << "Two-player console game\n";
    cout << "Player X and Player O take turns.\n";
    cout << "Choose positions numbered 1 to 9.\n";

    TicTacToe game;
    game.play();

    return 0;
}
