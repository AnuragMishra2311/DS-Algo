/* 

https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1#

Time Complexity : O(N*M)
Space complexity : O(N*M)

Important: Do coloumn wise traversal.

*/


bool check(int i, int j, int n, int m)
{
    if(i<0 or j<0 or i>=n or j>=m)
        return false;
    return true;
}

int maxGold(int n, int m, vector<vector<int>> grid)
    {
        vector<vector<int>>dp(n,vector<int>(m,0));

        // Initialize
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(j==0)
                    dp[i][j] = grid[i][j];
            }
        }
        
        // Coordinates of 3 directions
        int di[] = {0,-1,1};
        int dj[] = {-1,-1,-1};
        
        // Note: Do coloumn wise traversal.
        for(int j=1; j<m; j++)
        {
            for(int i=0; i<n; i++)
            {
                int maximum = 0;
                for(int k=0; k<3; k++)
                {
                    int ni = i+di[k];
                    int nj = j+dj[k];
                    if(check(ni,nj,n,m))
                    {
                        maximum = max(maximum, dp[ni][nj]);
                    }
                }
               dp[i][j] = maximum+grid[i][j];
            }
        }

        // Traverse through last coloumn and find max.
        int ans =0;
        for(int i=0; i<n; i++)
        {
            ans = max(ans, dp[i][m-1]);
        }
        return ans;
    }