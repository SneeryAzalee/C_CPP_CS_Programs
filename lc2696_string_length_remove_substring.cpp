/*
 *  LeetCode Problem: https://leetcode.com/problems/minimum-string-length-after-removing-substrings/?envType=daily-question&envId=2024-10-07
 */

#include <iostream>

using namespace std;

class Solution
{
    public:

        int minLength(string s)
        {
            while(s.find("AB") != -1 || s.find("CD") != -1)
            {
                if(s.find("AB") != -1)
                {
                    s.erase(s.find("AB"), 2);
                }
                else if(s.find("CD") != -1)
                {
                    s.erase(s.find("CD"), 2);
                }
            }

            return s.length();
        }
};

int main()
{
    string s;
    cout << "\nEnter string: ";
    getline(cin, s);

    Solution solution;
    cout << "\nMinimum length of string is: " << solution.minLength(s) << "\n";

    return 0;
}