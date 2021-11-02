/*

https://leetcode.com/problems/surrounded-regions/

Approach : Mark all zeroes accessible from border with some temp variable (Z), all remaining zeros are surrounded by X. 

Time Complexity : O(M*N)
Space Complexity : O(1)

*/


 bool out_of_bound(int i, int j, int m, int n)
    {
        if(i < 0 or j < 0 or i >= m or j >= n)
            return true;
        
        return false;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, int m, int n)
    {
          
        if(out_of_bound(i,j,m,n) or board[i][j] != 'O')
            return;
        
        board[i][j] = 'Z';
        
        int di[] = {-1, 0, 1, 0};
        int dj[] = {0, 1, 0, -1};
        
        for(int k = 0; k < 4; k++)
        {
            int ni = i + di[k];
            int nj = j + dj[k];
            dfs(board, ni, nj, m, n);
        }

    }
    
    void solve(vector<vector<char>>& board) 
    {
        int m = board.size(), n = board[0].size();
        
        // Call dfs for first and last row.
        for(int j=0; j<n; j++)
        {
            dfs(board, 0, j, m, n);
            dfs(board, m-1, j, m, n);
        }
        
        // Call dfs for first and last coloumn. 
        for(int i = 0; i < m; i++)
        {
            dfs(board, i, 0, m, n);
            dfs(board, i, n-1, m, n);
        }
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'Z')
                {
                    board[i][j] = 'O';  
                }
                
                else if(board[i][j] == 'O')  // These O's are surrounded by X.
                    board[i][j] = 'X';
            }
        }
    }