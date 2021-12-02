/*

https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/

Time Complexity : O(N)
Spcae Complexity : O(N)

*/

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) 
    {
        int n = prices.size();
        vector<int>nextSmallerElement(n, 0);
        stack<int>s;
        
        for(int i = n - 1; i >= 0; i--)
        {
            while(!s.empty() and s.top() > prices[i])
            {
                s.pop();
            }
            
            if(!s.empty())
                nextSmallerElement[i] = s.top();
            
            s.push(prices[i]);
        }
        
        for(int i = 0; i < n; i++)
        {
            prices[i] -= nextSmallerElement[i]; 
        }
        
        return prices;
    }
};