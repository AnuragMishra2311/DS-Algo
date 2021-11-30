/*

https://leetcode.com/problems/find-largest-value-in-each-tree-row/

Time complexity : O(N)
Space Complexity : O(max no of nodes in a level)

*/

class Solution {
public:
    vector<int> largestValues(TreeNode* root) 
    {
        if(root == NULL)
            return {};
        
        queue<TreeNode*>q;
        q.push(root);
        
        vector<int>maxEachLevel;
        
        // Level by level traversal 
        while(!q.empty())
        {
            int maximum = INT_MIN;
            int size = q.size();
            while(size--)
            {
               
                TreeNode *current = q.front();
                q.pop();
               
                if(current -> left)
                    q.push(current -> left);
                
                if(current -> right)
                    q.push(current -> right);
                
                maximum = max(maximum, current -> val);
            }
            
            maxEachLevel.push_back(maximum);
        }
        
        return maxEachLevel;
    }
};