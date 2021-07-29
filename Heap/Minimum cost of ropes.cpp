// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1/?

/*

Insert array elements in priority Q. Pop 2 elements and then push the sum of these 2 elements back into queue.

*/

long long minCost(long long arr[], long long n) 
    {
        priority_queue<long long, vector<long long>, greater<long long>>pq(arr, arr + n);
        
        long long ans = 0;
        while(pq.size()>=2)
        {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            
            ans += first + second;
            
            pq.push(first + second);
        }
    
        return ans;
    }

