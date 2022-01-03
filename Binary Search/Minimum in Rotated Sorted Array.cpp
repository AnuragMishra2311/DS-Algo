/*

https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

*/


class Solution 
{
    public:
    int findMin(vector<int>& nums) 
    {
        int low = 0;
        int high = nums.size() - 1;
        int minElement = INT_MAX;
        
        while(high >= low)
        {
            int mid = low + (high - low)/2;
            
            //minElement = min(minElement, arr[mid]);
            
            // if first half is sorted, then minimum will be nums[low].
            if(nums[mid] >= nums[low])
            {
                minElement = min(minElement, nums[low]);
                low = mid + 1;
            }
            
            // second half sorted, then minimum will be nums[mid].
            else
            {
                minElement = min(minElement, nums[mid]);
                high = mid - 1;
            }
        }
        
        return minElement;
    }
};