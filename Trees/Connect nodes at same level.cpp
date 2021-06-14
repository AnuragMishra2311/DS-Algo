/*

https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1#

Approach : If we are doing level by level traversal, then the nextRight pointer of popped node will point to q.front()


Level 1 : 10, NULL
Level 2 : 3 5 NULL
Level 3 : 4 1 2 NULL

How to push this NULL at the end of every level ?
When we are done traversing a level 
    1. Pop NULL of previous level.
    2. Push NULL for current level.

       10                       
      / \                      
     3   5          
    / \   \              
   4   1   2   


Q after level 1 traversal : Null, 3, 5
pop Null and then push NULL ->>>  3, 5, NULL

Q after last level traversal : NULL
Push NULL and then pop NULL ->>>> NULL
That is our q size is 1 and hence we will come out of while loop.

*/


// Time Complexity O(N)
// Space Complexity O(Maximum no of nodes in a level)

void connect(Node *root)
    {
        if(!root)
        {
            return ;
        }
        
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        
        while(q.size()!=1)
        {
            int size = q.size()-1;
            while(size--)
            {
                Node *current = q.front();
                q.pop();
                
                current->nextRight = q.front();
                
                if(current->left)
                {
                    q.push(current->left);
                }
                if(current->right)
                {
                    q.push(current->right);
                }
            }
            q.push(NULL);
            q.pop();
        }

    }    