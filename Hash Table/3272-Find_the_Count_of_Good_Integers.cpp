class Solution {
public:
    long long countGoodIntegers(int n,int k) 
    {
        unordered_set<string> s;
        int p=pow(10,(n-1)/2),mod=n%2;
        vector<long long> fact(n+1,1);
        long long ans=0;
        for(int i=p;i<p*10;i++)
        {
            string ss=to_string(i),rev=ss;
            reverse(rev.begin(),rev.end());
            ss+=rev.substr(mod);
            long long pal=stoll(ss);
            if(pal%k==0)
            {
                sort(ss.begin(),ss.end());
                s.insert(ss);
            }
        }
        for(int i=1;i<=n;i++)
        {
            fact[i]=fact[i-1]*i;
        }
        for(auto &i:s)
        {
            vector<int> count(10,0);
            for(auto &j:i)
            {
                count[j-'0']++;
            }
            long long total=(n-count[0])*fact[n-1];
            for(auto &j:count)
            {
                if(j>1)
                {
                    total/=fact[j];
                }  
            }
            ans+=total;
        }
        return ans;
    }
};
