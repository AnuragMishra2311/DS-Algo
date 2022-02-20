/*

https://leetcode.com/problems/remove-covered-intervals/

Approach : Sort it on the basis of first value, if two intervals have same first value then the one having larger 2nd value will
           come first.

           Set mini = intervals[i][0]
           maxi = intervals[i][1]

           Now iterate through the intervals and if 
           intervals[i][0] >= mini and intervals[i][1] <= maxi then the current interval can be merged.


TC : O(N log N)
SC : O(1)

*/

class Solution 
{
    public:
    
    static bool cmp(vector<int>v1, vector<int>v2)
    {
        if(v1[0] != v2[0])
            return v1[0] < v2[0];
        
        else
            return v1[1] > v2[1];
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        
        int mini = intervals[0][0];
        int maxi = intervals[0][1];
        int count = 0;
        
        for(int i = 1; i < n; i++)
        {
           if(intervals[i][0] >= mini and intervals[i][1] <= maxi)
               count += 1;
            
            mini = min(mini, intervals[i][0]);
            maxi = max(maxi, intervals[i][1]);
        }
        
       return n - count;
    }
};