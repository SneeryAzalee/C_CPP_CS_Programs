//Problem: Longest Common Prefix

//Write a function longestCommonPrefix that takes an array of strings as input and returns the longest common prefix of all strings in the array. If there is no common prefix, return an empty string "".

//For example:

//Input: ["flower", "flow", "flight"]
//Output: "fl"
//Input: ["dog", "racecar", "car"]
//Output: ""
//Implement the longestCommonPrefix function in C++.


#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int char_count(string inputs)
{
    int char_count = 0;
    for(char c : inputs)
    {
        char_count++;
    }
    return char_count;
}

string longestCommonPrefix(vector<string> inputs, int input_count)
{
    int shortest_char_count;
    for(int i = 0; i < input_count; i++)
    {
        if(i == 0)
        {
            shortest_char_count = char_count(inputs[i]);
        }
        else
        {
            int count = char_count(inputs[i]);
            if(count < shortest_char_count)
            {
                shortest_char_count = count;
            }
        }
    }
    
    string common_prefix = "";
    for(int i = 0; i < shortest_char_count; i++)
    {
        char c = inputs[0][i];
        int count = 1;
        
        for(int j = 1; j < input_count; j++)
        {
            if(c == inputs[j][i])
            {
                count++;
            }
        }
        
        if(count == input_count)
        {
            common_prefix += c;
        }
    }
    
    return common_prefix;
}

int main()
{
    string main_input;
    cout << "\nInput: ";
    getline(cin, main_input);
    
    stringstream extractor(main_input);
    string word;
    int input_count = 0;
    vector<string> inputs;
    
    while(extractor >> word)
    {
        input_count++;
        inputs.push_back(word);
    }
    
    cout << "\nOutput: " << longestCommonPrefix(inputs, input_count) << "\n";
    
    return 0;
}