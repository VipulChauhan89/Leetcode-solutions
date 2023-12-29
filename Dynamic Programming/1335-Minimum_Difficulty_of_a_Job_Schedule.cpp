class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty,int d) 
    {
        int jobs=jobDifficulty.size();
        if(jobs<d)
        {
            return -1;
        }
        vector<vector<int>> dp(d,vector<int>(jobs,0));
        dp[0][0]=jobDifficulty[0];
        for(int i=1;i<jobs;i++)
        {
            dp[0][i]=max(dp[0][i-1],jobDifficulty[i]);
        }
        for(int i=1;i<d;i++)
        {
            for(int j=i;j<jobs;j++)
            {
                int mx=jobDifficulty[j];
                dp[i][j]=INT_MAX;
                for(int k=j;k>=i;k--)
                {
                    mx=max(mx,jobDifficulty[k]);
                    dp[i][j]=min(dp[i][j],dp[i-1][k-1]+mx);
                }
            }
        }
        return dp[d-1][jobs-1];
    }
};
