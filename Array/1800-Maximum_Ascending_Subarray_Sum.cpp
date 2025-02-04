class Solution {
public:
    int maxAscendingSum(vector<int> &nums) 
    {
        int n=nums.size(),mxSum=0,currentSum=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]<nums[i])
            {
                currentSum+=nums[i];
            }
            else
            {
                mxSum=max(mxSum,currentSum);
                currentSum=nums[i];
            }
        }    
        return max(mxSum,currentSum);
    }
};
