// https://leetcode.com/problems/move-zeroes/

/*

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Move all 0's to end = Move all non zero elements to front.

Time Complexity : O(N)
Space Complexity : O(1)

*/

void moveZeroes(vector<int>& nums) 
    {
        int low = 0, n = nums.size(), i=0;
        while(i<n)
        {
            if(nums[i]!=0)
            {
                swap(nums[i],nums[low]);
                low++;
            }
            i++; 
        }
    }