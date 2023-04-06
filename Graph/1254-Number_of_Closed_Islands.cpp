class Solution {
public:
    void dfs(vector<vector<int>> &grid,int i,int j)
    {
        int m=grid.size(),n=grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==1)
        {
            return;
        }
        grid[i][j]=1;
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
    int closedIsland(vector<vector<int>> &grid) 
    {
        int m=grid.size(),n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0 && (i==0 || j==0 || i==m-1 || j==n-1))
                {
                    dfs(grid,i,j);
                }
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};
