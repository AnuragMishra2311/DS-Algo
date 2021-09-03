// https://www.interviewbit.com/problems/path-to-given-node/

// Time Complexity : O(N)
// Space Complexity : O(H)

void func(TreeNode * root, int x, vector<int>&temp, vector<int>&ans)
{
    if(root == NULL)
        return;
    temp.push_back(root->val);

    if(root -> val == x)
    {
        ans = temp;
    }

    func(root->left, x, temp, ans);
    func(root->right, x, temp, ans);

    temp.pop_back();
}

vector<int> Solution::solve(TreeNode* A, int B) 
{
    vector<int>ans;
    vector<int>temp;
    func(A, B, temp, ans);
    return ans;
}
