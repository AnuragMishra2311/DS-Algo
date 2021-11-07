/*

https://leetcode.com/problems/koko-eating-bananas/

*/


bool is_possible(vector<int>piles, int k, int h)
    {
        int hours = 0;
        for(int i = 0; i < piles.size(); i++)
        {
            hours += ceil((double)piles[i]/(double)k);
        }
        return hours <= h; 
    }
    
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans;
        
        while(high >= low)
        {
            int mid = low + (high - low)/2;
            if(is_possible(piles, mid, h))
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
