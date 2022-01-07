/*

https://leetcode.com/problems/squares-of-a-sorted-array/

Time complexity : O(N)
Space complexity : O(1)

*/

class Solution 
{
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        int position = n - 1;
        vector<int>result(n);
        
        while(i <= j)
        {
            if(abs(nums[i]) > abs(nums[j]))
            {
                result[position--] = nums[i]*nums[i];
                i += 1;
            }
            
            else
            {
                result[position--] = nums[j]*nums[j];
                j -= 1;
            }
        }
        
        return result;
    }
};