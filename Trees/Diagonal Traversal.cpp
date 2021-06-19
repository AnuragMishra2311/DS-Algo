// https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1#

/*
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4    7  13


O/P : 8 10 14 3 6 7 13 1 4

Approacg : Keep traversing right and keep appending the same in ans vector, if any node has left child then push it into q. 

*/


vector<int> diagonal(Node *root)
{
   vector<int>ans;
   queue<Node*>q;
   q.push(root);
   
   while(!q.empty())
   {
       Node *current = q.front();
       q.pop();
       
       while(current)
       {
           ans.push_back(current->data);
           if(current->left)
           {
               q.push(current->left);
           }
           current = current->right;
       }
   }
   return ans;
}