/* https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1/

Time Complexity : O(N * log M) M = summation of array.
Space Complexity : O(1)

*/

bool is_possible(int arr[], long long max_time, int k, int n)
    {
        
        long long current_time = 0;
        int painters = 1;
        
        for(int i = 0 ; i < n; i++)
        {
            current_time += arr[i];
            
            if(current_time > max_time)
            {
                painters += 1;
                current_time = arr[i];
            }
            
            if(painters > k)
                return false;
        }
        
        return true;
    }
  
    long long minTime(int arr[], int n, int k)
    {
        long long high = 0, low = INT_MIN, ans;
        
        for(int i = 0; i<n; i++)
        {
            high += arr[i];
            if(arr[i] > low)
                low = arr[i];
        }
        
        while (high >= low)
        {
            long long mid = low + (high - low)/2;
            
            if ( is_possible(arr, mid, k, n ) )
            {
                high = mid - 1;
                ans = mid;
            }
                
            else
                low = mid + 1;
        }
        
        return ans;
    }
