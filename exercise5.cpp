#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    string input_string;
    cout << "Inputs: ";
    getline(cin, input_string);
    vector<int> inputs;
    stringstream extractor(input_string);
    int num;
    
    while(extractor >> num)
    {
        inputs.push_back(num);
    }
    int n = inputs.size();
    int *p = &inputs[0];
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(*(p + i) < *(p + j))
            {
                int temp = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = temp;
            }
        }
    }
    
    cout << "\nOutput: ";
    for(int i : inputs)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}