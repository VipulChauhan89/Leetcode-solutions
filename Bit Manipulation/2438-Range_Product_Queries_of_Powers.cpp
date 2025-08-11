class Solution {
public:
    vector<int> productQueries(int n,vector<vector<int>> &queries)
    {
        const int mod=1e9+7;
        vector<int> powers,ans;
        int p=1;
        while(n>0)
        {
            if(n&1)
            {
                powers.push_back(p);
            }
            p<<=1;
            n>>=1;
        }
        for(int i=0;i<queries.size();i++)
        {
            p=1;
            for(int j=queries[i][0];j<=queries[i][1];j++)
            {
                p=((long long)p*powers[j])%mod;
            }
            ans.push_back(p);
        }
        return ans;
    }
};
