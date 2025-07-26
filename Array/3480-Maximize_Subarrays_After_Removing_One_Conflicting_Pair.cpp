class Solution {
public:
    void insert(int v,int &a,int &b)
    {
        if(v>a)
        {
            b=a;
            a=v;
        }
        else if(v>b)
        {
            b=v;
        }
    }
    long long maxSubarrays(int n,vector<vector<int>> &conflictingPairs)
    {
        vector<pair<int,int>> leftconf(n,{0,0});
        vector<long long> inc(n,0);
        long long ans=0,maxi=0;
        int lf=0,ls=0;
        for(auto &i:conflictingPairs)
        {
            int maxv=max(i[0],i[1]),minv=min(i[0],i[1]);
            insert(minv,leftconf[maxv-1].first,leftconf[maxv-1].second);
        }
        for(int i=1;i<=n;i++)
        {
            auto &lc=leftconf[i-1];
            insert(lc.first,lf,ls);
            insert(lc.second,lf,ls);
            ans+=i-lf;
            auto &j=inc[lf];
            j+=lf-ls;
            maxi=max(maxi,j);
        }
        return ans+maxi;
    }
};
