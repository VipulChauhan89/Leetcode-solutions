class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &grid,int n,int m,vector<int> &d)
    {
        int fish=grid[i][j];
        grid[i][j]=0;
        for(int a=0;a<4;a++)
        {
            int r=i+d[a],c=j+d[a+1];
            if(r<0 || r>=n || c<0 || c>=m || grid[r][c]==0)
            {
                continue;
            }
            fish+=dfs(r,c,grid,n,m,d);
        }
        return fish;
    }
    int findMaxFish(vector<vector<int>> &grid) 
    {
        vector<int> d={0,1,0,-1,0};
        int n=grid.size(),m=grid[0].size(),ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]>0)
                {
                    ans=max(ans,dfs(i,j,grid,n,m,d));
                }
            }
        }
        return ans;
    }
};
