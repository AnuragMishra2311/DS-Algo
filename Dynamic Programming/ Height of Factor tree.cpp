/*

Given a number n, return the height of it's factor tree.
Note : Don't consider 1 and number itself as factor.

N = 8

             8
            / \ 
           2   4
                \
                2
                
 
Height = 3

Approach : dp[i] = height of tree with root as "i".

N = 4

dp[1] = 
dp[2] = 1 + max( dp[j], such that j is factor of 2 ) we don't have any factor of 2 in range [2,2] (the no itself can't be facotr) = 1.
dp[3] = 1 + max( dp[j], such that j is factor of 3 ) we don't have any factor of 3 in range [2,2] = 1.

dp[4] = 1 + max( dp[j], such that j is factor of 4 ) = 1 + dp[2]  =  1 + 1 = 2
 
 
Time Complexity : O(N*N)
Space Complrxity : O(N)

*/

#include <bits/stdc++.h>
using namespace std;


int factor_tree(int n)
{
    int current;
    vector<int>dp(n+1, 1);
    
    for(int i = 2; i <= n; i++)
    {
        current = 0;
        for(int j = i - 1; j >= 2; j--)
        {
            if( i%j == 0 and dp[j] > current )
            {
                current = dp[j];
            }
        }
        
        dp[i] += current;
    }
    
    return dp[n];
}


int main()
{
    int n;
    cin >> n;
    cout << factor_tree(n);
    return 0;
}
