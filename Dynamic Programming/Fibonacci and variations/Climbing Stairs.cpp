/*

https://leetcode.com/problems/climbing-stairs/


Logic : 
When n=1, there is only one way.

n=2  (1 way)
    1->2

n=3 (2 ways) 
    1->2->3
    1->3

n=4 (3 ways)
    1->2->3->4
    1->3->4
    1->2->4

n=5 (5 ways)
    1->2->3->4->5
    1->3->4->5
    1->2->4->5
    1->2->3->5
    1->3->5    


If we clearly observe ans(n) = ans(n-1) + ans(n-2), This is nothing but fibonacci. 

*/


/* 
Bottom UP DP 
Space Complexity O(N)
Time Complexity O(N)
*/
int climbStairs(int n) 
{

    int dp[n+1];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }

    return dp[n];
}



/*

Space Complexity O(1)
Time Complexity O(N)

*/
    int climbStairs(int n) 
    {
        if(n<=2)
        {
            return n;
        }
        
        int first=1,second=1,temp;
        
        for(int i=2;i<=n;i++)
        {
            temp = first + second;
            first = second;
            second = temp;
        }
        return temp;
    }
