/* 

https://practice.geeksforgeeks.org/problems/minimum-cost-path3833/1/?

Given a square grid of size N, each cell of which contains integer cost which represents a cost to traverse through that cell, 
we need to find a path from top left cell to bottom right cell by which the total cost incurred is minimum.
From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j).

Dijkstra Algo

*/
    
    
    bool check(int i, int j, int n)
	{
	   if(i<0 or j<0 or i>=n or j>=n)
	        return false;
	        
	   return true;
	}
	
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>cost(n,vector<int>(n,INT_MAX));
        
        cost[0][0] = grid[0][0];
        pq.push({grid[0][0],{0,0}});
        
        int di[] = {-1, 0, 1, 0};
        int dj[] = {0, 1, 0, -1};
        
        while(!pq.empty())
        {
            auto node = pq.top().second;
            int i = node.first;
            int j = node.second;
            pq.pop();
            
            for(int k=0; k<4; k++)
            {
                int ni = i + di[k];
                int nj = j + dj[k];
                
                if(check(ni, nj, n) and cost[ni][nj] > cost[i][j] + grid[ni][nj])
                {
                    cost[ni][nj] = cost[i][j] + grid[ni][nj];
                    pq.push({cost[ni][nj],{ni,nj}});
                }
            }
        }
        
        return cost[n-1][n-1];
    }