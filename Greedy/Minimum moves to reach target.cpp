/*

https://leetcode.com/problems/minimum-moves-to-reach-target-score/

Greedy Approach : We want to utilise maximum no of double operations, and at the same time it will be optimal
                  to use double operation on larger number.

Go Backwards, if target is even and double operation >= 1, 
              set target =  target / 2

              else if target is odd :
              set target = target - 1

              repeat till target != 1

*/

class Solution 
{
public:

    int minMoves(int target, int maxDoubles) 
    {
        int moves = 0;
        
        while(target > 1)
        {
            
            if(maxDoubles == 0)
            {
                moves += target - 1;
                break;
            }
            
            moves += 1;
            
            if(target % 2 == 0 and maxDoubles >= 1)
            {
                target /= 2;
                maxDoubles -= 1;
            }
            
            else
            {
                target -= 1;
            }
        }
        
        return moves;
    }
};