#include <iostream>

using namespace std;

// LeetCode Problem: https://leetcode.com/problems/add-two-numbers/description/

struct ListNode
{
    int val;
    ListNode *next;
};


class Solution
{
    public:
    
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
        {
            int digit1, digit2, carry = 0;
            ListNode *result = nullptr, *selector = nullptr;
            
            while(l1 &&)
            {
                
            }
            
            cout << "\n\nResult: ";
            selector = result;
            while(selector)
            {
                cout << selector->val;
                selector = selector->next;
            }
            cout << "\n\n";
            
            
            return result;
        }
};


int main()
{
    int input_count, input;
    
    ListNode *l1 = nullptr;
    ListNode *selector = nullptr;
    
    Solution linkedlists;
    
    cout << "Enter number of inputs for L1: ";
    cin >> input_count;
    cout << "\nL1: ";
    
    for(int i = 0; i < input_count; i++)
    {
        cin >> input;
        
        ListNode *new_node = new ListNode;
        new_node->val = input;
        new_node->next = nullptr;
        
        if(!l1)
        {
            l1 = new_node;
            selector = new_node;
        }
        else
        {
            selector->next = new_node;
            selector = new_node;
        }
    }
    
    cout << "\n\n";
    
    ListNode *l2 = nullptr;
    selector = nullptr;
    
    cout << "Enter number of inputs for L2: ";
    cin >> input_count;
    cout << "\nL2: ";
    
    for(int i = 0; i < input_count; i++)
    {
        cin >> input;
        
        ListNode *new_node = new ListNode;
        new_node->val = input;
        new_node->next = nullptr;
        
        if(!l2)
        {
            l2 = new_node;
            selector = new_node;
        }
        else
        {
            selector->next = new_node;
            selector = new_node;
        }
    }
    
    linkedlists.addTwoNumbers(l1, l2);
    
    
    return 0;
}