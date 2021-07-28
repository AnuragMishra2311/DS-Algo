/*

https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1#

Step 1: Topological Sort
Step 2: Transpose of graph
Step 3: DFS for transposed graph according to topological sort.

*/

void toposort(vector<int>adj[], stack<int>&s, int visited[], int i)
{
    visited[i] = 1;
    
    for(auto it:adj[i])
    {
        if(!visited[it])
            toposort(adj, s, visited, it);
    }
    
    s.push(i);
}

void dfs(vector<int>adj[], int node, int visit[])
{
    visit[node] = 1;
    for(auto it:adj[node])
    {
        if(!visit[it])
            dfs(adj, it, visit);
    }
}

void transpose(vector<int> adj[], vector<int> *adj_T, int V)
{
    for(int i=0; i<V; i++)
    {
        for(auto it:adj[i])
        {
            adj_T[it].push_back(i);
        }
    }
}


int kosaraju(int V, vector<int> adj[])
    {
        int visited[V] = {0};
        vector<int> adj_T[V];
        stack<int>s;
        int count = 0;
        
        // Sttep 1: Topological sorting.
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                toposort(adj, s, visited, i);
            }
        }
        
        // Step 2: Transpose
        int visit[V] = {0};
        transpose(adj, adj_T, V);
        

        // Step 3: DFS according to topological sorting.
        while(!s.empty())
        {
            int node = s.top();
            s.pop();
            if(!visit[node])
            {
                dfs(adj_T, node, visit);
                count++;
            }
        }
       
        
        return count;
    }