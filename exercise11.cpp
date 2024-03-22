#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    string mainInput;
    cout << "Input: ";
    getline(cin, mainInput);
    
    stringstream extractor(mainInput);
    string word;
    vector<string> inputs;
    vector<int> inputCharCount;
    
    while(extractor >> word)
    {
        inputs.push_back(word);
        int charCount = word.length();
        inputCharCount.push_back(charCount);
    }
    
    for(int i = 0; i < inputs.size(); i++)
    {
        for(int j = 0; j < inputs.size(); j++)
        {
            if(inputCharCount[i] < inputCharCount[j])
            {
                int temp = inputCharCount[i];
                inputCharCount[i] = inputCharCount[j];
                inputCharCount[j] = temp;
                
                string temp2 = inputs[i];
                inputs[i] = inputs[j];
                inputs[j] = temp2;
            }
        }
    }
    
    cout << "\nOutput: ";
    for(string s : inputs)
    {
        cout << s << " ";
    }
    cout << "\n";
    
    return 0;
}