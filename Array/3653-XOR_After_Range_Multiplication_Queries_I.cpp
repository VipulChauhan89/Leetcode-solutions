class Solution {
public:
    int xorAfterQueries(vector<int> &nums,vector<vector<int>> &queries)
    {
        int mod=1e9+7;
        for(auto &t:queries)
        {
            int l=t[0],r=t[1],k=t[2],v=t[3];
            int idx=l;
            while(idx<=r)
            {
                long long temp=nums[idx];
                nums[idx]=(temp*v)%mod;
                idx+=k;
            }
        }
        int ans=0;
        for(int num:nums)
        {
            ans^=num;
        }
        return ans;
    }
};
