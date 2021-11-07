/*

https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

Time Complexity : O(N * log N)
Space Complexity : O(1)

Minimum possible divisor = 1
maximum = max(array).

*/

 bool is_possible(vector<int>nums, int mid, int threshold)
    {
        int division = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            division += ceil((double)nums[i]/(double)mid);
            if(division > threshold)
                return false;
        }
        
        return true;
    }


 int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int high = *max_element(nums.begin(), nums.end());
        int low = 1;
        int ans;
        while(high >= low)
        {
            int mid = low + (high - low)/2;
            if(is_possible(nums, mid, threshold))
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
