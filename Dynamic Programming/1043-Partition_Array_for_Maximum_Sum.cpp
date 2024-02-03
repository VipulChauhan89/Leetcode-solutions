class Solution {
public:
    int maxSumAfterPartitioning(vector<int> &arr,int k) 
    {
        int n=arr.size();
        vector<int> dp(k,0);
        for(int i=1;i<=n;i++)
        {
            int mxA=0,ans=0,k1=min(k,i);
            for(int j=1;j<=k1;j++)
            {
                mxA=max(mxA,arr[i-j]);
                ans=max(ans,dp[(i-j)%k]+j*mxA);
            }
            dp[i%k]=ans;
        }
        return dp[n%k];
    }
};
