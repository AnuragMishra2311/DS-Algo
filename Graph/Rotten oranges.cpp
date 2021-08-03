// https://leetcode.com/problems/rotting-oranges/


bool check(int i, int j, int m, int n)
{
    if(i<0 or j<0 or i>m-1 or j>n-1)
        return false;
    
    return true;
}


int orangesRotting(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0, time = 0;
        
        queue<pair<int,int>>q;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 2) // Push all rotten oranges in Q. 
                {
                    q.push({i,j});
                }
                
                if(grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }
        
        // If we don't have fresh oranges, then return 0.
        if(fresh==0)
            return 0;
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0; i<4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(check(nx, ny, m ,n) and grid[nx][ny] == 1)
                    {
                        fresh--;
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                    }
                }
                
            }
            time++;
            
        }
        
        
        return fresh==0?time-1:-1;
    }