/*

https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1#

Intuition : Topological Sort is possible only for directed acyclic graph. (DAG)

If we are unable to do topological sorting, that means the graph is cyclic.

*/

bool isCyclic(int V, vector<int> adj[]) 
{
	   	int indegree[V]={0};
	   	int count = 0;
	   	queue<int>q;
	   	
        // Calculate indegree

	   	for(int i=0; i<V; i++)
	   	{
	   	    for(auto it:adj[i])
	   	    {
	   	        indegree[it]++;
	   	    }
	   	}
	   	
        // Push nodes with indegree 0 in q.

	   	for(int i=0; i<V; i++)
	   	{
	   	    if(indegree[i]==0) q.push(i);
	   	}
	   	
        
	   while(!q.empty())
	   {
	       int node = q.front();
	       q.pop();
	       count++;
	       for(auto it:adj[node])
	       {
	           indegree[it]--;
	           if(indegree[it]==0) q.push(it);
	       }
	   }
	   	
	   	return count==V? false:true;
}