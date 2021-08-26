/*

https://leetcode.com/problems/maximum-profit-in-job-scheduling/

Sort on basis of finishing time. 

dp[i] = max profit till ith job

Either we can include the job or exclude it.
If including, find the latest non conflict job i.e job whose end time <= start time of current job
If excluding, dp[i- 1] will come into consideration.

Time Complexity : O(N*N)
Space Complexity : O(N)

*/

    static bool cmp(vector<int>job_1, vector<int>job_2)
    {
        return job_1[1] < job_2[1];
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        int n = endTime.size();
        vector<vector<int>>arr(n, vector<int>(3));
        
        for(int i = 0; i<n; i++)
        {
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }
        
        sort(arr.begin(), arr.end(), cmp);
        
        vector<int>dp(n, 0);
        
        dp[0] = arr[0][2];
        
        for(int i = 1; i<n; i++)
        {
            int temp = arr[i][2];
            for(int j = i - 1; j >= 0; j--)
            {
                if(arr[j][1] <= arr[i][0])
                {
                    temp += dp[j];
                    break;
                }
            }
            
            dp[i] = max(dp[i - 1], temp);
        } 
        return dp[n-1];
    }
