/*

https://leetcode.com/problems/two-furthest-houses-with-different-colors/

The ans will be optimal, when first house is as left as possible and
second house is as right as possible. That's why we are looking for 
left most house whose color is different than last one and similarly
last house whose color is different from first one. 

Steps 

Find the last house with different color of the fisrt house.
Find the first house with different color of the last house.
Return the max distance of these two options.

Time Complexity : O(N)
Space Complexity : O(1)

*/
class Solution {
    public int maxDistance(int[] colors) {
        int i = 0; 
        int j = colors.length - 1;
        int option1 = 0, option2 = 0;
        
        //First House with different color than last house.
        while(colors[i] == colors[j]){
            i++;
        }
        
        option1 = Math.abs(i - j);
        
        i = 0;
        j = colors.length - 1;
        
        // Last house with different color than first house.
        while(colors[j] == colors[i]){
            j--;
        }
        
        option2 = Math.abs(i - j);
        
        return Math.max(option1, option2);
        
    }
}