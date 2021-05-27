/*

https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

Iterate from left to right, find first element which is not sorted.From there on find minimum element upto n.
Now traverse from right to left, find first element which is not sorted. From that point find max element upto 0.

Now find starting index by traversing left to right and end index by traversing right to left.

Time complexity O(N)
Space Complexity O(1)

*/

int findUnsortedSubarray(vector<int>& arr) 
    {
        int low=INT_MAX,high=INT_MIN,index;
        int i,n=arr.size(),end,start;
        bool sorted=true;
       

       // Minimum element
        for(i=0;i<n-1;i++)
        {
            if(arr[i]>arr[i+1])
            {
                sorted=false;
            }
            
            if(!sorted)
            {
                low=min(low,arr[i+1]);
            }
        }
        

        // Maximum element
        sorted=true;
        
        for(i=n-1;i>0;i--)
        {
            if(arr[i]<arr[i-1])
            {
                sorted=false;
            }
            
            if(!sorted)
            {
                high=max(high,arr[i-1]);
            }
        }
         
        // Starting index of subarray
        for(i=0;i<n;i++)
        {
            if(arr[i]>low)
            {
                start=i;
                break;
            }
        }
        
        // End index of subarray
        for(i=n-1;i>=0;i--)
        {
            if(arr[i]<high)
            {
                end=i;
                break;
            }
        }
        
        return end-start<0 ? 0 : end-start+1;
    }


/*

Another Approach

Sort the array and then compare original array with sorted one, find the first and last index where elements are mismatching.

Time Complexity O(N*logN)
Space Complexity O(N)

*/

int findUnsortedSubarray(vector<int>& arr) 
    {
        
        int start=INT_MAX,end=INT_MIN;
        
        vector<int>copy(arr.begin(),arr.end());
        sort(copy.begin(),copy.end());
        bool sorted=true;
        
        for(int i=0;i<copy.size();i++)
        {
            if(copy[i]!=arr[i])
            {
                start=min(start,i);
                end=max(end,i);
                sorted=false;
            }
        }
        
        if(!sorted)
            return end-start+1;
        else
            return 0;
}