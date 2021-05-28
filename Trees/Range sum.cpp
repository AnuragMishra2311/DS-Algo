/*

https://leetcode.com/problems/range-sum-of-bst/

Space Complexity O(h)
Time Complexity O(N)

*/

int rangeSumBST(TreeNode* root, int low, int high) 
{
        if(root==NULL)
        {
            return 0;
        } 
        
        if( low <= root->val && root->val <= high)
           return root->val+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
        
        else
            return rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
}