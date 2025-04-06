class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) 
    {
        int n=nums.size(),mx=0;
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1),prev(n,-1),ans;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
            }
            if(dp[i]>dp[mx])
            {
                mx=i;
            }
        }
        for(int i=mx;i>=0;i=prev[i])
        {
            ans.push_back(nums[i]);
        }
        return ans;
    }
};
