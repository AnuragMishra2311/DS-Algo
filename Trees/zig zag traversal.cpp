/*

https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1#

Time Complexity O(N)
Space Complexity O(N)

*/


// Using 2 Stack

vector <int> zigZagTraversal(Node* root)
{
	vector<int>ans;
	stack<Node*>s1;
	stack<Node*>s2;
	Node *current;
	
	s1.push(root);
	
	while(!s1.empty() || !s2.empty())
	{
	    while(!s1.empty())
	    {
	        current = s1.top();
	        ans.push_back(current->data);
	        s1.pop();
	        
	        if(current->left)
	        {
	            s2.push(current->left);
	        }
	        if(current->right)
	        {
	            s2.push(current->right);
	        }

	    }
	    
	    while(!s2.empty())
	    {
	        current = s2.top();
	        ans.push_back(current->data);
	        s2.pop();
	        
	        if(current->right)
	        {
	            s1.push(current->right);
	        }
	        if(current->left)
	        {
	            s1.push(current->left);
	        }
	        
	    }
	}
	
	return ans;
}


/* Using 1 stack and 1 queue

Approach : If level is odd then push the nodes in stack so that the nodes at odd level will be printed in reverse order. 

*/

vector <int> zigZagTraversal(Node* root)
{
	vector<int>ans;
	stack<int>s;
	Node *current;
	queue<Node*>q;
	int i=1;
	q.push(root);
	
	ans.push_back(root->data);
	while(!q.empty())
	{
	    int size = q.size();
	    while(size--)
	    {
	        current = q.front();
	        if(i%2!=0)
	        {
	            if(current->left)
	            {
	                q.push(current->left);
	                s.push(current->left->data);
	            }
	            if(current->right)
	            {
	                q.push(current->right);
	                s.push(current->right->data);
	            }
	            q.pop();
	            
	        }
	        else
	        {
	            if(current->left)
	            {
	                q.push(current->left);
	                ans.push_back(current->left->data);
	            }
	            if(current->right)
	            {
	                q.push(current->right);
	                ans.push_back(current->right->data);
	            }
	            q.pop();
	        }
	    }
	    while(!s.empty())
	    {
	        ans.push_back(s.top());
	        s.pop();
	    }
	    i++;
	}
	
	return ans;
}