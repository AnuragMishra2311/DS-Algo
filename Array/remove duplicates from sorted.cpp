/*

https://leetcode.com/problems/remove-duplicates-from-sorted-array/

*/

int removeDuplicates(vector<int>& nums) 
    {
        if(nums.size()<=1)
        {
            return nums.size();
        }
        
        int n = nums.size();
        int j = 1;
        for(int i=0; i<n-1; i++)
        {
            if(nums[i]!=nums[i+1])
            {
                nums[j] = nums[i+1];
                j++;
            }
        }
        return j;
    }