class Solution {
public:
    int cherryPickup(vector<vector<int>> &grid) 
    {
        int row=grid.size(),col=grid[0].size();
        vector<vector<vector<int>>> dp(row,vector<vector<int>>(col,vector<int>(col,-1)));
        for(int i=0;i<col;i++)
        {
            for(int j=0;j<col;j++)
            {
                dp[row-1][i][j]=grid[row-1][i];
                if(i!=j)
                {
                    dp[row-1][i][j]+=grid[row-1][j];
                }
            }
        }
        for(int i=row-2;i>=0;i--)
        {
            for(int j=0;j<col;j++)
            {
                for(int k=0;k<col;k++)
                {
                    int c=grid[i][j];
                    if(j!=k)
                    {
                        c+=grid[i][k];
                    }
                    for(int l=j-1;l<=j+1;l++)
                    {
                        for(int m=k-1;m<=k+1;m++)
                        {
                            if(l>=0 && l<col && m>=0 && m<col)
                            {
                                dp[i][j][k]=max(dp[i][j][k],c+dp[i+1][l][m]);
                            }
                        }
                    }
                }
            }
        }
        return dp[0][0][col-1];
    }
};
