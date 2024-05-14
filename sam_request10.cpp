/*
    Anagram groups

    Input string:

        nat tan ant eat tea ate hello

    Output:

        1. nat tan ant
        2. ate tea eat
        3. hello

    Group anagram words, if theres a word thats not an anagram then separate it as well.
*/

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Sneery
{
public:

    string mainInput;
    vector<string> inputs, uniqueInputs;

    void setInput()
    {
        cout << "Input string:\n\n>> ";
        getline(cin, mainInput);
        stringstream extractor(mainInput);
        string temp;
        while(extractor >> temp)
        {
            inputs.push_back(temp);
        }
        uniqueInputs.push_back(inputs[0]);
    }

    void getResult()
    {
        int uniqueCount = 0;
        bool showNum = true;
        cout << "\nOutput:\n";
        for(int i = 0; i < uniqueInputs.size(); i++)
        {
            for(int j = 0; j < inputs.size(); j++)
            {
                string s1 = uniqueInputs[i];
                string s2 = inputs[j];
                if(s2.length() == s1.length() && s2 != "§")
                {
                    int charCount = 0;
                    for(int k = 0; k < s1.length(); k++)
                    {
                        for(int l = 0; l < s2.length(); l++)
                        {
                            if(s2[l] == s1[k] && s2[l] != '\a')
                            {
                                charCount++;
                                s2[l] = '\a';
                                break;
                            }
                        }
                    }
                    if(charCount == s1.length())
                    {
                        if(showNum)
                        {
                            cout << "\n" << ++uniqueCount << ". ";
                            showNum = false;
                        }
                        cout << inputs[j] << " ";
                        inputs[j] = "§";
                    }
                    else
                    {
                        bool repetitionFound = false;
                        for(int k = 0; k < uniqueInputs.size(); k++)
                        {
                            if(s2 == uniqueInputs[k])
                            {
                                repetitionFound = true;
                            }
                        }
                        if(!repetitionFound)
                        {
                            uniqueInputs.push_back(s2);
                        }
                    }
                }
                else
                {
                    if(s2 != "§")
                    {
                        bool repetitionFound = false;
                        for(int k = 0; k < uniqueInputs.size(); k++)
                        {
                            if(s2 == uniqueInputs[k])
                            {
                                repetitionFound = true;
                            }
                        }
                        if(!repetitionFound)
                        {
                            uniqueInputs.push_back(s2);
                        }
                    }
                }
            }
            showNum = true;
        }
        cout << "\n";
    }
};

int main()
{
    Sneery sneery;
    sneery.setInput();
    sneery.getResult();

    return 0;
}