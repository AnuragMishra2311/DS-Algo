// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1#


vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Priority queue (Min Heap)
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>q;
        
        vector<int>distance(V,INT_MAX);
        distance[S] = 0;
        
        q.push({0,S}); // Push source node in queue.

        while(!q.empty())
        {
            int node = q.top().second;
            q.pop();
            
            for(auto it:adj[node])
            {
                if(distance[node] + it[1] < distance[it[0]])
                {
                    distance[it[0]] = distance[node] + it[1];
                    q.push({distance[it[0]],it[0]});
                }
            }
        }
        return distance;
    }