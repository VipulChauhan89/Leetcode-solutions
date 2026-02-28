class Solution {
public:
    int concatenatedBinary(int n) {
        int mod=1000000007;
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            int shift=0,num=i;
            while(num)
            {
                num>>=1;
                shift++;
            }
            ans=((ans<<shift)%mod+i)%mod;
        }
        return (int)ans;
    }
};
