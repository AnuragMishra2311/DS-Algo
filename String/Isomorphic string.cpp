/*

https://leetcode.com/problems/isomorphic-strings/

Time Complexity : O(N)
Space Complexity : O(N)

*/

bool isIsomorphic(string str1, string str2) 
{
        if(str1.length()!=str2.length())
        {
            return false;
        }

        unordered_map<char,char>mp1;
        unordered_map<char,char>mp2;
        
        
        for(int i=0;i<str1.length();i++)
        {
            // If character exists in map1 but corresponding character != str2[i] OR vice versa then return false.
            if( (mp1[str1[i]]&&mp1[str1[i]]!=str2[i]) or (mp2[str2[i]] and mp2[str2[i]]!=str1[i]) )
            {
               return false;
            }
            
            else
            {
                mp1[str1[i]] = str2[i];
                mp2[str2[i]] = str1[i];
            }
        }
        
        return ans;
        
    }