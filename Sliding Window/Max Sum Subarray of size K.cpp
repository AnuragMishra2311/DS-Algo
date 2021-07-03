// https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1#

int maximumSumSubarray(int k, vector<int> &arr , int n)
    {
        int sum=0, ans = INT_MIN;
        for(int i=0; i<k; i++)
        {
            sum+=arr[i];
        }
        ans = max(ans,sum);
        
        for(int i=0; i<n-k; i++)
        {
            sum-=arr[i];
            sum+=arr[i+k];
            ans=max(ans,sum);
        }
        
        return ans;
    }