class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]>nums[i])
            {
                count++;
            }
        }
        if(count==1)
        {
            return (nums[0]>=nums[nums.size()-1])?true:false;
        }
        else if(count==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
