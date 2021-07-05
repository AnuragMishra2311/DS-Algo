// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

void dfs(vector<vector<char>>& grid, int i, int j,int m, int n,int visited[][501])
{
    if(i>=m or j>=n or i<0 or j<0 )
        return ;
        
    if(grid[i][j]=='0') return ;

    if(!visited[i][j])
    { 
        visited[i][j] = 1;
        int di[] = {1,-1,0,0,-1,1,-1,1}; 
        int dj[] = {0,0,1,-1,-1,1,1,-1};
        
        for(int a=0; a<8; a++)
        {
            int ni = i + di[a];
            int nj = j + dj[a];
            dfs(grid,ni,nj,m,n,visited);
        }
    }
    
}


int numIslands(vector<vector<char>>& grid) 
{
        int m = grid.size();
        int n = grid[0].size();
        int visited[501][501];
        memset(visited,0,sizeof(visited));
        
        int count = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]=='1' and !visited[i][j])
                {
                    dfs(grid,i,j,m,n,visited);
                    count++;
                }
            }
        }
        
        return count;
}