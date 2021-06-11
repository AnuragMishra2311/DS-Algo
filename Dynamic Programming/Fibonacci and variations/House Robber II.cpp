/*

https://leetcode.com/problems/house-robber-ii/

Logic: Same as House Rober, just call that function twice, one function call including first and excluding element 
another function call for excluding first element and including last element.

*/

int compute(vector<int>arr)
{
        int n=arr.size();
        if(n<=2)
        {
            return *max_element(arr.begin(),arr.end());
        }
       int dp[n];
	   dp[0]=arr[0];
	   dp[1]=max(arr[0],arr[1]);
	   
	   for(int i=2;i<n;i++)
	   {
	       dp[i]=max(arr[i]+dp[i-2],dp[i-1]);
	   }
	   
	   return dp[n-1];
}


    int rob(vector<int>& arr) 
    {
        int n=arr.size();
        if(n<=2)
        {
            return *max_element(arr.begin(),arr.end());
        }
        return max(compute(vector<int>(arr.begin(),arr.end()-1)),compute(vector<int>(arr.begin()+1,arr.end())));
    }