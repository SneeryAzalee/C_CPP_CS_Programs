// Make a program that will convert inputs in a set into binary if they're a whole number and the sum of their digits is a prime number.

#include <iostream>

using namespace std;
const int set_size = 100, input_size = 100;

bool isPrime(int input)
{
    int remainder, sum = 0;
    while(input > 0)
    {
        remainder = input % 10;
        sum += remainder;
        input /= 10;
    }
    
    bool composite = false;
    for(int i = 2; i < sum; i++)
    {
        if(sum % i == 0)
        {
            composite = true;
            break;
        }
    }
    if(!composite && sum > 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solution(double inputs[input_size], int input_count)
{
    for(int i = 0; i < input_count; i++)
    {
        double num = inputs[i];
        if(num == (int)num && isPrime((int)num))
        {
            int binary[input_size], binary_size = 0, remainder;
            for(int j = 0; (int)num > 0; j++)
            {
                remainder = (int)num % 2;
                binary[j] = remainder;
                num = (int)num / 2;
                binary_size++;
            }
            
            for(int j = binary_size - 1; j >= 0; j--)
            {
                cout << binary[j];
            }
        }
        else
        {
            cout << num;
        }
        cout << " ";
    }
}

int main()
{
    bool stop_loop = false;
    double inputs[set_size][input_size];
    int input_count[input_size], set_count = 0;

    // Get the inputs
    for(int i = 0; !stop_loop; i++)
    {
        if(i == 0)
        {
            cout << "Input: (-1 for next set, 0 to exit)\n\n";
        }
        cout << ":: Set " << i + 1 << " >> ";

        for(int j = 0; ; j++)
        {
            double num;
            cin >> num;
            
            if(num < 0)
            {
                break;
            }
            else if(num == 0)
            {
                stop_loop = true;
                break;
            }
            else
            {
                inputs[i][j] = num;
                input_count[i]++;
            }
        }
        set_count++;
    }
    
    // Print the output results
    cout << "\n\nOutput: (sorted, modified)\n";
    for(int i = 0; i < set_count; i++)
    {
        if(input_count[i] > 0)
        {
            cout << "\n:: Set " << i + 1 << " >> ";
            solution(inputs[i], input_count[i]);
        }
    }
    cout << "\n\n";

    return 0;
}