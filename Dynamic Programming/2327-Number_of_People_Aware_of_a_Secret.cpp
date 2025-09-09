class Solution {
public:
    int peopleAwareOfSecret(int n,int delay,int forget)
    {
        vector<long long> dp(n+1,0);
        dp[1]=1;
        long long share=0,MOD=1e9+7;
        for(int i=2;i<=n;i++)
        {
            if(i-delay>0)
            {
                share=(share+dp[i-delay]+MOD)%MOD;
            }
            if(i-forget>0)
            {
                share=(share-dp[i-forget]+MOD)%MOD;
            }
            dp[i]=share;
        }
        long long know=0;
        for(int i=n-forget+1;i<=n;i++)
        {
            know=(know+dp[i])%MOD;
        }
        return (int)know;
    }
};
