/* 

https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1#

Approach: 

    Keep incrementing i and update sum till sum < x. 

    Now start decrementing sum until sum > x

    We are coming out from loop when x>sum, that means count + 1 was the size of window whose sum > x
    So update ans with min(ans, count + 1).

*/


int sb(int arr[], int n, int x)
    {
        int ans = INT_MAX, i = 0, j = 0, sum = 0, count = 0;
        
        while(i<n and j<n)
        {
            // Keep incrementing sum till sum < x
            while(i<n and sum <= x)
            {
                sum += arr[i];
                i++;
                count++;
            }
            
            // Decrement sum till x > sum 
            while(j<n and sum > x)
            {
                sum -= arr[j];
                j++;
                count--;
            }

            ans = min(ans, count + 1);
        }
        
        return ans;
    }