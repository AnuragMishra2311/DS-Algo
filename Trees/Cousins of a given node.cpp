/*

https://practice.geeksforgeeks.org/problems/cousins-of-a-given-node/1/

Time Complexity : O(N)
Space Complexity : O(Max number of nodes in a level)

*/

    vector<int> printCousins(Node* root, Node* node_to_find)
    {
        vector<int>ans;
        queue<Node*>q;
        q.push(root);
        bool found = false;
        
        while(!q.empty())
        {
               int size = q.size();
               while(size--)
               {
                   Node* current = q.front();
                   q.pop();
                   if( (current -> left and current -> left == node_to_find) or (current -> right and current -> right == node_to_find))
                   {
                       found = true;
                       continue;
                   }
                   
                   if(current -> left)
                        q.push(current -> left);
                        
                    if (current -> right)
                        q.push(current -> right);
               }
               
               if(found)
                    break;
        }
        
        while(!q.empty())
        {
            ans.push_back(q.front() -> data);
            q.pop();
        }
            
        if(ans.empty())
            return {-1};
            
        return ans;
    }