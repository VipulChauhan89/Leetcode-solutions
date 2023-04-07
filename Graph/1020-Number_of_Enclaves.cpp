class Solution {
public:
    void dfs(vector<vector<int>> &grid,int i,int j) 
    {
        if(i<0 || j<0 || i==grid.size() || j==grid[i].size() || grid[i][j]!=1) 
        {
            return;
        }
        grid[i][j]=0;
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }

    int numEnclaves(vector<vector<int>> &grid) 
    {
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if(grid[i][j]==1)
                    {
                        dfs(grid,i,j);
                    }
                }
            }
        }

        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
