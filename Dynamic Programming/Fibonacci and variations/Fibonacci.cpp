//Top Down Approach


vector<long long>memo(1000,-1);

long long findNthFibonacci(int number)
{
        if(memo[number]==-1)
        {
            if(number==0 || number==1)
            {
                memo[number]=number;
            }
            else
            {
                memo[number]=findNthFibonacci(number-1)+findNthFibonacci(number-2);
            }
        }
        return memo[number];
        
}


// Bottom Up Approach


long long findNthFibonacci(int number)
{
        // Your Code Here
        long long int dp[number+1];
        dp[0]=0;
        dp[1]=1;

        for(int i=2;i<=number;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[number];
}