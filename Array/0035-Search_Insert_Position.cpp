class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int l=0,h=nums.size(),mid;
        if(target>nums[h-1])
        {
            return h;
        }
        while(l<=h)
        {
            mid=(l+h)/2;
            if(target==nums[mid])
            {
                return mid;
            }
            else if(target<nums[mid])
            {
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
};
