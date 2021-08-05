// https://www.geeksforgeeks.org/search-almost-sorted-array/

// Time complexity: O(log*N)
// Space Complexity: O(1)

int search_nearly_sorted(int arr[], int n, int x)
{
    int low = 0, high = n - 1;

    while(low <= high)
    {
        int mid = low + (high - low )/2;

        if(arr[mid] == x)
            return mid;

        else if(mid-1 >= low and arr[mid-1] == x)
            return mid - 1;

        else if(mid + 1 <= high and arr[mid+1] == x)
            return mid + 1;

        if(arr[mid] > x)
            high = mid - 2;

        else
            low = mid + 2;
    }
    return -1;
}