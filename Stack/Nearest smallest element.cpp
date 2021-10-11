/*

https://practice.geeksforgeeks.org/problems/maximum-difference-1587115620/1/?
Time Complexity : O(N)
Space Complexity : O(N)

*/

 int findMaxDiff(int arr[], int n)
    {
        int LS[n], RS[n], ans = INT_MIN;
        stack<int> s1, s2;
   
        // Nearest smallest on left side
        for(int i = n - 1; i >= 0; i--)
        {
            while(!s1.empty() and arr[i] <= s1.top())
                s1.pop();
                
            s1.empty() ? RS[i] = 0 : RS[i] = s1.top();
            
            s1.push(arr[i]);
        }
        
    
        // Nearest samllest on right side
        for(int i = 0 ; i < n; i++)
        {
            while(!s2.empty() and arr[i] <= s2.top())
                s2.pop();
                
            s2.empty() ? LS[i] = 0 : LS[i] = s2.top();
            
            s2.push(arr[i]);
        }
        
        
        for(int i =0; i<n; i++)
        {
            ans = max(ans, abs(RS[i] - LS[i]));
        }
        
        return ans;
    }
