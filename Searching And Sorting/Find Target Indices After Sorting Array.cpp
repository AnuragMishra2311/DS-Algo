/*

https://leetcode.com/problems/find-target-indices-after-sorting-array/

Time Complexity : O(N)
Space Complexity : O(1)

Approach : The position of target in sorted array depends on the number of elemenst smaller than target in array, 
           and the number of times target is present in array. 

*/

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) 
    {
        vector<int>ans;
        int count = 0, position = 0;
        for(auto element : nums)
        {
            if (element == target)
                count += 1;
            if (element < target)
                position += 1;
        }
        
        while(count--)
        {
            ans.push_back(position++);
        }
        
        return ans;
    }
};