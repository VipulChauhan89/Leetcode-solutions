class Solution {
public:
    long long maxSubarraySum(vector<int> &nums,int k)
    {
        int n=nums.size();
        long long prefix=0,ans=LLONG_MIN;
        vector<long long> mS(k,LLONG_MAX/2);
        mS[k-1]=0;
        for(int i=0;i<n;i++)
        {
            prefix+=nums[i];
            long long &ksum=mS[i%k];
            ans=max(ans,prefix-ksum);
            ksum=min(prefix,ksum);
        }
        return ans;
    }
};
