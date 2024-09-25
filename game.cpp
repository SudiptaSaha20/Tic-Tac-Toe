#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <string>
using namespace std;

class TicTacToe
{
private:
    char board[3][3];
    char playerA, playerB;

public:
    TicTacToe()
    {
        resetBoard();
    }

    // Function to reset the board for a new game
    void resetBoard()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = ' ';
            }
        }
    }

    // Function to print the current state of the board
    void printBoard()
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "|";
            for (int j = 0; j < 3; j++)
            {
                cout << " " << board[i][j] << " |";
            }
            cout << endl;
        }
    }

    // Function to validate player's sign input
    char validSign()
    {
        char sign;
        cout << "Choose your sign (X/O): ";
        cin >> sign;
        sign = tolower(sign);

        while (sign != 'x' && sign != 'o')
        {
            cout << "Invalid sign! Please choose X or O: ";
            cin >> sign;
            sign = tolower(sign);
        }
        return sign;
    }

    // Function to check if a cell is occupied
    bool isOccupied(int row, int col)
    {
        return (board[row][col] == 'x' || board[row][col] == 'o');
    }

    // Function to check if there is a match
    bool checkMatch(char sign)
    {
        // Check rows and columns
        for (int i = 0; i < 3; i++)
        {
            if ((board[i][0] == sign && board[i][1] == sign && board[i][2] == sign) ||
                (board[0][i] == sign && board[1][i] == sign && board[2][i] == sign))
            {
                return true;
            }
        }
        // Check diagonals
        if ((board[0][0] == sign && board[1][1] == sign && board[2][2] == sign) ||
            (board[2][0] == sign && board[1][1] == sign && board[0][2] == sign))
        {
            return true;
        }
        return false; // return false if no match found
    }

    // Function to play with the computer
    void playWithComputer()
    {
        srand(time(0));
        int row, col, count = 0;
        char comp;

        playerA = validSign();
        comp = (playerA == 'x') ? 'o' : 'x';
        cout << "You chose: " << playerA << ", Computer chose: " << comp << endl;
        cout << "Game starts now!\n";

        while (count < 9)
        {
            // Player's turn
            cout << "Your turn. Enter position (row, column): ";
            cin >> row >> col;

            while (isOccupied(row, col))
            {
                cout << "Cell occupied. Try another cell: ";
                cin >> row >> col;
            }

            board[row][col] = playerA;
            count++;
            printBoard();

            if (checkMatch(playerA))
            {
                cout << "You win!" << endl;
                return;
            }

            if (count == 9)
            {
                cout << "It's a tie!" << endl;
                return;
            }

            // Computer's turn
            cout << "Computer's turn:\n";
            do
            {
                row = rand() % 3;
                col = rand() % 3;
            } while (isOccupied(row, col));

            board[row][col] = comp;
            count++;
            cout << "Computer chose: (" << row << ", " << col << ")\n";
            printBoard();

            if (checkMatch(comp))
            {
                cout << "Computer wins!" << endl;
                return;
            }
        }
    }

    // Function to play with a friend
    void playWithFriend()
    {
        int row, col, count = 0;

        cout << "Player A\n";
        playerA = validSign();
        playerB = (playerA == 'x') ? 'o' : 'x';
        cout << "Player A chose: " << playerA << ", Player B chose: " << playerB << endl;
        cout << "Game starts now!\n";

        while (count < 9)
        {
            // Player A's turn
            cout << "Player A's turn. Enter position (row, column): ";
            cin >> row >> col;

            while (isOccupied(row, col))
            {
                cout << "Cell occupied. Try another cell: ";
                cin >> row >> col;
            }

            board[row][col] = playerA;
            count++;
            printBoard();

            if (checkMatch(playerA))
            {
                cout << "Player A wins!" << endl;
                return;
            }

            if (count == 9)
            {
                cout << "It's a tie!" << endl;
                return;
            }

            // Player B's turn
            cout << "Player B's turn. Enter position (row, column): ";
            cin >> row >> col;

            while (isOccupied(row, col))
            {
                cout << "Cell occupied. Try another cell: ";
                cin >> row >> col;
            }

            board[row][col] = playerB;
            count++;
            printBoard();

            if (checkMatch(playerB))
            {
                cout << "Player B wins!" << endl;
                return;
            }
        }
    }
};

int main()
{
    TicTacToe game;
    string playerChoice, repeat;

    cout<< "\033c";

    cout << "Welcome to the Tic-Tac-Toe game!\n";

    do
    {
        cout << "Who would you like to play with? (Computer/Friend): ";
        cin >> playerChoice;

        for (char &c : playerChoice)
        {
            c = tolower(c); // Convert to lowercase for case-insensitive comparison
        }

        if (playerChoice == "computer")
        {
            game.playWithComputer();
        }
        else if (playerChoice == "friend")
        {
            game.playWithFriend();
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> repeat;
        repeat = tolower(repeat[0]);
        game.resetBoard();

    } while (repeat == "y");

    return 0;
}
