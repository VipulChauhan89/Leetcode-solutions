class Solution {
public:
    const int mod=1e9+7;
    long long power(long long base,long long exp)
    {
        long long ans=1;
        while(exp>0)
        {
            if(exp&1)
            {
                ans=(ans*base)%mod;
            }
            base=(base*base)%mod;
            exp>>=1;
        }
        return ans;
    }
    long long modInv(long long n)
    {
        return power(n,mod-2);
    }
    int xorAfterQueries(vector<int> &nums,vector<vector<int>> &queries)
    {
        int n=nums.size(),limit=sqrt(n);
        unordered_map<int,vector<vector<int>>> lightK;
        for(auto &q:queries)
        {
            int l=q[0],r=q[1],k=q[2],v=q[3];
            if(k>=limit)
            {
                for(int i=l;i<=r;i+=k)
                {
                    nums[i]=(1LL*nums[i]*v)%mod;
                }
            }
            else
            {
                lightK[k].push_back(q);
            } 
        }
        for(auto &[k,query]:lightK)
        {
            vector<long long> diff(n,1);
            for(auto &q:query)
            {
                int l=q[0],r=q[1],v=q[3];
                diff[l]=(diff[l]*v)%mod;
                int steps=(r-l)/k;
                int next=l+(steps+1)*k;
                if(next<n)
                {
                    diff[next]=(diff[next]*modInv(v))%mod;
                }
            }
            for(int i=0;i<n;i++)
            {
                if(i>=k)
                {
                    diff[i]=(diff[i]*diff[i-k])%mod;
                }
                nums[i]=(1LL*nums[i]*diff[i])%mod;
            }
        }
        int ans=0;
        for(auto &num:nums)
        {
            ans^=num;
        }
        return ans; 
    }
};
