class Solution {
public:
    int longestCommonSubsequence(string text1,string text2) 
    {
        int t1Len=text1.length(),t2Len=text2.length();
        vector<vector<int>> dp(t1Len+1,vector<int>(t2Len+1,0));
        for(int i=1;i<=t1Len;i++)
        {
            for(int j=1;j<=t2Len;j++)
            {
                dp[i][j]=((text1[i-1]==text2[j-1])?dp[i-1][j-1]+1:max(dp[i-1][j],dp[i][j-1]));
            }
        }
        return dp[t1Len][t2Len];
    }
};
