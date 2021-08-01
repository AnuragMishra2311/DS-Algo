/*
https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1#

Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.
 
Time Complexity : O(N*N)
Space Complexity : O(N*N)

*/

 bool check(int i, int j, int N)
    {
    	if(i<0 or j<0 or i>=N or j>=N)
    		return false;
    	return true;
    }

	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N)
	{
	    int start_i = KnightPos[0]-1, start_j = KnightPos[1]-1;
	    int target_i = TargetPos[0]-1, target_j = TargetPos[1]-1;
	    
	    vector<vector<int>>visited(N, vector<int>(N, 0));
	    vector<vector<int>>cost(N, vector<int>(N, INT_MAX));
	    
	    cost[start_i][start_j] = 0;
	    visited[start_i][start_j] = 1;
	    
	    queue<pair<int,int>>q;
	    q.push({ start_i, start_j });
	    
	    int di[] = {-2, -2, -1, 1, 2, 2, -1, 1};
	    int dj[] = {-1, 1, 2, 2, 1, -1, -2, -2};
	    
	    while(!q.empty())
	    {
	        int i = q.front().first;
	        int j = q.front().second;
	        q.pop();
	        
	        for(int k=0; k<8; k++)
	        {
	            int ni = i + di[k];
	            int nj = j + dj[k];
	            
	            if(check(ni, nj, N) )
	            {
    	            if (!visited[ni][nj])
    	            {
    	                visited[ni][nj] = 1;
    	                cost[ni][nj] = cost[i][j] + 1;
    	                q.push({ni, nj});
    	            }
    	            
    	            else if(cost[ni][nj] > cost[i][j] + 1)
    	            {
    	                cost[ni][nj] = cost[i][j] + 1;
    	            }
	            }
	        }
	        
	    }
	    
	    return cost[target_i][target_j];
	    
	    
	}