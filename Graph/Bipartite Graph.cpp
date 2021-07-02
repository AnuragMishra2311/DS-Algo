// https://practice.geeksforgeeks.org/problems/bipartite-graph/1#


bool check(vector<int>adj[], int i, int color[])
{
        color[i] = 0;
	 
	    queue<int>q;
	    q.push(i);
	    
	    int manage[2]={1,0};
	    
	    while(!q.empty())
	    {
	        int node = q.front();
	        int current_color = color[node];
	        q.pop();
	        for(auto it:adj[node])
	        {
	            if(color[it] == -1)
	            {
	                color[it] = manage[current_color];
	                q.push(it);
	            }
	            else if(color[it]==current_color)
	            {
	                    return false;
	            }
	        }
	    }
	    
	    return true;
}


bool isBipartite(int V, vector<int>adj[])
	{
	    int color[V];
	    memset(color, -1, sizeof(color));
	    for(int i=0; i<V; i++)
	    {
	        if(color[i] == -1)
	        {
	            if(!check(adj, i, color))
	                return false;
	        }
	    }
	    
	    return true;
	}