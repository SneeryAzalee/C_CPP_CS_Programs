#include <iostream>

using namespace std;

string toLowerCase(string input)
{
    for(int i = 0; i < input.length(); i++)
    {
        input[i] = tolower(input[i]);
    }
    return input;
}

int numPlace(string input)
{
    string nums[] = {
                        "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                        "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
                        "twenty", "twenty-one", "twenty-two", "twenty-three", "twenty-four", "twenty-five", "twenty-six", "twenty-seven", "twenty-eight", "twenty-nine",
                        "thirty", "thirty-one", "thirty-two", "thirty-three", "thirty-four", "thirty-five", "thirty-six", "thirty-seven", "thirty-eight", "thirty-nine",
                        "forty", "forty-one", "forty-two", "forty-three", "forty-four", "forty-five", "forty-six", "forty-seven", "forty-eight", "forty-nine",
                        "fifty", "fifty-one", "fifty-two", "fifty-three", "fifty-four", "fifty-five", "fifty-six", "fifty-seven", "fifty-eight", "fifty-nine",
                        "sixty", "sixty-one", "sixty-two", "sixty-three", "sixty-four", "sixty-five", "sixty-six", "sixty-seven", "sixty-eight", "sixty-nine",
                        "seventy", "seventy-one", "seventy-two", "seventy-three", "seventy-four", "seventy-five", "seventy-six", "seventy-seven", "seventy-eight", "seventy-nine",
                        "eighty", "eighty-one", "eighty-two", "eighty-three", "eighty-four", "eighty-five", "eighty-six", "eighty-seven", "eighty-eight", "eighty-nine",
                        "ninety", "ninety-one", "ninety-two", "ninety-three", "ninety-four", "ninety-five", "ninety-six", "ninety-seven", "ninety-eight", "ninety-nine",
                        "one hundred"
                    };
    
    for(int i = 0; i < 100; i++)
    {
        if(input == nums[i])
        {
            return i + 1;
        }
    }
    
    cerr << "\nError: Invalid number!\n";
    return -1;
}

int main()
{
    int inputCount;
    cout << "\nNumber of inputs: ";
    cin >> inputCount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    string inputs[inputCount];
    int inputNum[inputCount];
    bool invalid = false;
    cout << "\n";
    for(int i = 0; i < inputCount && !invalid; i++)
    {
        string temp;
        cout << "Input " << i + 1 << ": ";
        getline(cin, temp);
        
        temp = toLowerCase(temp);
        int place = numPlace(temp);
        if(place != -1)
        {
            inputs[i] = temp;
            inputNum[i] = place;
        }
        else
        {
            invalid = true;
            break;
        }
    }
    
    for(int i = 0; i < inputCount && !invalid; i++)
    {
        for(int j = 0; j < inputCount && !invalid; j++)
        {
            if(inputNum[i] < inputNum[j])
            {
                int temp = inputNum[i];
                inputNum[i] = inputNum[j];
                inputNum[j] = temp;
                
                string temp2 = inputs[i];
                inputs[i] = inputs[j];
                inputs[j] = temp2;
            }
        }
    }
    
    cout << "\nOutput: ";
    if(!invalid)
    {
        for(int i = 0; i < inputCount; i++)
        {
            cout << inputs[i] << ((i == (inputCount - 1)) ? "" : ", ");
        }
    }
    cout << "\n";
    
    return 0;
}