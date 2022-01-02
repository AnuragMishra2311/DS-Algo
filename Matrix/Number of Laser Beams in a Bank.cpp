/*

https://leetcode.com/problems/number-of-laser-beams-in-a-bank/

Time complexity : O(M*N)
Space Complexity : O(1)

*/

class Solution {
public:
    int numberOfBeams(vector<string>& bank) 
    {
        int m = bank.size();
        int n = bank[0].size();
        int prev = 0;
        int result = 0;
        
        for(auto s : bank)
        {
            int count = 0;
            for(int i = 0; i < n; i++)
            {
                if(s[i] == '1')
                    count += 1;
            }
            
            if(count != 0)
            {
                result += count * prev;
                prev = count;
            }
        }
        return result;
    }
};