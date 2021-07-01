/* 

https://leetcode.com/problems/number-of-operations-to-make-network-connected/

Idea: For n computer, minimum no of cables we require is n-1. 
If  n-1 > total_cables, then it is not possible to connect all the computers.

Else:
Every computer in one component are connected to each other, all we need to do is connect one component with another component,
For this no of cables required is no of components-1.

Space Complexity : O(V+E) For adjacency list
Time Complexity  : O(V+E) 
*/
 
 
 void dfs(vector<int>adj[], int visited[], int start)
    {
        visited[start]=true;
        for(auto it:adj[start])
        {
            if(!visited[it])
            {
                dfs(adj, visited, it);
            }
        }
        
    }


    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        if(connections.size()<n-1) // Not possible
        {
            return -1;
        }
        
        vector <int>adj[n];
        // Adjacency List
        for (int i=0;i<connections.size();i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int component = 0;
        int visited[n];
        memset(visited,0,sizeof(visited));
        
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                dfs(adj, visited, i);
                component++;
            }
        }
        
        return component-1;
        
    }