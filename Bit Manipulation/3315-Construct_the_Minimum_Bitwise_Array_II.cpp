class Solution {
public:
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        for(auto &i:nums)
        {
            int remB=(1<<countr_one((unsigned)i))>>1;
            i^=(remB)|(-(remB==0) & ~i);
        }
        return move(nums);
    }
};
