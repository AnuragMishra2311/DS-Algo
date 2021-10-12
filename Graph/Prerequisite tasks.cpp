// https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/?

// If graph contains cycle, then it's a deadlock and all tasks can not be completed, otherwise yes.

bool is_cycle(int s, vector<int> adj[], int visited[], int recursion_stack[])
    {
        visited[s] = 1;
        recursion_stack[s] = 1;
        
        for(auto it:adj[s])
        {
            if(!visited[it])
            {
                if(is_cycle(it, adj, visited, recursion_stack))
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


bool isPossible(int N, vector<pair<int, int> >& prerequisites) 
	{
	    vector<int>adj[N];
	    int x = prerequisites.size();
  
      // Adj list of graph
	    for(int i = 0; i < x; i++)
	    {
	        int u = prerequisites[i].second;
	        int v = prerequisites[i].first;
	        adj[u].push_back(v);
	    }
	    
	    int visited[N] = {0};
	    int recursion_stack[N] = {0};
	    
	    for(int i=0; i<N; i++)
	   	{
	   	    if(!visited[i])
	   	    {
	   	        if(is_cycle(i, adj, visited, recursion_stack))
	   	            return false;
	   	    }
	   	}
	   	
	   	return true;
	}
