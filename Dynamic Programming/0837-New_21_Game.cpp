class Solution {
public:
    double new21Game(int n,int k,int maxPts) 
    {
        if(k==0 || k+maxPts<=n)
        {
            return 1;
        }
        vector<double> dp(n+1);
        double currSum=1,ans=0;
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            dp[i]=currSum/maxPts;
            if(i<k)
            {
                currSum+=dp[i];
            }
            else
            {
                ans+=dp[i];
            }
            if(i-maxPts>=0)
            {
                currSum-=dp[i-maxPts];
            }
        }
        return ans;
    }
};
