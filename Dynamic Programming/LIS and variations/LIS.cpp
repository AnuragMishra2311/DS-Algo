/*

https://leetcode.com/problems/longest-increasing-subsequence/

Time Complexity O(N^2)
Space Complexity O(N)

*/
    
    
    int lengthOfLIS(vector<int>& arr) 
    {
    
       int n=arr.size();
       int dp[n]; //will count the length of the LIS till the current index
       
       //Initialize
       dp[0]=1;
       
       for(int i=1;i<n;i++)
       {
           dp[i]=1;
           
           for(int j=0;j<i;j++)
           {
               if(arr[j]<arr[i])
               {
                   if(dp[j]+1>dp[i])
                   {
                       dp[i]=dp[j]+1;
                   }
               }

           }
           
       }
        
        return *max_element(dp,dp+n);
    }