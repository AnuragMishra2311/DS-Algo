// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1#

// Time Complexity : O(N^2)

int height(Node *root)
{
    if(root == NULL)
        return 0;
        
    return 1 + max(height(root->left), height(root->right));
}


    int diameter(Node* root) 
    {
        if(root == NULL)
            return 0;
            
        int left = height(root->left);
        int right = height(root->right);
        
        return max(left + right + 1, max(diameter(root->left), diameter(root->right)));
    }