// https://leetcode.com/problems/unique-paths/

int uniquePaths(int m, int n) 
    {
        int mat[m][n];
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 || j==0)
                    mat[i][j] = 1;
            }
        }
        
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                mat[i][j] = mat[i-1][j] + mat[i][j-1];
            }
        }
        
        return mat[m-1][n-1];
    }