class Solution {
public:
    int minimumOperations(vector<int> &nums) 
    {
        int ans=0;
        for(auto &i:nums)
        {
            int mod=i%3;
            ans+=min(mod,3-mod);
        }
        return ans;
    }
};
