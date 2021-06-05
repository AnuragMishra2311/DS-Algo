/*

https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1#


Do vertical order traversal and take last element from vector corresponding to each hd value in map.

*/


vector <int> bottomView(Node *root)
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
            ans.push_back(x.second.back());
        }
        
        return ans;
}
