class Solution {
public:
    long long maxTotalValue(vector<int> &nums,int k)
    {
        int mx=INT_MIN,mn=INT_MAX;
        for(auto &i:nums)
        {
            mx=max(mx,i);
            mn=min(mn,i);
        }
        return ((long long)mx-(long long)mn)*(long long)k;
    }
};
