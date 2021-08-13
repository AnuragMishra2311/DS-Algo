/*

https://practice.geeksforgeeks.org/problems/maximum-node-level/1

Time Complexity : O(N)
Space Complexity : O(Max nodes in a level)

*/

int maxNodeLevel(Node *root)
{
    int max_size = 0, level = -1, ans=0;
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty())
    {
        int size = q.size();
        level++;
        if(size > max_size)
        {
            max_size = size;
            ans = level;
        }
        while(size--)
        {
            Node *current = q.front();
            if(current->left)
                q.push(current->left);
                
            if(current->right)
                q.push(current->right);
                
            q.pop();
        }
    }
    
    return ans;
}