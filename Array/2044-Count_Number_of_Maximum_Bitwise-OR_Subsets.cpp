class Solution {
public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        unordered_map<int,int> dp;
        dp[0]=1;
        for(auto &i:nums)
        {
            unordered_map<int, int> new_dp=dp;
            for(auto &j:dp)
            {
                new_dp[j.first | i]+=j.second;
            }
            dp=move(new_dp);
        }
        int maxOr=0;
        for(auto &i:nums)
        {
            maxOr|=i;
        }
        return dp[maxOr];
    }
};
