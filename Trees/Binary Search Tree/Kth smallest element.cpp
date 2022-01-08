/*

https://leetcode.com/problems/kth-smallest-element-in-a-bst/

Approach : Traverse in inorder fashion, whenever we hit first null, parent of that null node is our 
           first node.So increase the currentNodeNumber by 1. Now check if currentNodeNumber == k 
           and accordingly perform action.

Time complexity : O(N)
Space complexity : O(H)

*/

class Solution {
  public:
    // Return the Kth smallest element in the given BST
    
    void solve(Node *root, int &ans, int k, int &currentNodeNumber)
    {
        if(root == NULL)
            return;
            
        solve(root -> left, ans, k, currentNodeNumber);
        currentNodeNumber += 1;
        if(currentNodeNumber == k)
        {
            ans = root -> data;
            return;
        }
        
        solve(root -> right, ans, k, currentNodeNumber);
    }
    
    int KthSmallestElement(Node *root, int k) 
    {
        int ans = -1;
        int currentNodeNumber = 0;
        solve(root, ans, k, currentNodeNumber);
        return ans;
    }
};