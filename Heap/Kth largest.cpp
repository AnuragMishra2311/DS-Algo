/*

https://practice.geeksforgeeks.org/problems/kth-largest-element5034/1/?track=DSA-Foundation-Heap&batchId=197

Time Complexity O(N*logK)
*/


    int KthLargest(int arr[], int n, int k) 
    {
        priority_queue<int>pq(arr,arr+n);
        int i=0;
        while(!pq.empty() and i<k-1)
        {
            pq.pop();
            i++;
        }
        return pq.top();
    }