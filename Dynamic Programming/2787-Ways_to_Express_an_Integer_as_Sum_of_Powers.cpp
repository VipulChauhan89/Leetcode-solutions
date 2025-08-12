class Solution {
public:
    int numberOfWays(int n,int x)
    {
        const int mod=1e9+7;
        vector<int> dp(n+1,0);
        dp[0]=1;
        int i=1;
        while(i)
        {
            long long power=1;
            for(int j=0;j<x;j++)
            {
                power*=i;
                if(power>n)
                {
                    break;
                }
            }
            if(power>n)
            {
                break;
            }
            for(int j=n;j>=power;j--)
            {
                dp[j]=(dp[j]+dp[j-power])%mod;
            }
            i++;
        }
        return dp[n];
    }
};
