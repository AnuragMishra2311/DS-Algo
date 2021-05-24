/*

https://practice.geeksforgeeks.org/problems/max-length-chain/1#

You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. 
A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. 
You have to find the longest chain which can be formed from the given set of pairs. 
 

Example 1:

Input:
N = 5
P[] = {5  24 , 39 60 , 15 28 , 27 40 , 50 90}
Output: 3
Explanation: The given pairs are { {5, 24}, {39, 60},
{15, 28}, {27, 40}, {50, 90} },the longest chain that
can be formed is of length 3, and the chain is
{{5, 24}, {27, 40}, {50, 90}}

*/

/*
Greedy Approach (Same like Activity Problem) 
Time complexity O(N*logN)
Space Complexity O(1)
*/

bool cmp(struct val o1,struct val o2)
{
    return o1.second<o2.second;
}

int maxChainLen(struct val p[],int n)
{
    sort(p,p+n,cmp);
    int ans=0,count=1;
    
    int last_ele=p[0].second;
    
    for(int i=1;i<n;i++)
    {
        if(p[i].first>last_ele)
        {
            count+=1;
            last_ele=p[i].second;
        }
    }
    
    return count;
}



/* 

DP Approach
Time Complexity O(N^2)
Space Complexity O(N)

*/


bool cmp(struct val o1,struct val o2)
{
    return o1.first<o2.first;
}


int maxChainLen(struct val p[],int n)
{
    sort(p,p+n,cmp);
    
    int dp[n];
    dp[0]=1;
    
    for(int i=1;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(p[i].first>p[j].second)
            {
                if(dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                }
            }
        }
    }
    
    return *max_element(dp,dp+n);
}