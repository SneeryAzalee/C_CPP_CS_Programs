#include <iostream>
#include <conio.h>

using namespace std;

class Sneery
{
    public:
    
        void clearInputBuffer()
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        void getGridSize()
        {
            cout << "\nEnter grid size: ";
            cin >> gridSize;
            clearInputBuffer();
        }
        
        void initializeMap()
        {
            char **newArray = new char*[gridSize];
            for(int i = 0; i < gridSize; i++)
            {
                newArray[i] = new char[gridSize];
            }
            delete[] map;
            map = newArray;
        }
        
        void resetMap()
        {
            for(int i = 0; i < gridSize; i++)
            {
                for(int j = 0; j < gridSize; j++)
                {
                    map[i][j] = '-';
                }
            }
        }
        
        void printMap()
        {
            cerr << "\e[2J\e[1;1H";
            for(int i = 0; i < gridSize; i++)
            {
                for(int j = 0; j < gridSize; j++)
                {
                    cerr << ((i == row && j == column) ? "\e[1;35m" : "\e[0m") << map[i][j] << "\e[0m ";
                }
                cerr << "\n";
            }
            cerr << "\n1. Set";
            cerr << "\n2. Reset";
            cerr << "\n3. Move up";
            cerr << "\n4. Move down";
            cerr << "\n5. Move left";
            cerr << "\n6. Move right";
            cerr << "\n0. Exit\n";
        }
        
        void interactiveMode()
        {
            bool toggle = true;
            printMap();
            while(toggle)
            {
                if(kbhit())
                {
                    char keyPressed = getch();
                    switch(keyPressed)
                    {
                        case '1':
                        {
                            setElement();
                            printMap();
                            break;
                        }
                        
                        case '2':
                        {
                            resetElement();
                            printMap();
                            break;
                        }
                        
                        case '3':
                        {
                            moveUp();
                            printMap();
                            break;
                        }
                        
                        case '4':
                        {
                            moveDown();
                            printMap();
                            break;
                        }
                        
                        case '5':
                        {
                            moveLeft();
                            printMap();
                            break;
                        }
                        
                        case '6':
                        {
                            moveRight();
                            printMap();
                            break;
                        }
                        
                        case '0':
                        {
                            toggle = false;
                            cerr << "\n\n";
                            break;
                        }
                        
                        default:
                        {
                            printMap();
                            break;
                        }
                    }
                }
            }
        }
        
        void setElement()
        {
            cerr << "\nSet element: ";
            cin >> map[row][column];
            clearInputBuffer();
        }
        
        void resetElement()
        {
            map[row][column] = '-';
        }
        
        void moveUp()
        {
            row = ((row > 0) ? --row : row);
        }
        
        void moveDown()
        {
            row = ((row < gridSize - 1) ? ++row : row);
        }
        
        void moveLeft()
        {
            column = ((column > 0) ? --column : column);
        }
        
        void moveRight()
        {
            column = ((column < gridSize - 1) ? ++column : column);
        }
        
        ~Sneery()
        {
            for(int i = 0; i < gridSize; i++)
            {
                delete[] map[i];
            }
            delete[] map;
        }
    
    private:
    
        int gridSize, row = 0, column = 0;
        char **map = new char*[0];
};

int main()
{
    Sneery sneery;
    sneery.getGridSize();
    sneery.initializeMap();
    sneery.resetMap();
    sneery.interactiveMode();
    
    return 0;
}