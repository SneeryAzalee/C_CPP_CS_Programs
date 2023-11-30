#include <stdio.h>
#include <stdlib.h>

// LeetCode Problem: https://leetcode.com/problems/remove-element/description/

int removeElement(int* nums, int numsSize, int val)
{
    int modifiers[numsSize + 1], k = 0;
    
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] != val)
        {
            modifiers[k] = nums[i];
            k++;
        }
    }
    
    for(int i = 0; i < k; i++)
    {
        nums[i] = modifiers[i];
    }
    
    
    // Output
    printf("\nArray = ");
    for(int i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\nNumber of exceptions: %d\n", k);
    
    
    
    return k;
}


int main()
{
    int numsSize;
    printf("Enter how many inputs: ");
    scanf("%d", &numsSize);
    int nums[numsSize + 1];
    printf("Inputs: ");
    
    for(int i = 0; i < numsSize; i++)
    {
        scanf("%d", &nums[i]);
    }
    
    int val;
    printf("Exclude number: ");
    scanf("%d", &val);
    
    
    removeElement(nums, numsSize, val);
    
    
    return 0;
}