/* 

https://www.hackerrank.com/challenges/append-and-delete/problem?h_r=profile



Idea: Calculate minimum number of insertions and deletions needed to convert s->t. Let this be total_req.

If k==total_req or k-total_req % 2 ==0 then we can convert s->t. To understand latter condition consider 

s=abc
t=abd
k=3

total_req= 1
k - total_req=2
Now,we can play with last character that is delete and append last character multiple time to make total_req = k. Only if k-total_req is even.

Last condition k>=2*n is for cases where we can delete all characters and append all of them after that.

example:
s=abc
t=abc
k=7

*/


string appendAndDelete(string s, string t, int k) 
{
    int m=s.size(),n=t.size(),i=0;
    while(i<m && i<n && s[i]==t[i])
    {
        i+=1;
    }
    int del=m-i;
    int app=n-i;
    int total_req=del+app;
    if( (k>=total_req && (k-total_req)%2==0 ) || k>=2*n )
    {
        return "Yes";
    }
    else
    {
        return "No";
    }
}
