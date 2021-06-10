/*

https://practice.geeksforgeeks.org/problems/sort-a-stack/1

Approach : ans will be our sorted stack. 
To sort in increasing order 

1. check if top of ans is smaller than current, if yes then keep poping from ans and 
   store the popped elements(less than current) in temp stack.
2. Now push currrent in ans. 
3. Then finally push all elements of temp in ans.

ans is sorted in increasing order.


Time Complexity : O(N*(N+N)) = O(N*2N) = O(N^2)
Space Complexity: O(N) 


*/

void SortedStack :: sort()
{
   //Your code here
   stack<int>ans;
   stack<int>temp;
   
   while(!s.empty())
   {
       int current = s.top();
       s.pop();
       while(!ans.empty() and current>ans.top())  //pop unitil current<=ans.top()
       {
           temp.push(ans.top());    // push all these elements in temp
           ans.pop();
       }
       ans.push(current);
       
       while(!temp.empty())
       {
           ans.push(temp.top());  //push back temp elements into ans.
           temp.pop();
       }
   }
   
   
   // if we reverse the ans, we will get stack sorted in decreasing order.
   while(!ans.empty())
   {
       s.push(ans.top());
       ans.pop();
   }
   