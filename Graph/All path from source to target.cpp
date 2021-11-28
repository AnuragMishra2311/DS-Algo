/*

https://leetcode.com/problems/all-paths-from-source-to-target/

Time Complexity : O(2^N)

*/

class Solution {
public:
    
    void dfs(vector<vector<int>>graph, int start, vector<vector<int>>&result, vector<int>&temp)
    {
        temp.push_back(start);
        
        // reached target
        if(start == graph.size() - 1) 
            result.push_back(temp);
    
        else
        {
            for(auto node : graph[start])
                dfs(graph, node, result, temp);
        }
        
        temp.pop_back();
    }
        
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        vector<vector<int>>result;
        vector<int>temp;
        dfs(graph, 0, result, temp);
        return result;
    }
};