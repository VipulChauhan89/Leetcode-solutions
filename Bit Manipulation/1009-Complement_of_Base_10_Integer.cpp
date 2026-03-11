class Solution {
public:
    int bitwiseComplement(int n)
    {
        int mask = n|1;
        for(int i=0;i<=4;i++)
        {
            mask|=mask>>(1<<i);
        }
        return n^mask;
    }
};
