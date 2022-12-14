class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int a=0,b=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i%2==0)
            {
                a=max(nums[i]+a,b);
            }
            else
            {
                b=max(nums[i]+b,a);
            }
        }
        return max(a,b);
    }
};
