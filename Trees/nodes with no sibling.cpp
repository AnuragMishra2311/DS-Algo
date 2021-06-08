/*

https://practice.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1

Time Complexity O(N)
Space Complexity O(N)

*/

vector<int> noSibling(Node* root)
{
    vector<int>ans;
    bool is_root = true;
    queue<Node*>q;
    q.push(root);
    
    while(q.empty() != true)
    {
        int size = q.size();
        while(size--)
        {
            Node *current = q.front();
            
            if(current->left)
            {
                q.push(current->left);
            }
            
            if(current->right)
            {
                q.push(current->right);
            }
            
            if(current->left==NULL and current->right) //has only one child, i.e right child
            {
                ans.push_back(current->right->data);
            }
            
            if(current->right==NULL and current->left) // has only one child i.e left child
            {
                ans.push_back(current->left->data);
            }
            
            q.pop();
        }
        
    }
    sort(ans.begin(),ans.end());
    if(ans.size()==0)
    {
        return {-1};
    }
    return ans;
}