// https://practice.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1/

/*

Approach : Start from top right corner, if 
x > mat[i][j] then we can eliminate current row.
x < mat[i][j] we can eliminate current coloumn.  

Time Complexty : O(M+N)
Space Complexity : O(1)

*/

bool search(vector<vector<int> > matrix, int n, int m, int x) 
    {
        int i = 0, j = m-1;
        
        while(i>=0 and i<=n-1 and j>=0 and j<=m-1)
        {
            if(matrix[i][j] == x)
                return true;
                
            if(matrix[i][j] > x)
                j--;
                
            else
                i++;
        }
        
        return false;
    }