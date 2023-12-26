class Solution {
public:
    const int mod=1000000007;
    int solve(vector<vector<int>> &dp,int n,int k,int target)
    {
        if(target==0 && n==0)
        {
            return 1;
        }
        else if(n==0 || target<=0)
        {
            return 0;
        }
        else if(dp[n][target]!=-1)
        {
            return dp[n][target]%mod;
        }
        int ways=0;
        for(int i=1;i<=k;i++)
        {
            ways=(ways+solve(dp,n-1,k,target-i))%mod;
        }
        dp[n][target]=ways%mod;
        return dp[n][target];
    }
    int numRollsToTarget(int n,int k,int target) 
    {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solve(dp,n,k,target);
    }
};
