#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Sneery
{
    public:
    
        Sneery(string input)
        {
            mainInput = input;
        };
        
        string mainInput;
        vector<string> uniqueInputs;
        vector<string> inputMain;
        vector<int> uniqueCounter;
        int inputCount = 0, highestUnique = 0;
        
        void extractString()
        {
            stringstream extractor(mainInput);
            string word;
            while(extractor >> word)
            {
                bool isUnique = true;
                for(string s : uniqueInputs)
                {
                    if(word == s)
                    {
                        isUnique = false;
                        break;
                    }
                }
                if(isUnique)
                {
                    uniqueInputs.push_back(word);
                }
                inputCount++;
                inputMain.push_back(word);
            }
        }
        
        void getHighestUnique()
        {
            for(int i = 0; i < uniqueInputs.size(); i++)
            {
                int count = 0;
                for(int j = 0; j < inputCount; j++)
                {
                    if(uniqueInputs[i] == inputMain[j])
                    {
                        count++;
                    }
                }
                uniqueCounter.push_back(count);
                if(count > highestUnique)
                {
                    highestUnique = count;
                }
            }
        }
        
        void getResult()
        {
            cout << "\nOutputs:\n\n";
            for(int i = 0; i < uniqueCounter.size(); i++)
            {
                if(uniqueCounter[i] == highestUnique)
                {
                    cout << ">> " << uniqueInputs[i] << " - " << highestUnique << "\n";
                }
            }
        }
};

int main()
{
    string mainInput;
    cout << "\nInput: ";
    getline(cin, mainInput);
    
    Sneery sneery(mainInput);
    sneery.extractString();
    sneery.getHighestUnique();
    sneery.getResult();
    
    return 0;
}