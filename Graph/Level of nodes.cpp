/*

https://practice.geeksforgeeks.org/problems/level-of-nodes-1587115620/1/?track=P100-Graph&batchId=197

Approach: Find minimum cost to reach from source node to destination node, where cost is 1.

*/


int nodeLevel(int V, vector<int> adj[], int X) 
	{   	    
	    if(X>=V)
	    {
	        return -1;
	    }
	    
	    if(X == 0)
	        return 0;
	   
	    int visited[V] = {0}, cost[V];
	    for(int i=0; i<V; i++)
	    {
	        cost[i] = INT_MAX;
	    }
	    
	    queue<int>q;
	    q.push(0);
	    visited[0] = 1;
	    cost[0] = 0;
	    
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        
	        for(auto it:adj[node])
	        {
	            if(!visited[it])
	            {
	                q.push(it);
	                visited[it] = 1;
	                cost[it] = cost[node]+1;
	            }
	            
	            else if(cost[it] > cost[node]+1)
	            {
	                cost[it] = cost[node] + 1;
	            }
	        }
	    }
	    return cost[X];
	}