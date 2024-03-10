#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Num_sort
{
    public:
    
        void execute(vector<int> inputs, int input_count)
        {
            for(int i = 0; i < input_count; i++)
            {
                for(int j = 0; j < input_count; j++)
                {
                    if(inputs[i] < inputs[j])
                    {
                        int temp;
                        temp = inputs[i];
                        inputs[i] = inputs[j];
                        inputs[j] = temp;
                    }
                }
            }
            
            for(int i = 0; i < input_count; i++)
            {
                cout << inputs[i] << " ";
            }
        }
};

int main()
{
    string input_string;
    cout << "Input/s: ";
    getline(cin, input_string);
    stringstream input_stream(input_string);
    int input_num, input_count = 0;
    vector<int> inputs;
    
    while(input_stream >> input_num)
    {
        inputs.push_back(input_num);
        input_count++;
    }
    
    Num_sort sneery;
    cout << "\nOutput/s: ";
    sneery.execute(inputs, input_count);
    cout << "\n";
    
    return 0;
}