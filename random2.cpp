#include <iostream>
#include <random>

using namespace std;

class Sneery
{
    public:
    
        void setTarget()
        {
            cout << "\nInput: ";
            getline(cin, input);
            target = input;
            
            cout << "\nTarget: ";
            for(int i = 0; ; i++)
            {
                char c = cin.get();
                if(c == '\n')
                {
                    break;
                }
                target[i] = c;
                targetCount++;
            }
        }
        
        void randomize()
        {
            random_device randDevice;
            mt19937 generator(randDevice());
            for(int i = 0; i < targetCount; )
            {
                uniform_int_distribution<int> random(i, input.length() - 1);
                int randNum = random(generator);
                if(input[randNum] == target[i])
                {
                    char temp = input[i];
                    input[i] = input[randNum];
                    input[randNum] = temp;
                    i++;
                }
                cout << "\n" << ++count << ". " << input << "   i: " << i << "  r: " << randNum;
                if(input == target)
                {
                    break;
                }
            }
            cout << "\n";
        }
    
    private:
    
        string input, target;
        int count = 0, targetCount = 0;
};

int main()
{
    Sneery sneery;
    sneery.setTarget();
    sneery.randomize();
    
    return 0;
}