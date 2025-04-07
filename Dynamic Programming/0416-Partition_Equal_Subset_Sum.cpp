class Solution {
public:
    bool canPartition(vector<int> &nums) 
    {
        int total=0;
        for(auto &i:nums)
        {
            total+=i;
        }
        if(total%2!=0)
        {
            return false;
        }
        int target=total/2;
        vector<bool> dp(target+1,false);
        dp[0]=true;
        for(auto &i:nums)
        {
            for(int j=target;j>=i;j--)
            {
                dp[j]=dp[j]||dp[j-i];
                if(dp[target])
                {
                    return true;
                }
            }
        }
        return dp[target];
    }
};
