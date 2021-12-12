/*

https://leetcode.com/problems/watering-plants-ii/

Time Complexity : O(N)
Space Complexity : O(1)

*/

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB)
    {
        int n = plants.size();
        int alicePosition = 0, bobPosition = n - 1;
        int aliceWater = capacityA, bobWater = capacityB;
        int count = 0;
        
        while( alicePosition <= bobPosition )
        {
            
            if( alicePosition == bobPosition )
            {
                // if any of them has water greater than that required by plant, no need to refill. 
                // In case when both of them can't water the plant, one need to refill.
                count += max(aliceWater, bobWater) >= plants[alicePosition] ? 0 : 1;    
                break;
            }
            
            if( plants[alicePosition] > aliceWater)
            {
                aliceWater = capacityA;
                count += 1;
            }
        
            
            if( plants[bobPosition] > bobWater)
            {
                bobWater = capacityB;
                count += 1;
            }
            
            aliceWater -= plants[alicePosition];
            bobWater -= plants[bobPosition];
            alicePosition += 1;
            bobPosition -= 1;
        }
        
        return count;
    }
};