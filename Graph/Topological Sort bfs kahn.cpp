// https://practice.geeksforgeeks.org/problems/topological-sort/1
	
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int indegree[V]={0};
	    queue<int>q;
	    vector<int>ans;
	    
		// Calculating indegree
	    for(int i=0;i<V;i++)
	    {
	        for(auto x:adj[i])
	        {
	            indegree[x]+=1;
	        }
	    }
	    
		// push nodes with indegree 0 into q.
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    
	    while(q.empty()!=true)
	    {
	        int temp=q.front();
	        q.pop();
	        ans.push_back(temp);
	        for(auto x: adj[temp])
	        {
	            indegree[x]-=1;
	            if(indegree[x]==0)
	            {
	                q.push(x);
	            }
	        }
	    }
	    
	    return ans;
	}