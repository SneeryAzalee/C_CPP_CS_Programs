#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

bool integer_checker(string input)
{
    bool number = true;
    int size = input.length();
    for(int i = 0; i < size; i++)
    {
        if(input[i] < '0' || input[i] > '9')
        {
            number = false;
            break;
        }
    }
    if(number)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool prime_checker(int input)
{
    bool composite = false;
    for(int i = 2; i < input; i++)
    {
        if(input % i == 0)
        {
            composite = true;
            break;
        }
    }
    if(!composite && input > 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

class Convert
{
    public:
    
        void execute(vector<string> inputs, int input_count)
        {
            for(int i = 0; i < input_count; i++)
            {
                if(integer_checker(inputs[i]))
                {
                    stringstream num_stream(inputs[i]);
                    int num;
                    num_stream >> num;
                    
                    if(prime_checker(num))
                    {
                        int remainder, result_count = 0;
                        vector<int> result;
                        for(int j = 0; num > 0; j++)
                        {
                            remainder = num % 2;
                            result.push_back(remainder);
                            result_count++;
                            num /= 2;
                        }
                        
                        for(int j = result_count - 1; j >= 0; j--)
                        {
                            cout << result[j];
                        }
                    }
                    else
                    {
                        cout << inputs[i];
                    }
                }
                else
                {
                    cout << inputs[i];
                }
                
                cout << " ";
            }
        }
};

int main()
{
    string input_string;
    cout << "Input/s: ";
    getline(cin, input_string);
    stringstream input_stream(input_string);
    string input_num;
    int input_count = 0;
    vector<string> inputs;
    
    while(input_stream >> input_num)
    {
        inputs.push_back(input_num);
        input_count++;
    }
    
    Convert sneery;
    cout << "\nOutput/s: ";
    sneery.execute(inputs, input_count);
    cout << "\n";
    
    return 0;
}