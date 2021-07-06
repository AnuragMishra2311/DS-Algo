// https://leetcode.com/problems/valid-parentheses/

// Time complexity : O(N)
// Space complexity : O(N) 

bool isValid(string str) 
    {
        unordered_map<char,char>mp;
        mp['('] = ')';
        mp['{'] = '}';
        mp['['] = ']';
        
        stack<int>s;
        for(auto it:str)
        {
            if(!s.empty() and mp[s.top()]==it)
            {
                s.pop();
            }
            else
            {
                s.push(it);
            }
        }
        
        return s.size()==0;
    }