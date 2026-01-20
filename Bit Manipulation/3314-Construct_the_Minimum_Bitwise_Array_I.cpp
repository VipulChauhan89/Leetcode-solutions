class Solution {
public:
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        vector<int> ans;
        for(auto &i:nums)
        {
            if(i & 1)
            {
                auto z=((i+1) & ~i)>>1;
                ans.push_back(i & ~z);
            }
            else
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
