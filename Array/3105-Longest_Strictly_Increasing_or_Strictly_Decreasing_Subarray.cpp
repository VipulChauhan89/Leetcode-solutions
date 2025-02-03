class Solution {
public:
    int longestMonotonicSubarray(vector<int> &nums) 
    {
        if(nums.empty())
        {
            return 0;
        } 
        int mxLength=1,increment=1,decrement=1;
        for(int i=1;i<nums.size();i++) 
        {
            if(nums[i]>nums[i-1])
            {
                increment++;
                decrement=1;
            } 
            else if(nums[i]<nums[i-1])
            {
                decrement++;
                increment=1;
            } 
            else
            {
                increment=decrement=1;
            } 
            mxLength=max(mxLength,max(increment,decrement));
        }
        return mxLength;
    }
};
