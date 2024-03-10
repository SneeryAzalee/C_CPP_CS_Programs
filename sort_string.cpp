#include <iostream>

using namespace std;

string *reallocate_string(string *input, int size)
{
    string *new_input = new string[size + 1];
    for(int i = 0; i < size; i++)
    {
        new_input[i] = input[i];
    }
    delete[] input;
    return new_input;
}

class Sneery
{
    public:
    
        string *arrange(string *input, int size)
        {
            for(int i = 0; i < size; i++)
            {
                for(int j = 0; j < size; j++)
                {
                    if(input[i] < input[j])
                    {
                        string temp = input[i];
                        input[i] = input[j];
                        input[j] = temp;
                    }
                }
            }
            
            return input;
        }
};

int main()
{
    string toggle = "";
    string *inputs = new string[0];
    int input_count = 0;
    
    cout << "Inputs: (leave it blank to exit)\n\n";
    do
    {
        cout << "(" << input_count + 1 << ")" << " >>  ";
        getline(cin, toggle);
        if(!toggle.empty())
        {
            inputs = reallocate_string(inputs, input_count);
            inputs[input_count++] = toggle;
        }
        
    } while(!toggle.empty());
    
    Sneery execute;
    execute.arrange(inputs, input_count);
    
    cout << "\n\nOutputs: (sorted)\n\n";
    for(int i = 0; i < input_count; i++)
    {
        cout << "(" << i + 1 << ")" << " >>  " << inputs[i] << "\n";
    }
    cout << "\n\n";
    
    delete[] inputs;
    
    return 0;
}