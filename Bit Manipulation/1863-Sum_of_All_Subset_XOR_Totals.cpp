class Solution {
public:
    int subsetXORSum(vector<int> &nums) 
    {
        int total=0;
        for(auto &i:nums)
        {
            total|=i;
        }
        return total*(1<<(nums.size()-1));
    }
};
