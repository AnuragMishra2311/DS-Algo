// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1#


/*

Maintain a pass by reference valid variable and set it to false, if any subtree is not balanced.

Time Complexity : O(N)
Spcae Complexity : O(H)

*/

int height(Node *root, bool &valid)
{
        if(!root)
            return 0;
        
        int left_height = height(root->left, valid);
        int right_height = height(root->right, valid);
        
        if( abs(left_height - right_height)>1 ) // If any subtree is not balanced, then set valid as false.
            valid = false;
        
        return 1 + max(left_height, right_height);
}


bool isBalanced(Node *root)
{
    bool valid=true;
    height(root, valid);
    return valid;
}


/*

Approach:  Keep appending abs(left_height - right_height) in a vector. Traverse the vector if any element is greater
than 1, return false else return true.

Time complexity : O(N)
Space Complexity : O(N)

*/

int height(Node *root, vector<int> &store)
{
    if(!root)
        return 0;
        
    int left = height(root->left, store);
    int right = height(root->right, store);
    
    int ans = 1 + max(left, right);
    store.push_back(abs(left-right));
    return ans;
    
}

bool isBalanced(Node *root)
{
    vector<int>store;
    height(root, store);
    
    for(auto i:store)
    {
        if(i>1)
            return false;
    }
    
    return true;
}


// Brute Force O(N^2) Time Complexity

int height(Node *root)
{
    if(!root) return 0;
    return 1 + max(height(root->left),height(root->right));
}

//Function to check whether a binary tree is balanced or not.
bool isBalanced(Node *root)
{
    if(!root) return true;

    int l = height(root->left); // height of left tree
    int r = height(root->right); // height of right tree
    return abs(l-r)<=1 && isBalanced(root->left) && isBalanced(root->right);
}