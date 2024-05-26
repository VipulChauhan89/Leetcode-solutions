class Solution {
public:
    const long long mod=1e9+7;
    long long dp[100001][2][3];
    long long solve(int i,int absent,int late)
    {
        if(i==0)
        {
            return 1;
        } 
        if(dp[i][absent][late]!=-1)
        {
            return dp[i][absent][late];
        } 
        long long ans=solve(i-1,absent,0);
        ans+=(late<2?solve(i-1,absent,late+1):0);
        ans+=(absent==0?solve(i-1,absent+1,0):0);
        return dp[i][absent][late]=ans%mod;
    }
    int checkRecord(int n) 
    {
        fill(&dp[0][0][0],&dp[0][0][0]+(n+1)*6,-1);
        return solve(n,0,0);
    }
};
