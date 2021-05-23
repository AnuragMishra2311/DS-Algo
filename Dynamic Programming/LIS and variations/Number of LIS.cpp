 /*

 https://leetcode.com/problems/number-of-longest-increasing-subsequence/


Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.

Example 1:

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].

 */
 
 
 int findNumberOfLIS(vector<int>& nums) 
 {
        
        int n = nums.size(); //finding the size of nums
        
        if(n <= 1) return n; //less than one length return n
        
        vector<int> dp(n+1, 1); //will count the length of the LIS till the current index
        vector<int> cnt(n+1, 1);// number of LIS till this index
        
        dp[0] = 1; //the length can be only 1 until the first element obviously
        
        
        for(int i = 1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
        
                if(nums[j] < nums[i]) //from j to i is an increasing subsequence
                {
                    if(dp[j]+1>dp[i]) //lenght of lis ill j is same as length of lis till i as of yet
                    {
                        
                        dp[i] = dp[j] + 1; //this is one length extra since i is a new element now included in the lis uptill j to becoome lis till i
                        
                        cnt[i] = cnt[j]; 
                        //the lis till j will be same as lis till i as this is not a new lis but an extension of lis till j, a new element is added in the same lis
                    }

                    else if (dp[j] + 1 == dp[i])
                    {
                        cnt[i] += cnt[j];
                        //all this lis till j will now be lis till i since this is a new lis not just an addition to previous lis, the lis uptill i wasof some length from some other jth element, this is another addition to the same lis
                    }                      
                }
            }
           
        }
        int lcs= *max_element(dp,dp+n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==lcs)
            {
                ans+=cnt[i];
            }
        }
        return ans;
}