class Solution {
public:
    int numberOfPaths(vector<vector<int>> &grid,int k)
    {
        int m=grid.size(),n=grid[0].size(),MOD=1e9+7;
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(k,0)));
        dp[0][0][grid[0][0]%k]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    continue;
                }
                for(int r=0;r<k;r++)
                {
                    int newR=(r+grid[i][j])%k;
                    if(i>0)
                    {
                        dp[i][j][newR]=(dp[i][j][newR]+dp[i-1][j][r])%MOD;
                    }
                    if(j>0)
                    {
                        dp[i][j][newR]=(dp[i][j][newR]+dp[i][j-1][r])%MOD;
                    }
                }
            }
        }
        return dp[m-1][n-1][0];
    }
};
