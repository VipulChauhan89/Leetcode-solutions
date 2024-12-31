class Solution {
public:
    const int MOD=1e9+7;
    int back(vector<vector<int>> &grid,int i,int j,int current,int k,vector<vector<vector<int>>> &dp)
    {
        int n=grid.size(),m=grid[0].size();
        if(i==n-1 && j==m-1)
        {
            return (((current^grid[i][j])==k)?1:0);
        }
        if(dp[i][j][current]!=-1)
        {
            return dp[i][j][current];
        }
        int path=0;
        if(i+1<n)
        {
            path=(path+back(grid,i+1,j,current^grid[i][j],k,dp))%MOD;
        }
        if(j+1<m)
        {
            path=(path+back(grid,i,j+1,current^grid[i][j],k,dp))%MOD;
        }
        return dp[i][j][current]=path;
    }
    int countPathsWithXorValue(vector<vector<int>> &grid,int k) 
    {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(16,-1)));
        return back(grid,0,0,0,k,dp);
    }
};
