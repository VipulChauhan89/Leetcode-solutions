class Solution {
public:
    double myPow(double x, int n) 
    {
        if(n==0)
        {
            return 1;
        }
        else if(n<0)
        {
            n=abs(n);
            x=1/x;
        }
        if(n%2==0)
        {
            return myPow(x*x,n/2);
        }
        return x*myPow(x,n-1);
    }
};
