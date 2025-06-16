class Solution {
public:
    int maximumDifference(vector<int> &nums) 
    {
        int n=nums.size(),mx=-1,mn=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]<=mn)
            {
                mn=nums[i];
            }
            else
            {
                mx=max(mx,nums[i]-mn);
            }    
        }
        return mx;
    }
};
