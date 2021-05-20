/*


https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/


You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.


Logic: We need to consider every peak immediately following a valley to maximize the profit. 
In case we skip one of the peaks (trying to obtain more profit), we will end up losing the 
profit over one of the transactions leading to an overall lesser profit.


Time Complexity O(N)
Space Complexity O(1)

*/



int maxProfit(vector<int>& prices) 
    {
        int current_min=INT_MAX;
        int n=prices.size();
        int total_profit=0;
        
        for(int i=0;i<n;i++)
        {
            if(prices[i]<current_min)
            {
                current_min=prices[i];
            }
            else if(prices[i]-current_min>0)
            {
                total_profit+=prices[i]-current_min;
                current_min=prices[i]; // set minimum to current price
            }
        }
        
        return total_profit;
    }




/*

SAME Q AS ABOVE BUT HERE WE NEED TO RETURN ALL THOSE INTERVALS

https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1/?track=md-arrays&batchId=144#

*/

vector<vector<int> > stockBuySell(vector<int> prices, int n)
{
        
        int current_min=INT_MAX;
        int index_minimum;
        vector< vector<int> > ans;
        
        for(int i=0;i<n;i++)
        {
            vector<int>temp;
            if(prices[i]<=current_min)
            {
                current_min=prices[i];
                index_minimum=i;
            }
            else if(prices[i]-current_min>0)
            {
                temp.push_back(index_minimum);
                temp.push_back(i);
                ans.push_back(temp);
                //cout<<index_minimum<<" "<<i<<endl;
                //cout<<"current_min is "<<current_min<<endl;
                current_min=prices[i];
                index_minimum=i;
            }
        }
        
        return ans;
}