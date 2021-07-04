// https://www.hackerrank.com/challenges/connected-cell-in-a-grid/problem

void dfs(vector<vector<int>> grid, vector<vector<int>>&visited, int &cnt, int i, int j, int n, int m)
{
    if(i<0 or j<0 or i>=n or j>=m or grid[i][j]==0 or visited[i][j]==1)
        return ;
        
    visited[i][j] = 1;
    cnt+=1;
    dfs(grid, visited, cnt, i-1,j, n, m); // UP
    dfs(grid, visited, cnt, i,j+1, n, m); // Right
    dfs(grid, visited, cnt, i+1,j, n, m); // Down
    dfs(grid, visited, cnt, i,j-1, n, m); // Left
    dfs(grid, visited, cnt, i-1,j-1, n, m); // uper left diagonal
    dfs(grid, visited, cnt, i-1,j+1, n, m); // upper right diagonal
    dfs(grid, visited, cnt, i+1,j+1, n, m); // bottom right diagonal
    dfs(grid, visited, cnt, i+1,j-1, n, m); // bottom left diagonal
    
}

int maxRegion(vector<vector<int>> grid) 
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>>visited(n,vector<int>(m,0));

    int ans = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int cnt=0;
            if(!visited[i][j] and grid[i][j]==1)
            {
                //cout<<"DFS called for "<<i<<" "<<j<<endl;
                dfs(grid, visited, cnt, i, j, n, m);
                ans = max(ans, cnt);
            }
        }
    }
    
    return ans;
}