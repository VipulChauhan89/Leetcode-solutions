class Solution {
public:
    int climbStairs(int n) 
    {
        if(n==1)
        {
            return n;
        }
        int a=1,b=1,c=0;
        for(int i=1;i<n;i++)
        {
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};
