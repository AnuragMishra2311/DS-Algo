// https://practice.geeksforgeeks.org/problems/cutted-segments1642/1#

int solve(int n, int x, int y, int z, int dp[])
{
        if(n==0)
            return 0;
 
        if(dp[n]!=-1) 
            return dp[n];
            
        int t1=INT_MIN,t2=INT_MIN,t3=INT_MIN;
        
        if(n>=x)
        {
            t1 = solve(n-x,x,y,z,dp);
        }
        if(n>=y)
        {
            t2 = solve(n-y,x,y,z, dp);
        }
        
        if(n>=z)
        {
            t3 = solve(n-z,x,y,z,dp);
        }
            
        return dp[n]= 1 + max(t1,max(t2,t3));
}

int maximizeTheCuts(int n, int x, int y, int z)
{   
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    return solve(n,x,y,z,dp);
}