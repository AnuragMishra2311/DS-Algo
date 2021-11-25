/*

https://leetcode.com/problems/integer-break/

Time complexity : O(N*N)
Spcae Complexity : O(N*N)

Consider the problem as subset sum, where we want to get a target sum using the array having numbers [1....n].

There is no point in breaking the number as (n,0) as this will result in pdt of 0. 
So the maximum number that we can have in our split is (n -1 ).

We have 2 options, either to include n in our sum or exclude it, if including we can again include it thats's why 
while including the function is called again for n. 
And if we are excluding n from our sum, then the function is called for (n - 1).  

*/
 
 int integerBreak(int n)
    {
        int dp[59][59];
        memset(dp, -1, sizeof(dp));
        return func(n, n-1, dp);
    }
    
    int func(int target, int n, int dp[][59]) 
    {
        if(n == 0 or target == 0)
            return dp[n][target] = 1;
        
        if (dp[n][target] != -1 )   
            return dp[n][target];

        // if target >= n that means, we can include n to get the target.
        if(target >= n)
            return dp[n][target] = max(n*func(target - n, n, dp), func(target, n - 1, dp));
            
        else // if n > target, then we can't include n in our sum. call for n - 1.
            return dp[n][target] = func(target, n - 1, dp);
    }