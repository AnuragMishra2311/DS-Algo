/*

https://practice.geeksforgeeks.org/problems/maximum-sum-of-increasing-order-elements-from-n-arrays4848/1#

Time Complexity : O(N log M)
Space Complexity : O(1)

Approach : Sort n arrays. 

           Our last element will be from Nth array, in order to maximise the sum, greedy approach will be to pick
           largest element from Nth Array.
           Then travere in (N-1)th Array and look for largest element that is smaller than prev element.

*/

int maximumSum( int n,int m, vector<vector<int>> &a) 
{
    // Sort Arrays
    for(int i = 0; i < n; i++)
    {
        sort(a[i].begin(), a[i].end());
    }
    
    int prev = a[n-1][m-1];
    int sum = prev;
    for(int i = n - 2; i >= 0; i--)
    {
        int j = m - 1;
        while(j >= 0 and a[i][j] >= prev) // Keep traversing till array[i][j] >= prev element.
        {
            j -= 1;
        }
        
        if(j < 0) // if no element is smaller than prev element, not possible to get the sum hence return 0.
            return 0;
        
        else
        {
            sum += a[i][j];
            prev = a[i][j];
        }
    }
    
    return sum;
}