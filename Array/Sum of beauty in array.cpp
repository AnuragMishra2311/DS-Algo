 /*
 
https://leetcode.com/problems/sum-of-beauty-in-the-array/

You are given a 0-indexed integer array nums. For each index i (1 <= i <= nums.length - 2) the beauty of nums[i] equals:

2, if nums[j] < nums[i] < nums[k], for all 0 <= j < i and for all i < k <= nums.length - 1.
1, if nums[i - 1] < nums[i] < nums[i + 1], and the previous condition is not satisfied.
0, if none of the previous conditions holds.
Return the sum of beauty of all nums[i] where 1 <= i <= nums.length - 2.
 
 
 Idea :  If an element is greater than max of elements present in it's left side, then it is also greater than all elemnts to it's left. 
         Similarly, if an element is smaller than miniimum element to it's right side, then it is also smaller than all elements to it's right side.
 
 Approach : Maintain 2 array, left and right to store max and min elements respectively. 
 
 Example : 
 array  = [1, 6, 10, 5,  4, 15]
 
 left =   [x, 1, 6,  10, 10, x], max to it's left
 right =  [x, 4, 4,  4,  15, x], min to it's right
 
 Now check for the condition. 
 
 Time Complexity : O(N)
 Space Complexity : O(N)
 
 */

int sumOfBeauties(vector<int>& nums) 
    {
        int n = nums.size();
        int current_max = INT_MIN;
        int current_min = INT_MAX;
        int result = 0;
        
        vector<int>left(n);        
        vector<int>right(n);
        
        // Left array
        for(int i = 1; i < n; i++)
        {
            if(nums[i-1] > current_max)
                current_max = nums[i-1];
            
            left[i] = current_max;
        }
        
  
        // Right array
        for(int i=n-2; i > 0; i--)
        {
            if(current_min > nums[i+1])
                current_min = nums[i+1];
            
            right[i] = current_min;
        }
        
        // Check for the condition and accordingly increment beauty value.
        for(int i = 1; i <= n-2; i++)
        {
            if(nums[i] > left[i] and nums[i] < right[i])
                result += 2;
            
            else if (nums[i-1] < nums[i] and nums[i] < nums[i+1])
                result += 1;
        }
        
        return result;
    }
