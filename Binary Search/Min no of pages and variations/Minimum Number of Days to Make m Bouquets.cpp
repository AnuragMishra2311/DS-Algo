/*

https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

Time complexity : O(N*Log N)
Space Complexity : O(1)

*/

class Solution {
public:
    
    bool isPossible(vector<int> bloomDay, int currentDay, int k, int m)
    {
        int n = bloomDay.size();
        int i = 0;
        int count = 0;
        
        while(i < n - k + 1)
        {
            int valid = 0;
            
            // check if the subarray starting @ i is possible or not.
            for(int j = 0; j < k; j++)
            {
                if(i + j < n and bloomDay[i + j] <= currentDay)
                {
                    valid += 1;
                }
                
                else
                {
                    i += j + 1;
                    break;
                }
            }
            
            // if current subarray is possible, then increase the count by 1 and next starting point by i + k.
            if(valid >= k)
            {
                count += 1;
                i += k;
            }   
        }
        
        return count >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        
        while(high >= low)
        {
            int mid = low + (high - low)/2;
            if(isPossible(bloomDay, mid, k, m))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};