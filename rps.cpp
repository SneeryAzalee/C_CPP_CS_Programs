// Make a program that will simulate a rock-paper-scissors game

#include <iostream>
#include <random>

using namespace std;

int main()
{
    int selection, bot, result;
    random_device rd;
    mt19937 gen(rd());
    char loop;
    do
    {
        cout << "\n(1) Rock\n(2) Paper\n(3) Scissors\n\nYOU >> ";
        cin >> selection;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        uniform_int_distribution<int> dis(1, 3);
        bot = dis(gen);
        result = (selection * selection) * (bot * bot);
        cout << "BOT >> " << bot << "\n";
        loop = 'n';
    
        /*
            1 = Rock
            2 = Paper
            3 = Scissors
        */    
        
        cout << "\n";
        if(selection == bot)
        {
            cout << "Tie!";
        }
        else
        {
            switch(result)
            {
                case 4:
            
                    cout << "Paper wins!";
                    break;
                    
                case 9:
                
                    cout << "Rock wins!";
                    break;
                    
                case 36:
                
                    cout << "Scissors wins!";
                    break;
                    
                default:
                
                    cout << "Invalid input!";
            }
        }
        cout << "\n";
        
        cout << "\nRetry? (y/n) >> ";
        cin >> loop;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        tolower(loop);
        cout << "\n";
        
    } while(loop == 'y');
    
    return 0;
}