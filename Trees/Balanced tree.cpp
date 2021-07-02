/*

https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1#

*/

// O(N^2) Time Complexity

int height(Node *root)
{
    if(!root) return 0;
    return 1 + max(height(root->left),height(root->right));
}

//Function to check whether a binary tree is balanced or not.
bool isBalanced(Node *root)
{
    if(!root) return true;

    int l = height(root->left); // height of left tree
    int r = height(root->right); // height of right tree
    return abs(l-r)<=1 && isBalanced(root->left) && isBalanced(root->right);
}