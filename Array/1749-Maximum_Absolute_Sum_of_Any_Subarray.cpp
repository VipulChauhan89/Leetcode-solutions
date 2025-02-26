class Solution {
public:
    int maxAbsoluteSum(vector<int> &nums) 
    {
        int sum=0,mnSum=0,mxSum=0;
        for(auto &i:nums)
        {
            sum+=i;
            mxSum=max(mxSum,sum);
            mnSum=min(mnSum,sum);
        }
        return abs(mxSum-mnSum);
    }
};
