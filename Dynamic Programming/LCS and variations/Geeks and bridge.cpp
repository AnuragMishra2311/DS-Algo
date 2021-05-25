/*

https://practice.geeksforgeeks.org/problems/geek-and-bridges/0/

Geek wants to build bridges between two banks of a river to help migrants to reach their homes. 
But, he can build a bridge only between two similar posts. Bridges can't overlap. 
The task is to find the maximum number of bridges geek can build. 

Note: Each of the posts is represented by either '*' or '@' or '#'.

Example: Let str1 = "*@#*", str2 = "*#". Then output will be 2.
* @ # *
|     / 
*  #


*/

#include<bits/stdc++.h>
using namespace std;

int lcs(int m, int n,string X, string Y)
{
    
    int dp[m+1][n+1],i,j;
    for(i=0;i<m+1;i++)
    {
        for(j=0;j<n+1;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
        }
    }
    
    for(i=1;i<m+1;i++)
    {
        for(j=1;j<n+1;j++)
        {
            if(X[i-1]==Y[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    
    return dp[m][n];
  
}


int main() 
{
	int t;
	cin>>t;
	while(t>0)
	{
	    string s1,s2;
	    cin>>s1;
	    cin>>s2;
	    t-=1;
	    cout<<lcs(s1.size(),s2.size(),s1,s2)<<endl;
	}
	return 0;
}