// https://practice.geeksforgeeks.org/problems/nearly-sorted-algorithm/0#

/*

Time Complexity: O(N* log K)
Space Complexity: O(K)

*/

#include <bits/stdc++.h>
using namespace std;

void nearly_sorted(vector<int>&arr, int n, int k)
{
    priority_queue<int, vector<int>, greater<int> >pq;
    int j = 0;
    for(int i = 0; i<n; i++)
    {
        pq.push(arr[i]);
        if(pq.size()>k)
        {
            arr[j] = pq.top();
            j++;
            pq.pop();
        }
    }
    
    while(!pq.empty())
    {
        arr[j] = pq.top();
        pq.pop();
        j++;
    }

}

void print(vector<int>arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() 
{
    int t, n, k, ele;
    cin>>t;
    while(t--)
    {
        cin>> n >> k;
        vector<int>arr(n);
        for(int i=0; i<n; i++)
        {
            cin>>ele;
            arr[i] = ele;
        }
        
        nearly_sorted(arr, n, k);
        
        print(arr);
    }
	return 0;
}