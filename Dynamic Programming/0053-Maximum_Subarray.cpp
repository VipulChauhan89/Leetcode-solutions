class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int prev_sum=nums[0],current_sum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prev_sum=max(nums[i],prev_sum+nums[i]);
            current_sum=max(current_sum,prev_sum);
        }
        return current_sum;
    }
};
