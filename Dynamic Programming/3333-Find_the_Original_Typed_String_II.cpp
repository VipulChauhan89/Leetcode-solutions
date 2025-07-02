class Solution {
public:
    int possibleStringCount(string word,int k)
    {
        int mod=1e9+7,count=1;
        if(word.empty())
        {
            return 0;
        }
        vector<int> groups,dp(k,0);
        dp[0]=1;
        for(int i=1;i<word.size();i++)
        {
            if(word[i]==word[i-1])
            {
                count++;
            }
            else
            {
                groups.push_back(count);
                count=1;
            }
        }
        groups.push_back(count);
        long long total=1;
        for(auto &i:groups)
        {
            total=(total*i)%mod;
        }
        if(k<=groups.size())
        {
            return total;
        }
        for(auto &i:groups)
        {
            vector<int> newDp(k,0);
            long long sum=0;
            for(int s=0;s<k;s++)
            {
                if(s>0)
                {
                    sum=(sum+dp[s-1])%mod;
                }
                if(s>i)
                {
                    sum=(sum-dp[s-i-1]+mod)%mod;
                }
                newDp[s]=sum;
            }
            dp=newDp;
        }
        long long invalid=0;
        for(int s=groups.size();s<k;s++)
        {
            invalid=(invalid+dp[s])%mod;
        }
        return (total-invalid+mod)%mod;
    }
};
