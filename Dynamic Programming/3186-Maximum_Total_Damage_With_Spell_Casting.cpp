class Solution {
public:
    long long maximumTotalDamage(vector<int> &power)
    {
        unordered_map<int,long long> m;
        vector<int> keys;
        for(auto &i:power)
        {
            m[i]++;
        }
        for(auto i:m)
        {
            keys.push_back(i.first);
        }
        sort(keys.begin(),keys.end());
        int n=keys.size();
        vector<long long> dp(n);
        dp[0]=m[keys[0]]*keys[0];
        for(int i=1;i<n;i++)
        {
            long long take=m[keys[i]]*keys[i];
            int prev=upper_bound(keys.begin(),keys.begin()+i,keys[i]-3)-keys.begin()-1;
            if(prev>=0)
            {
                take+=dp[prev];
            }
            dp[i]=max(dp[i-1],take);
        }
        return dp[n-1];
    }
};
