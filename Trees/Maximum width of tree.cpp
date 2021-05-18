/*

https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1


Given a Binary Tree, find the maximum width of it. Maximum width is defined as the maximum number of nodes in any level.    


          1
       /     \
     2        3
   /    \    / \
  4     5   6   7
   \
    8

Output: 4

Space Complexity : O(N)
Time Complexity : O(N)

*/



int getMaxWidth(Node* root)
{
        
       // Your code here
       int ans=INT_MIN,size;
       queue<Node*>q;
       q.push(root);
       while(q.empty()!=true)
       {
           size=q.size();
           ans=max(ans,size);
           while(size--)
           {
               Node *temp=q.front();
               if(temp->left)
               {
                   q.push(temp->left);
               }
               if(temp->right)
               {
                   q.push(temp->right);
               }
               q.pop();
           }
       }
       return ans;
}