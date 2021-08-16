/*

Approach : 2 case may arise
    1. We are including the element, in that case increment end.
    2. We are not including that element, that means we are starting a new subarray. In this case set start = i, end = i.

If current_sum > Max_sum,
    then store the value of start and end.

*/

void print_max_sum_subarray(int arr[], int n)
{
    int start = 0, end = 0, current_sum = arr[0], max_sum = arr[0], save_start, save_end;
    
    for(int i=1; i<n; i++)
    {
        if( arr[i] + current_sum > arr[i])
        {
            end += 1;
            current_sum += arr[i];
        }
        
        else
        {
            current_sum = arr[i];
            start = i;
            end = i;
        }
        
        if (current_sum > max_sum)
        {
            max_sum = current_sum;
            save_start = start;
            save_end = end;
        }
    }
    
    // Displaying subarray with max sum
    for(int i = save_start; i <= save_end; i++)
    {
        cout<<arr[i]<<" ";
    }
}
