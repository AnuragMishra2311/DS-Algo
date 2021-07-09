 /*
 
https://practice.geeksforgeeks.org/problems/rotation4723/1#

Approach : Find the element arr[i] such that arr[i]>arr[i+1], return i+1 as answer.

If arr[mid]<arr[n-1] then 2nd half of array is sorted ,search in first half else search in 2nd half.

*/

int findKRotation(int arr[], int n) 
	{
	    int low = 0, high = n-1;
	    while(low <= high)
	    {
	        
	       int mid = low + (high - low)/2;
	       
	       if(arr[mid] > arr[mid+1])
	            return mid + 1;
	            
	       if(arr[mid] < arr[n-1])
	            high = mid - 1;
	       else
	            low = mid + 1; 
	    }
	    
	    return 0;
	}