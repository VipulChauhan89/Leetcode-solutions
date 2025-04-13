class Solution {
public:
    long long solve(long long base,long long exponential,long long mod)
    {
        long long ans=1;
        while(exponential>0)
        {
            if(exponential%2==0)
            {
                base=(base*base)%mod;
                exponential/=2;
            }
            else
            {
                ans=(ans*base)%mod;
                exponential-=1;
            }
        }
        return ans;
    }
    int countGoodNumbers(long long n) 
    {
        long long even=(n+1)/2,odd=n/2,mod=1e9+7;
        return (int)((solve(5,even,mod)*solve(4,odd,mod))%mod);
    }
};
