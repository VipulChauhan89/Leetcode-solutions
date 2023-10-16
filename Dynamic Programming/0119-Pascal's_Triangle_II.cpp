class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        rowIndex++;
        vector<int> ans;
        vector<vector<int>> dp(rowIndex,vector<int>(1,1));
        for(int i=1;i<rowIndex;i++)
        {
            dp[i].resize(i+1,1);
            for(int j=1;j<i;j++)
            {
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];   
            }
        }
        for(int j=0;j<rowIndex;j++)
        {
            ans.push_back(dp[rowIndex-1][j]);
        }
        return ans;
    }
};
