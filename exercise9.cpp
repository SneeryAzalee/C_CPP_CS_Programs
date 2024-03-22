/*
    Write a program that will delete an element at a desired position from an array.
    
    Ex:
    
        Inputs:
        
            Enter size of array---------------->>   4
            Enter elements--------------------->>  10  2  3  5
            Enter position to be deleted------->>   2
        
        Outputs:
        
            Array after deleting position------>>  10  3  5
*/

#include <iostream>

using namespace std;

int *remove(int *elements, int arraySize, int deletePosition);

int main()
{
    int arraySize;
    cout << "\nEnter size of array:\n\n>> ";
    cin >> arraySize;
    int *elements = new int[arraySize];
    
    cout << "\nEnter elements:\n\n>> ";
    for(int i = 0; i < arraySize; i++)
    {
        int num;
        cin >> num;
        elements[i] = num;
    }
    
    int deletePosition;
    cout << "\nEnter position to be deleted: (index starts at 1)\n\n>> ";
    cin >> deletePosition;
    
    elements = remove(elements, arraySize, deletePosition - 1);
    cout << "\n\n\nArray after deleting position:\n\n>> ";
    for(int i = 0; i < arraySize - 1; i++)
    {
        cout << elements[i] << " ";
    }
    
    cout << "\n\n";
    delete[] elements;
    
    return 0;
}

int *remove(int *elements, int arraySize, int deletePosition)
{
    int *newElements = new int[arraySize - 1];
    bool elementDeleted = false;
    for(int i = 0; i < arraySize; i++)
    {
        if(i != deletePosition)
        {
            if(elementDeleted)
            {
                newElements[i - 1] = elements[i];
            }
            else
            {
                newElements[i] = elements[i];
            }
        }
        else
        {
            elementDeleted = true;
            continue;
        }
    }
    delete[] elements;
    return newElements;
}