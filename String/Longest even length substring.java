/*

https://practice.geeksforgeeks.org/problems/longest-even-length-substring/0

Approach : Considering every point as middle point, expand the substring in both direction. Whenever the condition is satisfied
comapre current length of substring with the previous one.

Time Complexity : O(N*N)
Spcae Complexity : O(1)

Example :
1234123

Consider 1 as midpoint(midpoint is included in left psrt of substring) so leftSum = 1, now expand the substring to include 2, 
So leftSum = 1 and rightSum = 2. We further can't expand the substring as we don't have any element left on LHS.

Consider 2 as midpoint, leftSum = 2 and rightSum = 3, now expand the substring 
leftSum = 2 + 1 = 3
rightSum = 3 + 4 = 7
We can't further increase the substring in left direction and hence stop.


Consider 3 as midpoint, 
leftSum = 3 and rightSum = 4
expand substring in both direction 
leftSum = 3 + 2 = 5
rightSum = 4 + 1 = 5 
Now leftSum = rightSum and hence update the value of maximumLength with 4 (2,3,4,1). 

And so on.

*/

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		sc.nextLine();
		while(t > 0){
    		String s = sc.nextLine();
    		int ans = LongestEvenSubstring(s);
	    	System.out.println(ans);
	    	t -= 1;
		}
	}
	
	public static int LongestEvenSubstring(String s){
	    int maximumLength = 0, j, k, n = s.length(), leftSum, rightSum;
	    
	    for(int i=0; i < n; i++){
	        j = i;
	        k = i + 1;
	        leftSum = 0;
	        rightSum = 0;
	        while(j >=0 && k < n){ // To keep a boundary check while expanding substring in both direction
	            leftSum += (int)s.charAt(j);
	            rightSum += (int)s.charAt(k);
	            
	            if(leftSum == rightSum){
	                maximumLength = Math.max(maximumLength, k-j+1);
	            }
	            
	            j -= 1;
	            k += 1;
	        }
	    }

	    return maximumLength;
	}
}