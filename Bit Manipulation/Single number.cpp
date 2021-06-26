/*
https://leetcode.com/problems/single-number/

a^a = 0, so at the end we will be left only with unique element.

Time Complexity : O(N)
Space Complexity : O(1)

*/
    
    int singleNumber(vector<int>& nums) 
    {
        int ans=0;
        for(int i=0; i<nums.size(); i++)
        {
            ans = ans^nums[i];
        }
        
        return ans;
    }