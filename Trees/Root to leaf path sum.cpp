// https://practice.geeksforgeeks.org/problems/root-to-leaf-path-sum/1/

// Time Complexity : O(N)
// Sapce Complexity : O(H)

bool solve(Node *root, int sum, int x)
    {
        if(!root)
            return false;
            
        if(root->left == NULL and root->right == NULL)
            return sum + root->data == x;
            
        return solve(root->left, sum + root->data, x) or solve(root->right, sum + root->data, x);
    }
    
    
bool hasPathSum(Node *root, int S) 
{
    return solve(root, 0, S);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool hasPathSum(Node *root, int S) 
{
        
        if(!root or S<0)
            return false;
            
        if(root->left == NULL and root->right == NULL)
            return S - root->data == 0;
            
        return hasPathSum(root->left, S - root->data) or hasPathSum(root->right, S - root->data);
}