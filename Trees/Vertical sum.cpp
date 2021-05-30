/*

https://practice.geeksforgeeks.org/problems/vertical-sum/1#


Time Complexity O(N*log HD) HD = total number of horizontal distance
Space Complexity O(h)

*/




void helper(Node *root,int hd,unordered_map<int,int>&mp)
{
    if(root==NULL)
    {
        return ;
    }
    
    mp[hd]+=root->data;
    helper(root->left,hd-1,mp);
    helper(root->right,hd+1,mp);
}


    vector <int> verticalSum(Node *root) 
    {
    
        vector<int>ans;

        unordered_map<int, int>mp; // Important Use map instead of unordered_map, coz map stores values in sorted order acc to keys.
        
        helper(root,0,mp);
        
        for(auto x:mp)
        {
            ans.push_back(x.second);
        }
        
        return ans;
    }