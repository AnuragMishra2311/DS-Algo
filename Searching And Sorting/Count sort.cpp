// https://practice.geeksforgeeks.org/problems/counting-sort/1/?

// Time Complexity : O(N+K)
// Space Complexity : O(K)s

string countSort(string arr)
    {
        int count[26] = {0}; // Since i/p only consists of lowercase alphabets.
        int n = arr.size();
        
        string output(arr);
        
        for(int i=0; i<n; i++)
        {
            count[arr[i]-'a']++;
        }
        
        for(int i=1; i<26; i++)
        {
            count[i] = count[i] + count[i-1];
        }
        
        for(int i=n-1; i>=0; i--)
        {
            output[count[arr[i]-'a']-1] = arr[i];
            count[arr[i]-'a']--;
        }
        
        return output;
    }