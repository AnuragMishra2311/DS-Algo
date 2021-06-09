/*

https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1#

https://leetcode.com/problems/house-robber/

*/

//Memoization Approach  

int solve(int *arr,int n,int dp[])
{
    //base case
    if(n<=0)
	{
	    return 0;
	}

	if(dp[n]!=-1)
	{
        return dp[n];
    }
    
	return dp[n]=max(arr[n-1]+solve(arr,n-2,dp),solve(arr,n-1,dp));
}

int findMaxSum(int *arr, int n) 
{
	   int dp[n+1];
	   memset(dp,-1,sizeof(dp));
	   return solve(arr,n,dp);
}




/* 

Top Down Approach
Space Complexity O(N)
Time Complexity O(N)

*/

int findMaxSum(int *arr, int n) 
{
	   int dp[n];
	   dp[0]=arr[0];
	   dp[1]=max(arr[0],arr[1]);
	   
	   for(int i=2;i<n;i++)
	   {
	       dp[i]=max(arr[i]+dp[i-2],dp[i-1]);
	   }
	   
	   return dp[n-1];
}


/*

Space Complexity O(1)
Time Complexity O(N)

*/

    int rob(vector<int>& arr) 
    {
        
        int n=arr.size();
        
        if(n<=2)
        {
            return *max_element(arr.begin(),arr.end());
        }
        
        int first=arr[0];
        int second=max(arr[0],arr[1]);
        int temp;
        
        for(int i=2;i<n;i++)
        {
            temp = max( first+arr[i],second );
            first=second;
            second=temp;
        }
        return max(first,second);
    }