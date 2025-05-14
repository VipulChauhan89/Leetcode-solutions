class Solution {
public:
    int lengthAfterTransformations(string s,int t,vector<int> &nums) 
    {
        long long mod=1e9+7,ans=0;;
        map<int,map<int,vector<long long>>> m;
        for(int i=0;i<26;i++)
        {
            vector<long long> v(26,0);
            for(int j=1;j<=nums[i];j++)
            {
                v[(i+j)%26]++;
            }
            m[1][i]=v;
        }
        for(int i=2;i<=t;i*=2)
        {
            for(int j=0;j<26;j++)
            {
                vector<long long> v(26,0),pre=m[i/2][j];
                for(int k=0;k<26;k++)
                {
                    auto prex=m[i/2][k];
                    for(int l=0;l<26;l++)
                    {
                        v[l]+=(pre[k]%mod*prex[l]%mod);
                        v[l]%=mod;
                    }
                }
                m[i][j]=v;
            }
        }
        vector<long long> c(26,0);
        for(auto &i:s)
        {
            c[i-'a']++;
        }
        int maxi=(1<<30);
        while(t)
        {
            if(t>=maxi)
            {
                vector<long long> v(26,0);
                for(int i=0;i<26;i++)
                {
                    vector<long long> pre=m[maxi][i];
                    for(int j=0;j<26;j++)
                    {
                        v[j]+=(c[i]%mod*pre[j]%mod);
                        v[j]%=mod;
                    }
                }
                c=v;
                t-=maxi;
            }
            maxi/=2;
        }
        for(int i=0;i<26;i++)
        {
            ans+=c[i];
            ans%=mod;
        }
        return ans;
    }
};
