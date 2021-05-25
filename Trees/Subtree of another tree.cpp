/*

https://leetcode.com/problems/subtree-of-another-tree/

Time Complexity O(N)
Space Complexity O(H)

*/

bool isIdentical(TreeNode *r1, TreeNode *r2)
    {
        // If either of r1 or r2 becomes null while other is not null, return false
        if(r1 && !r2 || r2 && !r1)
        {
            return false;
        }
    
        if(!r1 && !r2)
        {
            return true;
        }
        
        // condition when both are not null, Inorder Traversal 
            return isIdentical(r1->left,r2->left) && r1->val== r2->val && isIdentical(r1->right,r2->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        
        bool ans;
        if(root==NULL && subRoot==NULL)
        {
            return true;
        }
        
        else if( (!root && subRoot) ||(!subRoot && root) )
        {
            return false;
        }
        
        else if(root->val==subRoot->val)
        {
           ans= isIdentical(root,subRoot);
        }
        
        return ( ans || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot) );
    }
