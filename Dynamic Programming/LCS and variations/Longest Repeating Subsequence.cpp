/*

https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1#


Given a string str, find length of the longest repeating subseequence such that the two subsequence don’t have same string character at same position, 
i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.
 

Exampel 1:

Input: str = "axxxy"
Output: 2
Explanation: The longest repeating subsequenece
is "xx".



Logic: Same as LCS, just add one xtra condition i!=j. 


*/


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
            if(X[i-1]==Y[j-1] && i!=j)
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


		
int LongestRepeatingSubsequence(string str)
{
	return lcs(str.size(),str.size(),str,str);
}