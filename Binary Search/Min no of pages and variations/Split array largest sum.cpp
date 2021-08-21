// https://leetcode.com/problems/split-array-largest-sum/

bool is_possible(vector<int> arr, int m, int low, int high, int max_sum)
    {
        int mid = low + (high - low)/2;
        int count = 1, current_sum = 0;
        
        for(int i = 0; i<arr.size(); i++)
        {
            current_sum += arr[i];
            if(current_sum > max_sum)
            {
                count++;
                current_sum = arr[i];
            }
            
            if(count > m)
            {
                return false;
            }
        }
        
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) 
    {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans, mid;
        while(high >= low)
        {
            mid = low + (high - low)/2;
            if(is_possible(nums, m, low, high, mid))
            {
                high = mid - 1;
                ans = mid;
            }
            
            else
            {
                low = mid + 1;
            }
        }
        
        return ans;
    }