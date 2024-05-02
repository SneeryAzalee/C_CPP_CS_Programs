#include <iostream>
#include <random>
#include <vector>

using namespace std;

class Randomizer
{
    public:
    
        void setInput()
        {
            cout << "\nEnter input: ";
            getline(cin, input);
        }
        
        void randomize()
        {
            random_device randDevice;
            mt19937 generator(randDevice());
            uniform_int_distribution<int> random(0, input.length() - 1);
            for(int i = 0; i < input.length(); )
            {
                int randNum = random(generator);
                bool repetition = false;
                for(int j = 0; j < numList.size(); j++)
                {
                    if(randNum == numList[j])
                    {
                        repetition = true;
                        break;
                    }
                }
                if(!repetition)
                {
                    char temp = input[i];
                    input[i] = input[randNum];
                    input[randNum] = temp;
                    numList.push_back(randNum);
                    i++;
                }
            }
        }
        
        void getOutput()
        {
            cout << "\nOutput: " << input << "\n";
        }
    
    private:
    
        string input;
        vector<int> numList;
};

int main()
{
    Randomizer sneery;
    sneery.setInput();
    sneery.randomize();
    sneery.getOutput();
    
    return 0;
}