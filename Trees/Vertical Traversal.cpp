/*

https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1#


Time Complexity O(N*log HD) HD = total number of horizontal distance
Space Complexity O(h)

*/
    
    vector<int> verticalOrder(Node *root)
    {
        map<int,vector<int>>mp;
        queue<pair<Node*,int>>q;
        
        vector<int>ans;
        q.push({root,0});
        
        while(!q.empty())
        {
            Node *current=q.front().first;
            int hd = q.front().second;
            mp[hd].push_back(current->data);
            
            if(current->left)
            {
                q.push({current->left,hd-1});
            }
            if(current->right)
            {
                q.push({current->right,hd+1});
            }
            
            q.pop();
        }
        
        for(auto x:mp)
        {
            for(int a:x.second)
            {
                ans.push_back(a);
            }
            
        }
        
        return ans;
    }