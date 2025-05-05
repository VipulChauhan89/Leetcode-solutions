class Solution {
public:
    int numTilings(int n) 
    {
        const int mod=1e9+7;
        if(n==1 || n==2)
        {
            return n;
        }
        vector<long long> dp(n+1);
        dp[0]=dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            dp[i]=(2*dp[i-1]+dp[i-3])%mod;
        }
        return dp[n];
    }
};
