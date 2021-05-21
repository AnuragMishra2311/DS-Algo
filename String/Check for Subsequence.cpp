/*

https://practice.geeksforgeeks.org/problems/check-for-subsequence4930/1#

Given two strings A and B, find if A is a subsequence of B.

Input:
A = AXY 
B = YADXCP
Output: 0 
Explanation: A is not a subsequence of B
as 'Y' appears before 'A'.

Time Complexity: O(N)
Space Complexity: O(1)

*/

    bool isSubSequence(string A, string B) 
    {
        // code here
        int i=0,j=0;
        while(i<A.size() && j<B.size())
        {
            if(A[i]==B[j])
            {
                i+=1;
            }
            j+=1;
        }
        if(i==A.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }