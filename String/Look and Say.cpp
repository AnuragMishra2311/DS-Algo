/* 

https://practice.geeksforgeeks.org/problems/decode-the-pattern1138/1#

Approach: Generate all the ans upto n using ans of n-1th term. 

*/
    
    string lookandsay(int n) 
    {
        // code here
        string prev="1";
        string number="1";
        int count=1;
        string ans="1";
        
        for(int i=1;i<n;i++)
        {
            ans="";
            int j=0;
            while(j<prev.size())
            {
                if(prev[j]!=prev[j+1])
                {
                    ans=ans+to_string(count)+number;
                    number=prev[j+1];
                    count=1;
                }
                else
                {
                    count++;
                }
                
                j++;
            }
            prev=ans;
            number=prev[0];
        }
        
        return ans;
    } 