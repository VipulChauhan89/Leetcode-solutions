class Solution {
public:
    int reverseBits(int n)
    {
        if(n==0)
        {
            return 0;
        }
        int ans=0;
        while(n)
        {
            ans+=1<<(31-__builtin_ctz(n));
            n&=(n-1);
        }
        return ans;
    }
};
