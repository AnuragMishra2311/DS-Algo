/*

https://leetcode.com/problems/cousins-in-binary-tree/

At the end of first while loop, we will have all the cousins of x in our queue. Check if y is present in q or not, if present 
then x and y are cousins otherwise not.

Time Complexity : O(N)
Space Complexity : O(Max number of nodes in a level)

*/
 
 bool isCousins(TreeNode* root, int x, int y) 
    {
        queue<TreeNode*>q;
        q.push(root);
        bool found = false;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                TreeNode* current = q.front();
                q.pop();
                if( (current->left and current -> left -> val == x) or(current -> right and current -> right -> val == x))
                {
                    found = true;
                    continue;
                }
                
                if(current -> left)
                    q.push(current -> left);
                
                if(current -> right)
                    q.push(current -> right);
                
            }
            
            if(found)
                break;
        }
        
        while(!q.empty())
        {
            if(q.front() -> val == y)
                return true;
            q.pop();
        }
        
        return false;
    }