class Solution {
public:
    vector<int> pivotArray(vector<int> &nums,int pivot) 
    {
        vector<int> ans(nums.size(),0);
        int l=0,r=nums.size()-1;
        for(int i=0,j=nums.size()-1;i<nums.size();i++,j--) 
        {
            if(nums[i]<pivot) 
            {
                ans[l]=nums[i];
                l++;
            }
            if(nums[j]>pivot) 
            {
                ans[r]=nums[j];
                r--;
            }
        }
        while(l<=r) 
        {
            ans[l]=pivot;
            l++;
        }
        return ans;
    }
};
