/*

https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1#

Algorithm: keep track of parent, if any node is reachable by a node which is not it's parent then we have cycle

*/


bool check(int i,vector<int>adj[], int visited[])
{
        queue<pair<int,int>>q;
	    q.push({i,-1});
        
	    visited[i] = 1;
	    while(!q.empty())
	    {
	        int node = q.front().first;
	        int par = q.front().second;
	        q.pop();
	        for(auto it:adj[node])
	       {
	           if(!visited[it])
	           {
	               visited[it]=1;
	               q.push({it,node});
	           }
	           else if(it!=par)
	           return true;
	       }
	    }
	    
	    return false;
}


bool isCycle(int V, vector<int>adj[])
{
	    queue<pair<int,int>>q;
	    int visited[V] = {0};
	    
	    for(int i = 0; i<V; i++)
	    {
	        if(!visited[i])
	        {
	            if(check(i,adj,visited))
	                return true;
	        }
	    }
	    
	    return false;
}