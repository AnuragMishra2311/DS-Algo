/*

https://leetcode.com/problems/set-matrix-zeroes/

Time Complexity : O(M*N)
Space Complexity : O(M + N)

*/

void setZeroes(vector<vector<int>>& matrix) 
    {
        
        int m = matrix.size(), n = matrix[0].size();
        unordered_set<int> rows;
        unordered_set<int> coloumns;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    rows.insert(i);
                    coloumns.insert(j);
                }
            }
        }
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(rows.find(i) != rows.end() or coloumns.find(j) != coloumns.end())
                {
                    matrix[i][j] = 0;
                }
            }
        }
          
    }
