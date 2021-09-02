// https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1#

// Time Complexity : O(M + N)
// Space Complexity : O(M + N)
int doUnion(int a[], int n, int b[], int m)  
    {
        unordered_set<int>s;
        for(int i = 0; i<n; i++)
        {
            s.insert(a[i]);
        }
        
        for(int j = 0; j<m; j++)
        {
            s.insert(b[j]);
        }
        
        return s.size();
    }


/* 
If array is sorted, go with this approach. 
Note : Removing duplicates is necessary, in order to do so the function shift() is created.

Consider example : 
A[] = {1,1,1,1,1}
B[] = {3,4,5,6}

if we simply comapre i and j and don't remove duplicates then our ans will be [1,1,1,1,1,3,4,5,6].


Time Complexity : Is_sorted ? O(N + M) : O(N *log N + M * log M)
Space Complexity : O(1)

*/



 void shift(int arr[], int n, int &i, int current)
    {
        while(i < n and arr[i] == current)
        {
            i++;
        }
    }

int doUnion(int a[], int n, int b[], int m)  
    {
        sort(a, a+n);
        sort(b, b+m);
        vector<int>ans;
        
        int i = 0, j = 0;
        while (i < n and j < m)
        {
            if(a[i] > b[j])
            {
                ans.push_back(b[j]);
                shift(b, m, j, b[j]);
            }
            
            else if (a[i] < b[j])
            {
                ans.push_back(a[i]);
                shift(a, n, i, a[i]);
            }
            
            else if(a[i] == b[j])
            {
                ans.push_back(a[i]);
                shift(a, n, i, a[i]);
                shift(b, m, j, b[j]);
            }
            
        }
        
        while(i < n)
        {
            ans.push_back(a[i]);
            shift(a, n, i, a[i]);
        }
        
        
        while(j < m)
        {
            ans.push_back(b[j]);
            shift(b, m, j, b[j]);
        }
        
        return ans.size();
    }
