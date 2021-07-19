// https://practice.geeksforgeeks.org/problems/index-of-an-extra-element/1/

int findExtra(int a[], int b[], int n) 
    {
        int low = 0, high = n;
        while(high >= low)
        {
            int  mid = low + (high - low)/2;
         
               
            if(a[mid]!=b[mid] and (mid == 0 or a[mid-1]==b[mid-1]) and (mid==n-1 or a[mid+1]==b[mid]) )
                return mid;
             
                
            if(a[mid] == b[mid])
                low = mid + 1;
                
            else
                high = mid - 1;
        }
    }