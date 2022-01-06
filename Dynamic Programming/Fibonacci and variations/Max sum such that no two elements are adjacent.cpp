/*

https://www.hackerrank.com/challenges/max-array-sum/problem

Time Complexity : O(N)
Space Complexity : O(N), can be reduced to O(1) easily.

*/

int maxSubsetSum(vector<int> arr) 
{
    int n = arr.size();
    int dp[n];
    dp[0] = max(0, arr[0]);
    dp[1] = max(dp[0], arr[1]);
    
    for(int i = 2; i < n; i++)
    {
        dp[i] = max({dp[i - 2] + arr[i], arr[i], dp[i - 1]});
    }
    
    return dp[n - 1];
}