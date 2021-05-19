/*

https://leetcode.com/problems/trapping-rain-water/


Time : O(N)
Space : O(N)

*/



int trappingWater(int height[], int n)
{
        int i,current_max=INT_MIN,water_trapped=0;
        vector<int>left;
        vector<int>right(n,0);
        
        // Filling left vector
        for(i=0;i<n;i++)
        {
            if(height[i]>current_max)
            {
                current_max=height[i];
            }
            left.push_back(current_max);
        }
        
        current_max=INT_MIN;
        
        //Filling right vector
        for(i=n-1;i>=0;i--)
        {
            if(height[i]>current_max)
            {
                current_max=height[i];
            }
            right[i]=current_max;
        }
        
        //Calculating total water trapped
        
        for(i=0;i<n;i++)
        {
            water_trapped+=min(left[i],right[i])-height[i];
        }
        
        return water_trapped;
}