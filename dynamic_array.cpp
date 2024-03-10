#include <iostream>
#include <sstream>

using namespace std;

int *reallocate_memory(int *array, int size)
{
    int *new_array = new int[size + 1];
    for(int i = 0; i < size; i++)
    {
        new_array[i] = array[i];
    }
    delete[] array;
    return new_array;
}

int main()
{
    int size = 0;
    int *array = new int[1];
    string input_string;
    
    cout << "Input/s: ";
    getline(cin, input_string);
    stringstream input_stream(input_string);
    int num;
    
    while(input_stream >> num)
    {
        if(size > 0)
        {
            array = reallocate_memory(array, size);
        }
        array[size++] = num;
    }
    
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n" << size;
    delete[] array;
    
    return 0;
}