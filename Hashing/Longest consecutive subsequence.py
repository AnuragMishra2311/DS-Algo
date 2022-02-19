'''
https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1#

Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers 
can be in any order.

Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output: 6
Explanation: The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6 numbers form the longest consecutive subsquence.

'''

# Sorting 
# Time Complexity O(N*logN)
# Space Complexity O(1)

def findLongestConseqSubseq(arr, N):
    #code here
    arr.sort()
    
    count=1
    maximum_length=1
    
    for i in range(N-1):
        if arr[i]+1==arr[i+1]:
            count+=1
            if count>maximum_length:
                maximum_length=count
        elif arr[i]+1<arr[i+1]:
            count=1
    return maximum_length


'''
Using Hashing
Time complexity O(N)
Space Complexity O(N)


Approach : Check if current element is first element of the continous series, if so iterate until we get last element and keep the
track of Counter
'''

from collections import Counter

def findLongestConseqSubseq(arr, N):
    #code here
    d=Counter(arr)
    count=maximum=1
    for ele in d.keys():
        x=ele
        if d[ele-1]==0:  # ele is first element of series
            while(d[x+1]!=0):
                count+=1
                x+=1
            if count>maximum:
                maximum=count
            count=1
        
    return maximum