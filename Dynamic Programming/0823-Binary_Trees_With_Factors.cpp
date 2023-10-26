class Solution {
public:
    const int MOD=1e9+7;
    int numFactoredBinaryTrees(vector<int> &arr) 
    {
        int ans=0;
        sort(arr.begin(),arr.end());
        unordered_map<int,long> dp;
        for(auto i:arr)
        {
            dp[i]=1;
            for(auto j:arr)
            {
                if(i%j==0 && dp.find(i/j)!=dp.end())
                {
                    dp[i]+=dp[j]*dp[i/j];
                }
            }
        }
        for(auto &i:dp)
        {
            ans=(ans+i.second)%MOD;
        }
        return ans;
    }
};
