/*

https://practice.geeksforgeeks.org/problems/missing-element-of-ap2228/1#

Time Complexity : O(Log N)
Space Complexity : O(1)

*/

int findMissing(int arr[], int n)
{
    
    int diff = (arr[n - 1] - arr[0]) / n;
 
    int mid, low = 0, high = n - 1;
    
    while (low <= high)
    {   
        mid = (low + high) / 2;
    
        if ((arr[mid] - arr[0]) / diff == mid)
            low = mid + 1;
        
        else
            high = mid - 1;
    }
    
    return arr[high] + diff;
}
