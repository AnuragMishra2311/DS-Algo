/*

https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1#

Algorithm: keep track of parent, if any node is reachable by a node which is not it's parent then we have cycle

*/


bool check(int i,vector<int>adj[], int visited[], int prev)
{
    visited[i] = 1;
    
    for(auto it:adj[i])
    {
        if(!visited[it])
        {
           if( check(it,adj,visited,i) ) return true;
        }
        
        else if(it!=prev)
        {
            return true;
        }
    }

    
}

bool isCycle(int V, vector<int>adj[])
{
	    queue<pair<int,int>>q;
	    int visited[V] = {0};
	    
	    for(int i =0;i<V;i++)
	    {
	        if(!visited[i])
	        {
	            if(check(i,adj,visited,-1))
	                return true;
	        }
	    }
	    
	    return false;
}