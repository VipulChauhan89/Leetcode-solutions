class Solution {
public:
    long long maximumScore(vector<vector<int>> &grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(m==1)
        {
            return 0;
        }
        vector<vector<long long>> col(m,vector<long long>(n+1,0));
        for(int j=0;j<m;j++)
        {
            for(int i=0;i<n;i++)
            {
                col[j][i+1]=col[j][i]+grid[i][j];
            }
        }
        vector<vector<long long>> dp(n+1,vector<long long>(n+1,0));
        vector<vector<long long>> prefMax(n+1,vector<long long>(n+1,0));
        vector<vector<long long>> suffMax(n+1,vector<long long>(n+1,0));
        for(int c=1;c<m;c++)
        {

            vector<vector<long long>> newdp(n+1,vector<long long>(n+1,0));
            for(int curr=0;curr<=n;curr++)
            {
                for(int prev=0;prev<=n;prev++)
                {
                    if(curr<=prev)
                    {
                        long long gain=col[c][prev]-col[c][curr];
                        newdp[curr][prev]=max(newdp[curr][prev],suffMax[prev][0]+gain);
                    }
                    else
                    {
                        long long gain=col[c-1][curr]-col[c-1][prev];
                        newdp[curr][prev]=max({newdp[curr][prev],suffMax[prev][curr],prefMax[prev][curr]+gain});
                    }
                }
            }
            for(int curr=0;curr<=n;curr++)
            {
                prefMax[curr][0]=newdp[curr][0];
                for(int prev=1;prev<=n;prev++)
                {
                    long long penalty=0;
                    if(prev>curr)
                    {
                        penalty=col[c][prev]-col[c][curr];
                    }
                    prefMax[curr][prev]=max(prefMax[curr][prev-1],newdp[curr][prev]-penalty);
                }
                suffMax[curr][n]=newdp[curr][n];
                for(int prev=n-1;prev>=0;prev--)
                {
                    suffMax[curr][prev]=max(suffMax[curr][prev+1],newdp[curr][prev]);
                }
            }
            dp=move(newdp);
        }
        long long ans=0;
        for(int k=0;k<=n;k++)
        {
            ans=max({ans,dp[0][k],dp[n][k]});
        }
        return ans;
    }
};
