class Solution {
public:
    int minimumArea(vector<vector<int>> &grid)
    {
        int n=grid.size(),m=grid[0].size();
        int iMn=INT_MAX,iMx=INT_MIN,jMn=INT_MAX,jMx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    continue;
                }
                iMn=min(iMn,i);
                iMx=max(iMx,i);
                jMn=min(jMn,j);
                jMx=max(jMx,j);
            }
        }
        return (iMx-iMn+1)*(jMx-jMn+1);
    }
};
