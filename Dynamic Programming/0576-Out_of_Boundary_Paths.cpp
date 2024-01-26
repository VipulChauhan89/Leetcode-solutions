class Solution {
public:
    const int MOD=1e9+7;
    int solve(vector<vector<vector<int>>> &dp,int maxMove,int x,int y,int &m,int &n)
    {
        if(x<0 || x>=m || y<0 || y>=n)
        {
            return 1;
        }
        else if(maxMove<=0)
        {
            return 0;
        }
        else if(dp[x][y][maxMove]!=-1)
        {
            return dp[x][y][maxMove];
        }
        int ans=0;
        ans=(ans+solve(dp,maxMove-1,x+1,y,m,n))%MOD;
        ans=(ans+solve(dp,maxMove-1,x,y-1,m,n))%MOD;
        ans=(ans+solve(dp,maxMove-1,x-1,y,m,n))%MOD;
        ans=(ans+solve(dp,maxMove-1,x,y+1,m,n))%MOD;
        dp[x][y][maxMove]=ans;
        return ans;
    }
    int findPaths(int m,int n,int maxMove,int startRow,int startColumn) 
    {
        
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return solve(dp,maxMove,startRow,startColumn,m,n);
    }
};
