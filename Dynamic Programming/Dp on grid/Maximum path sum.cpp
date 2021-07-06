/*

https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1#

We can reach grid[i][j] from grid[i-1][j] or grid[i-1][j-1] or grid[i-1][j+1]

*/


bool check(int i, int j, int n)
{
    if(i<0 or j<0 or i>=n or j>=n)
        return false;
    return true;
}

int maximumPath(int N, vector<vector<int>> grid)
{   
    int dp[N][N]; 
    memset(dp,0,sizeof(dp));

    // Initialize dp
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(i==0)
            {
                dp[i][j] = grid[i][j];
                ans = max(ans,dp[i][j]);
            }
        }
    }
    
    // possible cordinates
    int di[] = {-1, -1, -1};
    int dj[] = {0, -1, 1};
    int ans = 0;

    for(int i=1; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            int ops = 0;
            for(int k=0; k<3; k++)
            {
                int ni = i + di[k];
                int nj = j + dj[k];
                if(check(ni, nj, N))
                {
                    ops = max(ops, dp[ni][nj] + grid[i][j]);
                }
            }
            
            dp[i][j] = ops;
            ans = max(dp[i][j],ans);
        }
    }
    return ans;  
}