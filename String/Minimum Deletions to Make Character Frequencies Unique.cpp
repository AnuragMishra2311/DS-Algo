/*

https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

Approach : Maintain a frequency counter. If current frequency has not been seen/used, insert it into set.
           otherwise keep decrementing the frequency unitl that has not been used or frequency reaches 0.

Time Complexity : O(N)
Space Complexity : O(N)

*/

class Solution {
public:
    int minDeletions(string s) 
    {
        int frequency[26] = {};
        int count = 0;
        
        for(auto ch : s)
        {
            frequency[ch - 'a'] += 1;
        }
        
        unordered_set<int>used;
        
        for(auto freq : frequency)
        {
            
            if( used.find(freq) == used.end() )
                used.insert(freq);
            
            else
            {
                while(freq != 0 and used.find(freq) != used.end())
                {
                    count += 1;
                    freq -= 1;
                }
                
                if(freq)
                    used.insert(freq);
            }
        }
        
        return count;
    }
};