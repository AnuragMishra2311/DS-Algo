/*

https://leetcode.com/problems/flood-fill/

Time Complexity : O(M*N)
Space Complexity : O(M*N) // recursion call stack.

*/


bool check(int i, int j, int m, int n)
    {
        if(i<0 or j<0 or i>=m or j>=n)
            return false;
        
        return true;
    }
    
    void dfs(vector<vector<int>>&image, int i, int j, int m, int n,int old_clr, int new_clr)
    {
        
        image[i][j] = new_clr;
        
        int di[] = {-1, 0, 1, 0};
        int dj[] = {0, 1, 0, -1};
        
        for(int k=0; k<4; k++)
        {
            int ni = i + di[k];
            int nj = j + dj[k];
            
            if(check(ni, nj, m, n) and image[ni][nj]==old_clr)
            {
                dfs(image, ni, nj, m, n, old_clr, new_clr);
            }
            
        }
    }


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
{
    int m = image.size();
    int n = image[0].size();
    
    int old_clr = image[sr][sc];
    if(old_clr != newColor) // If new_clr == old_clr, no need to call dfs.
        dfs(image, sr, sc, m, n, old_clr, newColor);
    return image;
}

