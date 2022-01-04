/*

https://practice.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/1#

Approach : Replace 0 with 1 and then find the no of subarray with sum = 0 using prefix sum method.

Time Complexity : O(N)
Space Complexity : O(N)

*/

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {

        unordered_map<int,int>mp;
        int sum = 0;
        long long int count = 0;

        // replace 0 with -1.
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == 0)
                arr[i] = -1;
        }
        

        // Count no of subarray with sum = 0
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];

            if(sum == 0)
                count += 1;

            count += mp[sum];
            mp[sum] += 1;
        }
        
        return count;
    }
};