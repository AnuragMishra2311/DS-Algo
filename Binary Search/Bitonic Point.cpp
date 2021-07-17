// https://practice.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array3001/1/

// Time complexity : O(Log n)

int findMaximum(int arr[], int n) 
	{
	    int low = 0, high = n;
	    while(high >= low)
	    {
	       int mid = low + (high-low)/2;
	        
	       if( (mid==0 or arr[mid]>arr[mid-1]) and ( mid == n-1 or arr[mid+1]<arr[mid]))
	            return arr[mid];
	            
	       if(arr[mid-1]<arr[mid])
	           low = mid + 1;
	           
	       else
	           high = mid - 1;
	       
	    }
	}