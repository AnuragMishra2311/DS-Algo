/*

https://leetcode.com/problems/sum-root-to-leaf-numbers/

Time Complexity : O(N)
Space Complexity : O(H), H = height of tree.

*/

void func(TreeNode* root, int &sum, string number)
    {
        // If root doesn't exist, return.
        if(root == NULL)
        {
            return;
        }
        
        // Add current val to number string.
        number += to_string(root->val);
        
        // If current node is leaf node, then add the number to sum and return.
        if(root->right == NULL and root->left == NULL)
        {
            sum += stoi(number);
            return;
        }
    
        func(root->left, sum, number);
        func(root->right, sum, number);
        
        // Pop root->val from number.
        number.pop_back();
    }
    
    
    int sumNumbers(TreeNode* root) 
    {
        int sum = 0;
        string number;
        
        func(root, sum, number);
        
        return sum;
    }
