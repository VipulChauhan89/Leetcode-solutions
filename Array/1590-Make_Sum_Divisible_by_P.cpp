class Solution {
public:
    int minSubarray(vector<int> &nums,int p)
    {
        int n=nums.size(),ans=n;
        long long sufsum=0,presum=0;
        unordered_map<int, int> dp;
        for(auto x:nums)
        {
            sufsum+=x;                  
        }
        dp[0]=-1;
        for(int i=0;i<n;i++)
        {
            presum+=nums[i];
            sufsum-=nums[i];
            dp[presum%p]=i;
            int rem=(p-sufsum%p)%p;
            if(dp.find(rem)!=dp.end())
            {
                ans=min(ans,i-dp[rem]);
            }
        }
        return (ans==n?-1:ans);
    }
};
