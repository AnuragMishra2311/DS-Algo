// https://leetcode.com/problems/sum-of-left-leaves/


void solve(TreeNode* root, int &sum, bool is_left)
    {
        if(root == NULL)
            return;
        
        if(root -> left == NULL and root -> right == NULL and is_left)
            sum += root -> val;
        
        solve(root -> left, sum, true);
        solve(root -> right, sum, false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) 
    {
        int sum = 0;
        solve(root, sum, false);
        return sum;
    }
};
