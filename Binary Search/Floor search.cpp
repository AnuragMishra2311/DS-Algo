// https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1#

// Note : High will always point to floor.

int findFloor(long long int arr[], int N, long long int K) 
{
    long long int low = 0, high = N-1;
    while(low <= high)
    {
        long long int mid = low + (high - low)/2;

        if(arr[mid] == K)
            return mid;
        
        else if(arr[mid] > K)
            high = mid - 1;
        
        else
            low = mid + 1;
    }

    return high;
}