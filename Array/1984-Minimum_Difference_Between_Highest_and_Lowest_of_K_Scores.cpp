class Solution {
public:
    int minimumDifference(vector<int> &nums,int k)
    {
        int n=nums.size(),ans=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<=n-k;i++)
        {
            ans=min(ans,nums[i+k-1]-nums[i]);
        }
        return ans;
    }
};
