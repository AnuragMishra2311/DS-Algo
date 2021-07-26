// https://practice.geeksforgeeks.org/problems/pairs-which-are-divisible-by-41920/1#

/*

Approach : Create a hashmap of arr[i]%k. 
a+b is divisible by k, then 
a%k + b%k = either k or 0.

If a=arr[i]%k, then we must add arr[i] with elements whose mod k = k-a 

Time Complexity: O(N)
Space Complexity : O(K)

*/



int count4Divisibiles(int arr[], int n)
    {
        int k = 4;
        unordered_map<int,int>mp;
        double ans = 0;
        for(int i=0; i<n; i++)
        {
            mp[arr[i]%k]++;
        }
        
        for(int i=0; i<n; i++)
        {
            // if arr[i] is divisible by k or arr[i]%k = k/2 then don't count that number.
            if(arr[i]%k == 0 or (k%2 ==0 and arr[i]%k == k/2))
            {
                ans+=mp[arr[i]%k]-1;
            }
            else
            {
                ans+=mp[k-arr[i]%k];
            }
        }
        return ceil(ans/2);
    }