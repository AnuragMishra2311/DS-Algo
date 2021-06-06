/*

https://leetcode.com/problems/edit-distance/

Time complexity O(N*M)
Space Complexity O(N*M)

*/

// Iterative

int minDistance(string word1, string word2) 
    {
        
        int m=word1.size(),n=word2.size();
        int dp[m+1][n+1];

        // Initialization 
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0)
                {
                    dp[i][j] = j;
                }
                
                else if(j==0)
                {
                    dp[i][j] = i;
                }
            }
        }
        


        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(word1[i-1]==word2[j-1]) // If corresponding characters are same
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])); // 1. Insert 2. Delete  3.Update 
            }
        }
        
        return dp[m][n];
    }



// Recursive

int solve(string s, string t, int m, int n, int dp[][501])
{
    if(n==0)
    {
        return m;
    }
    if(m==0)
    {
        return n;
    }
    
    if(dp[m][n]!=-1)
    {
        return dp[m][n];
    }
    
    if(s[m-1]==t[n-1])
    {
        dp[m][n] = solve(s,t,m-1,n-1,dp);
    }
    else
    {
        dp[m][n] = 1 + min( min(solve(s,t,m-1,n-1,dp),solve(s,t,m-1,n,dp)) , solve(s,t,m,n-1,dp) );
    }
    
    return dp[m][n];
}



    int minDistance(string word1, string word2) 
    {
        int dp[501][501];
        memset(dp,-1,sizeof(dp));
        return solve(word1,word2,word1.size(),word2.size(),dp);
    }