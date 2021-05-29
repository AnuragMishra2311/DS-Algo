/*

https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1#

Space Complexity O(N)
Time Complexity O(N) coz every element is pushed or popped xactly once in stack

*/


vector <int> calculateSpan(int price[], int n)
{
        if(n==1)
        {
            return {1};
        }
        
       vector<int> ans(n,1);
       stack<pair<int,int>>s;
       
       // Push first element
       s.push({price[0],ans[0]});
       
       
       for(int i=1;i<n;i++)
       {
           //If top element is greater than price[i], simply push in stack.
           if(price[i]<s.top().first)
           {
               s.push({price[i],ans[i]});
           }
           
           
           else
           {
               // Pop until stack is not empty OR top<=price[i]
               while(s.empty()!=true && s.top().first<=price[i])
               {
                   ans[i]+=s.top().second;
                   s.pop();
               }
               
               // Push current price into stack
               s.push({price[i],ans[i]});
           }
       }
       
       return ans;
}