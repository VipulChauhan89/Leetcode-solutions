class Solution {
public:
    int findFinalValue(vector<int> &nums,int original)
    {
        unordered_map<int,int> m;
        for(auto &i:nums)
        {
            m[i]++;
        }
        while(original<=1000 && m[original]>0)
        {
            original*=2;
        }
        return original;
    }
};
