#include <iostream>
#include <vector>

using namespace std;

// LeetCode Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

class Solution
{
    public:
    
        int removeDuplicates(vector<int> &nums)
        {
            int value, size = nums.size();
            vector<int> result;
            
            for(int i = 0; i < size; i++)
            {
                value = nums[i];
                if(value != -101)
                {
                    for(int j = i + 1; j < size; j++)
                    {
                        if(value == nums[j])
                        {
                            nums[j] = -101;
                        }
                    }
                    result.push_back(value);
                }
            }
            
            int k = result.size(), index = 0;
            
            for(int i = 0; i < k; i++)
            {
                nums[index++] = result[i];
            }
            
            return k;
        }
};

int main()
{
    vector<int> nums;
    Solution answer;
    int input_count;
    cout << "Enter number of inputs: ";
    cin >> input_count;
    
    for(int i = 1; i <= input_count; i++)
    {
        cout << i << ". ";
        int x;
        cin >> x;
        nums.push_back(x);
    }
    
    answer.removeDuplicates(nums);
    
    return 0;
}