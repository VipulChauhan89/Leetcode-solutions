class Solution {
public:
    long long mostPoints(vector<vector<int>> &questions) 
    {
        int n=questions.size();
        vector<long long> dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            int point=questions[i][0];
            int jump=questions[i][1];
            int next=min(n,jump+i+1);
            dp[i]=max(dp[i+1],point+dp[next]);
        }
        return dp[0];
    }
};
