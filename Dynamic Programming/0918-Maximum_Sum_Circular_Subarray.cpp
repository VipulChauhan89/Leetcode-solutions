class Solution {
public:
    int maxSum1(vector<int> &nums)
    {
        int prev_sum=nums[0],current_sum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prev_sum=max(nums[i],prev_sum+nums[i]);
            current_sum=max(current_sum,prev_sum);
        }
        return current_sum;
    }
    int maxSum2(vector<int> &nums)
    {
        int sum=nums[0],mx=nums[0];
        int prev_sum=nums[0],current_sum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            sum+=nums[i];
            mx=max(mx,nums[i]);
            prev_sum=min(nums[i],prev_sum+nums[i]);
            current_sum=min(current_sum,prev_sum);
        }
        return (sum>0 || sum-current_sum>0)?sum-current_sum:mx;
    }
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        return max(maxSum1(nums),maxSum2(nums));
    }
};
