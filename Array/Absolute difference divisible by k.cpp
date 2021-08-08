/*

https://www.geeksforgeeks.org/count-pairs-in-an-array-whose-absolute-difference-is-divisible-by-k/

Intuition: Absolute difference of two numbers(a , b) will be divisible by k, if and only if a%k == b%k.

Space Complexity : O(K)
Time Complexity : O(N)

*/
    
    long long countPairs(int n, int arr[], int k) 
    {
        unordered_map<long, long>mp;
        long long count = 0;
        
        for(int i=0; i<n; i++)
        {
            mp[arr[i]%k]++;
        }
        
        for(int i=0; i<n; i++)
        {
            count += mp[arr[i]%k] - 1;
        }
        
        return ceil((double)count/2);
    }


