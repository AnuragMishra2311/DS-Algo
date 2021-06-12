/*
https://practice.geeksforgeeks.org/problems/kth-smallest-element5545-1587115620/1/?track=DSA-Foundation-Heap#

Time Complexity O(N*logK)
*/
    
    
    int kthSmallest(int arr[], int n, int k)
    {
        priority_queue<int,vector<int>,greater<int>>pq(arr,arr+n);
        int i=0;
        while(!pq.empty() and i<k-1)
        {
            pq.pop();
            i++;
        }
        return pq.top();
    }