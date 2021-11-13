/* 

https://leetcode.com/problems/daily-temperatures/

Maintain a monotonic stack of pairs
Time Complexity : O(N)
Spcae Complexity : O(N)

*/
vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        stack<pair<int, int>>s;
        int n = temperatures.size() - 1;
        vector<int>ans(n+1); 
        
        for(int i = n; i >= 0; i--)
        {
            // keep poping while current element is greater than top of stack.
            while(!s.empty() and s.top().first <= temperatures[i] )
            {
                s.pop();
            }
            
            // if stack is empty, then there isn't any greater element present.
            if(s.empty())
            {
                ans[i] = 0;
            }
            
            // Top of stack is greater than current element.
            else
            {
                ans[i] = (n - i) - s.top().second;
            }
            
            s.push({temperatures[i], n - i});
        }
        
        return ans;
    }
