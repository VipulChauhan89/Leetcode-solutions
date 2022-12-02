class Solution {
public:
    int mySqrt(int x) 
    {
        int l=0,h=INT_MAX,ans=0;
        while(l<=h)
        {
            long long int m=l+(h-l)/2;
            if(m*m<=x)
            {
                ans=m;
                l=m+1;
            }
            else
            {
                h=m-1;
            }
        }
        return ans;
    }
};
