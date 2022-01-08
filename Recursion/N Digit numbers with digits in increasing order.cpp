/*

https://practice.geeksforgeeks.org/problems/n-digit-numbers-with-digits-in-increasing-order5903/1#

*/

class Solution
{
public:

    vector<int> result;
    
    void solve(int n, string number, int start)
    {
        if(n == 0)
            result.push_back(stoi(number));
            
        for(int i = start; i <= 9; i++)
        {
            string str = number + to_string(i);
            solve(n - 1, str, i + 1);
        }
    }

    
    vector<int> increasingNumbers(int N)
    {
        if (N == 1)
            result.push_back(0);
            
        solve(N, "", 1);
        return result;
    }
};