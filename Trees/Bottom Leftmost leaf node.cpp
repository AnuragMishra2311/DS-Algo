/*

https://leetcode.com/problems/find-bottom-left-tree-value/


Recursive Approach :

Time Complexity O(N)
Space Complexity O(h)

*/

// Note: Passing highest_level by reference is important. 

void func(TreeNode *root, int current_level, int &highest_level, int &ans)
{
    if(root)
    {
        if(current_level > highest_level)
        {
            ans=root->val;
            highest_level = current_level;
        }
        
        func(root->left, current_level + 1, highest_level, ans);
        func(root->right, current_level + 1, highest_level, ans);
    }
}



int findBottomLeftValue(TreeNode* root) 
{
        int ans;
        int a=INT_MIN;
        func(root, 0, a, ans);
        return ans;
}




/*

Iterative approach

Idea: Same as level by level travesal, keep track of first element in every level.

*/

    int findBottomLeftValue(TreeNode* root) 
    {
        queue<TreeNode*>q;
        int ans;
        q.push(root);
        
        while(q.empty()!=true)
        {
            int q_size = q.size();
            bool first = true;
            
            while(q_size--)
            {
                TreeNode *current = q.front();
                
                if(first == true)
                {
                    ans=current->val;
                    first=false;
                }
                
                if(current->left)
                {
                    q.push(current->left);
                }
                
                if(current->right)
                {
                    q.push(current->right);
                }
                
                q.pop();
            }
        }
        
        return ans;
    }