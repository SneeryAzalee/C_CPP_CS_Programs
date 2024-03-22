/*
    Write a program that will to insert values in an array.
    After the insertion, sort the array in ascending order.
    
    Ex:
    
        Inputs:
        
            Enter size of array---------------->>   4
            Enter elements--------------------->>  10  2  3  5
            Enter position to be inserted------>>   2
            Enter value to be inserted--------->>  16
        
        Outputs:
        
            Array after insertion-------------->>  10  16   2   3    5
            Array sorted----------------------->>   2   3   5  10   16
*/

#include <iostream>

using namespace std;

void insert(int *elements, int arraySize, int insertPosition, int insertValue);
void arrange(int *elements, int arraySize);

int main()
{
    int arraySize;
    cout << "\nEnter size of array:\n\n>> ";
    cin >> arraySize;
    int *elements = new int[arraySize + 1];
    
    cout << "\nEnter elements:\n\n>> ";
    for(int i = 0; i < arraySize; i++)
    {
        int num;
        cin >> num;
        elements[i] = num;
    }
    
    int insertPosition;
    cout << "\nEnter position to be inserted: (index starts at 1)\n\n>> ";
    cin >> insertPosition;
    
    int insertValue;
    cout << "\nEnter value to be inserted:\n\n>> ";
    cin >> insertValue;
    
    insert(elements, arraySize + 1, insertPosition - 1, insertValue);
    cout << "\n\n\nArray after insertion:\n\n>> ";
    for(int i = 0; i < arraySize + 1; i++)
    {
        cout << elements[i] << " ";
    }
    
    arrange(elements, arraySize + 1);
    cout << "\n\nArray sorted:\n\n>> ";
    for(int i = 0; i < arraySize + 1; i++)
    {
        cout << elements[i] << " ";
    }
    
    cout << "\n\n";
    delete[] elements;
    
    return 0;
}

void insert(int *elements, int arraySize, int insertPosition, int insertValue)
{
    bool valueInserted = false;
    int temp;
    for(int i = 0; i < arraySize; i++)
    {
        if(!valueInserted && i == insertPosition)
        {
            temp = elements[i];
            elements[i] = insertValue;
            valueInserted = true;
            continue;
        }
        else if(valueInserted)
        {
            int temp2 = elements[i];
            elements[i] = temp;
            temp = temp2;
        }
    }
}

void arrange(int *elements, int arraySize)
{
    for(int i = 0; i < arraySize; i++)
    {
        for(int j = 0; j < arraySize; j++)
        {
            if(elements[i] < elements[j])
            {
                int temp = elements[i];
                elements[i] = elements[j];
                elements[j] = temp;
            }
        }
    }
}