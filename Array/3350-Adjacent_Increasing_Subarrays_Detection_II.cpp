class Solution {
public:
    int maxIncreasingSubarrays(vector<int> &nums)
    {
        int n=nums.size(),u=1,pu=0,ans=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
                u++;
            }
            else
            {
                pu=u;
                u=1;
            }
            int h=u>>1,m=min(pu,u),c=max(h,m);
            if(c>ans)
            {
                ans=c;
            }
        }
        return ans;
    }
};
