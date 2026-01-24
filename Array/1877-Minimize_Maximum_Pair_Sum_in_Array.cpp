class Solution {
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(),nums.end());
        int ans=0,n=nums.size();
        for(int i=0;i<n>>1;i++)
        {
            ans=max(ans,nums[n-1-i]+nums[i]);
        }
        return ans;
    }
};
