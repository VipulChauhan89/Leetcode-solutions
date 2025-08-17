class Solution {
public:
    double new21Game(int n,int k,int maxPts)
    {
        if(k==0 || n>=k+maxPts)
        {
            return 1.0;
        }
        vector<double> dp(n+1);
        dp[0]=1;
        double mx=1,ans=0;
        for(int i=1;i<=n;i++)
        {
            dp[i]=mx/maxPts;
            if(i<k)
            {
                mx+=dp[i];
            }
            else
            {
                ans+=dp[i];
            }
            if(i-maxPts>=0)
            {
                mx-=dp[i-maxPts];
            }
        }
        return ans;
    }
};
