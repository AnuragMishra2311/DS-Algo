/*

https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/

Intuition : Irrespective of what path the robot takes, it will have to traverse all the rows between startRow and homeRow
and all the columns between startCol and homeCol.
Hence, making any other move other than traversing the required rows and columns will potentially incur more cost which 
can be avoided.

Time Complexity : O(M + N)
Space Complexity : O(1)

*/

int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) 
    {
        int horizontal_direction, vertical_direction;
        
        int startRow = startPos[0], startCol = startPos[1];
        int homeRow = homePos[0], homeCol = homePos[1];
        int cost = 0;
        
        // Left or right ?
        if(homeCol > startCol)
            horizontal_direction = 1;
        else
            horizontal_direction = -1;
        
        // up or down ?
        if(homeRow > startRow)
            vertical_direction = 1;
        else
            vertical_direction = -1;
        
        // horizontal movement
        while(startCol != homeCol)
        {
            startCol += horizontal_direction;
            cost += colCosts[startCol];
        }
        
        // vertical movement
        while(startRow != homeRow)
        {
            startRow += vertical_direction;
            cost += rowCosts[startRow];
        }
        
        return cost;
    }
    