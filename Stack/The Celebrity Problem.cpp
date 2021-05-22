/*

https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1#

A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. 
Here M[i][i] will always be 0.
Note: Follow 0 based indexing.
 

Example 1:

Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity. 


Time Complexity O(N)
Space Complexity O(N) for stack


*/



int celebrity(vector<vector<int> >& M, int n) 
    {
        int i,A,B;
        stack<int>s;
        
        for(i=0;i<n;i++)
        {
            s.push(i);
        }
        
        while(s.size()!=1)
        {
            A=s.top();
            s.pop();
            B=s.top();
            s.pop();
            
            
            if(M[A][B]==1) // if A knows B, then A can't be celebrity, but B can be
            {
                s.push(B);
            }
            
            else // else A can be celebrity.
            {
                s.push(A);
            }
        }
        
        
        
        int potential_celebrity_index=s.top();
        int row_count=0,column_count=0;
        
        // To check that celebrity don't know anyone.
        for(i=0;i<n;i++)
        {
            if(M[potential_celebrity_index][i]==0)
            {
                row_count+=1;
            }
        }
        
        // Check if everyone knows celebrity.
        for(i=0;i<n;i++)
        {
            if(M[i][potential_celebrity_index]==1)
            {
                column_count+=1;
            }
        }
        
        // If both the condition are satisfied then return index of celebrity
        if(row_count==n && column_count==n-1)
        {
            return potential_celebrity_index;
        }
        
        else
        {
            return -1;
        }
}