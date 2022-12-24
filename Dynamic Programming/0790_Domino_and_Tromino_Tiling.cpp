class Solution {
public:
    const int mod=1000000007;
    int numTilings(int n) 
    {
        long dp[5]={0,1,2,5}; 
        for(int i=4;i<=n;i++) 
        {
            dp[i%5]=(2*dp[(i-1)%5]+dp[(i-3)%5])%mod;
        }
        return dp[n%5];
    }
};
