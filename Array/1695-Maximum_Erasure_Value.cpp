class Solution {
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        unordered_set<int> s;
        int n=nums.size(),l=0,mxSum=0,curSum=0;
        for(int i=0;i<n;i++)
        {
            while(s.find(nums[i])!=s.end())
            {
                curSum-=nums[l];
                s.erase(nums[l]);
                l++;
            }
            curSum+=nums[i];
            s.insert(nums[i]);
            mxSum=max(mxSum,curSum);
        }
        return mxSum;
    }
};
