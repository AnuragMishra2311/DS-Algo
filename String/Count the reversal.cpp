// https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1#

/*

Idea: 1. Remove balanced brackets with the help of stack 
      2. Then count no of left and right brackets left in stack.

Space Complexity O(N)
Time Complexity O(N)

*/

int countRev (string str)
{
    if(str.size()&1) return -1;
    stack<char>s;
    unordered_map<char,char>mp;
    mp['{'] = '}';
    int left=0, right=0;
    for(auto ch:str)
    {
        if(!s.empty() and ch==mp[s.top()])
        {
            s.pop();
        }
        else
        {
            s.push(ch);
        }
    }
    
    while(!s.empty())
    {
        if(s.top()=='{')
        {
            left++;
        }
        else
        {
            right++;
        }
        s.pop();
    }
    return ceil((double)left/2) + ceil((double)right/2);
}

/*

Idea: Left and right represents no of unbalanced brackets respectively.

Time Complexity : O(N)
Space Complexity : O(1)

*/

int countRev (string str)
{
    if(str.size()&1) return -1;
    int left=0, right=0;
    for(auto ch:str)
    {
        if(ch=='}')
        {
            if(left==0)
                right++;
            else
                left--;
        }
        else
            left++;
    }
    return ceil((double)left/2) + ceil((double)right/2);
}