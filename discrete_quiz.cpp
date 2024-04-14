#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

using namespace std;

void clearInputBuffer()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

class Solution
{
    public:
    
        void linearSearch()
        {
            cout << "\nEnter integer elements: (space-separated)\n\n>> ";
            getline(cin, mainInput);
            stringstream extractor(mainInput);
            inputs.clear();
            while(extractor >> extractedNums)
            {
                inputs.push_back(extractedNums);
            }
            
            int target;
            cout << "\nEnter element to search:\n\n>> ";
            cin >> target;
            clearInputBuffer();
            
            bool targetFound = false;
            cout << "\n\nSearching element...\n\n\n";
            for(int i = 0; i < inputs.size(); i++)
            {
                cout << "Index " << i << ": " << inputs[i] << "\n";
                if(target == inputs[i])
                {
                    targetFound = true;
                    cout << "\n\nElement found at Index " << i << "\n\n";
                    break;
                }
            }
            if(!targetFound)
            {
                cout << "\n\nElement not found!\n\n";
            }
        }
        
        void bubbleSort()
        {
            cout << "\nEnter integer elements: (space-separated)\n\n>> ";
            getline(cin, mainInput);
            stringstream extractor(mainInput);
            inputs.clear();
            while(extractor >> extractedNums)
            {
                inputs.push_back(extractedNums);
            }
            
            int selection = 0;
            cout << "\nChoose sorting order:\n\n";
            cout << "1. Ascending\n";
            cout << "2. Descending\n";
            cout << "\n>> ";
            cin >> selection;
            clearInputBuffer();
            if(selection == 1)
            {
                cout << "\n\nSorting in ASCENDING order...\n\n\n";
                int passCount = 1;
                for(int i = 0; i < inputs.size(); i++)
                {
                    for(int j = 0; j < inputs.size(); j++)
                    {
                        if(inputs[i] < inputs[j])
                        {
                            int tempNum = inputs[i];
                            inputs[i] = inputs[j];
                            inputs[j] = tempNum;
                            cout << "Pass " << passCount++ << ":\n\n-> ";
                            for(int vectorNums : inputs)
                            {
                                cout << vectorNums << " ";
                            }
                            cout << "\n\n";
                        }
                    }
                }
                cout << "\nSorting complete!\n\n";
                cout << "\nFinal Order: ";
                for(int vectorNums : inputs)
                {
                    cout << vectorNums << " ";
                }
                cout << "\n\n";
            }
            else if(selection == 2)
            {
                cout << "\n\nSorting in DESCENDING order...\n\n\n";
                int passCount = 1;
                for(int i = 0; i < inputs.size(); i++)
                {
                    for(int j = 0; j < inputs.size(); j++)
                    {
                        if(inputs[i] > inputs[j])
                        {
                            int tempNum = inputs[i];
                            inputs[i] = inputs[j];
                            inputs[j] = tempNum;
                            cout << "Pass " << passCount++ << ":\n\n-> ";
                            for(int vectorNums : inputs)
                            {
                                cout << vectorNums << " ";
                            }
                            cout << "\n\n";
                        }
                    }
                }
                cout << "\nSorting complete!\n\n";
                cout << "\nFinal Order: ";
                for(int vectorNums : inputs)
                {
                    cout << vectorNums << " ";
                }
                cout << "\n\n";
            }
            else
            {
                cerr << "\n\nError: Invalid input!\n\n";
            }
        }
        
        void greedyOptimization()
        {
            cout << "\nEnter unique cents: (space-separated)\n\n>> ";
            getline(cin, mainInput);
            stringstream extractor(mainInput);
            inputs.clear();
            while(extractor >> extractedNums)
            {
                bool elementAlreadyPresent = false;
                for(int i = 0; i < inputs.size(); i++)
                {
                    if(extractedNums == inputs[i])
                    {
                        elementAlreadyPresent = true;
                        break;
                    }
                }
                if(!elementAlreadyPresent)
                {
                    inputs.push_back(extractedNums);
                }
            }
            
            int inputMultiplier[inputs.size()];
            for(int i = 0; i < inputs.size(); i++)
            {
                inputMultiplier[i] = 0;
            }
            
            int debt, debtOriginal;
            cout << "\nEnter item price: (cents)\n\n>> ";
            cin >> debt;
            debtOriginal = debt;
            clearInputBuffer();
            
            for(int i = 0; i < inputs.size(); i++)
            {
                for(int j = 0; j < inputs.size(); j++)
                {
                    if(inputs[i] > inputs[j])
                    {
                        int tempNum = inputs[i];
                        inputs[i] = inputs[j];
                        inputs[j] = tempNum;
                    }
                }
            }
            
            int passCount = 1;
            cout << "\n\nCalculating optimizations...\n\n\n";
            while(true)
            {
                int errorCount = 0;
                for(int i = 0; i < inputs.size(); i++)
                {
                    if((debt - inputs[i]) >= 0)
                    {
                        debt -= inputs[i];
                        inputMultiplier[i]++;
                        cout << "Pass " << passCount++ << ":\n\n-> ";
                        cout << "Subtracted " << inputs[i] << "c from debt! (" << debt << "c)\n\n";
                        break;
                    }
                    else
                    {
                        errorCount++;
                    }
                }
                if(errorCount == inputs.size())
                {
                    break;
                }
            }
            cout << "\nOptimizations complete!\n\n";
            cout << "\nYou will prepare: (Price: " << debtOriginal << " cents)\n\n";
            for(int i = 0; i < inputs.size(); i++)
            {
                cout << "-> " << inputs[i] << " cents (x" << inputMultiplier[i] << ")\n";
            }
            cout << "\nRemaining debt: " << debt << "\n\n";
        }
        
    private:
    
        vector<int> inputs;
        string mainInput;
        int extractedNums;
};

int main()
{
    Solution solution;
    int selection = 0;
    do
    {
        cout << "\nChoose an algorithm:\n\n";
        cout << "1. Search algorithm (linear)\n";
        cout << "2. Sort algorithm (bubble)\n";
        cout << "3. Optimization algorithm (greedy)\n";
        cout << "0. Exit!\n";
        cout << "\n>> ";
        cin >> selection;
        clearInputBuffer();
        
        switch(selection)
        {
            case 1:
                
                cout << "\n\nLINEAR SEARCH ALGORITHM\n\n";
                solution.linearSearch();
                break;
                
            case 2:
                
                cout << "\n\nBUBBLE SORT ALGORITHM\n\n";
                solution.bubbleSort();
                break;
                
            case 3:
                
                cout << "\n\nGREEDY OPTIMIZATION ALGORITHM\n\n";
                solution.greedyOptimization();
                break;
            
            case 0:
                
                break;
            
            default:
                
                cerr << "\n\nError: Invalid input!\n\n";
                break;    
        }
    
    } while(selection != 0);
    
    return 0;
}