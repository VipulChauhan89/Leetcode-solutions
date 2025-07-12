class Solution {
public:
    void solve(int round,int l,int r,int n,int &mn,int &mx,vector<vector<vector<bool>>> &dp)
    {
        if(dp[round][l][r])
        {
            return;
        }
        dp[round][l][r]=1;
        if(l>r)
        {
            return solve(round,r,l,n,mn,mx,dp);
        }
        if(l==r)
        {
            mn=min(round,mn);
            mx=max(round,mx);
            return;
        }
        int half=(n+1)/2,iN=min(l,half);
        for(int i=1;i<=iN;i++)
        {
            int j0=max(l-i+1,1);
            for(int j=min(half,r)-i;j>=j0;j--)
            {
                if(l+r-(i+j)<=n/2)
                {
                    solve(round+1,i,j,half,mn,mx,dp);
                }
            }
        }
    }
    vector<int> earliestAndLatest(int n,int firstPlayer,int secondPlayer)
    {
        int mn=6,mx=1;
        vector<vector<vector<bool>>> dp(6,vector<vector<bool>>(28,vector<bool>(29)));
        solve(1,firstPlayer,n+1-secondPlayer,n,mn,mx,dp);
        return {mn,mx};
    }
};
