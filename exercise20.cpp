#include <iostream>

using namespace std;

class Sneery
{
    public:
        
        void clearInputBuffer()
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        void initializeArray()
        {
            long long *newArray = new long long[arraySize];
            long long *newArray2 = new long long[arraySize];
            delete[] inputs;
            delete[] outputs;
            inputs = newArray;
            outputs = newArray2;
        }
        
        void getInputs()
        {
            cout << "\nEnter array size: ";
            cin >> arraySize;
            clearInputBuffer();
            initializeArray();
            cout << "\nEnter numbers:\n\n>> ";
            for(int i = 0; i < arraySize; i++)
            {
                cin >> inputs[i];
            }
            clearInputBuffer();
        }
        
        void calculateOutput()
        {
            for(int i = 0; i < arraySize; i++)
            {
                product = 1L;
                for(int j = 0; j < arraySize; j++)
                {
                    if(i != j)
                    {
                        product *= inputs[j];
                    }
                }
                outputs[i] = product;
            }
        }
        
        void printOutput()
        {
            cout << "\nOutput:\n\n>> ";
            for(int i = 0; i < arraySize; i++)
            {
                cout << outputs[i] << " ";
            }
            cout << "\n";
        }
        
        ~Sneery()
        {
            delete[] inputs;
            delete[] outputs;
        }
    
    private:
    
        int arraySize;
        long long *inputs = new long long[0], *outputs = new long long[0];
        long long product;
};

int main()
{
    Sneery sneery;
    sneery.getInputs();
    sneery.calculateOutput();
    sneery.printOutput();
    
    return 0;
}