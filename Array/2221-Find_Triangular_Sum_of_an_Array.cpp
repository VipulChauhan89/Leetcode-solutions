class Solution {
public:
    int triangularSum(vector<int> &nums)
    {
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<nums.size()-1;j++)
            {
                nums[j]=(nums[j]+nums[j+1])%10;
            }
        }
        return nums[0];
    }
};
