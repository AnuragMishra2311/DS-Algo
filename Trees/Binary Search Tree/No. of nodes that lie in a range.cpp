// https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1#

// Time Complexity : O(N)
// Space Complexity : O(H)


int getCount(Node *root, int l, int h)
{
    if(!root)
        return 0;
    
    int left = getCount(root->left, l, h);
    int right = getCount(root->right, l, h);
    
    if(l <= root->data  and root->data <=h)
        return 1 + left + right;
    
    return left + right;
}