/*

https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

Given an array arr of N positive integers, the task is to find the maximum sum increasing subsequence of the given array.
 

Example 1:

Input: N = 5, arr[] = {1, 101, 2, 3, 100} 
Output: 106
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3, 100}


Time Complexity O(N^2)
Space Complexity O(N)

*/


int maxSumIS(int arr[], int n)  
	{  
	    int i,j;
	    int dp[n];
	    
	    dp[0]=arr[0];
	    
	    for(i=1;i<n;i++)
	    {
	        dp[i]=arr[i]; // Initialize with arr[i] instead of 1(in case of LIS)
	        
	        for(j=0;j<i;j++)
	        {
	            if(arr[j]<arr[i])
	            {
	                if(dp[j]+arr[i]>dp[i])
	                {
	                    dp[i]=dp[j]+arr[i];
	                }
	            }
	        }
	    }
	    
	    return *max_element(dp,dp+n);
	}  