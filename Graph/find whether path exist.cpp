/*

https://practice.geeksforgeeks.org/problems/find-whether-path-exist5238/1

Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. 
You can traverse up, down, right and left.

The description of cells is as follows:

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Wall.

*/

// BFS

bool check(int i, int j, int n)
{
    if(i>=n or i<0 or j>=n or j<0)
        return false;
        
    return true;
}


bool is_Possible(vector<vector<int>>& grid) 
{
        int n = grid.size();
        vector<vector<int>> visited(n,vector<int>(n, 0));
        queue<pair<int,int>>q;
        
        bool found = false;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1) //push starting node in q.
                {
                    q.push({i,j});
                    found  = true;
                    break;
                }
            }
            if(found)
                break;
        }
        
        
        int di[] = {-1, 0, 1, 0};
        int dj[] = {0, 1, 0, -1};
        
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            if(grid[i][j] == 2) //destination reached
                return true;
                
                
            for(int k=0; k<4; k++)
            {
                int ni = i + di[k];
                int nj = j + dj[k];
                
                
                if(check(ni, nj, n) and grid[ni][nj]!=0 and visited[ni][nj]==0)
                {
                    q.push({ni, nj});
                    visited[ni][nj] = 1;
                }
            }
            
        }
        
        return 0;
}



// DFS 

bool dfs(vector<vector<int>>& visited, vector<vector<int>> grid, int i, int j, int n)
{
    if(i>=n or i<0 or j>=n or j<0 or grid[i][j]==0 or visited[i][j]==1)
        return false;
        
    if(grid[i][j] == 2)
        return true;
        
    visited[i][j] = 1;
    bool opt1 = dfs(visited, grid, i+1, j, n);
    bool opt2 = dfs(visited, grid, i, j+1, n);
    bool opt3 =dfs(visited, grid, i-1, j, n);
    bool opt4 =dfs(visited, grid, i, j-1, n);
    
    return opt1 or opt2 or opt3 or opt4;
}

 bool is_Possible(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>> visited(n,vector<int>(n, 0));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1)
                {
                   return dfs(visited, grid, i, j, n);
                }
            }
        }
        
        return 0;
    }