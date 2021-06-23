// https://practice.geeksforgeeks.org/problems/topological-sort/1


void solve(vector<int>adj[], int node, stack<int>&s, int visited[])
{
    visited[node] = 1;
    for(auto it:adj[node])
    {
        if(!visited[it])
        {
            solve(adj, it, s, visited);
        }
    }
    s.push(node);
}


	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int visited[V] = {0};
	    vector<int>ans;
	    stack<int>s;
	    
	    for(int i=0; i<V; i++)
	    {
	        if(!visited[i])
	        {
	            solve(adj, i, s, visited);
	        }
	    }
	    
	   while(!s.empty())
	   {
	       ans.push_back(s.top());
	       s.pop();
	   }
	   
	    return ans;
	}