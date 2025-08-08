class Solution {
public:
    double calculate(vector<vector<double>> &dp,int a,int b)
    {
        if(a<=0 && b<=0)
        {
            return 0.5;
        }
        if(a<=0)
        {
            return 1.0;
        }
        if(b<=0)
        {
            return 0.0;
        }
        if(dp[a][b]!=-1)
        {
            return dp[a][b];
        }
        dp[a][b]=0.25*(calculate(dp,a-100,b)+calculate(dp,a-75,b-25)+calculate(dp,a-50,b-50)+calculate(dp,a-25,b-75));
        return dp[a][b];
    }
    double soupServings(int n) {
        if(n>=4300)
        {
            return 1.0;
        }
        vector<vector<double>> dp(n+1,vector<double>(n+1,-1));
        return calculate(dp,n,n);
    }
};
