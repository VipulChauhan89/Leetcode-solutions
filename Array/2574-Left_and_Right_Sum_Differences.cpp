class Solution {
public:
    vector<int> leftRightDifference(vector<int> &nums)
    {
        int right_sum=0,left_sum=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            right_sum+=nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            right_sum-=nums[i];
            ans.push_back(abs(left_sum-right_sum));
            left_sum += nums[i];
        }
        return ans;
    }
};
