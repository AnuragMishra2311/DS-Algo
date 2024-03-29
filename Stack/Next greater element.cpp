/*

https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1#

Approach: The elements in stack will always be in increasing order.

Do the following:

    1. keep popping until stack is not empty and s.top < arr[i]
    2. if stack is empty, ans[i] = -1 else ans[i] = s.top
    3. push arr[i] into stack


Time Complexity  : O(N)
Space Complexity : O(N)

*/

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
        vector<long long>ans(n);
        stack<long long>s;
        for(int i=n-1; i>=0; i--)
        {
           while(!s.empty() and arr[i]>=s.top())
           {
               s.pop();
           }
           
           !s.empty() ? ans[i] = s.top(): ans[i] = -1;
           
           s.push(arr[i]);
           
        }
        
        return ans;
}