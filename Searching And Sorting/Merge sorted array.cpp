/*

https://leetcode.com/problems/merge-sorted-array/

Time complexity : O(N)
Space complexity : O(1)

*/

class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int i = m - 1;
        int j = n - 1;
        int position = m + n - 1; 
        
        while ( i >= 0 and j >= 0 )
        {
            if(nums1[i] > nums2[j])
                nums1[position--] = nums1[i--];
            
            else
                nums1[position--] = nums2[j--];
        }
        
        while( i >= 0)
            nums1[position--] = nums1[i--];
        
        while(j >= 0)
            nums1[position--] = nums2[j--];
    }
};