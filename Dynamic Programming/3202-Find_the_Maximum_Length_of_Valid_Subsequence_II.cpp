class Solution {
public:
    int maximumLength(vector<int> &nums,int k)
    {
        int ans=2;
        for(int i=0;i<k;i++)
        {
            vector<int> dp(k,0);
            for(int j=0;j<nums.size();j++)
            {
                int mod=nums[j]%k,pos=(i-mod+k)%k;
                dp[mod]=dp[pos]+1;
            }
            for(auto &j:dp)
            {
                ans=max(ans,j);
            }
        }
        return ans;
    }
};
