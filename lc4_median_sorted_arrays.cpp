// LeetCode Problem 4 : https://leetcode.com/problems/median-of-two-sorted-arrays/description/

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution
{
    public:
      
        double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
        {
            double result = -1.0;
            vector<int> combined;
            
            for(int i : nums1)
            {
                combined.push_back(i);
            }
            for(int i : nums2)
            {
                combined.push_back(i);
            }
            
            for(int i = 0; i < combined.size(); i++)
            {
                for(int j = 0; j < combined.size(); j++)
                {
                    if(combined[i] < combined[j])
                    {
                        int temp = combined[i];
                        combined[i] = combined[j];
                        combined[j] = temp;
                    }
                }
            }
            
            int midElement = combined.size() / 2.0;
            if(combined.size() % 2 == 0)
            {
                result = (combined[midElement - 1] + combined[midElement]) / 2.0;
            }
            else
            {
                result = combined[midElement];
            }
            
            return result;
        }
};

int main()
{
    vector<int> nums1, nums2;
    int numTemp;
    string firstInput, secondInput;
    stringstream extractor;
    Solution solution;
    double output;
    
    cout << "\nEnter 1st set integers:\n\n>> ";
    getline(cin, firstInput);
    cout << "\nEnter 2nd set integers:\n\n>> ";
    getline(cin, secondInput);
    
    extractor.clear();
    extractor.str(firstInput);
    while(extractor >> numTemp)
    {
        nums1.push_back(numTemp);
    }
    extractor.clear();
    extractor.str(secondInput);
    while(extractor >> numTemp)
    {
        nums2.push_back(numTemp);
    }
    
    output = solution.findMedianSortedArrays(nums1, nums2);
    cout << "\nMedian:\n\n>> " << output << "\n\n";

    return 0;
}