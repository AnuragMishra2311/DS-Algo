/*

https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1/?

*/

bool check(int i, int j, int n, int m )
{
   if (i<0 or j<0 or i>=n or j>=m)
        return false;
        
   return true;
}
  
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) 
    {
        if(!A[0][0])
            return -1;
        
        vector<vector<int>>cost(N,vector<int>(M,INT_MAX));
        vector<vector<int>>visited(N,vector<int>(M, 0));
        
        cost[0][0] = 0; 
        visited[0][0] = 1;
        
        queue<pair<int,int>>q;
        q.push({0,0});
        
        int di[] = {-1, 0, 1, 0};
        int dj[] = {0, 1, 0, -1};
        
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(int k = 0; k<4; k++)
            {
                int ni = i + di[k];
                int nj = j + dj[k]; 
                if( check(ni, nj, N, M) and A[ni][nj] == 1)
                {
                    if(visited[ni][nj] == 0 )
                    {
                        visited[ni][nj] = 1;
                        q.push({ni, nj});
                        cost[ni][nj] =  1 + cost[i][j];
                    }
                    
                    else if(cost[ni][nj] > cost[i][j] + 1)
                        cost[ni][nj] = 1 + cost[i][j];
                }
            }
        }
        
        return cost[X][Y] == INT_MAX ? -1 : cost[X][Y];
    }
