// https://practice.geeksforgeeks.org/problems/possible-paths-between-2-vertices-1587115620/1/


void dfs(vector<int> adj[], int src, int dst, int &ans)
{
    if(src == dst)
        ans+=1;
        
    for(auto it:adj[src])
    {
        dfs(adj, it, dst, ans);
    }
}


int countPaths(int V, vector<int> adj[], int source, int destination)
{
    int ans=0;
    dfs(adj, source, destination, ans);	    
    return ans;
}