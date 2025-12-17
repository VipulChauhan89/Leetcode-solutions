class Solution {
public:
    long long maximumProfit(vector<int> &prices,int k)
    {
        int n=prices.size();
        vector<vector<long long>>dp(n+1,vector<long long>(k+2,0)),mx1(n+1,vector<long long>(k+2,-1e12)),mx2(n+1,vector<long long>(k+2,-1e12));
        for(int i=1;i<=k;i++)
        { 
            mx1[n-1][i]=prices.back();
            mx2[n-1][i]=-prices.back();
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=1;j<=k;j++)
            {
                dp[i][j]=max(dp[i][j],dp[i+1][j]);
                long long mxi= mx1[i+1][j],mxj= mx2[i+1][j];
                dp[i][j]=max(dp[i][j],mxi-prices[i]);
                dp[i][j]=max(dp[i][j],mxj+prices[i]);
                mx1[i][j]= max({mx1[i][j],prices[i]+dp[i+1][j-1],mx1[i+1][j]});
                mx2[i][j]=max({mx2[i][j],dp[i+1][j-1]-prices[i],mx2[i+1][j]});
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dp[i][k]);
        }
        return ans;
    }
};
