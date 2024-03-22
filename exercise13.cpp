#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> ascending(vector<int> input, int size);
vector<int> descending(vector<int> input, int size);

int main()
{
    string mainInput;
    cout << "\nInput(s): ";
    getline(cin, mainInput);
    stringstream extractor(mainInput);
    int num, size = 0;
    vector<int> inputs;
    
    while(extractor >> num)
    {
        inputs.push_back(num);
        size++;
    }
    
    int sortType;
    cout << "\nChoose sorting type:\n\n1) Ascending\n2) Descending\n\n>> ";
    cin >> sortType;
    
    switch(sortType)
    {
        case 1:
            inputs = ascending(inputs, size);
            break;
        case 2:
            inputs = descending(inputs, size);
            break;
        default:
            cerr << "\nError: Invalid type!\n";    
    }
    
    cout << "\nOutput(s): ";
    for(int i : inputs)
    {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}

vector<int> ascending(vector<int> input, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(input[i] < input[j])
            {
                int temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }
    }
    
    return input;
}

vector<int> descending(vector<int> input, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(input[i] > input[j])
            {
                int temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }
    }
    
    return input;
}