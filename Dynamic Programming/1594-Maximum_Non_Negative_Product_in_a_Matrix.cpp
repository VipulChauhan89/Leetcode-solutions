class Solution {
public:
    int maxProductPath(vector<vector<int>> &grid)
    {
        int mod=1e9+7;
        int n=grid.size(),m=grid[0].size();
        vector<vector<long long>>dp_max(n,vector<long long>(m,0)),dp_min(n,vector<long long>(m,0));
        dp_max[0][0]=dp_min[0][0]=grid[0][0];
        for(int i=1;i<n;i++)
        {
            dp_min[i][0]=dp_max[i][0]=dp_max[i-1][0]*grid[i][0];
        }
        for(int i=1;i<m;i++)
        {
            dp_min[0][i]=dp_max[0][i]=dp_max[0][i-1]*grid[0][i];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                long long a=dp_min[i-1][j]*grid[i][j];
                long long b=dp_max[i-1][j]*grid[i][j];
                long long c=dp_min[i][j-1]*grid[i][j];
                long long d=dp_max[i][j-1]*grid[i][j];
                dp_min[i][j]=min({a,b,c,d});
                dp_max[i][j]=max({a,b,c,d});
            }
        }
        if(dp_max[n-1][m-1]<0)
        {
            return -1;
        }
        return dp_max[n-1][m-1]%mod;
    }
};
