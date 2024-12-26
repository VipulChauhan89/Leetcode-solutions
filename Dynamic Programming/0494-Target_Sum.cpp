class Solution {
public:
    int ans(vector<int> &nums,int &target,int current,int i)
    {
        if(i>=nums.size())
        {
            return current==target;
        }
        return ans(nums,target,current+nums[i],i+1)+ans(nums,target,current-nums[i],i+1);
    }
    int findTargetSumWays(vector<int> &nums,int target) 
    {
        return ans(nums,target,0,0);
    }
};
