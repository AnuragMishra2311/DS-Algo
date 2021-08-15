// https://leetcode.com/problems/minimum-path-sum/


// Memoization

int solve(vector<vector<int>>mat, int m,int n,int i,int j,int dp[][201])
{
    if(i>=m or j>=n)
    {
        return INT_MAX;
    }
    
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    
    if (i==m-1 and j==n-1)
    {
        return dp[i][j] = mat[i][j];
    }
    
    return dp[i][j] = mat[i][j] + min(solve(mat,m,n,i+1,j,dp),solve(mat,m,n,i,j+1,dp));

}

    int minPathSum(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int coloumn = grid[0].size();
        int dp[201][201];
        memset(dp,-1,sizeof(dp));
        return solve(grid,row,coloumn,0,0,dp);
    } 
 
 

 /* Tabulation

I/P:                                
 1 3 1 
 1 5 1
 4 2 1

DP matrix:   

for first row and coloumn, dp[i][j] will be grid[i][j] + dp[previous element]
 1 4 5
 2 7 6
 6 8 7


*/
 int minPathSum(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int coloumn = grid[0].size();
        int dp[row][coloumn];
        dp[0][0] = grid[0][0];
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<coloumn;j++)
            {

                // Initializing first row.
                if(i==0 and j!=0)
                {
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                }
                
                // Initializing first coloumn.
                if(j==0 and i!=0)
                {
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                }
            }
        }
        
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<coloumn;j++)
            {
                dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);  // min of up an left.
            }
        }
        
        return dp[row-1][coloumn-1];
        
    
    }