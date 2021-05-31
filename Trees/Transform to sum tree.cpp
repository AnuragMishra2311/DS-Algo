/*

https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1#

Given a Binary Tree of size N , where each node can have positive or negative values. 
Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree. 
The values of leaf nodes are changed to 0.

Time Complexity O(N)
Space Complexity O(h)

*/
    



int helper(Node *root)
{
    if(!root)
    {
        return 0;
    }
    int prev = root->data;
    root->data = helper(root->left) + helper(root->right);
    return prev+root->data;
    
}
    
void toSumTree(Node *root)
{
    helper(root);
}