class Solution {
public:
    int count_set_bits(int n)
    {
        int count=0;
        while(n)
        {
            count+=n&1;
            n>>=1;
        }
        return count;
    }
    int minimizeXor(int num1,int num2) 
    {
        int ans=0,n2=count_set_bits(num2);
        for(int i=31;i>=0 && n2;i--)
        {
            if((num1 & (1<<i)))
            {
                ans=(ans | (1<<i));
                n2--;
            }
        }
        for(int i=0;i<32 && n2;i++)
        {
            if(!(ans & (1<<i)))
            {
                ans=(ans | (1<<i));
                n2--;
            }
        }
        return ans;
    }
};
