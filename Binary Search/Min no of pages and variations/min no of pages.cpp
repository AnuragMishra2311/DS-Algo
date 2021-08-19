 // https://practice.geeksforgeeks.org/problems/relative-sorting4323/1#
 
 
 bool solve(int arr[], int k, int maximum_sum, int n)
    {
        int count = 1, sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            sum = sum + arr[i];
            if(sum > maximum_sum)
            {
                sum = arr[i];
                count++;
            }
        }
        
        
        return  count>k?false:true;
        
    }
    
    
    int findPages(int arr[], int n, int m) 
    {
        if(m > n)
            return -1;
            
        int low = 0;
        for(int i=0; i<n; i++)
        {
            if(arr[i] > low)
            {
                low = arr[i];
            }
        }
        
        int high = accumulate(arr, arr + n, 0);
        int mid, ans = -1;
        
        while( high >= low)
        {
            mid = (low + high)/2;
            
            if(solve(arr, m, mid, n))
            { 
                ans = mid;
                high = mid - 1;
                
            }
                
            else
            {
               low = mid + 1;
            }
        }
        
        return ans;
        
    }