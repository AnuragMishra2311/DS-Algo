/*

https://leetcode.com/problems/first-bad-version/

Time Complexity : O(log N)
Space Complexity : O(1)

*/

int firstBadVersion(int n)
{
        int low = 1, high = n, ans;
        while(low <= high)
        {
            int mid = low + (high - low)/2;

            // Note the boundary conditions, mid == 0 or mid == n. 
            if(mid == 0 or mid == n or (isBadVersion(mid) and isBadVersion(mid - 1) == false))
            {
                ans = mid;
                break;
            }
            
            isBadVersion(mid) ? high = mid - 1 : low = mid + 1;
        }
        
        return ans;
}