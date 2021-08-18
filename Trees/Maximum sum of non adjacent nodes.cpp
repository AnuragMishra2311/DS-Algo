/* 

https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1


Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of 
chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, 
if we have taken a node in our sum then we can’t take its any children in consideration and vice versa.

*/

int f(Node *root, bool parent)
{
    if(!root)
        return 0;
        
    if(parent == false)
        return  f(root->left, true)+ f(root->right, true);
        
    else
    return max( root->data+f(root->left,false)+f(root->right,false), f(root->left,true)+f(root->right,true));
}

int getMaxSum(Node *root) 
{
    return f(root, true);
}


/*

Time complexity : O(N)
Space complexity : O(N)

DP Aproach

*/

int f(Node *root, unordered_map<Node*, int> &dp)
{
    if(!root)
        return 0;
        
    int include = 0, exclude = 0;
        
    if(dp.find(root) != dp.end())
        return dp[root];
        

    exclude = f(root->left, dp) + f(root->right, dp);
        
    include =  root->data;
    if(root->left)
    {
        include+= f(root->left->left, dp);
        include+= f(root->left->right, dp);
    }
    
    if(root->right)
    {
        include+= f(root->right->left, dp);
        include+= f(root->right->right, dp);
    }
    
    return dp[root] = max(include, exclude);
}

int getMaxSum(Node *root) 
{
    unordered_map<Node*, int>dp;
    return f(root, dp);
}
