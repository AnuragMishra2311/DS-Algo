/* https://practice.geeksforgeeks.org/problems/three-sum-closest/1/?

Same 3 sum logic

Time Complexity : O(N*LogN) + O(N*N)
Space Complrxity : O(1)

*/
int threeSumClosest(vector<int> arr, int target) 
    {
        sort(arr.begin(), arr.end());
        int n = arr.size(), ans = INT_MAX , minimum_difference = INT_MAX;
        
        for(int i =0; i<n-2; i++)
        {
            int j = i + 1, k = n - 1;
            while(j < k)
            {
                int current_sum = arr[i] + arr[j] + arr[k];
                if(abs(current_sum - target) < minimum_difference)
                {
                    minimum_difference = abs(current_sum - target);
                    ans = current_sum;
                }
                    
                if( current_sum > target)
                    k--;
                else
                    j++;
            }
        }
        
        return  ans;
    }