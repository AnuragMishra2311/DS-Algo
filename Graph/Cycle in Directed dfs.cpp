// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1#


bool solve(int s, vector<int> adj[], int visited[], int recursion_stack[])
{
    visited[s] = 1;
    recursion_stack[s] = 1;
    
    for(auto it:adj[s])
    {
        if(!visited[it])
        {
            if(solve(it, adj, visited, recursion_stack))
            {
                return true;
            }
        }
        
        else
        {
            if(recursion_stack[it]) return true;
        }
    }
    
    recursion_stack[s] = 0;
    return false;
}
    
    
    
    
    bool isCyclic(int V, vector<int> adj[]) 
	{
	   	int recursion_stack[V]={0};
	   	int visited[V]={0};
	   	
	   	for(int i=0; i<V; i++)
	   	{
	   	    if(!visited[i])
	   	    {
	   	        if(solve(i, adj, visited, recursion_stack))
	   	        {
	   	            return true;
	   	        }
	   	    }
	   	}
	   	
	   	return false;
	}