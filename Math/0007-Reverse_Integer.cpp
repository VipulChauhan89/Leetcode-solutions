class Solution {
public:
    int reverse(int x) 
    {
        int sum=0,neg=0;
        if(x<0)
        {
            neg=1;
            x=abs(x);
        }
        while(x!=0)
        {
            int temp=x%10;
            x/=10;
            if(sum>INT_MAX/10||sum<INT_MIN/10) 
            {
                return 0;
            }
            sum=(sum*10)+temp;
        }
        return (neg==1)?-sum:sum;
    }
};
