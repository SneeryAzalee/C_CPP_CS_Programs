#include <iostream>
#include <vector>

using namespace std;

// LeetCode Problem: https://leetcode.com/problems/two-sum/description/

class Solution
{
    public:
    
        vector<int> twoSum(vector<int>& nums, int target)
        {
            int index = 0, inputs[nums.size()], toggle = 0;
            vector<int> result;
            
            for(int i : nums)
            {
                inputs[index++] = i;
            }
            
            for(int i = 0; i < nums.size() && toggle == 0; i++)
            {
                for(int j = 0; j < nums.size(); j++)
                {
                    if(inputs[i] + inputs[j] == target && i != j)
                    {
                        result.push_back(i);
                        result.push_back(j);
                        toggle = 1;
                        break;
                    }
                }
            }
            
            cout << "Index: [ ";
            for(int i : result)
            {
                cout << i << " ";
            }
            cout << "]\n\n";
            
            return result;
        }
};

int main()
{
    int input_count, target;
    Solution input;
    
    cout << "Enter number of inputs: ";
    cin >> input_count;
    cout << "Enter target number: ";
    cin >> target;
    cout << "\nInput/s: ";
    
    vector<int> nums;
    
    for(int i = 0; i < input_count; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    
    cout << "\n";
    
    input.twoSum(nums, target);
    
    
    return 0;
}