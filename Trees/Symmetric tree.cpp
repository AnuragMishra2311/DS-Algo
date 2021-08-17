// https://practice.geeksforgeeks.org/problems/symmetric-tree/1

bool solve(struct Node* root1, struct Node* root2)
{
    if(!root1 and !root2)
        return true;
        
    if (root1 && root2 && root1->data == root2->data)
        return solve(root1->left, root2->right) && solve(root1->right, root2->left);
               
    return false;
}

bool isSymmetric(struct Node* root)
{
	struct Node* root2 = root;
	return solve(root, root2);
}