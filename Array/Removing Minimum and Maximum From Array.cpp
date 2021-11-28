/*

https://leetcode.com/problems/removing-minimum-and-maximum-from-array/

Time Complexity : O(N)
Space Complexity : O(1)

Approach : We have 3 options
           1. Delete both the elements from start.
           2. Delete both elements from end. 
           3. Delete one from start and another from end.

*/

class Solution {
public:
    int minimumDeletions(vector<int>& nums) 
    {
        int min_index, max_index, min_element = INT_MAX, max_element = INT_MIN;
        for(int index = 0; index < nums.size(); index++)
        {
            if(nums[index] > max_element)
            {
                max_element = nums[index];
                max_index = index;
            }
            
            if(nums[index] < min_element)
            {
                min_element = nums[index];
                min_index = index;
            }
        }
        
        int option1 = max(min_index, max_index) + 1;
        int option2 = nums.size() - min(min_index, max_index);
        int option3 = min(min_index, max_index) + 1 + nums.size() - max(min_index, max_index);

        return min(option1, min(option2, option3));
    }
};