class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int n=nums.size(),st,j=1;
        if(n==1)
        {
            return 1;
        }
        st=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=st)
            {
                nums[j++]=nums[i];
                st=nums[i];
            }
        }
        return j;
    }
};
