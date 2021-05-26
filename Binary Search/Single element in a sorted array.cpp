/*

https://leetcode.com/problems/single-element-in-a-sorted-array/

Logic: how can we use binary search ?

If mid is even then arr[mid-1] shld != arr[mid], if it is equal than we have single element in lower half, otherwise upper half.

If mid is odd then arr[mid] shld be equal to arr[mid-1], if arr[mid]!=arr[mid-1], then we have single element in lower half otherwise in upper half.

*/



int singleNonDuplicate(vector<int>& nums) 
    {
        
        int n= nums.size();
        int high=n-1,low=0,mid,ans;
       
        while(high>=low)
        {
             mid=low+ ( (high-low)/2);
            if( mid==0 || mid==n-1 || ( nums[mid-1]!=nums[mid] && nums[mid+1]!=nums[mid] ) )
            {
                ans= nums[mid];
                break;
            }
            
            if(mid%2==0)
            {
                if(nums[mid-1]==nums[mid])
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            
            else
            {
                if(nums[mid-1]!=nums[mid])
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
        }
        
        return ans;
 }