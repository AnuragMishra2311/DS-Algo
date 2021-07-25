// https://practice.geeksforgeeks.org/problems/odd-even-level-difference/1

// Time Complexity : O(N)
// Space Complexity : O(H)


void solve(Node *root, int &odd_sum, int &even_sum, int level)
{
    if(!root)
        return ;
        
    if(level &1)
        odd_sum+=root->data;
    else
        even_sum+=root->data;
        
    solve(root->left, odd_sum, even_sum, level+1);
    solve(root->right, odd_sum, even_sum, level+1);
}


int getLevelDiff(Node *root)
    {
       int odd_sum = 0, even_sum = 0, level = 0;
       solve(root, odd_sum, even_sum, level);
       
       return even_sum - odd_sum;
    }