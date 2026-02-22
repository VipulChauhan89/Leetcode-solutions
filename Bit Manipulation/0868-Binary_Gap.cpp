class Solution {
public:
    int binaryGap(int n)
    {
        int d=0,p=32;
        while(n>0)
        {
            int ctz=countr_zero((unsigned)n);
            d=max(d,ctz-p);
            p=ctz;
            n&=(n-1);
        }
        return d;
    }
};
