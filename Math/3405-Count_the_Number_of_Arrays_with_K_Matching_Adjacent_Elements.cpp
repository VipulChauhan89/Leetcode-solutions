class Solution {
public:
    int MOD=1e9+7;
    long long modPow(long long a,long long b) 
    {
        long long ans=1;
        while(b>0) 
        {
            if(b%2==1)
            {
                ans=(ans*a)%MOD;
            }
            a=(a*a)%MOD;
            b/=2;
        }
        return ans;
    }

    long long modInv(long long x) 
    {
        return modPow(x,MOD-2);
    }
    int countGoodArrays(int n,int m,int k) 
    {
        vector<long long> fact(n,1);
        for(int i=1;i<n;i++)
        {
            fact[i]=(fact[i-1]*i)%MOD;
        }
        long long comb=(fact[n-1]*modInv(fact[k]))%MOD*modInv(fact[n-1-k])%MOD;
        long long ans=(comb*m)%MOD*modPow(m-1,n-1-k)%MOD;
        return ans;
    }
};
