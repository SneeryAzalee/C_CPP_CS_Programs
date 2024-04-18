#include <iostream>
#include <vector>

using namespace std;

class Input
{
    public:
    
        string mainInput;
        
        void setString()
        {
            cout << "Enter string: ";
            getline(cin, mainInput);
        }
};

class InputLength : public Input
{
    public:
    
        int stringCount;
        
        void getStringLength()
        {
            stringCount = mainInput.length();
        }
};

class HappyUnhappy : public InputLength
{
    public:
    
        bool happy = false;
        
        void getHappyUnhappyResult()
        {
            int tempStringCount = stringCount, rem;
            vector<int> separatedNums, totalSeparatedList;
            bool imInALoopTrap = false;
            
            while(!imInALoopTrap && !happy)
            {
                separatedNums.clear();
                while(tempStringCount > 0)
                {
                    rem = tempStringCount % 10;
                    separatedNums.push_back(rem);
                    tempStringCount /= 10;
                }
                
                int squaredSum = 0;
                for(int i = 0; i < separatedNums.size(); i++)
                {
                    squaredSum += separatedNums[i] * separatedNums[i];
                }
                
                if(squaredSum != 1)
                {
                    if(totalSeparatedList.size() == 0)
                    {
                        totalSeparatedList.push_back(squaredSum);
                        tempStringCount = squaredSum;
                    }
                    else
                    {
                        bool repetitionFound = false;
                        for(int i = 0; i < totalSeparatedList.size(); i++)
                        {
                            if(squaredSum == totalSeparatedList[i])
                            {
                                repetitionFound = true;
                                break;
                            }
                        }
                        
                        if(repetitionFound)
                        {
                            imInALoopTrap = true;
                        }
                        else
                        {
                            totalSeparatedList.push_back(squaredSum);
                            tempStringCount = squaredSum;
                        }
                    }
                }
                else
                {
                    happy = true;
                }
            }
        }
};

class PrintOutput : public HappyUnhappy
{
    public:
    
        void getResult()
        {
            if(happy)
            {
                cout << "\nHappy Number! Reversing string...\n\n";
                for(int i = mainInput.length() - 1; i >= 0; i--)
                {
                    cout << mainInput[i];
                }
            }
            else
            {
                cout << "\nUnhappy Number! String retained.\n\n";
                cout << mainInput;
            }
            cout << "\n";
        }
};

int main()
{
    PrintOutput output;
    output.setString();
    output.getStringLength();
    output.getHappyUnhappyResult();
    output.getResult();
    
    return 0;
}