// Note : Low will always point to Ceil.

int findCeil(int arr[], int N, int K) 
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
    
    return low==N?-1:low;
}