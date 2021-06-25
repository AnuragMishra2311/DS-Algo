/*

https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

Time Complexity O(N*logN)
Space Complexity O(1)

*/


bool canMakeArithmeticProgression(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        if(n<=2)
        {
            return true;
        }
        
        bool valid = true;
        int d = arr[1]-arr[0];
        for(int i=2;i<n;i++)
        {
            if(arr[i]-arr[i-1]!=d)
            {
                valid = false;
                return false;
            }
        }
        
        return valid;
    }