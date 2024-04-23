// LeetCode Problem 3 : https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include <iostream>

using namespace std;

class Solution
{
    public:

        int lengthOfLongestSubstring(string s)
        {
            int highestStringLength = 0;
            string temp = "";
            bool matchFound;
            
            for(int i = 0; i < s.length(); )
            {
                matchFound = false;
                for(int j = 0; j < temp.length() && !matchFound; j++)
                {
                    for(int k = 0; k < temp.length() && j != k && !matchFound; k++)
                    {
                        if(temp[j] == temp[k])
                        {
                            matchFound = true;
                        }
                    }
                }
                
                if(matchFound)
                {
                    string temp2 = "";
                    for(int j = 1; j < temp.length(); j++)
                    {
                        temp2 += temp[j];
                    }
                    temp = temp2;
                }
                else
                {
                    for(int j = 0; j < temp.length(); j++)
                    {
                        if(temp[j] == s[i])
                        {
                            matchFound = true;
                            break;
                        }
                    }
                    
                    if(matchFound)
                    {
                        string temp2 = "";
                        for(int j = 1; j < temp.length(); j++)
                        {
                            temp2 += temp[j];
                        }
                        temp = temp2;
                    }
                    else
                    {
                        temp += s[i];
                        highestStringLength = (temp.length() > highestStringLength) ? temp.length() : highestStringLength;
                        i++;
                    }
                }
            }
            
            return highestStringLength;
        }
};

int main()
{
    string input;
    cout << "Enter string: ";
    getline(cin, input);
    Solution solution;
    int longestnonrepeatingsubstring = solution.lengthOfLongestSubstring(input);
    cout << "Output: " << longestnonrepeatingsubstring;

    return 0;
}