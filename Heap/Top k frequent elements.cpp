/* https://leetcode.com/problems/top-k-frequent-elements/

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Maintain a map for frequency. Make a min heap of pairs, push {count, element} in priority Q.
If size of min heap > k, pop.

Time Complexity : O(N * Log K)
Space Complexity: O(Unique elements + k)

*/

vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int>ans;
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto it:mp)
        {
            pq.push({it.second, it.first});
            if( pq.size() > k )
            {
                pq.pop();
            }
        }
        
        while( !pq.empty() )
        {
            ans.push_back( pq.top().second );
            pq.pop();
        }
        return ans;
    }