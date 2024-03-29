/*

https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1#

Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. 
It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.


*/



int minOperations(string str1, string str2) 
{ 
	// Your code goes here
	int n=str1.size(),m=str2.size(),i,j;
	int dp[n+1][m+1];
	memset(dp,0,sizeof(dp));   // Initializing using memset coz we need to initialize first row and first coloumn as 0, so let's not use for loop for that
	    
	for(i=1;i<n+1;i++)
	{
	    for(j=1;j<m+1;j++)
	    {
	        if(str1[i-1]==str2[j-1])
	        {
	            dp[i][j]=1+dp[i-1][j-1];
	        }
	        else
	        {
	            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	        }
	    }

	}	        
	int lcs=dp[n][m];
	return n+m-(2*lcs);
}
