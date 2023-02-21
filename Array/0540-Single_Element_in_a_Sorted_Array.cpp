class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int l=0,h=nums.size()-2,mid;
        while(l<=h)
        {
            mid=l+(h-l)/2;
            if(nums[mid]==nums[mid^1])
            {
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        return nums[l];
    }
};
