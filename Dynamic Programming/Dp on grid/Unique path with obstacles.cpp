 // https://leetcode.com/problems/unique-paths-ii/
 
 
 
 int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        int mat[m][n];
        memset(mat,0,sizeof(mat));
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                // for [0,0] element
                if( i==0 and j==0 and obstacleGrid[i][j]==0 )
                {
                    mat[i][j] = 1;  //mat[0][0]
                }
                
                // Initializing first row
                else if(i==0 and j!=0 and obstacleGrid[i][j]==0 )
                {
                    mat[i][j] = mat[i][j-1];
                }
                
                
                // Initializing firsst coloumn
                else if(i!=0 and j==0 and obstacleGrid[i][j]==0 )
                {
                    mat[i][j] = mat[i-1][j];
                }
                
                
                // for rest of grid
                if(obstacleGrid[i][j]!=1 and i!=0 and j!=0)
                    mat[i][j] = mat[i-1][j] + mat[i][j-1];
                
            }
        }
        return mat[m-1][n-1]; 
    }