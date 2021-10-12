/*

https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/

Time Complexity : O(MN * Log(MN))
Space Complexity : O(M*N)

*/
int minOperations(vector<vector<int>>& grid, int x) 
    {
        vector<int>nums;
        int operations = 0;
        int m = grid.size(), n = grid[0].size();
  
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                nums.push_back(grid[i][j]);
            }
        }
        
        sort(nums.begin(), nums.end());
  
        // Median 
        int median = nums[(m*n)/2];
        for(int i = 0 ; i < m*n; i++)
        {
            if(abs(nums[i] - median) % x != 0) // nums[i] can't be converted to median. Hence return -1.
                return -1;
            
            else
                operations += abs(nums[i] - median) / x;
        }
        
        return operations;
    }
