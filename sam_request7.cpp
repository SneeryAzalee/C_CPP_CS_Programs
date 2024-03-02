#include <iostream>

using namespace std;
const int set_size = 100, input_size = 100;

bool prime_checker(int input)
{
    int count = 0;
    for(int i = 2; i < input; i++)
    {
        if(input % i == 0)
        {
            count++;
            break;
        }
    }
    if(count == 0 && input > 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool composite_checker(int input)
{
    int count = 0;
    for(int i = 2; i < input; i++)
    {
        if(input % i == 0)
        {
            count++;
            break;
        }
    }
    if(count > 0 && input > 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void prime(int inputs[input_size], int size)
{
    int targets[input_size], prime_list[input_size], targets_size = 0, index, lowest_prime, highest_prime;
    
    index = 0;
    for(int i = 0; i < size; i++)
    {
        if(prime_checker(inputs[i]))
        {
            if(index == 0)
            {
                lowest_prime = inputs[i];
                highest_prime = inputs[i];
            }
            else
            {
                if(inputs[i] < lowest_prime)
                {
                    lowest_prime = inputs[i];
                }
                else if(inputs[i] > highest_prime)
                {
                    highest_prime = inputs[i];
                }
            }
            targets[index] = i;
            targets_size++;
            index++;
        }
    }
    
    index = 0;
    for(int i = lowest_prime; i <= highest_prime; i++)
    {
        int index2 = 0;
        for(int j = targets[index2]; index2 < targets_size; j = targets[++index2])
        {
            if(i == inputs[j])
            {
                prime_list[index++] = i;
            }
        }
    }
    
    index = 0;
    for(int i = targets[index]; index < targets_size; i = targets[++index])
    {
        inputs[i] = prime_list[index];
    }
    
    for(int i = 0; i < size; i++)
    {
        cout << inputs[i] << " ";
    }
}

void composite(int inputs[input_size], int size)
{
    int targets[input_size], composite_list[input_size], targets_size = 0, index, lowest_composite, highest_composite;
    
    index = 0;
    for(int i = 0; i < size; i++)
    {
        if(composite_checker(inputs[i]))
        {
            if(index == 0)
            {
                lowest_composite = inputs[i];
                highest_composite = inputs[i];
            }
            else
            {
                if(inputs[i] < lowest_composite)
                {
                    lowest_composite = inputs[i];
                }
                else if(inputs[i] > highest_composite)
                {
                    highest_composite = inputs[i];
                }
            }
            targets[index] = i;
            targets_size++;
            index++;
        }
    }
    
    index = 0;
    for(int i = highest_composite; i >= lowest_composite; i--)
    {
        int index2 = 0;
        for(int j = targets[index2]; index2 < targets_size; j = targets[++index2])
        {
            if(i == inputs[j])
            {
                composite_list[index++] = i;
            }
        }
    }
    
    index = 0;
    for(int i = targets[index]; index < targets_size; i = targets[++index])
    {
        inputs[i] = composite_list[index];
    }
    
    for(int i = 0; i < size; i++)
    {
        cout << inputs[i] << " ";
    }
}

int main()
{
    int inputs[set_size][input_size], set_count = 0, input_count[input_size];
    bool end = false;

    for(int i = 0; !end; i++)
    {
        if(i == 0)
        {
            cout << "\nInputs: (0 for next set, -1 to end)\n\n";
        }
        cout << ":: Set " << i + 1 << " >> ";

        for(int j = 0;; j++)
        {
            int num;
            cin >> num;
            if(num > 0)
            {
                inputs[i][j] = num;
                input_count[i]++;
            }
            else if(num == 0)
            {
                break;
            }
            else if(num < 0)
            {
                end = true;
                break;
            }
        }
        set_count++;
    }

    for(int i = 0; i < set_count; i++)
    {
        if(i == 0)
        {
            cout << "\n\nOutputs: (Sorted)\n\n";
        }

        if(input_count[i] > 0)
        {
            cout << ":: Set " << i + 1 << " >> ";
            if((i + 1) % 2 == 1)
            {
                prime(inputs[i], input_count[i]);
            }
            else if((i + 1) % 2 == 0)
            {
                composite(inputs[i], input_count[i]);
            }
            cout << endl;
        }
    }
    cout << endl;

    return 0;
}