/* 

https://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency-1587115621/1#

Given an array of integers, sort the array according to frequency of elements. That is elements that have higher frequency come first. 
If frequencies of two elements are same, then smaller number comes first.

Example :

Input:
N = 5
A[] = {5,5,4,6,4}
Output: 4 4 5 5 6
Explanation: The highest frequency here is
2. Both 5 and 4 have that frequency. Now
since the frequencies are same then 
smallerelement comes first. So 4 4 comes 
firstthen comes 5 5. Finally comes 6.
The output is 4 4 5 5 6.


Time Complexity : O(N*LogN)
Space complexity : O(N)

*/


bool cmp(pair<int,int>p1,pair<int,int>p2)
{
    if(p1.second==p2.second)
    {
        return p1.first<p2.first;
    }
    else
    {
        return p1.second>p2.second;
    }
}


vector<int> sortByFreq(int arr[],int n)
{
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]+=1;
        }
        
        vector<pair<int,int>>temp; //value,Count
        for(auto x:mp)
        {
            temp.push_back({x.first,x.second});
        }
        
        sort(temp.begin(),temp.end(),cmp);
        
        vector<int>ans;
        
        for(auto x:temp)
        {
            while(x.second--)
            ans.push_back(x.first);
        }
        
        return ans;
}