/*

https://practice.geeksforgeeks.org/problems/pairs-with-specific-difference1533/1#

Intuition: Sort the array in descending order. If arr[i]-arr[i+1] < K, then include this pair, otherwise not.

Space Complexity : O(1)
Time Complexity : O(N*logN)

*/

int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        sort(arr, arr+N, greater<int>());
        int ans = 0, i = 0;
        
        while(i<N-1)
        {
            if( (arr[i] - arr[i+1]) < K )
            {
                ans+= arr[i+1] + arr[i];
                i+=2;
            }
            
            else
                i+=1;
        }
        
        return ans;
    }