class Solution {
public:
    int longestArithSeqLength(vector<int> &nums) 
    {
        int maxLength=0,n=nums.size();
        unordered_map<int,int> dp[n+1];
        for(int i=n-1;i>=0;i--) 
        {
            for(int j=n-1;j>i;j--) 
            {
                int difference=nums[j]-nums[i];
                if(dp[j].count(difference)) 
                {
                    dp[i][difference]=dp[j][difference]+1;
                }
                else 
                {
                    dp[i][difference]=2;
                }
                maxLength=max(maxLength,dp[i][difference]);
            }
        }
        return maxLength;
    }
};
