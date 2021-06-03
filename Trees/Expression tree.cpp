/*

https://practice.geeksforgeeks.org/problems/expression-tree/1#


*/

int evalTree(node* root) 
{
        if(root->right==NULL && root->left==NULL)
        {
            return stoi(root->data);
        }
        int x=evalTree(root->left);
        int y=evalTree(root->right);
        
        if(root->data=="+")
            return x+y;
        
        else if(root->data=="-")
            return x-y;
        
        else if(root->data=="/")
            return x/y;
        
        else
            return x*y;
}