/*
 *  LeetCode Problem: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
 */

#include <iostream>
#include <stack>

using namespace std;

class Solution
{
    public:

        int minSwaps(string s)
        {
            stack<char> stack;
            int unbalancedCount = 0;

            for(int i = 0; i < s.size(); i++)
            {
                char c = s[i];
                if(c == '[')
                {
                    stack.push(c);
                }
                else if(c == ']')
                {
                    if(stack.empty())
                    {
                        unbalancedCount++;
                    }
                    else
                    {
                        stack.pop();
                    }
                }
            }

            return (unbalancedCount + 1) / 2;
        }
};

int main()
{
    Solution solution;

    string input;
    cout << "\nInput: ";
    getline(cin,input);

    int result = solution.minSwaps(input);

    cout << "\nMinimum swap count/s to balance: " << result << "\n";

    return 0;
}