/*

https://leetcode.com/problems/k-closest-points-to-origin/

Time Complexity : O(N*LogK)
Space Complexity : O(K)

*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        priority_queue<pair<int,vector<int>>, vector<pair<int,vector<int>>>>pq;
        vector<vector<int>>ans;
        
        for(int i = 0; i < points.size(); i++)
        {
            int x = pow(points[i][0], 2);
            int y = pow(points[i][1], 2);
            int distance = x + y;
            pq.push({distance, points[i]});
            
            if(pq.size() > k)
                pq.pop();
        }
        
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};