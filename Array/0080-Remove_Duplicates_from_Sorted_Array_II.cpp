class Solution {
public:
    int removeDuplicates(vector<int> &nums) 
    {
        int n=nums.size(),s=2;
        if(n<=2)
        {
            return n;
        }
        for(int i=2;i<n;i++)
        {
            if(nums[s-2]!=nums[i])
            {
                nums[s++]=nums[i];
            }
        }    
        return s;
    }
};
