/*

https://practice.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1/

Time Complexity : O(N LogN)
Space complexity : O(N)

*/

bool static cmp(pair<int,int>p1, pair<int,int>p2)
    {
        if( p1.first == p2.first)
            return p1.second > p2.second;
        return p1.first > p2.first;
    }
    
    
    vector<int> topK(vector<int>& nums, int k) 
    {
        int n = nums.size();
        unordered_map<int, int>mp; // map to maintian count of elements
      
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]] += 1;
        }
        
        vector<pair<int, int>>combined; // store elements along with their count in a vector.
        
        for(auto it : mp)
        {
            combined.push_back({it.second, it.first});
        }
        
        sort(combined.begin(), combined.end(), cmp);
       
        vector<int>ans;
        
        for(int i = 0 ; i < k; i++)
        {
            ans.push_back(combined[i].second);
        }
        return ans;
    }
