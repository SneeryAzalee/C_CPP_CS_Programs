#include <iostream>

using namespace std;

void classification(double input)
{
    if(input < 18.5)
    {
        cout << "Underweight\n";
    }
    else if(input >= 18.5 && input <= 24.9)
    {
        cout << "Normal\n";
    }
    else if(input >= 25.0 && input <= 29.9)
    {
        cout << "Obesity\n";
    }
    else if(input >= 35.0 && input <= 39.9)
    {
        cout << "Moderate Obesity\n";
    }
    else if(input >= 40.0)
    {
        cout << "Extreme Obesity\n";
    }
}

int main()
{
    double weight, height, bmi;
    cout << "Enter weight: ";
    cin >> weight;
    cout << "Enter height: ";
    cin >> height;
    
    bmi = weight / (height * height);
    cout << "\nBMI: " << bmi << " - ";
    
    classification(bmi);
    
    return 0;
}