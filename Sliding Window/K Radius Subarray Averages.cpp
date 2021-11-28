/*

https://leetcode.com/problems/k-radius-subarray-averages/

SLIDING WINDOW APPROACH 
Time Complexity : O(N)
Space Complexity : O(1)

*/

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int>result(n, -1);
        long long int window_sum = 0;
        int i = 0, j = 0;
        
        if(k == 0)
            return nums;
        
        // length of array is too small for even one window 
        if(n < (2*k) + 1)
            return result;
        
        // for first window
        while(i <= 2*k)
        {
            window_sum += nums[i++];
        }
        
        i = k;
        while( i + k + 1< n)
        {
            result[i] = window_sum / (2*k + 1);
            window_sum -= nums[i - k];
            i += 1;
            window_sum += nums[i + k];
        }
        
        result[i] = window_sum / (2*k + 1);
        return result;
    }
};

/*

PREFIX SUM APPROACH

Time Complexity : O(N)
Space Complexity : O(N)

*/

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) 
    {
        int n = nums.size();
        long long sum = 0;
        vector<int>result(n, -1);
        vector<long long>prefixSum;
        
        for(auto element : nums)
        {
            sum += element;
            prefixSum.push_back(sum);
        }
        
        
        for(int i = k; i < n - k; i++)
        {
            result[i] = ( prefixSum[i + k] - ( (i - k - 1) >= 0 ? prefixSum[i - k - 1] : 0 ) )/ (2*k + 1);
        }
        
        return result;
    }
};