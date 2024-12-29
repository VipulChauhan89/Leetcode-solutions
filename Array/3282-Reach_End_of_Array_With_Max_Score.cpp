class Solution {
public:
    long long findMaximumScore(vector<int> &nums) 
    {
        int n=nums.size(),j=0;
        long long ans=0,k=nums[0];
        for(int i=1;i<n-1;i++) 
        {
            if(nums[j]<nums[i])
            {
                ans+=(i-j)*k;
                k=nums[i];
                j=i;
            }
        }
        return ans+(n-j-1)*k;
    }
};
