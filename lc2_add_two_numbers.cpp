// LeetCode Problem 2 : https://leetcode.com/problems/add-two-numbers/description/

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

class Solution
{
    public:
       
        void insertValues(int val, ListNode *&tempList)
        {
            ListNode *newNode = new ListNode;
            newNode->val = val;
            newNode->next = nullptr;
            
            if(tempList == nullptr)
            {
                tempList = newNode;
                return;
            }
            
            ListNode *current = tempList;
            while(current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
        
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
        {
            ListNode *result = nullptr;
            ListNode *highest = nullptr;
            ListNode *lowest = nullptr;
            ListNode *l1Backup = l1;
            ListNode *l2Backup = l2;
            int excess = 0, l1Nodes = 0, l2Nodes = 0;
            
            while(l1 != nullptr)
            {
                l1Nodes++;
                l1 = l1->next;
            }
            
            while(l2 != nullptr)
            {
                l2Nodes++;
                l2 = l2->next;
            }
            
            highest = (l1Nodes > l2Nodes) ? l1Backup : l2Backup;
            lowest = (l1Nodes <= l2Nodes) ? l1Backup : l2Backup;
            
            while(highest != nullptr)
            {
                if(lowest != nullptr)
                {
                    int output = highest->val + lowest->val + ((excess > 0) ? (excess--) : (excess));
                    if(output >= 10)
                    {
                        output -= 10;
                        excess++;
                    }
                    insertValues(output, result);
                    lowest = lowest->next;
                }
                else
                {
                    int output = highest->val + ((excess > 0) ? (excess--) : (excess));
                    if(output >= 10)
                    {
                        output -= 10;
                        excess++;
                    }
                    insertValues(output, result);
                }
                highest = highest->next;
            }
            
            if(excess > 0)
            {
                insertValues(excess, result);
            }
            
            return result;
        }
};

int main()
{
    ListNode *l1 = nullptr;
    ListNode *l2 = nullptr;
    ListNode *sum = nullptr;
    Solution solution;
    string input;
    
    cout << "\nEnter 1st set of digits:\n\n>> ";
    getline(cin, input);
    for(int i = 0; i < input.length(); i++)
    {
        if(isdigit(input[i]))
        {
            solution.insertValues((input[i] - '0'), l1);
        }
    }
    
    cout << "\nEnter 2nd set of digits:\n\n>> ";
    getline(cin, input);
    for(int i = 0; i < input.length(); i++)
    {
        if(isdigit(input[i]))
        {
            solution.insertValues((input[i] - '0'), l2);
        }
    }
    
    sum = solution.addTwoNumbers(l1, l2);
    
    cout << "\nSum of all sets:\n\n>> ";
    while(sum != nullptr)
    {
        cout << sum->val << " ";
        sum = sum->next;
    }
    cout << "\n";
    
    return 0;
}