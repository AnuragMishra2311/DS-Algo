/* 

https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1# 
 
Approach : Level by level traversal. At any level if any of the node is leaf but not all nodes are leaf, that means 
all leaf nodes are not at same level.

Keep track of leaf nodes for all level, if we come across a condition where leaf!=0(atleast one node is leaf) and 
leaf!=size (All nodes pf that level are not leaf) then return true.

Time Complexity : O(N)
Space Complexity : O(Max no of nodes in a level)

*/
 
 bool check(Node *root)
    {
        queue<Node *>q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            int save = size;
            int leaf = 0;
            
            while(save--)
            {
                Node *current = q.front();
                if(current->left)
                    q.push(current->left);
                    
                if(current->right)
                    q.push(current->right);
                    
                if(current->right == NULL and current->left == NULL)
                    leaf++;
                    
                q.pop();
            }
            
            if(leaf!=0 and leaf!=size) // means atleat one node in this level is leaf but not all nodes are leaf
                return false;
        }
        
        return true;
    }