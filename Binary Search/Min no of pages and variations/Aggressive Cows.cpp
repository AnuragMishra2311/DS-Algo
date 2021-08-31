/*

https://www.spoj.com/problems/AGGRCOW/

Minimum Distance = 1 when stalls are installed at contigous locations and every stall has one cow.
Maximum Distance = stall at last position - stall at first position i.e when we only have 2 cows.

Use binary search in the above mentioned search space to check if it is possible to put cows with a minimum distance of (mid).

Time Complexity : O(N * log N)

*/


#include <bits/stdc++.h>
using namespace std;

bool is_possible(vector<int>stalls, int number_of_cows, int minimum_distance_bw_2_cow)
{
    int count = 1, prev = stalls[0], n = stalls.size();
    for( int i = 1; i < n; i++)
    {
        if( (stalls[i] - prev ) >= minimum_distance_bw_2_cow)
        {
            count++;
            prev = stalls[i];
        }
      
        if( count == number_of_cows)
            return true;
        
    }
    
    return false;
}


int agressive_cows(vector<int>stalls, int number_of_cows)
{
    int n = stalls.size(), ans;
    int low = 1;
    int high = stalls[ n - 1] - stalls[0];
    while(high >= low)
    {
        int mid = low + (high - low)/2;
        
        if(is_possible(stalls, number_of_cows, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}


int main()
{
    int number_of_stalls, number_of_cows, test_cases;
    cin >> test_cases;
    while(test_cases --)
    {
        cin >> number_of_stalls;
        cin >> number_of_cows;
        
        vector<int>stalls;
        for( int i = 0; i < number_of_stalls; i++)
        {
            int x;
            cin >> x;
            stalls.push_back(x);
        }
        
        // Sort in order to apply binary search
        sort(stalls.begin(), stalls.end());
        
        cout << agressive_cows(stalls, number_of_cows) << endl;   
    }
    return 0;
}
