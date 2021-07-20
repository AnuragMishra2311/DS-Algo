/*

https://practice.geeksforgeeks.org/problems/counting-elements-in-two-arrays/1/

Approach : Sort second array, then find index of floor for every element of first array.

Time Complexity : O(N*logN) for sorting  + O(M*logN) for m times binary search = O((N+M)*logN)

*/

int binary(int arr[], int x, int n)
    {
        int low = 0, high = n-1;
        while( high >= low )
        {
            int mid = low + (high - low)/2;
            
            arr[mid]>x?high=mid-1:low=mid+1;
        }
        return high+1;
    }
  
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], 
                                 int m, int n)
    {
        
        sort(arr2, arr2+n);
        vector<int>ans;
        for(int i=0; i<m; i++)
        {
            int temp = binary(arr2, arr1[i], n);
            ans.push_back(temp);
        }
        return ans;
    }