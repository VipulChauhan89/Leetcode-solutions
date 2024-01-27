class Solution {
public:
    int kInversePairs(int n,int k) 
    {
        const int MOD=1e9+7;
        vector<vector<int>> dp(1001,vector<int>(1001,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                for(int l=0;l<=min(j,i-1);l++)
                {
                    if(j-l>=0)
                    {
                        dp[i][j]=(dp[i][j]+dp[i-1][j-l])%MOD;
                    }
                }
            }
        }
        return dp[n][k];
    }
};
