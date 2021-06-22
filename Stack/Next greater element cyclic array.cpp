/*

https://leetcode.com/problems/next-greater-element-ii/


Brute Force : First check in RHS of ith element, if not found then check for LHS of ith element.
Time Complexity : O(N^2)
Space Complexity : O(1)

*/

vector<int> nextGreaterElements(vector<int>& nums) 
{
        int n = nums.size();
        vector<int>ans(n,-1);
        
        for(int i=0;i<n;i++)
        {
            bool found = false;
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]>nums[i])
                {
                    ans[i] = nums[j];
                    found = true;
                    break;
                }
            }
            
            if(!found)
            {
                for(int k=0; k<i; k++)
                {
                    if(nums[k]>nums[i])
                    {
                        ans[i] = nums[k];
                        break;
                    }
                }
            }
        }
        
        return ans;
}


/*

I/P : [1,2,4,3]

Approach : For circular array, consider the array [1,2,4,3] + [1,2,4,3] 

Now, ans for this modified array will be same as that of original array.
Note: No need to extend the array, we will consider extended part as imaginary array and will be accessing it
using the index [i%n].  initialize i = (2*n)-1

Now, run the normal stack algo and we will end up having ans in our ans vector.

Time Complexity  : O(2*N) = O(N)
Space Complexity : O(N)
*/

vector<int> nextGreaterElements(vector<int>& nums) 
{
        int n = nums.size();
        vector<int>ans(n);
        stack<int>s;
        
        for(int i=2*n-1; i>=0; i--)
        {
            while(!s.empty() and s.top()<=nums[i%n])
            {
                s.pop();
            }
            
            !s.empty()? ans[i%n]=s.top(): ans[i%n]=-1;
            
            s.push(nums[i%n]);
        }
        
        return ans;
}