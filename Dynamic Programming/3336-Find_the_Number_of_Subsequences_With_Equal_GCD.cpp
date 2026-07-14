class Solution {
public:
    int subsequencePairCount(vector<int> &nums)
    {
        int mod=1e9+7,n=nums.size(),mx=*max_element(nums.begin(),nums.end());
        vector<vector<int>> dp(mx+1,vector<int>(mx+1,0));
        dp[0][0]=1;
        for(int num:nums)
        {
            vector<vector<int>> newDp(mx+1,vector<int>(mx+1,0));
            for(int gcd1=0;gcd1<=mx;gcd1++)
            {
                int newGcd1=gcd(gcd1,num);
                for(int gcd2=0;gcd2<=mx;gcd2++)
                {
                    if(dp[gcd1][gcd2]==0)
                    {
                        continue;
                    }
                    int ways=dp[gcd1][gcd2];
                    int newGcd2=gcd(gcd2,num);
                    newDp[gcd1][gcd2]=(newDp[gcd1][gcd2]+ways)%mod;
                    newDp[newGcd1][gcd2]=(newDp[newGcd1][gcd2]+ways)%mod;
                    newDp[gcd1][newGcd2]=(newDp[gcd1][newGcd2]+ways)%mod;
                }
            }
            dp=newDp;
        }
        int ans=0;
        for(int gcdVal=1;gcdVal<=mx;gcdVal++)
        {
            ans=(ans+dp[gcdVal][gcdVal])%mod;
        }
        return ans;
    }
};
