/*

https://leetcode.com/problems/search-insert-position/

Time Complexity : O(log N)
Space Complexity : O(1)

*/
 
 int searchInsert(vector<int>& nums, int target) 
    {
        int low = 0, high = nums.size() - 1;
        while(high >= low)
        {
            int mid = low + (high - low)/2;
            
            if(nums[mid] == target)
                return mid;
            
            nums[mid] > target ? high = mid - 1 : low = mid + 1;
        }
        
        return low;
    }