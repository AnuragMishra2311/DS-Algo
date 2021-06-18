// https://leetcode.com/problems/minimum-depth-of-binary-tree/

/*

Don't forget to consider the skew tree case, in that case ans will be 1+max(ld,rd).

Time Complexity O(N)
Space Complexity O(H) H = height of tree.

*/
    
    int minDepth(TreeNode* root) 
    {
      if(!root)
      {
          return 0;
      }
        int ld = minDepth(root->left);
        int rd = minDepth(root->right);

        if(rd!=0 and ld!=0) // Tree is not skew, return min(ld,rd)
        {
            return 1+min(rd,ld);
        }
        
        if(rd!=0 and ld==0)  //Right Skewed tree 
        {
            return rd+1;
        }
        
        else  // Left Skewed Tree
        {
            return ld+1;
        }
    }