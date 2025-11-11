class Solution {
public:
    int findMaxForm(vector<string> &strs,int m,int n)
    {
        vector<vector<int> > dp(m+1,vector<int>(n+1,0));
        for(auto &s:strs)
        {
            int len=s.size(),c0=count(s.begin(),s.end(),'0'),c1=len-c0;
            for(int i=m;i>=c0;i--)
            {
                for(int j=n;j>=c1;j--)
                {
                    dp[i][j]=max(dp[i][j],dp[i-c0][j-c1]+1);
                }
            }
        }
        return dp[m][n];
    }
};
