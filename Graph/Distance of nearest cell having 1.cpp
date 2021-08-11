	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int m = grid.size();
	    int n = grid[0].size();
	    vector<vector<int>>ans(m, vector<int>(n,2000));
	    
	    queue<pair<int,int>>q;
	    int dx[] = {-1, 0, 1, 0};
	    int dy[] = {0, 1, 0, -1};
	    
	    for(int i=0; i<m; i++)
	    {
	        for(int j=0; j<n; j++)
	        {
	            if(grid[i][j] == 1)
	            {
	                ans[i][j] = 0;
	                q.push({i,j});
	            }
	        }
	    }
	    
	    while(!q.empty())
	    {
	        int x = q.front().first;
	        int y = q.front().second;
	        q.pop();
	        for(int i=0; i<4; i++)
	        {
	            int nx = x + dx[i];
	            int ny = y + dy[i];
	            
	            if(nx>=0 and ny>=0 and nx<m and ny<n )
	            {
	                if(ans[nx][ny] > ans[x][y]+1)
	               {
	                   ans[nx][ny] = ans[x][y] + 1;
	                   q.push({nx,ny});
	               }
	            }
	        }
	    }
	    
	    return ans;
	}