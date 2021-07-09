// https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1#

// Recursive 
int first(int arr[],int x,int low,int high)
{
    int mid=(low+high)/2;
    if(low>high)
        return -1;

    else if(arr[mid]>x)
        first(arr,x,low,mid-1);

    else if(arr[mid]<x)
        first(arr,x,mid+1,high);

    else
    {
        if(mid==0||arr[mid-1]!=x)
            return mid;
        else
            first(arr,x,low,mid-1);
    }
}



int last(int arr[],int x,int low,int high,int n){
    int mid=(low+high)/2;
    if(low>high){
        return -1;
    }
    else if(arr[mid]>x){
        last(arr,x,low,mid-1,n);
    }
    else if(arr[mid]<x){
        last(arr,x,mid+1,high,n);
    }
    else{
        if(mid==n-1 || arr[mid+1]!=x){
                return mid;
        }
        else{
            last(arr,x,mid+1,high,n);
            }
        }
}


vector<int> find(int arr[], int n, int x) 
{
	return {first(arr,x,0,n-1),last(arr,x,0,n-1,n)};
}



// Iterative 
int first(int n, int arr[], int x)
{
    int low = 0, high = n-1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] == x)
        {
           
            if(mid == 0 || arr[mid-1] != arr[mid])
                return mid;
            else
                high = mid - 1;
        }
        else
            (arr[mid] > x)? high = mid - 1 : low = mid + 1; 
    }
    
    return -1;
}

int last(int n, int arr[], int x)
{
    int low = 0, high = n-1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] == x)
        {
            if(mid == n-1 || arr[mid+1] != arr[mid])
                return mid;

            else
                low = mid + 1;
        }
        else
            (arr[mid] > x)? high = mid - 1 : low = mid + 1; 
    }
    
    return -1;
}


vector<int> find(int arr[], int n , int x )
{
    return {first(n, arr, x),last(n, arr, x)};
}