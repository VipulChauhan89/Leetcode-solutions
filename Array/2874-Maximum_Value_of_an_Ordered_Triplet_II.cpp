class Solution {
public:
    long long maximumTripletValue(vector<int> &nums) 
    {
        long mxTriplet=0,mxEle=0,mxDiff=0;
        for(auto &i:nums)
        {
            mxTriplet=max(mxTriplet,mxDiff*i);
            mxDiff=max(mxDiff,mxEle-i);
            mxEle=max(mxEle,(long)i);
        }
        return mxTriplet;
    }
};
