// https://practice.geeksforgeeks.org/problems/maximum-sum-problem2211/1/

// Memoization

int f(int n, int dp[])
{
    if(n<=0) return 0;
    
    if(dp[n]!=-1) return dp[n];
    
    return dp[n] = max(n, f(n/2, dp) + f(n/3, dp) + f(n/4, dp));
}


int maxSum(int n)
{   
    int dp[n+1];
    memset(dp, -1, sizeof(dp));            
    return f(n, dp);
}

// Tabulation

int maxSum(int n)
{
    int dp[n+1];
    dp[0] = 0;

    for(int i=1; i<=n; i++)
    {
        dp[i] = max(i, dp[i/2] + dp[i/3] + dp[i/4]);
    }    

    return dp[n];
}