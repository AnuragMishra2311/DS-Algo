/* 
https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#


Approach : 
Whenver a -ve element is encountered, push it into queue. 
For every window check if q is empty or not, if empty then ans for that window will be 0 otherwise q.front().

Imp: Check if arr[i]=q.front(), that means we need to pop this element from q coz we are excluding i from our current window 
to get next window.

*/


vector<long long> printFirstNegativeInteger(long long int arr[],long long int n, long long int k) 
{
    queue<long long>q;
    vector<long long>ans;
    
    int i=0,j=0;
    while(j<n) 
    {
        if(arr[j]<0) // Push -ve elements in q.
            q.push(arr[j]);
        
        if(j-i+1<k) // keep incrementing j until window size!=k
        {
            j++;
        }
       
        else if(j-i+1 == k) // For windows having size == k.
        {
           if(!q.empty()) // If q not empty, then we have an answer for the present window.
           {
               ans.push_back(q.front());
               
               // If arr[i]=q.front() then pop the element coz we will be remove ith element from our current window.
               if(q.front() == arr[i])
                   q.pop(); 
           }
           
           else
           {
               ans.push_back(0);
           }
            
           i++;
           j++;
        }
    }
    
    return ans;
}