// https://leetcode.com/problems/same-tree/

// Time Complexity : O(N)
// Space Complexity : O(H)


bool isSameTree(TreeNode* p, TreeNode* q) 
    {
         if( (p == NULL and q != NULL) or (q == NULL and p != NULL) )
            return false;
        
        if(p == NULL and q == NULL)
            return true;
        
        return p -> val == q ->val and isSameTree(p -> left, q -> left) and isSameTree(p -> right, q -> right);
    }
