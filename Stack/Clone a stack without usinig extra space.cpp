/*

https://practice.geeksforgeeks.org/problems/clone-a-stack-without-usinig-extra-space/1#

Time Complexity : O(N*N)
Space Complexity : O(1)


*/

class Solution
{
    public:
    void clonestack(stack<int> st, stack<int>& cloned)
    {
        while(st.size() != 0)
        {
            int stTop = st.top();
            st.pop();
            int clonedSize = cloned.size();
            int save = cloned.size();

            while(clonedSize > 0)
            {
                int top = cloned.top();
                cloned.pop();
                st.push(top);
                clonedSize -= 1;
            }
            
            cloned.push(stTop);
            
            while(save > 0)
            {
                cloned.push(st.top());
                st.pop();
                save -= 1;
            }
        }
    }
};