class Solution {
public:
    int maximumCount(vector<int> &nums) 
    {
        int n=nums.size(),c1=0,c2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                c1++;
            }
            else if(nums[i]<0)
            {
                c2++;
            }
        }
        return max(c1,c2);
    }
};
