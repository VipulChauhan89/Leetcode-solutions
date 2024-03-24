class Solution {
public:
    int findDuplicate(vector<int> &nums) 
    {
        sort(nums.begin(),nums.end());
        int ans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]==nums[i])
            {
                ans=nums[i];
                break;
            }
        }
        return ans;
    }
};
