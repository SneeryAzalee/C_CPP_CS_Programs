#include <iostream>

using namespace std;

void clearInputBuffer()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

char getTileStatus(int tileValue, int tileNumber)
{
    if(tileValue == 1)
    {
        return 'X';
    }
    else if(tileValue == 2)
    {
        return 'O';
    }
    else
    {
        return tileNumber + '1';
    }
}

bool inputIsNumberInRange(char input)
{
    if(isdigit(input) && input >= '1' && input <= '9')
    {
        return true;
    }
    return false;
}

class TicTacToe
{
    public:
    
        void getPlayerNames()
        {
            cout << "\nEnter Player 1 name:\n\n>> ";
            getline(cin, namePlayer1);
            cout << "\nEnter Player 2 name:\n\n>> ";
            getline(cin, namePlayer2);
        }
        
        void printBoard()
        {
            for(int i = 0; i < 30; i++)
            {
                cout << "\n";
            }
            for(int i = 0; i < 9; i++)
            {
                char c = getTileStatus(boardValues[i], i);
                if(i % 3 == 0 && i != 0)
                {
                    cout << "\n-----+-----+-----\n";
                }
                if(i == 1 || i == 4 || i == 7 || i == 2 || i == 5 || i == 8)
                {
                    cout << "|";
                }
                cout << "  " << c << "  ";
            }
            cout << "\n\n";
        }
        
        void getWhoseTurn()
        {
            if(playerTurn == 1)
            {
                cout << "\n(X) " << namePlayer1 << ((tolower(namePlayer1[namePlayer1.length() - 1]) == 's') ? "\'" : "\'s") << " turn!\n";
            }
            else
            {
                cout << "\n(O) " << namePlayer2 << ((tolower(namePlayer2[namePlayer2.length() - 1]) == 's') ? "\'" : "\'s") << " turn!\n";
            }
        }
        
        void getBoardValue(int tileNumber)
        {
            char inputTileNumber;
            bool isValid = false;
            while(!isValid)
            {
                cout << "\n>> ";
                cin >> inputTileNumber;
                clearInputBuffer();
                if(inputIsNumberInRange(inputTileNumber))
                {
                    int value = inputTileNumber - '1';
                    if(boardValues[value] >= 1 ^ boardValues[value] <= 2)
                    {
                        boardValues[value] = (playerTurn == 1) ? 1 : 2;
                        isValid = true;
                    }
                    else
                    {
                        cerr << "\nError: Tile is occupied!\n";
                    }
                }
                else
                {
                    cerr << "\nError: Invalid input!\n";
                }
            }
        }
        
        void swapPlayerTurn()
        {
            playerTurn = (playerTurn == 2) ? 1 : 2;
        }
        
        void checkWinningLines()
        {
            if(boardValues[0] == boardValues[1] && boardValues[1] == boardValues[2])
            {
                hasWinner = true;
            }
            else if(boardValues[3] == boardValues[4] && boardValues[4] == boardValues[5])
            {
                hasWinner = true;
            }
            else if(boardValues[6] == boardValues[7] && boardValues[7] == boardValues[8])
            {
                hasWinner = true;
            }
            else if(boardValues[0] == boardValues[3] && boardValues[3] == boardValues[6])
            {
                hasWinner = true;
            }
            else if(boardValues[1] == boardValues[4] && boardValues[4] == boardValues[7])
            {
                hasWinner = true;
            }
            else if(boardValues[2] == boardValues[5] && boardValues[5] == boardValues[8])
            {
                hasWinner = true;
            }
            else if(boardValues[0] == boardValues[4] && boardValues[4] == boardValues[8])
            {
                hasWinner = true;
            }
            else if(boardValues[2] == boardValues[4] && boardValues[4] == boardValues[6])
            {
                hasWinner = true;
            }
        }
        
        bool checkHasWinner()
        {
            return hasWinner;
        }
        
        void announceWinner()
        {
            cout << "\n" << ((playerTurn == 1) ? namePlayer1 : namePlayer2) << " wins the game!\n";
        }
        
        void resetGame()
        {
            int *newBoardValues = new int[9];
            delete[] boardValues;
            boardValues = newBoardValues;
            hasWinner = false;
            for(int i = 0; i < 9; i++)
            {
                boardValues[i] = i + 11;
            }
        }
        
        ~TicTacToe()
        {
            delete[] boardValues;
        }
        
    private:
    
        string namePlayer1;
        string namePlayer2;
        int *boardValues = new int[9];
        int playerTurn = 2;
        bool hasWinner = false;
};

int main()
{
    int exit = 1;
    TicTacToe tictactoe;
    tictactoe.getPlayerNames();
    do
    {
        bool hasWinner = false;
        tictactoe.resetGame();
        for(int i = 0; i < 9; i++)
        {
            tictactoe.printBoard();
            tictactoe.swapPlayerTurn();
            tictactoe.getWhoseTurn();
            tictactoe.getBoardValue(i);
            tictactoe.checkWinningLines();
            hasWinner = tictactoe.checkHasWinner();
            if(hasWinner)
            {
                break;
            }
        }
        tictactoe.printBoard();
        if(hasWinner)
        {
            tictactoe.announceWinner();
        }
        else
        {
            cout << "\nDraw!\n";
        }
        
        cout << "\n\n0. Rematch\n1. Exit\n\n>> ";
        cin >> exit;
        clearInputBuffer();
        
    } while(exit == 0);
    
    return 0;
}