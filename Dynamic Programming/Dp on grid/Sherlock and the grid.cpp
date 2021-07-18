// https://www.codechef.com/problems/GRID

// Space Complexity : O(N*N)
// Time Complexity : O(N*N)

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() 
{
	int t, count, n;
	char ele;
	cin>>t;
	while(t>0)
	{
	    cin>>n;
	    vector<vector<char>>grid(n,vector<char>(n));
	    vector<vector<bool>>right(n,vector<bool>(n));
	    vector<vector<bool>>down(n,vector<bool>(n));
	    
	    count=0;
	    
	    // Input
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0; j<n; j++)
	        {
	            cin>>ele;
	            grid[i][j] = ele;
	        }
	    }
	    
	    
	    // Fill right Mattrix
	    for(int i=0; i<n; i++)
	    {
    	    for(int j=n-1; j>=0; j--)
    	    {
    	        if( j== n-1)
    	        {
    	            right[i][j] = grid[i][j]=='.'?true:false;
    	        }
    	            
    	       else
    	       {
    	            if( grid[i][j] == '.' and right[i][j+1])
    	                right[i][j] = true;
        	       else
        	            right[i][j] = false;
    	       }
    	    }
	    }
	    
	    // Fill Down Matrix
	    
	    for(int j=n-1; j>=0; j--)
	    {
    	    for(int i=n-1; i>=0; i--)
    	    {
    	       if( i== n-1)
    	        {
    	            down[i][j] = grid[i][j]=='.'?true:false;
    	        }
    	            
    	       else
    	       {
    	            if( grid[i][j] == '.' and down[i+1][j])
    	                down[i][j] = true;
        	       else
        	            down[i][j] = false;
    	       }
    	    }
	    }
	    
	   // Count No of cells
	    
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<n; j++)
	        {
	           if(right[i][j] and down[i][j])
	                count++;
	        }
	    }
	   
	   
	    cout<<count<<endl;
	    t--;
	    
	}
	return 0;
}
