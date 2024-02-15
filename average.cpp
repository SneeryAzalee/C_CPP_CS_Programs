// Make a program that will get the average of multiple numbers

#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    string input;
    vector<int> inputs;
    int count = 0, precision = 20;
    double sum = 0.0;
    
    cout << "Enter inputs: ";
    getline(cin, input);
    
    stringstream nums(input);
    int temp;
    
    while(nums >> temp)
    {
        inputs.push_back(temp);
        count++;
    }
    
    for(int i : inputs)
    {
        sum += i;
    }
    
    sum /= count;
    cout << "\nAverage: " << setprecision(precision) << sum << endl;
    
    return 0;
}