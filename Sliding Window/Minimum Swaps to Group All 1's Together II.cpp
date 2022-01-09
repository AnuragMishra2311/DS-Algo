/*

https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

Approach : count no of 1s in nums, let it be k. Now for every subarray of size k, 
           No of zeros in that subarray = no of swaps required.


Time Complexity : O(N)
Space Complexity : O(1)

*/

class Solution {
public:
    int minSwaps(vector<int>& nums) 
    {
        int n = nums.size();
        int k = count(nums.begin(), nums.end(), 1);
        int countZero = count(nums.begin(), nums.begin() + k, 0);
        int minimum = countZero;
        
        for(int i = 0; i < 2*n - k; i++)
        {
            if(nums[i % n] == 0)
                countZero -= 1;
            
            if(nums[(i + k) % n] == 0)
                countZero += 1;
            
            minimum = min(minimum, countZero);
        }
        
        return minimum;
    }
};