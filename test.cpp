#include <iostream>
#include <sstream>

using namespace std;

int *reallocateMem(int *input, int count)
{
    int *new_input = new int[count + 1];
    for(int i = 0; i < count; i++)
    {
        new_input[i] = input[i];
    }
    delete[] input;
    return new_input;
}

int stringToInt(string input)
{
    int result = 0;
    for(int i = 0; i < input.length(); i++)
    {
        result = (result * 10) + (input[i] - '0');
    }
    return result;
}

bool isNumber(string input)
{
    for(int i = 0; i < input.length(); i++)
    {
        if(!isdigit(input[i]))
        {
            return false;
        }
    }
    return true;
}

class Sneery
{
    public:
    
        Sneery(string studentGrades)
        {
            grades = new int[_gradeCount];
            stringstream extract(studentGrades);
            string num;
            while(extract >> num)
            {
                if(isNumber(num))
                {
                    grades = reallocateMem(grades, _gradeCount);
                    grades[_gradeCount++] = stringToInt(num);
                }
                else
                {
                    cerr << "\nError! (Invalid grade)\n";
                    _inputsAccepted = false;
                    break;
                }
            }
        };
        
        bool inputsAccepted()
        {
            return _inputsAccepted;
        }
        
        double getAverage()
        {
            double sum = 0.0;
            for(int i = 0; i < _gradeCount; i++)
            {
                sum += grades[i];
            }
            return (sum / _gradeCount);
        }
        
        ~Sneery()
        {
            delete[] grades;
        };
    
    private:
    
        int _gradeCount = 0;
        int *grades;
        bool _inputsAccepted = true;
};

int main()
{
    string studentName, studentGrades;
    
    cout << "\nStudent Name: ";
    getline(cin, studentName);
    cout << "\nEnter Grades: ";
    getline(cin, studentGrades);
    
    Sneery sneery(studentGrades);
    if(sneery.inputsAccepted())
    {
        double average = sneery.getAverage();
        cout << "\n\nAverage grade of " << studentName << " : " << average << "\n\n";
    }
    
    return 0;
}