/* 
https://leetcode.com/problems/intersection-of-two-arrays/

Time Complexity  = Is_Sorted ? O(N) : O(N * Log N)
Space Complexity = O(1)

*/
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums1.size(), m = nums2.size();
        vector<int>ans;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
    
        int i = 0, j = 0;
        while (i <n and j <m)
        {
            if(nums1[i] > nums2[j])
                j++;
            
            else if (nums1[i] == nums2[j])
            {
                ans.push_back(nums1[i]);
                int current = nums1[i];
                
                // This is done to remove duplicates from the intersection array.
                while( i < n and nums1[i] == current)
                    i++;
                
                while(j < m and nums2[j] == current)
                    j++;
            }
            
            else
                i++;
        }
        
        return ans;
            
    }
