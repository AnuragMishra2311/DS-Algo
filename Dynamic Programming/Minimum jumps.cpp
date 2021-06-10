/*

https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1#


Recursion: valid only when it is possible to reach last index.

Time Complexity : O(N^N)


*/


int frog(int arr[],int n,int start)
{
    if(start>=n)
    {
        return 0;
    }
    int current_min=INT_MAX-1;
    for(int i=1;i<=arr[start];i++)
    {
        current_min= min(current_min,1+frog(arr,n,start+i));
    }
    return current_min;
}


int minJumps(int arr[], int n)
{
    // Your code here
    return frog(arr,n,0);
}



/* 

O(N^2) Approach

dp[i] = min no of jumps required to reach ith position

initialize dp with INT_MAX

dp[0]=0

    For i=1 to n-1 

        set visited = false 
        check For j=0 to i 
            is it possible to reach ith position from j
                if yes:
                temp = dp[j]+1 steps is required to reach i from j
                update dp[i] = min(temp,dp[i])
                set visited =true
        
        if visited = false that means it is not possible to reach ith position
        return -1


Space Complexity O(N^2)
Time Complexity O(N)

*/

 int minJumps(int arr[], int n)
    {
        vector<int>dp(n,INT_MAX);
        dp[0] = 0;
        
        for(int i=1;i<n;i++)
        {
            bool visited = false;
            for(int j=0;j<i;j++)
            {
                if(arr[j]+j >= i)
                {
                    int temp = dp[j]+1;
                    dp[i] = min(dp[i],temp);
                    visited = true;
                }
                
            }                
            if(!visited)
            {
                return -1;
            }
        }
        return dp[n-1];
    }



/*

Greedy Approach

Space Complexity O(1)
Time Complexity O(N)

i is iterated till n-2, not till last element. Coz if we have a case where we are landing on last position that means we already
have ans in jumps. But since i==current_reach, so we will increment jumps by 1, which will lead to wrong ans. 

Consider xample for above case.

2,3,1,1,4

*/

    int minJumps(int arr[], int n)
    {
        int current_reach = 0;
        int max_reach = 0, jumps=0;
        
        for(int i = 0; i<n-1;i++)
        {
            max_reach = max(arr[i]+i,max_reach);
            
            if(i == current_reach) //Now we need to take a jump to move forward
            {
                jumps++;
                if(i==max_reach)      // it's not possible to reach ith position then return -1
                {
                    return -1;
                }
                current_reach = max_reach;
            }
        }
        
        return jumps;
    }