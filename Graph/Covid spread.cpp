// https://practice.geeksforgeeks.org/problems/269f61832b146dd5e6d89b4ca18cbd2a2654ebbe/1/?

bool check(int i, int j, int n, int m)
{
    if(i<0 or j<0 or i>=n or j>=m)
        return false;
    return true;
}


int helpaterp(vector<vector<int>> hospital)
    {
        int n = hospital.size(), m = hospital[0].size();
        int t = -1, healthy = 0; 
        queue<pair<int, int >>q;
        
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(hospital[i][j] == 2)
                {
                    q.push({i , j});
                }
                
                if(hospital[i][j] == 1)
                {
                    healthy++;
                }
                
            }
        }
        
        int di[] = {-1, 0, 1, 0};
        int dj[] = {0, 1, 0, -1};
        
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int i = q.front().first;
                int j = q.front().second;
                
                for(int k = 0; k < 4; k++)
                {
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    
                    if(check(ni, nj, n, m) and hospital[ni][nj] == 1)
                    {
                        healthy--;
                        hospital[ni][nj] = 2;
                        q.push({ni , nj});
                    }
                }
                
                q.pop();
            }
            
            t++;
        }
        
        return healthy == 0 ? t :-1;
    }
