// https://leetcode.com/problems/deepest-leaves-sum/submissions/

Time Complexity : O(N)
Space Complexity : O(max nodes in any level)

int deepestLeavesSum(TreeNode* root) 
    {
        queue<TreeNode*>q;
        q.push(root);
        int sum_of_current_level_nodes;
        while(!q.empty())
        {
            int size = q.size();
            sum_of_current_level_nodes = 0;
            while(size--)
            {
                TreeNode *current = q.front();
                sum_of_current_level_nodes += current->val;
                
                if(current->left)
                    q.push(current->left);
                if(current->right)
                    q.push(current->right);
                
                q.pop();
            }
        }
        
        return sum_of_current_level_nodes;
    }
