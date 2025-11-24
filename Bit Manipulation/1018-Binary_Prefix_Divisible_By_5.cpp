class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int> &nums)
    {
        vector<bool> ans;
        int value=0;
        for(auto &i:nums)
        {
            value=((value<<1)+i)%5;
            ans.push_back(value==0);
        }
        return ans;
    }
};
