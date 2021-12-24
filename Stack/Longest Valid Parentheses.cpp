/*

https://leetcode.com/problems/longest-valid-parentheses/

Time Complexity : O(N)
Space Complexity : O(N)

*/

class Solution {
public:
    int longestValidParentheses(string str) 
    {
        stack<int>s;
        s.push(-1);
        
        int result = 0, n = str.size();
        
        for(int i = 0; i < n; i++)
        {
            if(str[i] == '(')
                s.push(i);
            
            else
            {
                s.pop();
                
                if(!s.empty())
                    result = max(result, i - s.top());
                
                else
                    s.push(i);
            }
        }
        return result;
    }
};