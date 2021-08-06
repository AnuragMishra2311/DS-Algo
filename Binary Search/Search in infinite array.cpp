// https://www.geeksforgeeks.org/find-position-element-sorted-array-infinite-numbers/

int binary_search(int arr[], int low, int high, int x)
{
    while(low <= high)
    {
        int mid = low + (high - low)/2;

        if(arr[mid] == x)
            return mid;

        else if(arr[mid] > x)
            high = mid - 1;

        else
            low = mid + 1;
    }

    return -1;
}


int infinite_search(int arr[], int x)
{
    int low = 0, high = 1;

    while(arr[high] < x)
    {
        low = high;
        high = high * 2;
    }

    return binary_search(arr, low, high, x);
}