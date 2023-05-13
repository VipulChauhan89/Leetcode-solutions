class Solution {
public:
    const int MOD=1e9+7;
    int countGoodStrings(int low,int high,int zero,int one) 
    {
        vector<long long> dp(high+1,0);
        dp[0]=1;
        long long ans=0; 
        for(int i=1;i<=high;i++)
        {
            if(i>=zero)
            {
                dp[i]=(dp[i]%MOD+dp[abs(zero-i)]%MOD)%MOD; 
            }
            if(i>=one)
            {
                dp[i]=(dp[i]%MOD+dp[abs(one-i)]%MOD)%MOD; 
            }
            if(i>=low)
            {
                ans=(ans%MOD+dp[i]%MOD)%MOD;
            }
        }
        return ans;
    }
};
