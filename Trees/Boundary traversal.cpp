// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#


void inorder(Node *root, vector<int> &ans)
{
    if(!root)
        return ;
        
    if(root->left == NULL and root->right == NULL)
    {
        ans.push_back(root->data);
    }
        
    inorder(root->left, ans);
    inorder(root->right, ans);
}

vector <int> printBoundary(Node *root)
    {
       vector<int>right;
       vector<int>bottom;
       vector<int>ans;
       
       ans.push_back(root->data);
       
       Node * curr = root->left;


       // Left boundary
       while(curr)
       {
            if(!(curr->left == NULL and curr->right == NULL)) // Not a leaf node
               ans.push_back(curr->data);
               
            if(curr->left)
                curr = curr->left;
                
            else
                curr = curr->right;
           
       }
       
       // Leaf Nodes
       inorder(root, ans);
      

      // Right Boundary
       curr = root->right;
       while(curr)
       {
            if(!(curr->left == NULL and curr->right == NULL)) // Not a leaf node
                right.push_back(curr->data);
                
            if(curr->right)
                curr = curr->right;
                
            else
                curr = curr->left;
       }
       
       reverse(right.begin(), right.end());
      
       for(auto it:right)
       {
           ans.push_back(it);
       }
       
       return ans;
    }