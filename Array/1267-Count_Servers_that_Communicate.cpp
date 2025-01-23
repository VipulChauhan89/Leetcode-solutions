class Solution {
public:
    int countServers(vector<vector<int>> &grid) 
    {
        int n=grid.size(),m=grid[0].size(),ans=0;
        vector<int> row(n,0),column(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    row[i]++;
                    column[j]++;
                }
            }
        }   
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && (row[i]>1 || column[j]>1))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
